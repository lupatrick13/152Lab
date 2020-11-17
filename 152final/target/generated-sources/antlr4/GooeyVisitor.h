
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;


// Generated from Gooey.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "GooeyParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by GooeyParser.
 */
class  GooeyVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by GooeyParser.
   */
    virtual antlrcpp::Any visitProgram(GooeyParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitProgramHeader(GooeyParser::ProgramHeaderContext *context) = 0;

    virtual antlrcpp::Any visitTitle(GooeyParser::TitleContext *context) = 0;

    virtual antlrcpp::Any visitBlock(GooeyParser::BlockContext *context) = 0;

    virtual antlrcpp::Any visitDeclarations(GooeyParser::DeclarationsContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclarationsList(GooeyParser::VariableDeclarationsListContext *context) = 0;

    virtual antlrcpp::Any visitVariableDeclarations(GooeyParser::VariableDeclarationsContext *context) = 0;

    virtual antlrcpp::Any visitVariableIdentifierList(GooeyParser::VariableIdentifierListContext *context) = 0;

    virtual antlrcpp::Any visitVariableIdentifier(GooeyParser::VariableIdentifierContext *context) = 0;

    virtual antlrcpp::Any visitTypes(GooeyParser::TypesContext *context) = 0;

    virtual antlrcpp::Any visitFunctiondef(GooeyParser::FunctiondefContext *context) = 0;

    virtual antlrcpp::Any visitFuncDec(GooeyParser::FuncDecContext *context) = 0;

    virtual antlrcpp::Any visitParameter(GooeyParser::ParameterContext *context) = 0;

    virtual antlrcpp::Any visitParameterDecList(GooeyParser::ParameterDecListContext *context) = 0;

    virtual antlrcpp::Any visitParameterDec(GooeyParser::ParameterDecContext *context) = 0;

    virtual antlrcpp::Any visitParameterIdList(GooeyParser::ParameterIdListContext *context) = 0;

    virtual antlrcpp::Any visitParameterId(GooeyParser::ParameterIdContext *context) = 0;

    virtual antlrcpp::Any visitReturnType(GooeyParser::ReturnTypeContext *context) = 0;

    virtual antlrcpp::Any visitVariable(GooeyParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitArrayVardec(GooeyParser::ArrayVardecContext *context) = 0;

    virtual antlrcpp::Any visitModifierDeclare(GooeyParser::ModifierDeclareContext *context) = 0;

    virtual antlrcpp::Any visitModifier(GooeyParser::ModifierContext *context) = 0;

    virtual antlrcpp::Any visitActionDef(GooeyParser::ActionDefContext *context) = 0;

    virtual antlrcpp::Any visitActDec(GooeyParser::ActDecContext *context) = 0;

    virtual antlrcpp::Any visitActionName(GooeyParser::ActionNameContext *context) = 0;

    virtual antlrcpp::Any visitSign(GooeyParser::SignContext *context) = 0;

    virtual antlrcpp::Any visitFunctionCall(GooeyParser::FunctionCallContext *context) = 0;

    virtual antlrcpp::Any visitProcedureCall(GooeyParser::ProcedureCallContext *context) = 0;

    virtual antlrcpp::Any visitFunctionName(GooeyParser::FunctionNameContext *context) = 0;

    virtual antlrcpp::Any visitArgumentList(GooeyParser::ArgumentListContext *context) = 0;

    virtual antlrcpp::Any visitArgument(GooeyParser::ArgumentContext *context) = 0;

    virtual antlrcpp::Any visitStatement(GooeyParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitPredefinedRoutineCall(GooeyParser::PredefinedRoutineCallContext *context) = 0;

    virtual antlrcpp::Any visitPredefinedRoutine(GooeyParser::PredefinedRoutineContext *context) = 0;

    virtual antlrcpp::Any visitCompoundStatement(GooeyParser::CompoundStatementContext *context) = 0;

    virtual antlrcpp::Any visitEmptyStatement(GooeyParser::EmptyStatementContext *context) = 0;

    virtual antlrcpp::Any visitStatementList(GooeyParser::StatementListContext *context) = 0;

    virtual antlrcpp::Any visitAssignmentStatement(GooeyParser::AssignmentStatementContext *context) = 0;

    virtual antlrcpp::Any visitLhs(GooeyParser::LhsContext *context) = 0;

    virtual antlrcpp::Any visitRhs(GooeyParser::RhsContext *context) = 0;

    virtual antlrcpp::Any visitIfStatement(GooeyParser::IfStatementContext *context) = 0;

    virtual antlrcpp::Any visitWhileStatement(GooeyParser::WhileStatementContext *context) = 0;

    virtual antlrcpp::Any visitForStatement(GooeyParser::ForStatementContext *context) = 0;

    virtual antlrcpp::Any visitExpression(GooeyParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitSimpleExpression(GooeyParser::SimpleExpressionContext *context) = 0;

    virtual antlrcpp::Any visitTerm(GooeyParser::TermContext *context) = 0;

    virtual antlrcpp::Any visitVariableFactor(GooeyParser::VariableFactorContext *context) = 0;

    virtual antlrcpp::Any visitNumberFactor(GooeyParser::NumberFactorContext *context) = 0;

    virtual antlrcpp::Any visitCharacterFactor(GooeyParser::CharacterFactorContext *context) = 0;

    virtual antlrcpp::Any visitStringFactor(GooeyParser::StringFactorContext *context) = 0;

    virtual antlrcpp::Any visitFunctionCallFactor(GooeyParser::FunctionCallFactorContext *context) = 0;

    virtual antlrcpp::Any visitNotFactor(GooeyParser::NotFactorContext *context) = 0;

    virtual antlrcpp::Any visitParenthesizedFactor(GooeyParser::ParenthesizedFactorContext *context) = 0;

    virtual antlrcpp::Any visitNumber(GooeyParser::NumberContext *context) = 0;

    virtual antlrcpp::Any visitUnsignedNumber(GooeyParser::UnsignedNumberContext *context) = 0;

    virtual antlrcpp::Any visitCharacterConstant(GooeyParser::CharacterConstantContext *context) = 0;

    virtual antlrcpp::Any visitStringConstant(GooeyParser::StringConstantContext *context) = 0;

    virtual antlrcpp::Any visitRelOp(GooeyParser::RelOpContext *context) = 0;

    virtual antlrcpp::Any visitAddOp(GooeyParser::AddOpContext *context) = 0;

    virtual antlrcpp::Any visitMulOp(GooeyParser::MulOpContext *context) = 0;


};

