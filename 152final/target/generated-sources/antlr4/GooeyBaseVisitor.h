
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;


// Generated from Gooey.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"
#include "GooeyVisitor.h"


/**
 * This class provides an empty implementation of GooeyVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  GooeyBaseVisitor : public GooeyVisitor {
public:

  virtual antlrcpp::Any visitProgram(GooeyParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgramHeader(GooeyParser::ProgramHeaderContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTitle(GooeyParser::TitleContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBlock(GooeyParser::BlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarations(GooeyParser::DeclarationsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDeclarationsList(GooeyParser::VariableDeclarationsListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableDeclarations(GooeyParser::VariableDeclarationsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableIdentifierList(GooeyParser::VariableIdentifierListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableIdentifier(GooeyParser::VariableIdentifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypes(GooeyParser::TypesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctiondef(GooeyParser::FunctiondefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncDec(GooeyParser::FuncDecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameter(GooeyParser::ParameterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterDecList(GooeyParser::ParameterDecListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterDec(GooeyParser::ParameterDecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterIdList(GooeyParser::ParameterIdListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameterId(GooeyParser::ParameterIdContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnType(GooeyParser::ReturnTypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(GooeyParser::VariableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModifierDeclare(GooeyParser::ModifierDeclareContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModifier(GooeyParser::ModifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitActionDef(GooeyParser::ActionDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitActDec(GooeyParser::ActDecContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitActionName(GooeyParser::ActionNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSign(GooeyParser::SignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionCall(GooeyParser::FunctionCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProcedureCall(GooeyParser::ProcedureCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionName(GooeyParser::FunctionNameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgumentList(GooeyParser::ArgumentListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArgument(GooeyParser::ArgumentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(GooeyParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPredefinedRoutineCall(GooeyParser::PredefinedRoutineCallContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPredefinedRoutine(GooeyParser::PredefinedRoutineContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompoundStatement(GooeyParser::CompoundStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEmptyStatement(GooeyParser::EmptyStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatementList(GooeyParser::StatementListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssignmentStatement(GooeyParser::AssignmentStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLhs(GooeyParser::LhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRhs(GooeyParser::RhsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIfStatement(GooeyParser::IfStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStatement(GooeyParser::WhileStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStatement(GooeyParser::ForStatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(GooeyParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpleExpression(GooeyParser::SimpleExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTerm(GooeyParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariableFactor(GooeyParser::VariableFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumberFactor(GooeyParser::NumberFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCharacterFactor(GooeyParser::CharacterFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringFactor(GooeyParser::StringFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctionCallFactor(GooeyParser::FunctionCallFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNotFactor(GooeyParser::NotFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParenthesizedFactor(GooeyParser::ParenthesizedFactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNumber(GooeyParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnsignedNumber(GooeyParser::UnsignedNumberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCharacterConstant(GooeyParser::CharacterConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringConstant(GooeyParser::StringConstantContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRelOp(GooeyParser::RelOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddOp(GooeyParser::AddOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMulOp(GooeyParser::MulOpContext *ctx) override {
    return visitChildren(ctx);
  }


};

