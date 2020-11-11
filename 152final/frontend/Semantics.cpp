#include <vector>
#include <set>

#include "antlr4-runtime.h"

#include "intermediate/symtab/SymtabStack.h"
#include "intermediate/symtab/Symtab.h"
#include "intermediate/symtab/SymtabEntry.h"
#include "intermediate/symtab/Predefined.h"
#include "intermediate/type/Typespec.h"
#include "intermediate/type/TypeChecker.h"
#include "intermediate/util/CrossReferencer.h"
#include "SemanticErrorHandler.h"
#include "Semantics.h"

namespace intermediate { namespace symtab {
    int Symtab::unnamedIndex = 0;
}}

namespace frontend {

using namespace std;
using namespace intermediate::symtab;
using namespace intermediate::type;
using namespace intermediate::util;

Object Semantics::visitProgram(GooeyParser::ProgramContext *ctx)
{
	visit(ctx->programHeader());
	visit(ctx->block()->declarations());
	if(ctx->block()->functiondef() != nullptr)
		visit(ctx->block()->functiondef());
	visit(ctx->block()->compoundStatement());

	CrossReferencer crossReferencer;
	crossReferencer.print(symtabStack);
	return nullptr;
}
Object Semantics::visitProgramHeader(GooeyParser::ProgramHeaderContext *ctx)
{
	GooeyParser::TitleContext *titCtx = ctx->title();
	string Name = titCtx->IDENTIFIER()->getText();

	programId = symtabStack->enterLocal(Name, PROGRAM);
	programId->setRoutineSymtab(symtabStack->push());

	symtabStack->setProgramId(programId);
	symtabStack->getLocalSymtab()->setOwner(programId);

	titCtx->entry = programId;

	return nullptr;
}
Object Semantics::visitVariableDeclarations(GooeyParser::VariableDeclarationsContext *ctx)
{
    GooeyParser::TypesContext *typeCtx = ctx->types();
    visit(typeCtx);

    GooeyParser::VariableIdentifierListContext *listCtx =
                                                ctx->variableIdentifierList();

    // Loop over the variables being declared.
    for (GooeyParser::VariableIdentifierContext *idCtx :
                                                listCtx->variableIdentifier())
    {
        int lineNumber = idCtx->getStart()->getLine();
        string variableName = toLowerCase(idCtx->IDENTIFIER()->getText());
        SymtabEntry *variableId = symtabStack->lookupLocal(variableName);

        if (variableId == nullptr)
        {
        	variableId = symtabStack->enterLocal(variableName, VARIABLE);
        	if(idCtx->modifier() == nullptr)
        	{
				variableId->setType(typeCtx->type);
        	}
        	else
        	{
        		Typespec *arrayType = new Typespec(ARRAY);
        		arrayType->setArrayElementCount(stoi(idCtx->modifier()->INTEGER()->getText()));
        		arrayType->setArrayElementType(typeCtx->type);
        		arrayType->setArrayIndexType(Predefined::integerType);
        		arrayType->setIdentifier(typeCtx->type->getIdentifier());
        		variableId->setType(arrayType);
        	}
			// Assign slot numbers to local variables.
			Symtab *symtab = variableId->getSymtab();
			if (symtab->getNestingLevel() > 1)
			{
				variableId->setSlotNumber(symtab->nextSlotNumber());
			}

			idCtx->entry = variableId;

        }
        else
        {
            error.flag(REDECLARED_IDENTIFIER, ctx);
        }

        variableId->appendLineNumber(lineNumber);
    }

    return nullptr;
}

Object Semantics::visitVariable(GooeyParser::VariableContext *ctx)
{
	int lineNumber = ctx->getStart()->getLine();
	string variableName = toLowerCase(ctx->IDENTIFIER()->getText());
	SymtabEntry *variableId = symtabStack->lookupLocal(variableName);
	if(variableId != nullptr)
	{
		ctx->type = variableId->getType();
		ctx->entry = variableId;
		if(ctx->type->getForm() == Form::ARRAY)
		{
			int count = ctx->type->getArrayElementCount();
			int index =  ctx->modifier() != nullptr ? stoi(ctx->modifier()->INTEGER()->getText()) : -1;
			bool inRange = count > index && index >=0;
			if(inRange)
				ctx->type = variableId->getType()->getArrayElementType();
			else
				error.flag(INVALID_FIELD, ctx);
		}
	}
	else
	{
		error.flag(UNDECLARED_IDENTIFIER, ctx);
	}
	variableId->appendLineNumber(lineNumber);
	return nullptr;
}
Object Semantics::visitTypes(GooeyParser::TypesContext *ctx)
{
	string typeName = toLowerCase(ctx->IDENTIFIER()->getText());
	SymtabEntry *typeId = symtabStack->lookup(typeName);
	if(typeId != nullptr)
	{
		if(typeId->getKind() != TYPE)
		{
			error.flag(INVALID_TYPE, ctx);
			ctx->type = Predefined::integerType;
		}
		else
		{
			ctx->type = typeId->getType();
		}
		typeId->appendLineNumber(ctx->start->getLine());
	}
	else
	{
		error.flag(UNDECLARED_IDENTIFIER, ctx);
		ctx->type = Predefined::integerType;
	}
	ctx->entry = typeId;
	return nullptr;
}

Object Semantics::visitFuncDec(GooeyParser::FuncDecContext *ctx)
{
	GooeyParser::ParameterContext *parameters = ctx->parameter();
	string FuncName;
	Typespec *returnType = nullptr;

	FuncName = toLowerCase(ctx->functionName()->IDENTIFIER()->getText());
	SymtabEntry *functionId = symtabStack->lookupLocal(FuncName);
	if(functionId != nullptr)
	{
		error.flag(REDECLARED_IDENTIFIER, ctx->getStart()->getLine(), FuncName);
		return nullptr;
	}

	functionId = symtabStack->enterLocal(FuncName, toLowerCase(ctx->returnType()->getText()) == "void" ? PROCEDURE : FUNCTION);

	functionId->setRoutineCode(DECLARED);
	ctx->functionName()->entry = functionId;

	SymtabEntry *parentId = symtabStack->getLocalSymtab()->getOwner();
	parentId->appendSubroutine(functionId);
	functionId->setRoutineSymtab(symtabStack->push());
	ctx->functionName()->entry = functionId;

	Symtab *symtab = symtabStack->getLocalSymtab();
	symtab->setOwner(functionId);

	if(parameters->parameterDecList() != nullptr)
	{
		vector<SymtabEntry *> *parameterIds =
				visit(parameters->parameterDecList()).as<vector<SymtabEntry *>*>();
		functionId->setRoutineParameters(parameterIds);
		for (SymtabEntry *parmId : *parameterIds)
		{
			parmId->setSlotNumber(symtab->nextSlotNumber());
		}
	}
	if(toLowerCase(ctx->returnType()->getText()) != "void")
	{
		GooeyParser::ReturnTypeContext *retTypeCtx = ctx->returnType();
		visit(retTypeCtx);
		returnType = retTypeCtx->type;

		if(returnType->getForm() != SCALAR)
		{
			error.flag(INVALID_RETURN_TYPE, retTypeCtx);
			returnType = Predefined::integerType;
		}
		functionId->setType(returnType);
		ctx->functionName()->type = returnType;
	}
	else
		ctx->functionName()->type = nullptr;
	if(ctx->declarations() != nullptr)
		visit(ctx->declarations());

	if(toLowerCase(ctx->returnType()->getText()) != "void")
	{
		SymtabEntry *assocVarId = symtabStack->enterLocal(FuncName, VARIABLE);
		assocVarId->setSlotNumber(symtab->nextSlotNumber());
		assocVarId->setType(returnType);
	}

	visit(ctx->statement());
	functionId->setExecutable(ctx->statement());

	symtabStack->pop();
	return nullptr;
}

Object Semantics::visitParameterDecList( GooeyParser::ParameterDecListContext *ctx)
{
	vector<SymtabEntry *> *parameterList = new vector<SymtabEntry *>();

	for(GooeyParser::ParameterDecContext *dclCtx : ctx->parameterDec())
	{
		vector<SymtabEntry *> parameterSublist = visit(dclCtx).as<vector<SymtabEntry*>>();
		for(SymtabEntry *id :parameterSublist) parameterList->push_back(id);
	}

	return parameterList;
}

Object Semantics::visitParameterDec(GooeyParser::ParameterDecContext *ctx)
{
	Kind kind = VALUE_PARAMETER;
	GooeyParser::TypesContext *typeCtx = ctx->types();
	visit(typeCtx);
	Typespec *parmType = typeCtx->type;

	vector<SymtabEntry *> parameterSublist;

	GooeyParser::ParameterIdListContext *listCtx = ctx->parameterIdList();

	for(GooeyParser::ParameterIdContext *idCtx: listCtx->parameterId())
	{
		int lineNum = idCtx->getStart()->getLine();
		string parmName = toLowerCase(idCtx->IDENTIFIER()->getText());
		SymtabEntry *parmId = symtabStack->lookupLocal(parmName);

		if(parmId == nullptr)
		{
			parmId = symtabStack->enterLocal(parmName, kind);
			parmId->setType(parmType);
		}
		else
			error.flag(REDECLARED_IDENTIFIER, idCtx);

		idCtx->entry = parmId;
		idCtx->type = parmType;

		parameterSublist.push_back(parmId);
		parmId->appendLineNumber(lineNum);
	}
	return parameterSublist;
}

Object Semantics::visitReturnType(GooeyParser::ReturnTypeContext *ctx)
{
	string typeName = toLowerCase(ctx->IDENTIFIER()->getText());
	SymtabEntry *typeId = symtabStack ->lookup(typeName);

	if(typeId != nullptr)
	{
		if(typeId->getKind() != TYPE)
		{
			error.flag(INVALID_TYPE, ctx);
			ctx->type = Predefined::integerType;
		}
		else
			ctx->type = typeId->getType();

		typeId->appendLineNumber(ctx->start->getLine());
	}
	else if(typeName == "void")
	{
		ctx->type = nullptr;
	}
	else
	{
		error.flag(UNDECLARED_IDENTIFIER, ctx);
		ctx->type = Predefined::integerType;
	}
	ctx->entry = typeId;
	return nullptr;
}

Object Semantics::visitAssignmentStatement(GooeyParser::AssignmentStatementContext *ctx)
{
	GooeyParser::LhsContext *lhsCtx = ctx->lhs();
	GooeyParser::RhsContext *rhsCtx = ctx->rhs();

	visitChildren(ctx);

	Typespec *lhsType = lhsCtx->type;
	Typespec *rhsType = rhsCtx->expression()->type;

	if(!TypeChecker::areAssignmentCompatible(lhsType, rhsType))
	{
		error.flag(INCOMPATIBLE_ASSIGNMENT, ctx);
	}
	return nullptr;
}

Object Semantics::visitLhs(GooeyParser::LhsContext *ctx)
{
	GooeyParser::VariableContext *varCtx = ctx->variable();
	visit(varCtx);
	ctx->type = varCtx->type;

	return nullptr;
}


void Semantics::checkCallArguments(
        GooeyParser::ArgumentListContext *listCtx, vector<SymtabEntry *> *parms)
{
    int parmsCount = parms->size();
    int argsCount = listCtx != nullptr ? listCtx->argument().size() : 0;

    if (parmsCount != argsCount)
    {
        error.flag(ARGUMENT_COUNT_MISMATCH, listCtx);
        return;
    }

    // Check each argument against the corresponding parameter.
    for (int i = 0; i < parmsCount; i++)
    {
        GooeyParser::ArgumentContext *argCtx = listCtx->argument()[i];
        GooeyParser::ExpressionContext *exprCtx = argCtx->expression();
        visit(exprCtx);

        SymtabEntry *parmId = (*parms)[i];
        Typespec *parmType = parmId->getType();
        Typespec *argType  = exprCtx->type;

        // For a VAR parameter, the argument must be a variable
        // with the same datatype.
        if (parmId->getKind() == REFERENCE_PARAMETER)
        {
            if (expressionIsVariable(exprCtx))
            {
                if (parmType != argType)
                {
                    error.flag(TYPE_MISMATCH, exprCtx);
                }
            }
            else
            {
                error.flag(ARGUMENT_MUST_BE_VARIABLE, exprCtx);
            }
        }

        // For a value parameter, the argument type must be
        // assignment compatible with the parameter type.
        else if (!TypeChecker::areAssignmentCompatible(parmType, argType))
        {
            error.flag(TYPE_MISMATCH, exprCtx);
        }
    }
}

bool Semantics::expressionIsVariable(GooeyParser::ExpressionContext *exprCtx)
{
	if(exprCtx->simpleExpression().size() == 1)
	{
		GooeyParser::SimpleExpressionContext *simpleCtx = exprCtx->simpleExpression(0);
		if(simpleCtx->term().size() == 1)
		{
			GooeyParser::TermContext *termCtx = simpleCtx->term(0);
			if(termCtx->factor().size() == 0)
			{
				return dynamic_cast<GooeyParser::VariableFactorContext *> (termCtx->factor(0)) != nullptr;
			}
		}
	}

	return false;
}

Object Semantics::visitExpression(GooeyParser::ExpressionContext *ctx)
{
	GooeyParser::SimpleExpressionContext *simpleCtx1 = ctx->simpleExpression(0);
	visit(simpleCtx1); //visit first term

	Typespec *simpleType1 = simpleCtx1->type;
	ctx->type = simpleType1;

	GooeyParser::RelOpContext *relOpCtx = ctx->relOp();

	//Second Simple expression if there is relop
	if(relOpCtx != nullptr)
	{
		GooeyParser::SimpleExpressionContext *simpleCtx2 = ctx->simpleExpression(1);
		visit(simpleCtx2);

		Typespec *simpleType2 = simpleCtx2->type;
		if(!TypeChecker::areComparisonCompatible(simpleType1, simpleType2))
		{
			error.flag(INCOMPATIBLE_COMPARISON, ctx);
		}
		ctx->type = Predefined::booleanType;
	}
	return nullptr;
}

Object Semantics::visitSimpleExpression(GooeyParser::SimpleExpressionContext *ctx)
{
	int count = ctx->term().size();
	GooeyParser::SignContext *signCtx = ctx->sign();
	bool hasSign = signCtx != nullptr;
	GooeyParser::TermContext *termCtx1 = ctx->term(0);

	if(hasSign)
	{
		string sign = signCtx->getText();
		if(sign == "+" && sign == "-")
		{
			error.flag(INVALID_SIGN, signCtx);
		}
	}

	visit(termCtx1);
	Typespec *termType1 = termCtx1->type;

	for(int i = 1; i<count; i++)
	{
		string op = toLowerCase(ctx->addOp(i-1)->getText());
		GooeyParser::TermContext *termCtx2 = ctx->term(i);
		visit(termCtx2);
		Typespec *termType2 = termCtx2->type;

		if(op == "or")
		{
			if(!TypeChecker::isBoolean(termType1))
				error.flag(TYPE_MUST_BE_BOOLEAN, termCtx1);
			if(!TypeChecker::isBoolean(termType2))
				error.flag(TYPE_MUST_BE_BOOLEAN, termCtx2);
			if(hasSign)
				error.flag(INVALID_SIGN, signCtx);
			termType2 = Predefined::booleanType;
		}
		else if(op == "+")
		{
			if(TypeChecker::areBothInteger(termType1, termType2))
				termType2 = Predefined::integerType;
			else if (TypeChecker::isAtLeastOneReal(termType1, termType2))
				termType2 = Predefined::realType;
			else if (TypeChecker::isAtLeastOneString(termType1, termType2))
			{
				if(hasSign) error.flag(INVALID_SIGN, signCtx);
				termType2 = Predefined::stringType;
			}
			else
			{
				if(!TypeChecker::isIntegerOrReal(termType1))
				{
					error.flag(TYPE_MUST_BE_NUMERIC, termCtx1);
					termType2 = Predefined::integerType;
				}
				if(!TypeChecker::isIntegerOrReal(termType2))
				{
					error.flag(TYPE_MUST_BE_NUMERIC, termCtx2);
					termType2 = Predefined::integerType;
				}
			}
		}
		else // -
		{
			if(TypeChecker::areBothInteger(termType1, termType2))
				termType2 = Predefined::integerType;
			else if (TypeChecker::isAtLeastOneReal(termType1, termType2))
				termType2 = Predefined::realType;
			else
			{
				if(!TypeChecker::isIntegerOrReal(termType1))
				{
					error.flag(TYPE_MUST_BE_NUMERIC, termCtx1);
					termType2 = Predefined::integerType;
				}
				if(!TypeChecker::isIntegerOrReal(termType2))
				{
					error.flag(TYPE_MUST_BE_NUMERIC, termCtx2);
					termType2 = Predefined::integerType;
				}
			}
		}
		termType1 = termType2;
	}
	ctx->type = termType1;
	return nullptr;
}

Object Semantics::visitTerm(GooeyParser::TermContext *ctx)
{
    int count = ctx->factor().size();
    GooeyParser::FactorContext *factorCtx1 = ctx->factor()[0];

    // First factor.
    visit(factorCtx1);
    Typespec *factorType1 = factorCtx1->type;

    // Loop over any subsequent factors.
    for (int i = 1; i < count; i++)
    {
        string op = toLowerCase(ctx->mulOp()[i-1]->getText());
        GooeyParser::FactorContext *factorCtx2 = ctx->factor()[i];
        visit(factorCtx2);
        Typespec *factorType2 = factorCtx2->type;

        if (op == "*")
        {
            // Both operands integer  ==> integer result
            if (TypeChecker::areBothInteger(factorType1, factorType2))
            {
                factorType2 = Predefined::integerType;
            }

            // Both real operands ==> real result
            // One real and one integer operand ==> real result
            else if (TypeChecker::isAtLeastOneReal(factorType1, factorType2))
            {
                factorType2 = Predefined::realType;
            }

            // Type mismatch.
            else
            {
                if (!TypeChecker::isIntegerOrReal(factorType1))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, factorCtx1);
                    factorType2 = Predefined::integerType;
                }
                if (!TypeChecker::isIntegerOrReal(factorType2))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, factorCtx2);
                    factorType2 = Predefined::integerType;
                }
            }
        }
        else if (op == "/")
        {
            // All integer and real operand combinations ==> real result
            if (   TypeChecker::areBothInteger(factorType1, factorType2)
                || TypeChecker::isAtLeastOneReal(factorType1, factorType2))
            {
                factorType2 = Predefined::realType;
            }

            // Type mismatch.
            else
            {
                if (!TypeChecker::isIntegerOrReal(factorType1))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, factorCtx1);
                    factorType2 = Predefined::integerType;
                }
                if (!TypeChecker::isIntegerOrReal(factorType2))
                {
                    error.flag(TYPE_MUST_BE_NUMERIC, factorCtx2);
                    factorType2 = Predefined::integerType;
                }
            }
        }

        else if (op == "and")
        {
            // Both operands bool ==> bool result. Else type mismatch.
            if (!TypeChecker::isBoolean(factorType1))
            {
                error.flag(TYPE_MUST_BE_BOOLEAN, factorCtx1);
                factorType2 = Predefined::booleanType;
            }
            if (!TypeChecker::isBoolean(factorType2))
            {
                error.flag(TYPE_MUST_BE_BOOLEAN, factorCtx2);
                factorType2 = Predefined::booleanType;
            }
        }

        factorType1 = factorType2;
    }

    ctx->type = factorType1;
    return nullptr;
}

Object Semantics::visitVariableFactor(GooeyParser::VariableFactorContext *ctx)
{
    GooeyParser::VariableContext *varCtx = ctx->variable();
    visit(varCtx);
    ctx->type = varCtx->type;

    return nullptr;
}

Object Semantics::visitNumberFactor(GooeyParser::NumberFactorContext *ctx)
{
    GooeyParser::NumberContext          *numberCtx   = ctx->number();
    GooeyParser::UnsignedNumberContext  *unsignedCtx = numberCtx->unsignedNumber();

    ctx->type = (unsignedCtx->INTEGER() != nullptr) ? Predefined::integerType
                                        : Predefined::realType;

    return nullptr;
}

Object Semantics::visitCharacterFactor(GooeyParser::CharacterFactorContext *ctx)
{
    ctx->type = Predefined::charType;
    return nullptr;
}

Object Semantics::visitStringFactor(GooeyParser::StringFactorContext *ctx)
{
    ctx->type = Predefined::stringType;
    return nullptr;
}

Object Semantics::visitNotFactor(GooeyParser::NotFactorContext *ctx)
{
    GooeyParser::FactorContext *factorCtx = ctx->factor();
    visit(factorCtx);

    if (factorCtx->type != Predefined::booleanType)
    {
        error.flag(TYPE_MUST_BE_BOOLEAN, factorCtx);
    }

    ctx->type = Predefined::booleanType;
    return nullptr;
}

Object Semantics::visitParenthesizedFactor(
                                GooeyParser::ParenthesizedFactorContext *ctx)
{
    GooeyParser::ExpressionContext *exprCtx = ctx->expression();
    visit(exprCtx);
    ctx->type = exprCtx->type;

    return nullptr;
}

Object Semantics::visitProcedureCall(GooeyParser::ProcedureCallContext *ctx)
{
	GooeyParser::FunctionNameContext *nameCtx = ctx->functionName();
	GooeyParser::ArgumentListContext *listCtx = ctx->argumentList();
	string name = toLowerCase(ctx->functionName()->getText());
	SymtabEntry *procedureId = symtabStack->lookup(name);
	bool badName = false;

	if(procedureId == nullptr)
	{
		error.flag(UNDECLARED_IDENTIFIER, nameCtx);
		badName = true;
	}
	else if(procedureId->getKind() != PROCEDURE)
	{
		error.flag(NAME_MUST_BE_PROCEDURE, nameCtx);
		badName = true;
	}

	if(badName)
	{
		for(GooeyParser::ArgumentContext *exprCtx : listCtx->argument())
		{
			visit(exprCtx);
		}
	}

	else
	{
		vector<SymtabEntry *> *parms = procedureId->getRoutineParameters();
		checkCallArguments(listCtx, parms);
	}
	nameCtx->entry = procedureId;
	return nullptr;
}

Object Semantics::visitFunctionCallFactor( GooeyParser::FunctionCallFactorContext *ctx)
{
    GooeyParser::FunctionCallContext *callCtx = ctx->functionCall();
    GooeyParser::FunctionNameContext *nameCtx = callCtx->functionName();
    GooeyParser::ArgumentListContext *listCtx = callCtx->argumentList();
    string name = toLowerCase(callCtx->functionName()->getText());
    SymtabEntry *functionId = symtabStack->lookup(name);
    bool badName = false;

    ctx->type = Predefined::integerType;

    if (functionId == nullptr)
    {
        error.flag(UNDECLARED_IDENTIFIER, nameCtx);
        badName = true;
    }
    else if (functionId->getKind() != FUNCTION)
    {
        error.flag(NAME_MUST_BE_FUNCTION, nameCtx);
        badName = true;
    }

    // Bad function name. Do a simple arguments check and then leave.
    if (badName)
    {
        for (GooeyParser::ArgumentContext *exprCtx : listCtx->argument())
        {
            visit(exprCtx);
        }
    }

    // Good function name.
    else
    {
        vector<SymtabEntry *> *parms = functionId->getRoutineParameters();
        checkCallArguments(listCtx, parms);
        ctx->type = functionId->getType();
    }

    nameCtx->entry = functionId;
    nameCtx->type  = ctx->type;

    return nullptr;
}

Object Semantics::visitPredefinedRoutineCall(GooeyParser::PredefinedRoutineCallContext *ctx)
{
	string routineName = toLowerCase(ctx->predefinedRoutine()->getText());
	visit(ctx->variable());
	Typespec *type = ctx->variable()->type;
	SymtabEntry *varId = ctx->variable()->entry;
	SymtabEntry *routineId = symtabStack->lookup(routineName);
	int argSize = ctx->argumentList() != nullptr ? ctx->argumentList()->argument().size() : 0;

	//check if fucntion and variables are defined
	if(varId == nullptr)
		error.flag(UNDECLARED_IDENTIFIER, ctx->variable());

	if(routineId != nullptr) ctx->routine = routineId;
	else
		error.flag(UNDECLARED_IDENTIFIER, ctx->predefinedRoutine());

	if(argSize < 1) error.flag(INVALID_FIELD, ctx);

	if(varId->getKind() != Kind::VARIABLE){ error.flag(INVALID_TYPE, ctx->variable()); return nullptr;}
	//some predefined routins can only be used with certain types

	if(varId->getType()->getForm() == Form::COMPONENT)
	{
		if(type->getIdentifier()->getName() == "label" || type->getIdentifier()->getName() == "button")
		{
			if(routineName == "add")
				error.flag(INVALID_TYPE, ctx->variable());
		}
	}
	else
		error.flag(INVALID_TYPE, ctx->variable());
	//check arguments
	if(routineName == "add")
	{
		if(argSize != 2)
			error.flag(INVALID_FIELD, ctx);
		else
		{
			GooeyParser::ExpressionContext *arg1Ctx = ctx->argumentList()->argument(0)->expression();
			GooeyParser::ExpressionContext *arg2Ctx = ctx->argumentList()->argument(1)->expression();
			visit(arg1Ctx);
			visit(arg2Ctx);
			if(arg1Ctx->type->getForm() != Form:: COMPONENT) error.flag(INVALID_TYPE, arg1Ctx);
			if(toLowerCase(arg1Ctx->getText()) == varId->getName()) error.flag(INVALID_FIELD, arg1Ctx);
			if(arg2Ctx->type->getIdentifier()->getName() != "str")
			{
				error.flag(INVALID_TYPE, arg2Ctx);
			}
		}
	}

	if(routineName == "create")
	{
		if(argSize != 1)
			error.flag(INVALID_FIELD,ctx);
		else
		{
			GooeyParser::ExpressionContext *arg1Ctx = ctx->argumentList()->argument(0)->expression();
			visit(arg1Ctx);
			if(arg1Ctx->type->getIdentifier()->getName() != "str")
			{
				error.flag(INVALID_TYPE, arg1Ctx);
			}
		}
	}


	return nullptr;
}
} //namespace
