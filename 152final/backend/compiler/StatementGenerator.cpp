#include <string>
#include <vector>
#include <map>

#include "GooeyBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/Predefined.h"
#include "Compiler.h"
#include "StatementGenerator.h"

namespace backend { namespace compiler {

using namespace std;
using namespace intermediate;

struct CustomSort final
{
	bool operator() (const pair< pair<string,Typespec*>, int> &LHS, const pair< pair<string,Typespec*>, int> &RHS) const
	{
		if(LHS.first.second == Predefined::charType)
			return LHS.first.first[1] < RHS.first.first[1];
		else if(LHS.first.second == Predefined::realType)
			return stof(LHS.first.first) < stof(RHS.first.first);
		else if(LHS.first.second == Predefined::integerType || LHS.first.second->getForm() == Form::ENUMERATION)
			return stoi(LHS.first.first) < stoi(RHS.first.first);
		return true;
	}
};

void StatementGenerator::emitAssignment(GooeyParser::AssignmentStatementContext *ctx)
{
    GooeyParser::VariableContext *varCtx  = ctx->lhs()->variable();
    GooeyParser::ExpressionContext *exprCtx = ctx->rhs()->expression();
    SymtabEntry *varId = varCtx->entry;
    Typespec *varType  = varCtx->type;
    Typespec *exprType = exprCtx->type;

    // The last modifier, if any, is the variable's last subscript or field.
    //bool modifiercheck = varCtx->modifier() != nullptr;


    // Emit code to evaluate the expression.
    compiler->visit(exprCtx);

    // float variable := integer constant
    if (   (varType == Predefined::realType)
        && (exprType->baseType() == Predefined::integerType)) emit(I2F);

    if(varId->getType()->getForm() == Form::ARRAY)
    {
    	compiler->visit(varCtx);
    }
    else
    	emitStoreValue(varId, varType);

}

void StatementGenerator::emitIf(GooeyParser::IfStatementContext *ctx)
{
	/***** Complete this member function. *****/
    Label *exitLabel;
    Label *elseLabel = new Label();

    compiler->visit(ctx->expression());

    emit(IFEQ, elseLabel);
    compiler->visit(ctx->statement(0));

    if(ctx->statement(1) != nullptr)
    {
    	exitLabel = new Label();
    	emit(GOTO,exitLabel);
    }

    emitLabel(elseLabel);

    if(ctx->statement(1) != nullptr)
    {
    	compiler->visit(ctx->statement(1));
    	emitLabel(exitLabel);
    }

}

void StatementGenerator::emitWhile(GooeyParser::WhileStatementContext *ctx)
{
    /***** Complete this member function. *****/
	Label *loop = new Label();
	Label *exit = new Label();

	emitLabel(loop);

	compiler->visit(ctx->expression());
	emit(IFEQ, exit);

	compiler->visit(ctx->statement());
	emit(GOTO,loop);

	emitLabel(exit);

}

void StatementGenerator::emitFor(GooeyParser::ForStatementContext *ctx)
{
    /***** Complete this member function. *****/
	SymtabEntry *variableId = ctx->variable()->entry;
	Typespec *varType  = ctx->variable()->type;
	GooeyParser::ExpressionContext *expr0Ctx = ctx->expression(0);
	Instruction crement = IF_ICMPGT;

	Label *exit = new Label();
	Label *loop = new Label();
	Label *cmp1 = new Label();
	Label *cmp2 = new Label();

	compiler->visit(expr0Ctx);
	emitStoreValue(variableId, varType);
	emitLabel(loop);

	emitLoadValue(variableId);

	compiler->visit(ctx->expression(1));
	emit(crement, cmp1);
	emitLoadConstant(0);
	emit(GOTO, cmp2);
	emitLabel(cmp1);
	emitLoadConstant(1);
	emitLabel(cmp2);
	//check if you go into loop again
	emit(IFNE, exit);
	compiler->visit(ctx->statement());
	// Increment/decrement
	emitLoadValue(variableId);
	emitLoadConstant(1);
	if(crement == IF_ICMPGT) 	emit(IADD);
	else 						emit(ISUB);
	emitStoreValue(variableId, varType);
	//final part, go to loop to check condition and exit if condition false
	emit(GOTO, loop);
	emitLabel(exit);
}


void StatementGenerator::emitFunctionCall(GooeyParser::FunctionCallContext *ctx)
{
    /***** Complete this member function. *****/
	SymtabEntry *routineId = ctx->functionName()->entry;
	GooeyParser::ArgumentListContext *argListCtx = ctx->argumentList();
	emitCall(routineId, argListCtx);
}
void StatementGenerator::emitProcedureCall(GooeyParser::ProcedureCallContext *ctx)
{
    /***** Complete this member function. *****/
	SymtabEntry *routineId = ctx->functionName()->entry;
	GooeyParser::ArgumentListContext *argListCtx = ctx->argumentList();
	emitCall(routineId, argListCtx);
}
void StatementGenerator::emitCall(SymtabEntry *routineId,
                                  GooeyParser::ArgumentListContext *argListCtx)
{
    /***** Complete this member function. *****/
	string ProcName = routineId->getName();
	string Param = "";
	int index = 0;
	vector<SymtabEntry *> *parmIds = routineId->getRoutineParameters();
	if(ProcName == "random")
	{
		emit(GETSTATIC, programName + "/_random", "Ljava/util/Random;");
	}
	if(parmIds != nullptr)
	{
		for(SymtabEntry * parmId : *parmIds)
			Param += typeDescriptor(parmId); //gets all parameters
	}

	if(argListCtx != nullptr){
		for(GooeyParser::ArgumentContext *args : argListCtx->argument())
		{
			const char checkType = Param.at(index);
			Typespec *type = args->expression()->type;

			compiler->visit(args->expression());
			localStack->increase(0);

			if(typeDescriptor(type).at(0) != checkType) //to get correct type conversion for parameters
			{
				string temp = typeDescriptor(type) + "2" + Param[index];
				if(temp == "I2F") emit(I2F);
				else if(temp == "I2C") emit(I2C);
				else if(temp == "I2D") emit(I2D);
				else if(temp == "F2I") emit(F2I);
				else if(temp == "F2D") emit(F2D);
				else if(temp == "D2F") emit(D2F);
			}
			index++;
		}
	}
	if(ProcName == "random")
	{
		emit(INVOKEVIRTUAL, "java/util/Random/nextInt(I)I");
	}
	else
		emit(INVOKESTATIC, programName + "/" + ProcName + "(" + Param + ")" + typeDescriptor(routineId));
}

void StatementGenerator::emitPredefined(GooeyParser::PredefinedRoutineCallContext *ctx)
{
	string routineName = ctx->routine->getName();
	GooeyParser::ArgumentListContext *argCtx = nullptr;
	GooeyParser::ActionNameContext *action = nullptr;
	GooeyParser::VariableContext *varCtx = ctx->variable();
	vector<GooeyParser::ExpressionContext *> *indexs = new vector<GooeyParser::ExpressionContext *>();
	if(ctx->variable()->modifier(0) != nullptr)
	{
		for(GooeyParser::ModifierContext *expCtx : ctx->variable()->modifier())
		{
			indexs->push_back(expCtx->expression());
		}
	}
	if(ctx->argumentList()!= nullptr)
	{
		argCtx = ctx->argumentList();
		if(ctx->argumentList()->argument(0)->actionName() != nullptr) action = ctx->argumentList()->argument(0)->actionName();

	}
	string text = "";
	SymtabEntry *varId = ctx->variable()->entry;
	if(routineName == "create") // do the create routine
	{
		if(argCtx != nullptr)
			emitCreate(argCtx, varId,indexs);
		else
			emitCreate(nullptr, varId, indexs);
	}
	if(routineName == "add")
	{
		emitAdd(argCtx, varId, indexs);
	}
	if(routineName == "finish")
	{
		emitAdd(argCtx, varId, indexs, 1);
	}
	if(routineName == "settext")
	{
		emitSetText(argCtx, varId);
	}
	if(routineName == "addaction")
	{

		emitAddAction(action, varId);
	}
}

void StatementGenerator::emitCreate(GooeyParser::ArgumentListContext *argCtx, SymtabEntry *entry, vector<GooeyParser::ExpressionContext*> *indexs)
{
	Typespec *type = entry->getType();
	string varName = entry->getName();
	int arrayC = type->getArrayElementCount();
	string object = arrayC ? "" :objectTypeName(type);
	string typeName = arrayC ? "" : type->getIdentifier()->getName();
    int nestingLevel = entry->getSymtab()->getNestingLevel();
    int slot = entry->getSlotNumber();
    if(arrayC > 0)
    {
    	while(type->getForm() == Form::ARRAY) type = type->getArrayElementType();
    	typeName = type->getIdentifier()->getName();
    	object = objectTypeName(type);
    }
	emitLine();

	emit(NEW, object);
	emit(DUP);
	if(argCtx != nullptr)
	{
		compiler->visit(argCtx);
		emit(INVOKESPECIAL, object + "/<init>(Ljava/lang/String;)V");
	}
	else if( typeName== "panel")
	{
	    emit(NEW, "java/awt/BorderLayout");
	    emit(DUP);
	    emit(INVOKESPECIAL, "java/awt/BorderLayout/<init>()V");
	    emit(INVOKESPECIAL, "javax/swing/JPanel/<init>(Ljava/awt/LayoutManager;)V");
	    emit(DUP);
	    emit(BIPUSH, 5);
	    emit(BIPUSH, 5);
	    emit(BIPUSH, 5);
	    emit(BIPUSH, 5);
	    emit(INVOKESTATIC, "javax/swing/BorderFactory/createEmptyBorder(IIII)Ljavax/swing/border/Border;");
	    emit(INVOKEVIRTUAL, "javax/swing/JPanel/setBorder(Ljavax/swing/border/Border;)V");

	}
	else if(typeName == "text")
	{
		emit(INVOKESPECIAL, object + "/<init>()V");
	}
	if(nestingLevel == 1)
	{
		if(arrayC == 0)
			emit(PUTSTATIC, programName + "/" + varName, typeDescriptor(entry));
		else
		{
			emitLoadArray(entry, indexs);
			emit(AASTORE);
		}
	}

	else
	{
		emitRangeCheck(entry->getType());
		emitStoreLocal(entry->getType(), slot);
	}
}
void StatementGenerator::emitAdd(GooeyParser::ArgumentListContext *argCtx, SymtabEntry *var1,
		vector<GooeyParser::ExpressionContext*> *indexs)
{
	string LHSname = var1->getName();
	string LHStype = typeDescriptor(var1);
	string LHStypesmall = objectTypeName(var1->getType());
    int nestingLevel = var1->getSymtab()->getNestingLevel();
    int slot1 = var1->getSlotNumber();
    int arrc1 = var1->getType()->getArrayElementCount();
    emitLine();
    if(nestingLevel == 1)
    {
    	if(arrc1 == 0)
    		emit(GETSTATIC, programName + "/" + LHSname, LHStype);
    	else
    	{
    		emitLoadArray(var1, indexs);
    	}
    	compiler->visit(argCtx);
		emit(INVOKEVIRTUAL, LHStypesmall + "/add(Ljava/awt/Component;Ljava/lang/Object;)V");
    }
    else
    {
		emitLoadLocal(var1->getType(), slot1);
		compiler->visit(argCtx);
		emit(INVOKEVIRTUAL, LHStypesmall + "/add(Ljava/awt/Component;Ljava/lang/Object;)V");
    }

}
void StatementGenerator::emitAdd(GooeyParser::ArgumentListContext *argCtx,SymtabEntry *var,vector<GooeyParser::ExpressionContext*> *indexs, int check )
{
	string LHSname = var->getName();
	string LHStype = typeDescriptor(var);
    int nestingLevel = var->getSymtab()->getNestingLevel();
    int slot = var->getSlotNumber();
    int arrc = var->getType()->getArrayElementCount();

	emitLine();
	emit(GETSTATIC, programName + "/" + "_mainframe", "Ljavax/swing/JFrame;");
	if(nestingLevel == 1)
	{
		if(arrc == 0)
			emit(GETSTATIC, programName + "/" + LHSname, LHStype);
		else emitLoadArray(var, indexs);
	}
	else
		emitLoadLocal(var->getType(),slot);
	compiler->visit(argCtx);
	emit(INVOKEVIRTUAL, "javax/swing/JFrame/add(Ljava/awt/Component;Ljava/lang/Object;)V");

}

void StatementGenerator::emitSetText(GooeyParser::ArgumentListContext *argCtx, SymtabEntry *var)
{
	string varName = var->getName();
	string varType = typeDescriptor(var);
	string varTypeS = objectTypeName(var->getType());
	emit(GETSTATIC, programName+ "/" + varName, varType);
	compiler->visit(argCtx);
	emit(INVOKEVIRTUAL,varTypeS + "/setText(Ljava/lang/String;)V");

}

void StatementGenerator::emitAddAction(GooeyParser::ActionNameContext *ctx, SymtabEntry *var)
{

	string varName = var->getName();
	string varType = typeDescriptor(var);
	string varTypeS = objectTypeName(var->getType());
	SymtabEntry *actionId = ctx->entry;
	string actionName = actionId->getName();
	emit(GETSTATIC, programName+ "/" + varName, varType);
	emit(NEW, programName + "_" + actionName);
	emit(DUP);
	emit(INVOKESPECIAL, programName + "_" + actionName +"/<init>()V");
	emit(INVOKEVIRTUAL, varTypeS + "/addActionListener(Ljava/awt/event/ActionListener;)V");
}


void StatementGenerator::emitLoadArray(SymtabEntry *array, vector<GooeyParser::ExpressionContext *> *indexs)
{
	emitLoadValue(array);
	for(GooeyParser::ExpressionContext *expCtx : *indexs)
	{
		compiler->visit(expCtx);
		emit(AALOAD);
	}
}
}} // namespace backend::compiler
