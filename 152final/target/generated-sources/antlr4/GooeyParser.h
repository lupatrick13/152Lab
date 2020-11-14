
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;


// Generated from Gooey.g4 by ANTLR 4.8

#pragma once


#include "antlr4-runtime.h"




class  GooeyParser : public antlr4::Parser {
public:
  enum {
    T__0 = 1, T__1 = 2, T__2 = 3, T__3 = 4, T__4 = 5, T__5 = 6, T__6 = 7, 
    T__7 = 8, T__8 = 9, T__9 = 10, T__10 = 11, T__11 = 12, T__12 = 13, T__13 = 14, 
    T__14 = 15, T__15 = 16, T__16 = 17, T__17 = 18, T__18 = 19, T__19 = 20, 
    T__20 = 21, GOOEY = 22, AND = 23, OR = 24, WHILE = 25, FOR = 26, IF = 27, 
    ELSE = 28, TO = 29, BY = 30, VAR = 31, FUNC = 32, MAIN = 33, ACT = 34, 
    IDENTIFIER = 35, INTEGER = 36, REAL = 37, NEWLINE = 38, WS = 39, QUOTE = 40, 
    CHARACTER = 41, STRING = 42, COMMENT = 43
  };

  enum {
    RuleProgram = 0, RuleProgramHeader = 1, RuleTitle = 2, RuleBlock = 3, 
    RuleDeclarations = 4, RuleVariableDeclarationsList = 5, RuleVariableDeclarations = 6, 
    RuleVariableIdentifierList = 7, RuleVariableIdentifier = 8, RuleTypes = 9, 
    RuleFunctiondef = 10, RuleFuncDec = 11, RuleParameter = 12, RuleParameterDecList = 13, 
    RuleParameterDec = 14, RuleParameterIdList = 15, RuleParameterId = 16, 
    RuleReturnType = 17, RuleVariable = 18, RuleModifierDeclare = 19, RuleModifier = 20, 
    RuleActionDef = 21, RuleActDec = 22, RuleActionName = 23, RuleSign = 24, 
    RuleFunctionCall = 25, RuleProcedureCall = 26, RuleFunctionName = 27, 
    RuleArgumentList = 28, RuleArgument = 29, RuleStatement = 30, RulePredefinedRoutineCall = 31, 
    RulePredefinedRoutine = 32, RuleCompoundStatement = 33, RuleEmptyStatement = 34, 
    RuleStatementList = 35, RuleAssignmentStatement = 36, RuleLhs = 37, 
    RuleRhs = 38, RuleIfStatement = 39, RuleWhileStatement = 40, RuleForStatement = 41, 
    RuleExpression = 42, RuleSimpleExpression = 43, RuleTerm = 44, RuleFactor = 45, 
    RuleNumber = 46, RuleUnsignedNumber = 47, RuleCharacterConstant = 48, 
    RuleStringConstant = 49, RuleRelOp = 50, RuleAddOp = 51, RuleMulOp = 52
  };

  GooeyParser(antlr4::TokenStream *input);
  ~GooeyParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class ProgramHeaderContext;
  class TitleContext;
  class BlockContext;
  class DeclarationsContext;
  class VariableDeclarationsListContext;
  class VariableDeclarationsContext;
  class VariableIdentifierListContext;
  class VariableIdentifierContext;
  class TypesContext;
  class FunctiondefContext;
  class FuncDecContext;
  class ParameterContext;
  class ParameterDecListContext;
  class ParameterDecContext;
  class ParameterIdListContext;
  class ParameterIdContext;
  class ReturnTypeContext;
  class VariableContext;
  class ModifierDeclareContext;
  class ModifierContext;
  class ActionDefContext;
  class ActDecContext;
  class ActionNameContext;
  class SignContext;
  class FunctionCallContext;
  class ProcedureCallContext;
  class FunctionNameContext;
  class ArgumentListContext;
  class ArgumentContext;
  class StatementContext;
  class PredefinedRoutineCallContext;
  class PredefinedRoutineContext;
  class CompoundStatementContext;
  class EmptyStatementContext;
  class StatementListContext;
  class AssignmentStatementContext;
  class LhsContext;
  class RhsContext;
  class IfStatementContext;
  class WhileStatementContext;
  class ForStatementContext;
  class ExpressionContext;
  class SimpleExpressionContext;
  class TermContext;
  class FactorContext;
  class NumberContext;
  class UnsignedNumberContext;
  class CharacterConstantContext;
  class StringConstantContext;
  class RelOpContext;
  class AddOpContext;
  class MulOpContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ProgramHeaderContext *programHeader();
    BlockContext *block();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  ProgramHeaderContext : public antlr4::ParserRuleContext {
  public:
    ProgramHeaderContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *GOOEY();
    TitleContext *title();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramHeaderContext* programHeader();

  class  TitleContext : public antlr4::ParserRuleContext {
  public:
    SymtabEntry * entry = nullptr;
    TitleContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TitleContext* title();

  class  BlockContext : public antlr4::ParserRuleContext {
  public:
    BlockContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationsContext *declarations();
    antlr4::tree::TerminalNode *MAIN();
    CompoundStatementContext *compoundStatement();
    FunctiondefContext *functiondef();
    ActionDefContext *actionDef();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  BlockContext* block();

  class  DeclarationsContext : public antlr4::ParserRuleContext {
  public:
    SymtabEntry * entry = nullptr;
    DeclarationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VAR();
    VariableDeclarationsListContext *variableDeclarationsList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationsContext* declarations();

  class  VariableDeclarationsListContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclarationsListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VariableDeclarationsContext *> variableDeclarations();
    VariableDeclarationsContext* variableDeclarations(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableDeclarationsListContext* variableDeclarationsList();

  class  VariableDeclarationsContext : public antlr4::ParserRuleContext {
  public:
    VariableDeclarationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypesContext *types();
    VariableIdentifierListContext *variableIdentifierList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableDeclarationsContext* variableDeclarations();

  class  VariableIdentifierListContext : public antlr4::ParserRuleContext {
  public:
    VariableIdentifierListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<VariableIdentifierContext *> variableIdentifier();
    VariableIdentifierContext* variableIdentifier(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableIdentifierListContext* variableIdentifierList();

  class  VariableIdentifierContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry;
    VariableIdentifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    ModifierDeclareContext *modifierDeclare();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableIdentifierContext* variableIdentifier();

  class  TypesContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    TypesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypesContext* types();

  class  FunctiondefContext : public antlr4::ParserRuleContext {
  public:
    FunctiondefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUNC();
    std::vector<FuncDecContext *> funcDec();
    FuncDecContext* funcDec(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctiondefContext* functiondef();

  class  FuncDecContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    FuncDecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ReturnTypeContext *returnType();
    FunctionNameContext *functionName();
    ParameterContext *parameter();
    CompoundStatementContext *compoundStatement();
    DeclarationsContext *declarations();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FuncDecContext* funcDec();

  class  ParameterContext : public antlr4::ParserRuleContext {
  public:
    ParameterContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ParameterDecListContext *parameterDecList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterContext* parameter();

  class  ParameterDecListContext : public antlr4::ParserRuleContext {
  public:
    ParameterDecListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParameterDecContext *> parameterDec();
    ParameterDecContext* parameterDec(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterDecListContext* parameterDecList();

  class  ParameterDecContext : public antlr4::ParserRuleContext {
  public:
    ParameterDecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    TypesContext *types();
    ParameterIdListContext *parameterIdList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterDecContext* parameterDec();

  class  ParameterIdListContext : public antlr4::ParserRuleContext {
  public:
    ParameterIdListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ParameterIdContext *> parameterId();
    ParameterIdContext* parameterId(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterIdListContext* parameterIdList();

  class  ParameterIdContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    ParameterIdContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParameterIdContext* parameterId();

  class  ReturnTypeContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    ReturnTypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ReturnTypeContext* returnType();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    ModifierContext *modifier();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableContext* variable();

  class  ModifierDeclareContext : public antlr4::ParserRuleContext {
  public:
    ModifierDeclareContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *INTEGER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModifierDeclareContext* modifierDeclare();

  class  ModifierContext : public antlr4::ParserRuleContext {
  public:
    ModifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ModifierContext* modifier();

  class  ActionDefContext : public antlr4::ParserRuleContext {
  public:
    ActionDefContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ACT();
    std::vector<ActDecContext *> actDec();
    ActDecContext* actDec(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ActionDefContext* actionDef();

  class  ActDecContext : public antlr4::ParserRuleContext {
  public:
    SymtabEntry * entry = nullptr;
    ActDecContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ActionNameContext *actionName();
    CompoundStatementContext *compoundStatement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ActDecContext* actDec();

  class  ActionNameContext : public antlr4::ParserRuleContext {
  public:
    SymtabEntry * entry = nullptr;
    ActionNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ActionNameContext* actionName();

  class  SignContext : public antlr4::ParserRuleContext {
  public:
    SignContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SignContext* sign();

  class  FunctionCallContext : public antlr4::ParserRuleContext {
  public:
    FunctionCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionNameContext *functionName();
    ArgumentListContext *argumentList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionCallContext* functionCall();

  class  ProcedureCallContext : public antlr4::ParserRuleContext {
  public:
    ProcedureCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    FunctionNameContext *functionName();
    ArgumentListContext *argumentList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProcedureCallContext* procedureCall();

  class  FunctionNameContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry = nullptr;
    FunctionNameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionNameContext* functionName();

  class  ArgumentListContext : public antlr4::ParserRuleContext {
  public:
    ArgumentListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ArgumentContext *> argument();
    ArgumentContext* argument(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentListContext* argumentList();

  class  ArgumentContext : public antlr4::ParserRuleContext {
  public:
    ArgumentContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();
    ActionNameContext *actionName();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgumentContext* argument();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    CompoundStatementContext *compoundStatement();
    AssignmentStatementContext *assignmentStatement();
    IfStatementContext *ifStatement();
    WhileStatementContext *whileStatement();
    ForStatementContext *forStatement();
    EmptyStatementContext *emptyStatement();
    ProcedureCallContext *procedureCall();
    PredefinedRoutineCallContext *predefinedRoutineCall();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  PredefinedRoutineCallContext : public antlr4::ParserRuleContext {
  public:
    SymtabEntry * routine = nullptr;
    PredefinedRoutineCallContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();
    PredefinedRoutineContext *predefinedRoutine();
    ArgumentListContext *argumentList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PredefinedRoutineCallContext* predefinedRoutineCall();

  class  PredefinedRoutineContext : public antlr4::ParserRuleContext {
  public:
    PredefinedRoutineContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  PredefinedRoutineContext* predefinedRoutine();

  class  CompoundStatementContext : public antlr4::ParserRuleContext {
  public:
    CompoundStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    StatementListContext *statementList();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CompoundStatementContext* compoundStatement();

  class  EmptyStatementContext : public antlr4::ParserRuleContext {
  public:
    EmptyStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  EmptyStatementContext* emptyStatement();

  class  StatementListContext : public antlr4::ParserRuleContext {
  public:
    StatementListContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementListContext* statementList();

  class  AssignmentStatementContext : public antlr4::ParserRuleContext {
  public:
    AssignmentStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    LhsContext *lhs();
    RhsContext *rhs();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AssignmentStatementContext* assignmentStatement();

  class  LhsContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    LhsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  LhsContext* lhs();

  class  RhsContext : public antlr4::ParserRuleContext {
  public:
    RhsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RhsContext* rhs();

  class  IfStatementContext : public antlr4::ParserRuleContext {
  public:
    IfStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    ExpressionContext *expression();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *ELSE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  IfStatementContext* ifStatement();

  class  WhileStatementContext : public antlr4::ParserRuleContext {
  public:
    WhileStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    ExpressionContext *expression();
    StatementContext *statement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  WhileStatementContext* whileStatement();

  class  ForStatementContext : public antlr4::ParserRuleContext {
  public:
    ForStatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    VariableContext *variable();
    std::vector<ExpressionContext *> expression();
    ExpressionContext* expression(size_t i);
    antlr4::tree::TerminalNode *TO();
    StatementContext *statement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ForStatementContext* forStatement();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SymtabEntry * entry;
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<SimpleExpressionContext *> simpleExpression();
    SimpleExpressionContext* simpleExpression(size_t i);
    RelOpContext *relOp();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  SimpleExpressionContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    SimpleExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TermContext *> term();
    TermContext* term(size_t i);
    SignContext *sign();
    std::vector<AddOpContext *> addOp();
    AddOpContext* addOp(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpleExpressionContext* simpleExpression();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FactorContext *> factor();
    FactorContext* factor(size_t i);
    std::vector<MulOpContext *> mulOp();
    MulOpContext* mulOp(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TermContext* term();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    Typespec * type = nullptr;
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    FactorContext() = default;
    void copyFrom(FactorContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  NumberFactorContext : public FactorContext {
  public:
    NumberFactorContext(FactorContext *ctx);

    NumberContext *number();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  StringFactorContext : public FactorContext {
  public:
    StringFactorContext(FactorContext *ctx);

    StringConstantContext *stringConstant();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  CharacterFactorContext : public FactorContext {
  public:
    CharacterFactorContext(FactorContext *ctx);

    CharacterConstantContext *characterConstant();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  VariableFactorContext : public FactorContext {
  public:
    VariableFactorContext(FactorContext *ctx);

    VariableContext *variable();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  FunctionCallFactorContext : public FactorContext {
  public:
    FunctionCallFactorContext(FactorContext *ctx);

    FunctionCallContext *functionCall();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  NotFactorContext : public FactorContext {
  public:
    NotFactorContext(FactorContext *ctx);

    FactorContext *factor();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ParenthesizedFactorContext : public FactorContext {
  public:
    ParenthesizedFactorContext(FactorContext *ctx);

    ExpressionContext *expression();

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  FactorContext* factor();

  class  NumberContext : public antlr4::ParserRuleContext {
  public:
    NumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    UnsignedNumberContext *unsignedNumber();
    SignContext *sign();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NumberContext* number();

  class  UnsignedNumberContext : public antlr4::ParserRuleContext {
  public:
    UnsignedNumberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REAL();
    antlr4::tree::TerminalNode *INTEGER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  UnsignedNumberContext* unsignedNumber();

  class  CharacterConstantContext : public antlr4::ParserRuleContext {
  public:
    CharacterConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHARACTER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  CharacterConstantContext* characterConstant();

  class  StringConstantContext : public antlr4::ParserRuleContext {
  public:
    StringConstantContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StringConstantContext* stringConstant();

  class  RelOpContext : public antlr4::ParserRuleContext {
  public:
    RelOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RelOpContext* relOp();

  class  AddOpContext : public antlr4::ParserRuleContext {
  public:
    AddOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *OR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  AddOpContext* addOp();

  class  MulOpContext : public antlr4::ParserRuleContext {
  public:
    MulOpContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *AND();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  MulOpContext* mulOp();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

