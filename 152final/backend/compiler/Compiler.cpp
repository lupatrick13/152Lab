#include "intermediate/symtab/Predefined.h"
#include "Compiler.h"

namespace backend { namespace compiler {

Object Compiler::visitProgram(GooeyParser::ProgramContext *ctx)
{
    createNewGenerators(code);
    programCode->emitProgram(ctx);

    return nullptr;
}

Object Compiler::visitFuncDec(
                                GooeyParser::FuncDecContext *ctx)
{
    createNewGenerators(programCode);
    programCode->emitRoutine(ctx);
    return nullptr;
}

Object Compiler::visitActDec( GooeyParser::ActDecContext *ctx)
{
	programCode->emitAction(ctx);
	return nullptr;
}

Object Compiler::visitStatement(GooeyParser::StatementContext *ctx)
{
    if (   (ctx->compoundStatement() == nullptr)
        && (ctx->emptyStatement() == nullptr))
    {
        statementCode->emitComment(ctx);
    }

    return visitChildren(ctx);
}

Object Compiler::visitAssignmentStatement(
                                GooeyParser::AssignmentStatementContext *ctx)
{
    statementCode->emitAssignment(ctx);
    return nullptr;
}

Object Compiler::visitIfStatement(GooeyParser::IfStatementContext *ctx)
{
    statementCode->emitIf(ctx);
    return nullptr;
}


Object Compiler::visitWhileStatement(GooeyParser::WhileStatementContext *ctx)
{
    statementCode->emitWhile(ctx);
    return nullptr;
}

Object Compiler::visitForStatement(GooeyParser::ForStatementContext *ctx)
{
    statementCode->emitFor(ctx);
    return nullptr;
}


Object Compiler::visitExpression(GooeyParser::ExpressionContext *ctx)
{
    expressionCode->emitExpression(ctx);
    return nullptr;
}

Object Compiler::visitVariableFactor(GooeyParser::VariableFactorContext *ctx)
{
    expressionCode->emitLoadValue(ctx->variable());
    return nullptr;
}

Object Compiler::visitVariable(GooeyParser::VariableContext *ctx)
{
    expressionCode->emitLoadVariable(ctx);
    return nullptr;
}

Object Compiler::visitNumberFactor(GooeyParser::NumberFactorContext *ctx)
{
    if (ctx->type == Predefined::integerType)
    {
        expressionCode->emitLoadIntegerConstant(ctx->number());
    }
    else
    {
        expressionCode->emitLoadRealConstant(ctx->number());
    }

    return nullptr;
}

Object Compiler::visitCharacterFactor(GooeyParser::CharacterFactorContext *ctx)
{
    char ch = ctx->getText()[1];
    expressionCode->emitLoadConstant(ch);

    return nullptr;
}

Object Compiler::visitStringFactor(GooeyParser::StringFactorContext *ctx)
{
    string jasminString = convertString(ctx->getText(), true);
    expressionCode->emitLoadConstant(jasminString);

    return nullptr;
}

Object Compiler::visitFunctionCallFactor(
                                GooeyParser::FunctionCallFactorContext *ctx)
{
    statementCode->emitFunctionCall(ctx->functionCall());
    return nullptr;
}

Object Compiler::visitProcedureCall(
                                GooeyParser::ProcedureCallContext *ctx)
{
    statementCode->emitProcedureCall(ctx);
    return nullptr;
}

Object Compiler::visitNotFactor(GooeyParser::NotFactorContext *ctx)
{
    expressionCode->emitNotFactor(ctx);
    return nullptr;
}

Object Compiler::visitParenthesizedFactor(
                                GooeyParser::ParenthesizedFactorContext *ctx)
{
    return visit(ctx->expression());
}

Object Compiler::visitPredefinedRoutineCall(GooeyParser::PredefinedRoutineCallContext *ctx)
{
	statementCode->emitPredefined(ctx);
	return nullptr;
}



}}  // namespace backend::compiler
