#include <string>
#include <vector>
#include <map>

#include "PascalBaseVisitor.h"
#include "antlr4-runtime.h"

#include "intermediate/symtab/Predefined.h"
#include "Compiler.h"
#include "StatementGenerator.h"

namespace backend { namespace compiler {

using namespace std;
using namespace intermediate;

void StatementGenerator::emitAssignment(PascalParser::AssignmentStatementContext *ctx)
{
    PascalParser::VariableContext *varCtx  = ctx->lhs()->variable();
    PascalParser::ExpressionContext *exprCtx = ctx->rhs()->expression();
    SymtabEntry *varId = varCtx->entry;
    Typespec *varType  = varCtx->type;
    Typespec *exprType = exprCtx->type;

    // The last modifier, if any, is the variable's last subscript or field.
    int modifierCount = varCtx->modifier().size();
    PascalParser::ModifierContext *lastModCtx = modifierCount == 0
                            ? nullptr : varCtx->modifier()[modifierCount - 1];

    // The target variable has subscripts and/or fields.
    if (modifierCount > 0)
    {
        lastModCtx = varCtx->modifier()[modifierCount - 1];
        compiler->visit(varCtx);
    }

    // Emit code to evaluate the expression.
    compiler->visit(exprCtx);

    // float variable := integer constant
    if (   (varType == Predefined::realType)
        && (exprType->baseType() == Predefined::integerType)) emit(I2F);

    // Emit code to store the expression value into the target variable.
    // The target variable has no subscripts or fields.
    if (lastModCtx == nullptr) emitStoreValue(varId, varId->getType());

    // The target variable is a field.
    else if (lastModCtx->field() != nullptr)
    {
        emitStoreValue(lastModCtx->field()->entry, lastModCtx->field()->type);
    }

    // The target variable is an array element.
    else
    {
        emitStoreValue(nullptr, varType);
    }
}

void StatementGenerator::emitIf(PascalParser::IfStatementContext *ctx)
{
	/***** Complete this member function. *****/
    Label *exitLabel;
    Label *elseLabel = new Label();

    compiler->visit(ctx->expression());

    emit(IFEQ, elseLabel);
    compiler->visit(ctx->trueStatement());

    if(ctx->falseStatement() != nullptr)
    {
    	exitLabel = new Label();
    	emit(GOTO,exitLabel);
    }

    emitLabel(elseLabel);

    if(ctx->falseStatement() != nullptr)
    {
    	compiler->visit(ctx->falseStatement());
    	emitLabel(exitLabel);
    }

}

void StatementGenerator::emitCase(PascalParser::CaseStatementContext *ctx)
{
    /***** Complete this member function. *****/
	vector<Label*> stuffs;
	Label *exit;
	int index = 0;
	compiler->visit(ctx->expression());
	emit(LOOKUPSWITCH);
	for (PascalParser::CaseBranchContext *Branch : ctx->caseBranchList()->caseBranch())
	{
		if(Branch->children.size() > 0)
		{
			stuffs.push_back(new Label());
			for(PascalParser::CaseConstantContext *constant: Branch->caseConstantList()->caseConstant())
			{
				Typespec *type = constant->type;
				string temp = constant->getText();
				if(type == Predefined::charType)
					emitLabel(temp[1], stuffs[index]);
				else if(type == Predefined::realType)
					emitLabel(stof(temp), stuffs[index]);
				else if(type == Predefined::integerType)
					emitLabel(stoi(temp), stuffs[index]);
			}
			index++;
		}
	}
	exit = new Label();
	emitLabel("default", exit);
	index = 0;
	for(PascalParser::CaseBranchContext *Branch: ctx->caseBranchList()->caseBranch())
	{

		if(Branch->children.size() > 0)
		{
			emitLabel(stuffs[index]);
			compiler->visit(Branch->statement());
			emit(GOTO, exit);
			index++;
		}
	}
	emitLabel(exit);
}

void StatementGenerator::emitRepeat(PascalParser::RepeatStatementContext *ctx)
{
    Label *loopTopLabel  = new Label();
    Label *loopExitLabel = new Label();

    emitLabel(loopTopLabel);

    compiler->visit(ctx->statementList());
    compiler->visit(ctx->expression());
    emit(IFNE, loopExitLabel);
    emit(GOTO, loopTopLabel);

    emitLabel(loopExitLabel);
}

void StatementGenerator::emitWhile(PascalParser::WhileStatementContext *ctx)
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

void StatementGenerator::emitFor(PascalParser::ForStatementContext *ctx)
{
    /***** Complete this member function. *****/
	SymtabEntry *variableId = ctx->variable()->variableIdentifier()->entry;
	Typespec *varType  = ctx->variable()->variableIdentifier()->type;
	PascalParser::ExpressionContext *expr0Ctx = ctx->expression(0);
	Instruction crement = ctx->TO() != nullptr ? IF_ICMPGT : IF_ICMPLT;

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

void StatementGenerator::emitProcedureCall(PascalParser::ProcedureCallStatementContext *ctx)
{
    /***** Complete this member function. *****/
	SymtabEntry *routineId = ctx->procedureName()->entry;
	PascalParser::ArgumentListContext *argListCtx = ctx->argumentList();
	emitCall(routineId, argListCtx);

}

void StatementGenerator::emitFunctionCall(PascalParser::FunctionCallContext *ctx)
{
    /***** Complete this member function. *****/
	SymtabEntry *routineId = ctx->functionName()->entry;
	PascalParser::ArgumentListContext *argListCtx = ctx->argumentList();
	emitCall(routineId, argListCtx);
}

void StatementGenerator::emitCall(SymtabEntry *routineId,
                                  PascalParser::ArgumentListContext *argListCtx)
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
		for(PascalParser::ArgumentContext *args : argListCtx->argument())
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

void StatementGenerator::emitWrite(PascalParser::WriteStatementContext *ctx)
{
    emitWrite(ctx->writeArguments(), false);
}

void StatementGenerator::emitWriteln(PascalParser::WritelnStatementContext *ctx)
{
    emitWrite(ctx->writeArguments(), true);
}

void StatementGenerator::emitWrite(PascalParser::WriteArgumentsContext *argsCtx,
                      bool needLF)
{
    emit(GETSTATIC, "java/lang/System/out", "Ljava/io/PrintStream;");

    // WRITELN with no arguments.
    if (argsCtx == nullptr)
    {
        emit(INVOKEVIRTUAL, "java/io/PrintStream.println()V");
        localStack->decrease(1);
    }

    // Generate code for the arguments.
    else
    {
        string format;
        int exprCount = createWriteFormat(argsCtx, format, needLF);

        // Load the format string.
        emit(LDC, format);

        // Emit the arguments array.
       if (exprCount > 0)
        {
            emitArgumentsArray(argsCtx, exprCount);

            emit(INVOKEVIRTUAL,
                        string("java/io/PrintStream/printf(Ljava/lang/String;")
                      + string("[Ljava/lang/Object;)")
                      + string("Ljava/io/PrintStream;"));
            localStack->decrease(2);
            emit(POP);
        }
        else
        {
            emit(INVOKEVIRTUAL,
                 "java/io/PrintStream/print(Ljava/lang/String;)V");
            localStack->decrease(2);
        }
    }
}

int StatementGenerator::createWriteFormat(
                                PascalParser::WriteArgumentsContext *argsCtx,
                                string& format, bool needLF)
{
    int exprCount = 0;
    format += "\"";

    // Loop over the write arguments.
    for (PascalParser::WriteArgumentContext *argCtx : argsCtx->writeArgument())
    {
        Typespec *type = argCtx->expression()->type;
        string argText = argCtx->getText();

        // Append any literal strings.
        if (argText[0] == '\'') format += convertString(argText, true);

        // For any other expressions, append a field specifier.
        else
        {
            exprCount++;
            format.append("%");

            PascalParser::FieldWidthContext *fwCtx = argCtx->fieldWidth();
            if (fwCtx != nullptr)
            {
                string sign = (   (fwCtx->sign() != nullptr)
                               && (fwCtx->sign()->getText() == "-")) ? "-" : "";
                format += sign + fwCtx->integerConstant()->getText();

                PascalParser::DecimalPlacesContext *dpCtx =
                                                        fwCtx->decimalPlaces();
                if (dpCtx != nullptr)
                {
                    format += "." + dpCtx->integerConstant()->getText();
                }
            }

            string typeFlag = type == Predefined::integerType ? "d"
                            : type == Predefined::realType    ? "f"
                            : type == Predefined::booleanType ? "b"
                            : type == Predefined::charType    ? "c"
                            :                                  "s";
            format += typeFlag;
        }
    }

    format += needLF ? "\\n\"" : "\"";

    return exprCount;
}

void StatementGenerator::emitArgumentsArray(
                    PascalParser::WriteArgumentsContext *argsCtx, int exprCount)
{
    // Create the arguments array.
    emitLoadConstant(exprCount);
    emit(ANEWARRAY, "java/lang/Object");

    int index = 0;

    // Loop over the write arguments to fill the arguments array.
    for (PascalParser::WriteArgumentContext *argCtx :
                                                argsCtx->writeArgument())
    {
        string argText = argCtx->getText();
        PascalParser::ExpressionContext *exprCtx = argCtx->expression();
        Typespec *type = exprCtx->type->baseType();

        // Skip string constants, which were made part of
        // the format string.
        if (argText[0] != '\'')
        {
            emit(DUP);
            emitLoadConstant(index++);

            compiler->visit(exprCtx);

            Form form = type->getForm();
            if (    ((form == SCALAR) || (form == ENUMERATION))
                 && (type != Predefined::stringType))
            {
                emit(INVOKESTATIC, valueOfSignature(type));
            }

            // Store the value into the array.
            emit(AASTORE);
        }
    }
}

void StatementGenerator::emitRead(PascalParser::ReadStatementContext *ctx)
{
    emitRead(ctx->readArguments(), false);
}

void StatementGenerator::emitReadln(PascalParser::ReadlnStatementContext *ctx)
{
    emitRead(ctx->readArguments(), true);
}

void StatementGenerator::emitRead(PascalParser::ReadArgumentsContext *argsCtx,
                                  bool needSkip)
{
    int size = argsCtx->variable().size();

    // Loop over read arguments.
    for (int i = 0; i < size; i++)
    {
        PascalParser::VariableContext *varCtx = argsCtx->variable()[i];
        Typespec *varType = varCtx->type;

        if (varType == Predefined::integerType)
        {
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/nextInt()I");
            emitStoreValue(varCtx->entry, nullptr);
        }
        else if (varType == Predefined::realType)
        {
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/nextFloat()F");
            emitStoreValue(varCtx->entry, nullptr);
        }
        else if (varType == Predefined::booleanType)
        {
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/nextBoolean()Z");
            emitStoreValue(varCtx->entry, nullptr);
        }
        else if (varType == Predefined::charType)
        {
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(LDC, "\"\"");
            emit(INVOKEVIRTUAL,
                 string("java/util/Scanner/useDelimiter(Ljava/lang/String;)") +
                 string("Ljava/util/Scanner;"));
            emit(POP);
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/next()Ljava/lang/String;");
            emit(ICONST_0);
            emit(INVOKEVIRTUAL, "java/lang/String/charAt(I)C");
            emitStoreValue(varCtx->entry, nullptr);

            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/reset()Ljava/util/Scanner;");

        }
        else  // string
        {
            emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
            emit(INVOKEVIRTUAL, "java/util/Scanner/next()Ljava/lang/String;");
            emitStoreValue(varCtx->entry, nullptr);
        }
    }

    // READLN: Skip the rest of the input line.
    if (needSkip)
    {
        emit(GETSTATIC, programName + "/_sysin Ljava/util/Scanner;");
        emit(INVOKEVIRTUAL, "java/util/Scanner/nextLine()Ljava/lang/String;");
        emit(POP);
    }
}

}} // namespace backend::compiler
