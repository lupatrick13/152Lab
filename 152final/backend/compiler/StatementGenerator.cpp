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
    bool modifiercheck = varCtx->modifier() != nullptr;


    // Emit code to evaluate the expression.
    compiler->visit(exprCtx);

    // float variable := integer constant
    if (   (varType == Predefined::realType)
        && (exprType->baseType() == Predefined::integerType)) emit(I2F);


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
	cout << ctx->functionName()->entry << endl;
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

	emit(INVOKESTATIC, programName + "/" + ProcName + "(" + Param + ")" + typeDescriptor(routineId));
}

void StatementGenerator::emitPredefined(GooeyParser::PredefinedRoutineCallContext *ctx)
{
	string routineName = ctx->routine->getName();
	GooeyParser::ExpressionContext *expr1 = ctx->argumentList() != nullptr ? ctx->argumentList()->argument(0)->expression() : nullptr;
	string text = "";
	SymtabEntry *varId = ctx->variable()->entry;
	if(routineName == "create") // do the create routine
	{
		if(expr1 != nullptr)
			emitCreate(expr1, varId);
		else
			emitCreate(nullptr, varId);
	}
	if(routineName == "add")
	{
		GooeyParser::ExpressionContext *expr2 = ctx->argumentList()->argument(1)->expression();
		SymtabEntry *var2Id = expr1->entry;
		emitAdd(expr2, varId, var2Id);
	}
	if(routineName == "finish")
	{
		emitAdd(varId);
	}
}

void StatementGenerator::emitCreate(GooeyParser::ExpressionContext *title, SymtabEntry *entry)
{
	string varName = entry->getName();
	string object = objectTypeName(entry->getType());
	string typeName = entry->getType()->getIdentifier()->getName();
	emitLine();
	emit(NEW, object);
	emit(DUP);
	if(title != nullptr)
	{
		compiler->visit(title);
		emit(INVOKESPECIAL, object + "/<init>(Ljava/lang/String;)V");
	}
	else if( typeName== "panel")
	{
	    emit(NEW, "java/awt/BorderLayout");
	    emit(DUP);
	    emit(INVOKESPECIAL, "java/awt/BorderLayout/<init>()V");
	    emit(INVOKESPECIAL, "javax/swing/JPanel/<init>(Ljava/awt/LayoutManager;)V");

	}
	else if(typeName == "text")
	{
		emit(INVOKESPECIAL, object + "/<init>()V");
	}
    emit(PUTSTATIC, programName + "/" + varName, typeDescriptor(entry));
}
void StatementGenerator::emitAdd(GooeyParser::ExpressionContext *title, SymtabEntry *var1, SymtabEntry *var2)
{
	string LHSname = var1->getName();
	string RHSname = var2->getName();
	string LHStype = typeDescriptor(var1);
	string RHStype = typeDescriptor(var2);
	string LHStypesmall = objectTypeName(var1->getType());

	emitLine();
	emit(GETSTATIC, programName + "/" + LHSname, LHStype);
	emit(GETSTATIC, programName + "/" + RHSname, RHStype);
	compiler->visit(title);
	emit(INVOKEVIRTUAL, LHStypesmall + "/add(Ljava/awt/Component;Ljava/lang/Object;)V");

}
void StatementGenerator::emitAdd(SymtabEntry *var)
{
	string LHSname = var->getName();
	string LHStype = typeDescriptor(var);

	emitLine();
	emit(GETSTATIC, programName + "/" + "_mainframe", "Ljavax/swing/JFrame;");
	emit(GETSTATIC, programName + "/" + LHSname, LHStype);
	emit(LDC, "\"Center\"");
	emit(INVOKEVIRTUAL, "javax/swing/JFrame/add(Ljava/awt/Component;Ljava/lang/Object;)V");

}
}} // namespace backend::compiler
