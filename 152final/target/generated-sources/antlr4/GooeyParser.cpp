
    #include <map>
    #include "intermediate/symtab/Symtab.h"
    #include "intermediate/type/Typespec.h"
    using namespace intermediate::symtab;
    using namespace intermediate::type;


// Generated from Gooey.g4 by ANTLR 4.8


#include "GooeyVisitor.h"

#include "GooeyParser.h"


using namespace antlrcpp;
using namespace antlr4;

GooeyParser::GooeyParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

GooeyParser::~GooeyParser() {
  delete _interpreter;
}

std::string GooeyParser::getGrammarFileName() const {
  return "Gooey.g4";
}

const std::vector<std::string>& GooeyParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& GooeyParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

GooeyParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GooeyParser::ProgramHeaderContext* GooeyParser::ProgramContext::programHeader() {
  return getRuleContext<GooeyParser::ProgramHeaderContext>(0);
}

GooeyParser::BlockContext* GooeyParser::ProgramContext::block() {
  return getRuleContext<GooeyParser::BlockContext>(0);
}

std::vector<tree::TerminalNode *> GooeyParser::ProgramContext::INTEGER() {
  return getTokens(GooeyParser::INTEGER);
}

tree::TerminalNode* GooeyParser::ProgramContext::INTEGER(size_t i) {
  return getToken(GooeyParser::INTEGER, i);
}


size_t GooeyParser::ProgramContext::getRuleIndex() const {
  return GooeyParser::RuleProgram;
}


antlrcpp::Any GooeyParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::ProgramContext* GooeyParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, GooeyParser::RuleProgram);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(108);
    programHeader();
    setState(114);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GooeyParser::T__0) {
      setState(109);
      match(GooeyParser::T__0);
      setState(110);
      match(GooeyParser::INTEGER);
      setState(111);
      match(GooeyParser::T__1);
      setState(112);
      match(GooeyParser::INTEGER);
      setState(113);
      match(GooeyParser::T__2);
    }
    setState(116);
    match(GooeyParser::T__3);
    setState(117);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProgramHeaderContext ------------------------------------------------------------------

GooeyParser::ProgramHeaderContext::ProgramHeaderContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::ProgramHeaderContext::GOOEY() {
  return getToken(GooeyParser::GOOEY, 0);
}

GooeyParser::TitleContext* GooeyParser::ProgramHeaderContext::title() {
  return getRuleContext<GooeyParser::TitleContext>(0);
}


size_t GooeyParser::ProgramHeaderContext::getRuleIndex() const {
  return GooeyParser::RuleProgramHeader;
}


antlrcpp::Any GooeyParser::ProgramHeaderContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitProgramHeader(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::ProgramHeaderContext* GooeyParser::programHeader() {
  ProgramHeaderContext *_localctx = _tracker.createInstance<ProgramHeaderContext>(_ctx, getState());
  enterRule(_localctx, 2, GooeyParser::RuleProgramHeader);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(119);
    match(GooeyParser::GOOEY);
    setState(120);
    title();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TitleContext ------------------------------------------------------------------

GooeyParser::TitleContext::TitleContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::TitleContext::IDENTIFIER() {
  return getToken(GooeyParser::IDENTIFIER, 0);
}


size_t GooeyParser::TitleContext::getRuleIndex() const {
  return GooeyParser::RuleTitle;
}


antlrcpp::Any GooeyParser::TitleContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitTitle(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::TitleContext* GooeyParser::title() {
  TitleContext *_localctx = _tracker.createInstance<TitleContext>(_ctx, getState());
  enterRule(_localctx, 4, GooeyParser::RuleTitle);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    match(GooeyParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

GooeyParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GooeyParser::DeclarationsContext* GooeyParser::BlockContext::declarations() {
  return getRuleContext<GooeyParser::DeclarationsContext>(0);
}

tree::TerminalNode* GooeyParser::BlockContext::MAIN() {
  return getToken(GooeyParser::MAIN, 0);
}

GooeyParser::CompoundStatementContext* GooeyParser::BlockContext::compoundStatement() {
  return getRuleContext<GooeyParser::CompoundStatementContext>(0);
}

GooeyParser::FunctiondefContext* GooeyParser::BlockContext::functiondef() {
  return getRuleContext<GooeyParser::FunctiondefContext>(0);
}

GooeyParser::ActionDefContext* GooeyParser::BlockContext::actionDef() {
  return getRuleContext<GooeyParser::ActionDefContext>(0);
}


size_t GooeyParser::BlockContext::getRuleIndex() const {
  return GooeyParser::RuleBlock;
}


antlrcpp::Any GooeyParser::BlockContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitBlock(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::BlockContext* GooeyParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 6, GooeyParser::RuleBlock);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(124);
    declarations();
    setState(126);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GooeyParser::FUNC) {
      setState(125);
      functiondef();
    }
    setState(129);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GooeyParser::ACT) {
      setState(128);
      actionDef();
    }
    setState(131);
    match(GooeyParser::MAIN);
    setState(132);
    match(GooeyParser::T__4);
    setState(133);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

GooeyParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::DeclarationsContext::VAR() {
  return getToken(GooeyParser::VAR, 0);
}

GooeyParser::VariableDeclarationsListContext* GooeyParser::DeclarationsContext::variableDeclarationsList() {
  return getRuleContext<GooeyParser::VariableDeclarationsListContext>(0);
}


size_t GooeyParser::DeclarationsContext::getRuleIndex() const {
  return GooeyParser::RuleDeclarations;
}


antlrcpp::Any GooeyParser::DeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitDeclarations(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::DeclarationsContext* GooeyParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 8, GooeyParser::RuleDeclarations);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(135);
    match(GooeyParser::VAR);
    setState(136);
    match(GooeyParser::T__4);
    setState(137);
    variableDeclarationsList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationsListContext ------------------------------------------------------------------

GooeyParser::VariableDeclarationsListContext::VariableDeclarationsListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GooeyParser::VariableDeclarationsContext *> GooeyParser::VariableDeclarationsListContext::variableDeclarations() {
  return getRuleContexts<GooeyParser::VariableDeclarationsContext>();
}

GooeyParser::VariableDeclarationsContext* GooeyParser::VariableDeclarationsListContext::variableDeclarations(size_t i) {
  return getRuleContext<GooeyParser::VariableDeclarationsContext>(i);
}


size_t GooeyParser::VariableDeclarationsListContext::getRuleIndex() const {
  return GooeyParser::RuleVariableDeclarationsList;
}


antlrcpp::Any GooeyParser::VariableDeclarationsListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarationsList(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::VariableDeclarationsListContext* GooeyParser::variableDeclarationsList() {
  VariableDeclarationsListContext *_localctx = _tracker.createInstance<VariableDeclarationsListContext>(_ctx, getState());
  enterRule(_localctx, 10, GooeyParser::RuleVariableDeclarationsList);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(139);
    variableDeclarations();
    setState(144);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(140);
        match(GooeyParser::T__3);
        setState(141);
        variableDeclarations(); 
      }
      setState(146);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx);
    }
    setState(147);
    match(GooeyParser::T__3);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableDeclarationsContext ------------------------------------------------------------------

GooeyParser::VariableDeclarationsContext::VariableDeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GooeyParser::TypesContext* GooeyParser::VariableDeclarationsContext::types() {
  return getRuleContext<GooeyParser::TypesContext>(0);
}

GooeyParser::VariableIdentifierListContext* GooeyParser::VariableDeclarationsContext::variableIdentifierList() {
  return getRuleContext<GooeyParser::VariableIdentifierListContext>(0);
}


size_t GooeyParser::VariableDeclarationsContext::getRuleIndex() const {
  return GooeyParser::RuleVariableDeclarations;
}


antlrcpp::Any GooeyParser::VariableDeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitVariableDeclarations(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::VariableDeclarationsContext* GooeyParser::variableDeclarations() {
  VariableDeclarationsContext *_localctx = _tracker.createInstance<VariableDeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 12, GooeyParser::RuleVariableDeclarations);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(149);
    types();
    setState(150);
    variableIdentifierList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableIdentifierListContext ------------------------------------------------------------------

GooeyParser::VariableIdentifierListContext::VariableIdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GooeyParser::VariableIdentifierContext *> GooeyParser::VariableIdentifierListContext::variableIdentifier() {
  return getRuleContexts<GooeyParser::VariableIdentifierContext>();
}

GooeyParser::VariableIdentifierContext* GooeyParser::VariableIdentifierListContext::variableIdentifier(size_t i) {
  return getRuleContext<GooeyParser::VariableIdentifierContext>(i);
}


size_t GooeyParser::VariableIdentifierListContext::getRuleIndex() const {
  return GooeyParser::RuleVariableIdentifierList;
}


antlrcpp::Any GooeyParser::VariableIdentifierListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitVariableIdentifierList(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::VariableIdentifierListContext* GooeyParser::variableIdentifierList() {
  VariableIdentifierListContext *_localctx = _tracker.createInstance<VariableIdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 14, GooeyParser::RuleVariableIdentifierList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(152);
    variableIdentifier();
    setState(157);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GooeyParser::T__1) {
      setState(153);
      match(GooeyParser::T__1);
      setState(154);
      variableIdentifier();
      setState(159);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableIdentifierContext ------------------------------------------------------------------

GooeyParser::VariableIdentifierContext::VariableIdentifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::VariableIdentifierContext::IDENTIFIER() {
  return getToken(GooeyParser::IDENTIFIER, 0);
}

GooeyParser::ArrayVardecContext* GooeyParser::VariableIdentifierContext::arrayVardec() {
  return getRuleContext<GooeyParser::ArrayVardecContext>(0);
}


size_t GooeyParser::VariableIdentifierContext::getRuleIndex() const {
  return GooeyParser::RuleVariableIdentifier;
}


antlrcpp::Any GooeyParser::VariableIdentifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitVariableIdentifier(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::VariableIdentifierContext* GooeyParser::variableIdentifier() {
  VariableIdentifierContext *_localctx = _tracker.createInstance<VariableIdentifierContext>(_ctx, getState());
  enterRule(_localctx, 16, GooeyParser::RuleVariableIdentifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(162);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(160);
      match(GooeyParser::IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(161);
      arrayVardec();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypesContext ------------------------------------------------------------------

GooeyParser::TypesContext::TypesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::TypesContext::IDENTIFIER() {
  return getToken(GooeyParser::IDENTIFIER, 0);
}


size_t GooeyParser::TypesContext::getRuleIndex() const {
  return GooeyParser::RuleTypes;
}


antlrcpp::Any GooeyParser::TypesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitTypes(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::TypesContext* GooeyParser::types() {
  TypesContext *_localctx = _tracker.createInstance<TypesContext>(_ctx, getState());
  enterRule(_localctx, 18, GooeyParser::RuleTypes);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(164);
    match(GooeyParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctiondefContext ------------------------------------------------------------------

GooeyParser::FunctiondefContext::FunctiondefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::FunctiondefContext::FUNC() {
  return getToken(GooeyParser::FUNC, 0);
}

std::vector<GooeyParser::FuncDecContext *> GooeyParser::FunctiondefContext::funcDec() {
  return getRuleContexts<GooeyParser::FuncDecContext>();
}

GooeyParser::FuncDecContext* GooeyParser::FunctiondefContext::funcDec(size_t i) {
  return getRuleContext<GooeyParser::FuncDecContext>(i);
}


size_t GooeyParser::FunctiondefContext::getRuleIndex() const {
  return GooeyParser::RuleFunctiondef;
}


antlrcpp::Any GooeyParser::FunctiondefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitFunctiondef(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::FunctiondefContext* GooeyParser::functiondef() {
  FunctiondefContext *_localctx = _tracker.createInstance<FunctiondefContext>(_ctx, getState());
  enterRule(_localctx, 20, GooeyParser::RuleFunctiondef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(166);
    match(GooeyParser::FUNC);
    setState(167);
    match(GooeyParser::T__4);
    setState(171);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GooeyParser::IDENTIFIER) {
      setState(168);
      funcDec();
      setState(173);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FuncDecContext ------------------------------------------------------------------

GooeyParser::FuncDecContext::FuncDecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GooeyParser::ReturnTypeContext* GooeyParser::FuncDecContext::returnType() {
  return getRuleContext<GooeyParser::ReturnTypeContext>(0);
}

GooeyParser::FunctionNameContext* GooeyParser::FuncDecContext::functionName() {
  return getRuleContext<GooeyParser::FunctionNameContext>(0);
}

GooeyParser::ParameterContext* GooeyParser::FuncDecContext::parameter() {
  return getRuleContext<GooeyParser::ParameterContext>(0);
}

GooeyParser::CompoundStatementContext* GooeyParser::FuncDecContext::compoundStatement() {
  return getRuleContext<GooeyParser::CompoundStatementContext>(0);
}

GooeyParser::DeclarationsContext* GooeyParser::FuncDecContext::declarations() {
  return getRuleContext<GooeyParser::DeclarationsContext>(0);
}


size_t GooeyParser::FuncDecContext::getRuleIndex() const {
  return GooeyParser::RuleFuncDec;
}


antlrcpp::Any GooeyParser::FuncDecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitFuncDec(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::FuncDecContext* GooeyParser::funcDec() {
  FuncDecContext *_localctx = _tracker.createInstance<FuncDecContext>(_ctx, getState());
  enterRule(_localctx, 22, GooeyParser::RuleFuncDec);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(174);
    returnType();
    setState(175);
    functionName();
    setState(176);
    parameter();
    setState(178);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GooeyParser::VAR) {
      setState(177);
      declarations();
    }
    setState(180);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterContext ------------------------------------------------------------------

GooeyParser::ParameterContext::ParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GooeyParser::ParameterDecListContext* GooeyParser::ParameterContext::parameterDecList() {
  return getRuleContext<GooeyParser::ParameterDecListContext>(0);
}


size_t GooeyParser::ParameterContext::getRuleIndex() const {
  return GooeyParser::RuleParameter;
}


antlrcpp::Any GooeyParser::ParameterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitParameter(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::ParameterContext* GooeyParser::parameter() {
  ParameterContext *_localctx = _tracker.createInstance<ParameterContext>(_ctx, getState());
  enterRule(_localctx, 24, GooeyParser::RuleParameter);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(182);
    match(GooeyParser::T__0);
    setState(184);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GooeyParser::IDENTIFIER) {
      setState(183);
      parameterDecList();
    }
    setState(186);
    match(GooeyParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterDecListContext ------------------------------------------------------------------

GooeyParser::ParameterDecListContext::ParameterDecListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GooeyParser::ParameterDecContext *> GooeyParser::ParameterDecListContext::parameterDec() {
  return getRuleContexts<GooeyParser::ParameterDecContext>();
}

GooeyParser::ParameterDecContext* GooeyParser::ParameterDecListContext::parameterDec(size_t i) {
  return getRuleContext<GooeyParser::ParameterDecContext>(i);
}


size_t GooeyParser::ParameterDecListContext::getRuleIndex() const {
  return GooeyParser::RuleParameterDecList;
}


antlrcpp::Any GooeyParser::ParameterDecListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitParameterDecList(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::ParameterDecListContext* GooeyParser::parameterDecList() {
  ParameterDecListContext *_localctx = _tracker.createInstance<ParameterDecListContext>(_ctx, getState());
  enterRule(_localctx, 26, GooeyParser::RuleParameterDecList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(188);
    parameterDec();
    setState(193);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GooeyParser::T__3) {
      setState(189);
      match(GooeyParser::T__3);
      setState(190);
      parameterDec();
      setState(195);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterDecContext ------------------------------------------------------------------

GooeyParser::ParameterDecContext::ParameterDecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GooeyParser::TypesContext* GooeyParser::ParameterDecContext::types() {
  return getRuleContext<GooeyParser::TypesContext>(0);
}

GooeyParser::ParameterIdListContext* GooeyParser::ParameterDecContext::parameterIdList() {
  return getRuleContext<GooeyParser::ParameterIdListContext>(0);
}


size_t GooeyParser::ParameterDecContext::getRuleIndex() const {
  return GooeyParser::RuleParameterDec;
}


antlrcpp::Any GooeyParser::ParameterDecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitParameterDec(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::ParameterDecContext* GooeyParser::parameterDec() {
  ParameterDecContext *_localctx = _tracker.createInstance<ParameterDecContext>(_ctx, getState());
  enterRule(_localctx, 28, GooeyParser::RuleParameterDec);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(196);
    types();
    setState(197);
    parameterIdList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterIdListContext ------------------------------------------------------------------

GooeyParser::ParameterIdListContext::ParameterIdListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GooeyParser::ParameterIdContext *> GooeyParser::ParameterIdListContext::parameterId() {
  return getRuleContexts<GooeyParser::ParameterIdContext>();
}

GooeyParser::ParameterIdContext* GooeyParser::ParameterIdListContext::parameterId(size_t i) {
  return getRuleContext<GooeyParser::ParameterIdContext>(i);
}


size_t GooeyParser::ParameterIdListContext::getRuleIndex() const {
  return GooeyParser::RuleParameterIdList;
}


antlrcpp::Any GooeyParser::ParameterIdListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitParameterIdList(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::ParameterIdListContext* GooeyParser::parameterIdList() {
  ParameterIdListContext *_localctx = _tracker.createInstance<ParameterIdListContext>(_ctx, getState());
  enterRule(_localctx, 30, GooeyParser::RuleParameterIdList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(199);
    parameterId();
    setState(204);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GooeyParser::T__1) {
      setState(200);
      match(GooeyParser::T__1);
      setState(201);
      parameterId();
      setState(206);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterIdContext ------------------------------------------------------------------

GooeyParser::ParameterIdContext::ParameterIdContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::ParameterIdContext::IDENTIFIER() {
  return getToken(GooeyParser::IDENTIFIER, 0);
}


size_t GooeyParser::ParameterIdContext::getRuleIndex() const {
  return GooeyParser::RuleParameterId;
}


antlrcpp::Any GooeyParser::ParameterIdContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitParameterId(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::ParameterIdContext* GooeyParser::parameterId() {
  ParameterIdContext *_localctx = _tracker.createInstance<ParameterIdContext>(_ctx, getState());
  enterRule(_localctx, 32, GooeyParser::RuleParameterId);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(207);
    match(GooeyParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnTypeContext ------------------------------------------------------------------

GooeyParser::ReturnTypeContext::ReturnTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::ReturnTypeContext::IDENTIFIER() {
  return getToken(GooeyParser::IDENTIFIER, 0);
}


size_t GooeyParser::ReturnTypeContext::getRuleIndex() const {
  return GooeyParser::RuleReturnType;
}


antlrcpp::Any GooeyParser::ReturnTypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitReturnType(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::ReturnTypeContext* GooeyParser::returnType() {
  ReturnTypeContext *_localctx = _tracker.createInstance<ReturnTypeContext>(_ctx, getState());
  enterRule(_localctx, 34, GooeyParser::RuleReturnType);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(209);
    match(GooeyParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

GooeyParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::VariableContext::IDENTIFIER() {
  return getToken(GooeyParser::IDENTIFIER, 0);
}

std::vector<GooeyParser::ModifierContext *> GooeyParser::VariableContext::modifier() {
  return getRuleContexts<GooeyParser::ModifierContext>();
}

GooeyParser::ModifierContext* GooeyParser::VariableContext::modifier(size_t i) {
  return getRuleContext<GooeyParser::ModifierContext>(i);
}


size_t GooeyParser::VariableContext::getRuleIndex() const {
  return GooeyParser::RuleVariable;
}


antlrcpp::Any GooeyParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::VariableContext* GooeyParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 36, GooeyParser::RuleVariable);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(211);
    match(GooeyParser::IDENTIFIER);
    setState(215);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GooeyParser::T__5) {
      setState(212);
      modifier();
      setState(217);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayVardecContext ------------------------------------------------------------------

GooeyParser::ArrayVardecContext::ArrayVardecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::ArrayVardecContext::IDENTIFIER() {
  return getToken(GooeyParser::IDENTIFIER, 0);
}

std::vector<GooeyParser::ModifierDeclareContext *> GooeyParser::ArrayVardecContext::modifierDeclare() {
  return getRuleContexts<GooeyParser::ModifierDeclareContext>();
}

GooeyParser::ModifierDeclareContext* GooeyParser::ArrayVardecContext::modifierDeclare(size_t i) {
  return getRuleContext<GooeyParser::ModifierDeclareContext>(i);
}


size_t GooeyParser::ArrayVardecContext::getRuleIndex() const {
  return GooeyParser::RuleArrayVardec;
}


antlrcpp::Any GooeyParser::ArrayVardecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitArrayVardec(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::ArrayVardecContext* GooeyParser::arrayVardec() {
  ArrayVardecContext *_localctx = _tracker.createInstance<ArrayVardecContext>(_ctx, getState());
  enterRule(_localctx, 38, GooeyParser::RuleArrayVardec);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(218);
    match(GooeyParser::IDENTIFIER);
    setState(222);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GooeyParser::T__5) {
      setState(219);
      modifierDeclare();
      setState(224);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModifierDeclareContext ------------------------------------------------------------------

GooeyParser::ModifierDeclareContext::ModifierDeclareContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::ModifierDeclareContext::INTEGER() {
  return getToken(GooeyParser::INTEGER, 0);
}


size_t GooeyParser::ModifierDeclareContext::getRuleIndex() const {
  return GooeyParser::RuleModifierDeclare;
}


antlrcpp::Any GooeyParser::ModifierDeclareContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitModifierDeclare(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::ModifierDeclareContext* GooeyParser::modifierDeclare() {
  ModifierDeclareContext *_localctx = _tracker.createInstance<ModifierDeclareContext>(_ctx, getState());
  enterRule(_localctx, 40, GooeyParser::RuleModifierDeclare);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225);
    match(GooeyParser::T__5);
    setState(226);
    match(GooeyParser::INTEGER);
    setState(227);
    match(GooeyParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ModifierContext ------------------------------------------------------------------

GooeyParser::ModifierContext::ModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GooeyParser::ExpressionContext* GooeyParser::ModifierContext::expression() {
  return getRuleContext<GooeyParser::ExpressionContext>(0);
}


size_t GooeyParser::ModifierContext::getRuleIndex() const {
  return GooeyParser::RuleModifier;
}


antlrcpp::Any GooeyParser::ModifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitModifier(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::ModifierContext* GooeyParser::modifier() {
  ModifierContext *_localctx = _tracker.createInstance<ModifierContext>(_ctx, getState());
  enterRule(_localctx, 42, GooeyParser::RuleModifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(229);
    match(GooeyParser::T__5);
    setState(230);
    expression();
    setState(231);
    match(GooeyParser::T__6);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ActionDefContext ------------------------------------------------------------------

GooeyParser::ActionDefContext::ActionDefContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::ActionDefContext::ACT() {
  return getToken(GooeyParser::ACT, 0);
}

std::vector<GooeyParser::ActDecContext *> GooeyParser::ActionDefContext::actDec() {
  return getRuleContexts<GooeyParser::ActDecContext>();
}

GooeyParser::ActDecContext* GooeyParser::ActionDefContext::actDec(size_t i) {
  return getRuleContext<GooeyParser::ActDecContext>(i);
}


size_t GooeyParser::ActionDefContext::getRuleIndex() const {
  return GooeyParser::RuleActionDef;
}


antlrcpp::Any GooeyParser::ActionDefContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitActionDef(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::ActionDefContext* GooeyParser::actionDef() {
  ActionDefContext *_localctx = _tracker.createInstance<ActionDefContext>(_ctx, getState());
  enterRule(_localctx, 44, GooeyParser::RuleActionDef);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(233);
    match(GooeyParser::ACT);
    setState(234);
    match(GooeyParser::T__4);
    setState(238);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GooeyParser::IDENTIFIER) {
      setState(235);
      actDec();
      setState(240);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ActDecContext ------------------------------------------------------------------

GooeyParser::ActDecContext::ActDecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GooeyParser::ActionNameContext* GooeyParser::ActDecContext::actionName() {
  return getRuleContext<GooeyParser::ActionNameContext>(0);
}

GooeyParser::CompoundStatementContext* GooeyParser::ActDecContext::compoundStatement() {
  return getRuleContext<GooeyParser::CompoundStatementContext>(0);
}


size_t GooeyParser::ActDecContext::getRuleIndex() const {
  return GooeyParser::RuleActDec;
}


antlrcpp::Any GooeyParser::ActDecContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitActDec(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::ActDecContext* GooeyParser::actDec() {
  ActDecContext *_localctx = _tracker.createInstance<ActDecContext>(_ctx, getState());
  enterRule(_localctx, 46, GooeyParser::RuleActDec);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(241);
    actionName();
    setState(242);
    compoundStatement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ActionNameContext ------------------------------------------------------------------

GooeyParser::ActionNameContext::ActionNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::ActionNameContext::IDENTIFIER() {
  return getToken(GooeyParser::IDENTIFIER, 0);
}


size_t GooeyParser::ActionNameContext::getRuleIndex() const {
  return GooeyParser::RuleActionName;
}


antlrcpp::Any GooeyParser::ActionNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitActionName(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::ActionNameContext* GooeyParser::actionName() {
  ActionNameContext *_localctx = _tracker.createInstance<ActionNameContext>(_ctx, getState());
  enterRule(_localctx, 48, GooeyParser::RuleActionName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(244);
    match(GooeyParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignContext ------------------------------------------------------------------

GooeyParser::SignContext::SignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GooeyParser::SignContext::getRuleIndex() const {
  return GooeyParser::RuleSign;
}


antlrcpp::Any GooeyParser::SignContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitSign(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::SignContext* GooeyParser::sign() {
  SignContext *_localctx = _tracker.createInstance<SignContext>(_ctx, getState());
  enterRule(_localctx, 50, GooeyParser::RuleSign);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(246);
    _la = _input->LA(1);
    if (!(_la == GooeyParser::T__7

    || _la == GooeyParser::T__8)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionCallContext ------------------------------------------------------------------

GooeyParser::FunctionCallContext::FunctionCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GooeyParser::FunctionNameContext* GooeyParser::FunctionCallContext::functionName() {
  return getRuleContext<GooeyParser::FunctionNameContext>(0);
}

GooeyParser::ArgumentListContext* GooeyParser::FunctionCallContext::argumentList() {
  return getRuleContext<GooeyParser::ArgumentListContext>(0);
}


size_t GooeyParser::FunctionCallContext::getRuleIndex() const {
  return GooeyParser::RuleFunctionCall;
}


antlrcpp::Any GooeyParser::FunctionCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitFunctionCall(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::FunctionCallContext* GooeyParser::functionCall() {
  FunctionCallContext *_localctx = _tracker.createInstance<FunctionCallContext>(_ctx, getState());
  enterRule(_localctx, 52, GooeyParser::RuleFunctionCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(248);
    functionName();
    setState(249);
    match(GooeyParser::T__0);
    setState(251);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GooeyParser::T__0)
      | (1ULL << GooeyParser::T__7)
      | (1ULL << GooeyParser::T__8)
      | (1ULL << GooeyParser::T__13)
      | (1ULL << GooeyParser::IDENTIFIER)
      | (1ULL << GooeyParser::INTEGER)
      | (1ULL << GooeyParser::REAL)
      | (1ULL << GooeyParser::CHARACTER)
      | (1ULL << GooeyParser::STRING))) != 0)) {
      setState(250);
      argumentList();
    }
    setState(253);
    match(GooeyParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcedureCallContext ------------------------------------------------------------------

GooeyParser::ProcedureCallContext::ProcedureCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GooeyParser::FunctionNameContext* GooeyParser::ProcedureCallContext::functionName() {
  return getRuleContext<GooeyParser::FunctionNameContext>(0);
}

GooeyParser::ArgumentListContext* GooeyParser::ProcedureCallContext::argumentList() {
  return getRuleContext<GooeyParser::ArgumentListContext>(0);
}


size_t GooeyParser::ProcedureCallContext::getRuleIndex() const {
  return GooeyParser::RuleProcedureCall;
}


antlrcpp::Any GooeyParser::ProcedureCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitProcedureCall(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::ProcedureCallContext* GooeyParser::procedureCall() {
  ProcedureCallContext *_localctx = _tracker.createInstance<ProcedureCallContext>(_ctx, getState());
  enterRule(_localctx, 54, GooeyParser::RuleProcedureCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(255);
    functionName();
    setState(256);
    match(GooeyParser::T__0);
    setState(258);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GooeyParser::T__0)
      | (1ULL << GooeyParser::T__7)
      | (1ULL << GooeyParser::T__8)
      | (1ULL << GooeyParser::T__13)
      | (1ULL << GooeyParser::IDENTIFIER)
      | (1ULL << GooeyParser::INTEGER)
      | (1ULL << GooeyParser::REAL)
      | (1ULL << GooeyParser::CHARACTER)
      | (1ULL << GooeyParser::STRING))) != 0)) {
      setState(257);
      argumentList();
    }
    setState(260);
    match(GooeyParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionNameContext ------------------------------------------------------------------

GooeyParser::FunctionNameContext::FunctionNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::FunctionNameContext::IDENTIFIER() {
  return getToken(GooeyParser::IDENTIFIER, 0);
}


size_t GooeyParser::FunctionNameContext::getRuleIndex() const {
  return GooeyParser::RuleFunctionName;
}


antlrcpp::Any GooeyParser::FunctionNameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitFunctionName(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::FunctionNameContext* GooeyParser::functionName() {
  FunctionNameContext *_localctx = _tracker.createInstance<FunctionNameContext>(_ctx, getState());
  enterRule(_localctx, 56, GooeyParser::RuleFunctionName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(262);
    match(GooeyParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentListContext ------------------------------------------------------------------

GooeyParser::ArgumentListContext::ArgumentListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GooeyParser::ArgumentContext *> GooeyParser::ArgumentListContext::argument() {
  return getRuleContexts<GooeyParser::ArgumentContext>();
}

GooeyParser::ArgumentContext* GooeyParser::ArgumentListContext::argument(size_t i) {
  return getRuleContext<GooeyParser::ArgumentContext>(i);
}


size_t GooeyParser::ArgumentListContext::getRuleIndex() const {
  return GooeyParser::RuleArgumentList;
}


antlrcpp::Any GooeyParser::ArgumentListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitArgumentList(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::ArgumentListContext* GooeyParser::argumentList() {
  ArgumentListContext *_localctx = _tracker.createInstance<ArgumentListContext>(_ctx, getState());
  enterRule(_localctx, 58, GooeyParser::RuleArgumentList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(264);
    argument();
    setState(269);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GooeyParser::T__1) {
      setState(265);
      match(GooeyParser::T__1);
      setState(266);
      argument();
      setState(271);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentContext ------------------------------------------------------------------

GooeyParser::ArgumentContext::ArgumentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GooeyParser::ExpressionContext* GooeyParser::ArgumentContext::expression() {
  return getRuleContext<GooeyParser::ExpressionContext>(0);
}

GooeyParser::ActionNameContext* GooeyParser::ArgumentContext::actionName() {
  return getRuleContext<GooeyParser::ActionNameContext>(0);
}


size_t GooeyParser::ArgumentContext::getRuleIndex() const {
  return GooeyParser::RuleArgument;
}


antlrcpp::Any GooeyParser::ArgumentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitArgument(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::ArgumentContext* GooeyParser::argument() {
  ArgumentContext *_localctx = _tracker.createInstance<ArgumentContext>(_ctx, getState());
  enterRule(_localctx, 60, GooeyParser::RuleArgument);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(276);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 17, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(272);
      expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(273);
      actionName();
      setState(274);
      match(GooeyParser::T__9);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

GooeyParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GooeyParser::CompoundStatementContext* GooeyParser::StatementContext::compoundStatement() {
  return getRuleContext<GooeyParser::CompoundStatementContext>(0);
}

GooeyParser::AssignmentStatementContext* GooeyParser::StatementContext::assignmentStatement() {
  return getRuleContext<GooeyParser::AssignmentStatementContext>(0);
}

GooeyParser::IfStatementContext* GooeyParser::StatementContext::ifStatement() {
  return getRuleContext<GooeyParser::IfStatementContext>(0);
}

GooeyParser::WhileStatementContext* GooeyParser::StatementContext::whileStatement() {
  return getRuleContext<GooeyParser::WhileStatementContext>(0);
}

GooeyParser::ForStatementContext* GooeyParser::StatementContext::forStatement() {
  return getRuleContext<GooeyParser::ForStatementContext>(0);
}

GooeyParser::EmptyStatementContext* GooeyParser::StatementContext::emptyStatement() {
  return getRuleContext<GooeyParser::EmptyStatementContext>(0);
}

GooeyParser::ProcedureCallContext* GooeyParser::StatementContext::procedureCall() {
  return getRuleContext<GooeyParser::ProcedureCallContext>(0);
}

GooeyParser::PredefinedRoutineCallContext* GooeyParser::StatementContext::predefinedRoutineCall() {
  return getRuleContext<GooeyParser::PredefinedRoutineCallContext>(0);
}


size_t GooeyParser::StatementContext::getRuleIndex() const {
  return GooeyParser::RuleStatement;
}


antlrcpp::Any GooeyParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::StatementContext* GooeyParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 62, GooeyParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(286);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(278);
      compoundStatement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(279);
      assignmentStatement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(280);
      ifStatement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(281);
      whileStatement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(282);
      forStatement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(283);
      emptyStatement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(284);
      procedureCall();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(285);
      predefinedRoutineCall();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PredefinedRoutineCallContext ------------------------------------------------------------------

GooeyParser::PredefinedRoutineCallContext::PredefinedRoutineCallContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GooeyParser::VariableContext* GooeyParser::PredefinedRoutineCallContext::variable() {
  return getRuleContext<GooeyParser::VariableContext>(0);
}

GooeyParser::PredefinedRoutineContext* GooeyParser::PredefinedRoutineCallContext::predefinedRoutine() {
  return getRuleContext<GooeyParser::PredefinedRoutineContext>(0);
}

GooeyParser::ArgumentListContext* GooeyParser::PredefinedRoutineCallContext::argumentList() {
  return getRuleContext<GooeyParser::ArgumentListContext>(0);
}


size_t GooeyParser::PredefinedRoutineCallContext::getRuleIndex() const {
  return GooeyParser::RulePredefinedRoutineCall;
}


antlrcpp::Any GooeyParser::PredefinedRoutineCallContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitPredefinedRoutineCall(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::PredefinedRoutineCallContext* GooeyParser::predefinedRoutineCall() {
  PredefinedRoutineCallContext *_localctx = _tracker.createInstance<PredefinedRoutineCallContext>(_ctx, getState());
  enterRule(_localctx, 64, GooeyParser::RulePredefinedRoutineCall);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(288);
    variable();
    setState(289);
    match(GooeyParser::T__9);
    setState(290);
    predefinedRoutine();
    setState(291);
    match(GooeyParser::T__0);
    setState(293);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GooeyParser::T__0)
      | (1ULL << GooeyParser::T__7)
      | (1ULL << GooeyParser::T__8)
      | (1ULL << GooeyParser::T__13)
      | (1ULL << GooeyParser::IDENTIFIER)
      | (1ULL << GooeyParser::INTEGER)
      | (1ULL << GooeyParser::REAL)
      | (1ULL << GooeyParser::CHARACTER)
      | (1ULL << GooeyParser::STRING))) != 0)) {
      setState(292);
      argumentList();
    }
    setState(295);
    match(GooeyParser::T__2);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PredefinedRoutineContext ------------------------------------------------------------------

GooeyParser::PredefinedRoutineContext::PredefinedRoutineContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::PredefinedRoutineContext::IDENTIFIER() {
  return getToken(GooeyParser::IDENTIFIER, 0);
}


size_t GooeyParser::PredefinedRoutineContext::getRuleIndex() const {
  return GooeyParser::RulePredefinedRoutine;
}


antlrcpp::Any GooeyParser::PredefinedRoutineContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitPredefinedRoutine(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::PredefinedRoutineContext* GooeyParser::predefinedRoutine() {
  PredefinedRoutineContext *_localctx = _tracker.createInstance<PredefinedRoutineContext>(_ctx, getState());
  enterRule(_localctx, 66, GooeyParser::RulePredefinedRoutine);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(297);
    match(GooeyParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompoundStatementContext ------------------------------------------------------------------

GooeyParser::CompoundStatementContext::CompoundStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GooeyParser::StatementListContext* GooeyParser::CompoundStatementContext::statementList() {
  return getRuleContext<GooeyParser::StatementListContext>(0);
}


size_t GooeyParser::CompoundStatementContext::getRuleIndex() const {
  return GooeyParser::RuleCompoundStatement;
}


antlrcpp::Any GooeyParser::CompoundStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitCompoundStatement(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::CompoundStatementContext* GooeyParser::compoundStatement() {
  CompoundStatementContext *_localctx = _tracker.createInstance<CompoundStatementContext>(_ctx, getState());
  enterRule(_localctx, 68, GooeyParser::RuleCompoundStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(299);
    match(GooeyParser::T__10);
    setState(300);
    statementList();
    setState(301);
    match(GooeyParser::T__11);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EmptyStatementContext ------------------------------------------------------------------

GooeyParser::EmptyStatementContext::EmptyStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GooeyParser::EmptyStatementContext::getRuleIndex() const {
  return GooeyParser::RuleEmptyStatement;
}


antlrcpp::Any GooeyParser::EmptyStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitEmptyStatement(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::EmptyStatementContext* GooeyParser::emptyStatement() {
  EmptyStatementContext *_localctx = _tracker.createInstance<EmptyStatementContext>(_ctx, getState());
  enterRule(_localctx, 70, GooeyParser::RuleEmptyStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);

   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementListContext ------------------------------------------------------------------

GooeyParser::StatementListContext::StatementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GooeyParser::StatementContext *> GooeyParser::StatementListContext::statement() {
  return getRuleContexts<GooeyParser::StatementContext>();
}

GooeyParser::StatementContext* GooeyParser::StatementListContext::statement(size_t i) {
  return getRuleContext<GooeyParser::StatementContext>(i);
}


size_t GooeyParser::StatementListContext::getRuleIndex() const {
  return GooeyParser::RuleStatementList;
}


antlrcpp::Any GooeyParser::StatementListContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitStatementList(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::StatementListContext* GooeyParser::statementList() {
  StatementListContext *_localctx = _tracker.createInstance<StatementListContext>(_ctx, getState());
  enterRule(_localctx, 72, GooeyParser::RuleStatementList);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(305);
    statement();
    setState(310);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GooeyParser::T__3) {
      setState(306);
      match(GooeyParser::T__3);
      setState(307);
      statement();
      setState(312);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignmentStatementContext ------------------------------------------------------------------

GooeyParser::AssignmentStatementContext::AssignmentStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GooeyParser::LhsContext* GooeyParser::AssignmentStatementContext::lhs() {
  return getRuleContext<GooeyParser::LhsContext>(0);
}

GooeyParser::RhsContext* GooeyParser::AssignmentStatementContext::rhs() {
  return getRuleContext<GooeyParser::RhsContext>(0);
}


size_t GooeyParser::AssignmentStatementContext::getRuleIndex() const {
  return GooeyParser::RuleAssignmentStatement;
}


antlrcpp::Any GooeyParser::AssignmentStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitAssignmentStatement(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::AssignmentStatementContext* GooeyParser::assignmentStatement() {
  AssignmentStatementContext *_localctx = _tracker.createInstance<AssignmentStatementContext>(_ctx, getState());
  enterRule(_localctx, 74, GooeyParser::RuleAssignmentStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(313);
    lhs();
    setState(314);
    match(GooeyParser::T__12);
    setState(315);
    rhs();
    setState(317);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      setState(316);
      match(GooeyParser::T__3);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LhsContext ------------------------------------------------------------------

GooeyParser::LhsContext::LhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GooeyParser::VariableContext* GooeyParser::LhsContext::variable() {
  return getRuleContext<GooeyParser::VariableContext>(0);
}


size_t GooeyParser::LhsContext::getRuleIndex() const {
  return GooeyParser::RuleLhs;
}


antlrcpp::Any GooeyParser::LhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitLhs(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::LhsContext* GooeyParser::lhs() {
  LhsContext *_localctx = _tracker.createInstance<LhsContext>(_ctx, getState());
  enterRule(_localctx, 76, GooeyParser::RuleLhs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
    variable();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RhsContext ------------------------------------------------------------------

GooeyParser::RhsContext::RhsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GooeyParser::ExpressionContext* GooeyParser::RhsContext::expression() {
  return getRuleContext<GooeyParser::ExpressionContext>(0);
}


size_t GooeyParser::RhsContext::getRuleIndex() const {
  return GooeyParser::RuleRhs;
}


antlrcpp::Any GooeyParser::RhsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitRhs(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::RhsContext* GooeyParser::rhs() {
  RhsContext *_localctx = _tracker.createInstance<RhsContext>(_ctx, getState());
  enterRule(_localctx, 78, GooeyParser::RuleRhs);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(321);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStatementContext ------------------------------------------------------------------

GooeyParser::IfStatementContext::IfStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::IfStatementContext::IF() {
  return getToken(GooeyParser::IF, 0);
}

GooeyParser::ExpressionContext* GooeyParser::IfStatementContext::expression() {
  return getRuleContext<GooeyParser::ExpressionContext>(0);
}

std::vector<GooeyParser::StatementContext *> GooeyParser::IfStatementContext::statement() {
  return getRuleContexts<GooeyParser::StatementContext>();
}

GooeyParser::StatementContext* GooeyParser::IfStatementContext::statement(size_t i) {
  return getRuleContext<GooeyParser::StatementContext>(i);
}

tree::TerminalNode* GooeyParser::IfStatementContext::ELSE() {
  return getToken(GooeyParser::ELSE, 0);
}


size_t GooeyParser::IfStatementContext::getRuleIndex() const {
  return GooeyParser::RuleIfStatement;
}


antlrcpp::Any GooeyParser::IfStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitIfStatement(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::IfStatementContext* GooeyParser::ifStatement() {
  IfStatementContext *_localctx = _tracker.createInstance<IfStatementContext>(_ctx, getState());
  enterRule(_localctx, 80, GooeyParser::RuleIfStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(323);
    match(GooeyParser::IF);
    setState(324);
    match(GooeyParser::T__0);
    setState(325);
    expression();
    setState(326);
    match(GooeyParser::T__2);
    setState(327);
    statement();
    setState(330);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      setState(328);
      match(GooeyParser::ELSE);
      setState(329);
      statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WhileStatementContext ------------------------------------------------------------------

GooeyParser::WhileStatementContext::WhileStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::WhileStatementContext::WHILE() {
  return getToken(GooeyParser::WHILE, 0);
}

GooeyParser::ExpressionContext* GooeyParser::WhileStatementContext::expression() {
  return getRuleContext<GooeyParser::ExpressionContext>(0);
}

GooeyParser::StatementContext* GooeyParser::WhileStatementContext::statement() {
  return getRuleContext<GooeyParser::StatementContext>(0);
}


size_t GooeyParser::WhileStatementContext::getRuleIndex() const {
  return GooeyParser::RuleWhileStatement;
}


antlrcpp::Any GooeyParser::WhileStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitWhileStatement(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::WhileStatementContext* GooeyParser::whileStatement() {
  WhileStatementContext *_localctx = _tracker.createInstance<WhileStatementContext>(_ctx, getState());
  enterRule(_localctx, 82, GooeyParser::RuleWhileStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(332);
    match(GooeyParser::WHILE);
    setState(333);
    match(GooeyParser::T__0);
    setState(334);
    expression();
    setState(335);
    match(GooeyParser::T__2);
    setState(336);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStatementContext ------------------------------------------------------------------

GooeyParser::ForStatementContext::ForStatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::ForStatementContext::FOR() {
  return getToken(GooeyParser::FOR, 0);
}

GooeyParser::VariableContext* GooeyParser::ForStatementContext::variable() {
  return getRuleContext<GooeyParser::VariableContext>(0);
}

std::vector<GooeyParser::ExpressionContext *> GooeyParser::ForStatementContext::expression() {
  return getRuleContexts<GooeyParser::ExpressionContext>();
}

GooeyParser::ExpressionContext* GooeyParser::ForStatementContext::expression(size_t i) {
  return getRuleContext<GooeyParser::ExpressionContext>(i);
}

GooeyParser::StatementContext* GooeyParser::ForStatementContext::statement() {
  return getRuleContext<GooeyParser::StatementContext>(0);
}

tree::TerminalNode* GooeyParser::ForStatementContext::DOWNTO() {
  return getToken(GooeyParser::DOWNTO, 0);
}

tree::TerminalNode* GooeyParser::ForStatementContext::TO() {
  return getToken(GooeyParser::TO, 0);
}


size_t GooeyParser::ForStatementContext::getRuleIndex() const {
  return GooeyParser::RuleForStatement;
}


antlrcpp::Any GooeyParser::ForStatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitForStatement(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::ForStatementContext* GooeyParser::forStatement() {
  ForStatementContext *_localctx = _tracker.createInstance<ForStatementContext>(_ctx, getState());
  enterRule(_localctx, 84, GooeyParser::RuleForStatement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(338);
    match(GooeyParser::FOR);
    setState(339);
    match(GooeyParser::T__0);
    setState(340);
    variable();
    setState(341);
    match(GooeyParser::T__12);
    setState(342);
    expression();
    setState(343);
    _la = _input->LA(1);
    if (!(_la == GooeyParser::DOWNTO

    || _la == GooeyParser::TO)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(344);
    expression();
    setState(345);
    match(GooeyParser::T__2);
    setState(346);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

GooeyParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GooeyParser::SimpleExpressionContext *> GooeyParser::ExpressionContext::simpleExpression() {
  return getRuleContexts<GooeyParser::SimpleExpressionContext>();
}

GooeyParser::SimpleExpressionContext* GooeyParser::ExpressionContext::simpleExpression(size_t i) {
  return getRuleContext<GooeyParser::SimpleExpressionContext>(i);
}

GooeyParser::RelOpContext* GooeyParser::ExpressionContext::relOp() {
  return getRuleContext<GooeyParser::RelOpContext>(0);
}


size_t GooeyParser::ExpressionContext::getRuleIndex() const {
  return GooeyParser::RuleExpression;
}


antlrcpp::Any GooeyParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::ExpressionContext* GooeyParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 86, GooeyParser::RuleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(348);
    simpleExpression();
    setState(352);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GooeyParser::T__14)
      | (1ULL << GooeyParser::T__15)
      | (1ULL << GooeyParser::T__16)
      | (1ULL << GooeyParser::T__17)
      | (1ULL << GooeyParser::T__18)
      | (1ULL << GooeyParser::T__19))) != 0)) {
      setState(349);
      relOp();
      setState(350);
      simpleExpression();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleExpressionContext ------------------------------------------------------------------

GooeyParser::SimpleExpressionContext::SimpleExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GooeyParser::TermContext *> GooeyParser::SimpleExpressionContext::term() {
  return getRuleContexts<GooeyParser::TermContext>();
}

GooeyParser::TermContext* GooeyParser::SimpleExpressionContext::term(size_t i) {
  return getRuleContext<GooeyParser::TermContext>(i);
}

GooeyParser::SignContext* GooeyParser::SimpleExpressionContext::sign() {
  return getRuleContext<GooeyParser::SignContext>(0);
}

std::vector<GooeyParser::AddOpContext *> GooeyParser::SimpleExpressionContext::addOp() {
  return getRuleContexts<GooeyParser::AddOpContext>();
}

GooeyParser::AddOpContext* GooeyParser::SimpleExpressionContext::addOp(size_t i) {
  return getRuleContext<GooeyParser::AddOpContext>(i);
}


size_t GooeyParser::SimpleExpressionContext::getRuleIndex() const {
  return GooeyParser::RuleSimpleExpression;
}


antlrcpp::Any GooeyParser::SimpleExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitSimpleExpression(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::SimpleExpressionContext* GooeyParser::simpleExpression() {
  SimpleExpressionContext *_localctx = _tracker.createInstance<SimpleExpressionContext>(_ctx, getState());
  enterRule(_localctx, 88, GooeyParser::RuleSimpleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(355);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
    case 1: {
      setState(354);
      sign();
      break;
    }

    }
    setState(357);
    term();
    setState(363);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GooeyParser::T__7)
      | (1ULL << GooeyParser::T__8)
      | (1ULL << GooeyParser::OR))) != 0)) {
      setState(358);
      addOp();
      setState(359);
      term();
      setState(365);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

GooeyParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GooeyParser::FactorContext *> GooeyParser::TermContext::factor() {
  return getRuleContexts<GooeyParser::FactorContext>();
}

GooeyParser::FactorContext* GooeyParser::TermContext::factor(size_t i) {
  return getRuleContext<GooeyParser::FactorContext>(i);
}

std::vector<GooeyParser::MulOpContext *> GooeyParser::TermContext::mulOp() {
  return getRuleContexts<GooeyParser::MulOpContext>();
}

GooeyParser::MulOpContext* GooeyParser::TermContext::mulOp(size_t i) {
  return getRuleContext<GooeyParser::MulOpContext>(i);
}


size_t GooeyParser::TermContext::getRuleIndex() const {
  return GooeyParser::RuleTerm;
}


antlrcpp::Any GooeyParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::TermContext* GooeyParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 90, GooeyParser::RuleTerm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(366);
    factor();
    setState(372);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GooeyParser::T__20)
      | (1ULL << GooeyParser::T__21)
      | (1ULL << GooeyParser::AND))) != 0)) {
      setState(367);
      mulOp();
      setState(368);
      factor();
      setState(374);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

GooeyParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GooeyParser::FactorContext::getRuleIndex() const {
  return GooeyParser::RuleFactor;
}

void GooeyParser::FactorContext::copyFrom(FactorContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
  this->type = ctx->type;
  this->array = ctx->array;
}

//----------------- NumberFactorContext ------------------------------------------------------------------

GooeyParser::NumberContext* GooeyParser::NumberFactorContext::number() {
  return getRuleContext<GooeyParser::NumberContext>(0);
}

GooeyParser::NumberFactorContext::NumberFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any GooeyParser::NumberFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitNumberFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- StringFactorContext ------------------------------------------------------------------

GooeyParser::StringConstantContext* GooeyParser::StringFactorContext::stringConstant() {
  return getRuleContext<GooeyParser::StringConstantContext>(0);
}

GooeyParser::StringFactorContext::StringFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any GooeyParser::StringFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitStringFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- CharacterFactorContext ------------------------------------------------------------------

GooeyParser::CharacterConstantContext* GooeyParser::CharacterFactorContext::characterConstant() {
  return getRuleContext<GooeyParser::CharacterConstantContext>(0);
}

GooeyParser::CharacterFactorContext::CharacterFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any GooeyParser::CharacterFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitCharacterFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- VariableFactorContext ------------------------------------------------------------------

GooeyParser::VariableContext* GooeyParser::VariableFactorContext::variable() {
  return getRuleContext<GooeyParser::VariableContext>(0);
}

GooeyParser::VariableFactorContext::VariableFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any GooeyParser::VariableFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitVariableFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- FunctionCallFactorContext ------------------------------------------------------------------

GooeyParser::FunctionCallContext* GooeyParser::FunctionCallFactorContext::functionCall() {
  return getRuleContext<GooeyParser::FunctionCallContext>(0);
}

GooeyParser::FunctionCallFactorContext::FunctionCallFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any GooeyParser::FunctionCallFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitFunctionCallFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- NotFactorContext ------------------------------------------------------------------

GooeyParser::FactorContext* GooeyParser::NotFactorContext::factor() {
  return getRuleContext<GooeyParser::FactorContext>(0);
}

GooeyParser::NotFactorContext::NotFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any GooeyParser::NotFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitNotFactor(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ParenthesizedFactorContext ------------------------------------------------------------------

GooeyParser::ExpressionContext* GooeyParser::ParenthesizedFactorContext::expression() {
  return getRuleContext<GooeyParser::ExpressionContext>(0);
}

GooeyParser::ParenthesizedFactorContext::ParenthesizedFactorContext(FactorContext *ctx) { copyFrom(ctx); }


antlrcpp::Any GooeyParser::ParenthesizedFactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitParenthesizedFactor(this);
  else
    return visitor->visitChildren(this);
}
GooeyParser::FactorContext* GooeyParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 92, GooeyParser::RuleFactor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(386);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<GooeyParser::VariableFactorContext>(_localctx));
      enterOuterAlt(_localctx, 1);
      setState(375);
      variable();
      break;
    }

    case 2: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<GooeyParser::NumberFactorContext>(_localctx));
      enterOuterAlt(_localctx, 2);
      setState(376);
      number();
      break;
    }

    case 3: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<GooeyParser::CharacterFactorContext>(_localctx));
      enterOuterAlt(_localctx, 3);
      setState(377);
      characterConstant();
      break;
    }

    case 4: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<GooeyParser::StringFactorContext>(_localctx));
      enterOuterAlt(_localctx, 4);
      setState(378);
      stringConstant();
      break;
    }

    case 5: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<GooeyParser::FunctionCallFactorContext>(_localctx));
      enterOuterAlt(_localctx, 5);
      setState(379);
      functionCall();
      break;
    }

    case 6: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<GooeyParser::NotFactorContext>(_localctx));
      enterOuterAlt(_localctx, 6);
      setState(380);
      match(GooeyParser::T__13);
      setState(381);
      factor();
      break;
    }

    case 7: {
      _localctx = dynamic_cast<FactorContext *>(_tracker.createInstance<GooeyParser::ParenthesizedFactorContext>(_localctx));
      enterOuterAlt(_localctx, 7);
      setState(382);
      match(GooeyParser::T__0);
      setState(383);
      expression();
      setState(384);
      match(GooeyParser::T__2);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

GooeyParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GooeyParser::UnsignedNumberContext* GooeyParser::NumberContext::unsignedNumber() {
  return getRuleContext<GooeyParser::UnsignedNumberContext>(0);
}

GooeyParser::SignContext* GooeyParser::NumberContext::sign() {
  return getRuleContext<GooeyParser::SignContext>(0);
}


size_t GooeyParser::NumberContext::getRuleIndex() const {
  return GooeyParser::RuleNumber;
}


antlrcpp::Any GooeyParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::NumberContext* GooeyParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 94, GooeyParser::RuleNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(389);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GooeyParser::T__7

    || _la == GooeyParser::T__8) {
      setState(388);
      sign();
    }
    setState(391);
    unsignedNumber();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnsignedNumberContext ------------------------------------------------------------------

GooeyParser::UnsignedNumberContext::UnsignedNumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::UnsignedNumberContext::REAL() {
  return getToken(GooeyParser::REAL, 0);
}

tree::TerminalNode* GooeyParser::UnsignedNumberContext::INTEGER() {
  return getToken(GooeyParser::INTEGER, 0);
}


size_t GooeyParser::UnsignedNumberContext::getRuleIndex() const {
  return GooeyParser::RuleUnsignedNumber;
}


antlrcpp::Any GooeyParser::UnsignedNumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitUnsignedNumber(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::UnsignedNumberContext* GooeyParser::unsignedNumber() {
  UnsignedNumberContext *_localctx = _tracker.createInstance<UnsignedNumberContext>(_ctx, getState());
  enterRule(_localctx, 96, GooeyParser::RuleUnsignedNumber);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(393);
    _la = _input->LA(1);
    if (!(_la == GooeyParser::INTEGER

    || _la == GooeyParser::REAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CharacterConstantContext ------------------------------------------------------------------

GooeyParser::CharacterConstantContext::CharacterConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::CharacterConstantContext::CHARACTER() {
  return getToken(GooeyParser::CHARACTER, 0);
}


size_t GooeyParser::CharacterConstantContext::getRuleIndex() const {
  return GooeyParser::RuleCharacterConstant;
}


antlrcpp::Any GooeyParser::CharacterConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitCharacterConstant(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::CharacterConstantContext* GooeyParser::characterConstant() {
  CharacterConstantContext *_localctx = _tracker.createInstance<CharacterConstantContext>(_ctx, getState());
  enterRule(_localctx, 98, GooeyParser::RuleCharacterConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    match(GooeyParser::CHARACTER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StringConstantContext ------------------------------------------------------------------

GooeyParser::StringConstantContext::StringConstantContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::StringConstantContext::STRING() {
  return getToken(GooeyParser::STRING, 0);
}


size_t GooeyParser::StringConstantContext::getRuleIndex() const {
  return GooeyParser::RuleStringConstant;
}


antlrcpp::Any GooeyParser::StringConstantContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitStringConstant(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::StringConstantContext* GooeyParser::stringConstant() {
  StringConstantContext *_localctx = _tracker.createInstance<StringConstantContext>(_ctx, getState());
  enterRule(_localctx, 100, GooeyParser::RuleStringConstant);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(397);
    match(GooeyParser::STRING);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RelOpContext ------------------------------------------------------------------

GooeyParser::RelOpContext::RelOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GooeyParser::RelOpContext::getRuleIndex() const {
  return GooeyParser::RuleRelOp;
}


antlrcpp::Any GooeyParser::RelOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitRelOp(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::RelOpContext* GooeyParser::relOp() {
  RelOpContext *_localctx = _tracker.createInstance<RelOpContext>(_ctx, getState());
  enterRule(_localctx, 102, GooeyParser::RuleRelOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(399);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GooeyParser::T__14)
      | (1ULL << GooeyParser::T__15)
      | (1ULL << GooeyParser::T__16)
      | (1ULL << GooeyParser::T__17)
      | (1ULL << GooeyParser::T__18)
      | (1ULL << GooeyParser::T__19))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AddOpContext ------------------------------------------------------------------

GooeyParser::AddOpContext::AddOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::AddOpContext::OR() {
  return getToken(GooeyParser::OR, 0);
}


size_t GooeyParser::AddOpContext::getRuleIndex() const {
  return GooeyParser::RuleAddOp;
}


antlrcpp::Any GooeyParser::AddOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitAddOp(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::AddOpContext* GooeyParser::addOp() {
  AddOpContext *_localctx = _tracker.createInstance<AddOpContext>(_ctx, getState());
  enterRule(_localctx, 104, GooeyParser::RuleAddOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(401);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GooeyParser::T__7)
      | (1ULL << GooeyParser::T__8)
      | (1ULL << GooeyParser::OR))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MulOpContext ------------------------------------------------------------------

GooeyParser::MulOpContext::MulOpContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GooeyParser::MulOpContext::AND() {
  return getToken(GooeyParser::AND, 0);
}


size_t GooeyParser::MulOpContext::getRuleIndex() const {
  return GooeyParser::RuleMulOp;
}


antlrcpp::Any GooeyParser::MulOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<GooeyVisitor*>(visitor))
    return parserVisitor->visitMulOp(this);
  else
    return visitor->visitChildren(this);
}

GooeyParser::MulOpContext* GooeyParser::mulOp() {
  MulOpContext *_localctx = _tracker.createInstance<MulOpContext>(_ctx, getState());
  enterRule(_localctx, 106, GooeyParser::RuleMulOp);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(403);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GooeyParser::T__20)
      | (1ULL << GooeyParser::T__21)
      | (1ULL << GooeyParser::AND))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> GooeyParser::_decisionToDFA;
atn::PredictionContextCache GooeyParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN GooeyParser::_atn;
std::vector<uint16_t> GooeyParser::_serializedATN;

std::vector<std::string> GooeyParser::_ruleNames = {
  "program", "programHeader", "title", "block", "declarations", "variableDeclarationsList", 
  "variableDeclarations", "variableIdentifierList", "variableIdentifier", 
  "types", "functiondef", "funcDec", "parameter", "parameterDecList", "parameterDec", 
  "parameterIdList", "parameterId", "returnType", "variable", "arrayVardec", 
  "modifierDeclare", "modifier", "actionDef", "actDec", "actionName", "sign", 
  "functionCall", "procedureCall", "functionName", "argumentList", "argument", 
  "statement", "predefinedRoutineCall", "predefinedRoutine", "compoundStatement", 
  "emptyStatement", "statementList", "assignmentStatement", "lhs", "rhs", 
  "ifStatement", "whileStatement", "forStatement", "expression", "simpleExpression", 
  "term", "factor", "number", "unsignedNumber", "characterConstant", "stringConstant", 
  "relOp", "addOp", "mulOp"
};

std::vector<std::string> GooeyParser::_literalNames = {
  "", "'('", "','", "')'", "';'", "':'", "'['", "']'", "'-'", "'+'", "'.'", 
  "'{'", "'}'", "'='", "'!'", "'=='", "'!='", "'<'", "'<='", "'>'", "'>='", 
  "'*'", "'/'", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "'\"'"
};

std::vector<std::string> GooeyParser::_symbolicNames = {
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "GOOEY", "AND", "OR", "WHILE", "FOR", "IF", "ELSE", 
  "DOWNTO", "TO", "BY", "VAR", "FUNC", "MAIN", "ACT", "IDENTIFIER", "INTEGER", 
  "REAL", "NEWLINE", "WS", "QUOTE", "CHARACTER", "STRING", "COMMENT"
};

dfa::Vocabulary GooeyParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> GooeyParser::_tokenNames;

GooeyParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x2f, 0x198, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x3, 0x2, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0x75, 0xa, 0x2, 0x3, 0x2, 
    0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 
    0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0x81, 0xa, 0x5, 0x3, 0x5, 0x5, 0x5, 0x84, 
    0xa, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0x91, 0xa, 
    0x7, 0xc, 0x7, 0xe, 0x7, 0x94, 0xb, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 
    0x3, 0x8, 0x3, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x7, 0x9, 0x9e, 0xa, 
    0x9, 0xc, 0x9, 0xe, 0x9, 0xa1, 0xb, 0x9, 0x3, 0xa, 0x3, 0xa, 0x5, 0xa, 
    0xa5, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 
    0xc, 0xac, 0xa, 0xc, 0xc, 0xc, 0xe, 0xc, 0xaf, 0xb, 0xc, 0x3, 0xd, 0x3, 
    0xd, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0xb5, 0xa, 0xd, 0x3, 0xd, 0x3, 0xd, 
    0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0xbb, 0xa, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 
    0xf, 0x3, 0xf, 0x3, 0xf, 0x7, 0xf, 0xc2, 0xa, 0xf, 0xc, 0xf, 0xe, 0xf, 
    0xc5, 0xb, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x7, 0x11, 0xcd, 0xa, 0x11, 0xc, 0x11, 0xe, 0x11, 0xd0, 0xb, 
    0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 
    0x7, 0x14, 0xd8, 0xa, 0x14, 0xc, 0x14, 0xe, 0x14, 0xdb, 0xb, 0x14, 0x3, 
    0x15, 0x3, 0x15, 0x7, 0x15, 0xdf, 0xa, 0x15, 0xc, 0x15, 0xe, 0x15, 0xe2, 
    0xb, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 0x3, 
    0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 
    0xef, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 0xf2, 0xb, 0x18, 0x3, 0x19, 0x3, 
    0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 
    0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0xfe, 0xa, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x105, 0xa, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x1f, 0x7, 
    0x1f, 0x10e, 0xa, 0x1f, 0xc, 0x1f, 0xe, 0x1f, 0x111, 0xb, 0x1f, 0x3, 
    0x20, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x117, 0xa, 0x20, 
    0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 
    0x21, 0x3, 0x21, 0x5, 0x21, 0x121, 0xa, 0x21, 0x3, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x3, 0x22, 0x5, 0x22, 0x128, 0xa, 0x22, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 
    0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x7, 0x26, 
    0x137, 0xa, 0x26, 0xc, 0x26, 0xe, 0x26, 0x13a, 0xb, 0x26, 0x3, 0x27, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x140, 0xa, 0x27, 0x3, 0x28, 
    0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
    0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x14d, 0xa, 0x2a, 
    0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
    0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
    0x2d, 0x5, 0x2d, 0x163, 0xa, 0x2d, 0x3, 0x2e, 0x5, 0x2e, 0x166, 0xa, 
    0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x7, 0x2e, 0x16c, 
    0xa, 0x2e, 0xc, 0x2e, 0xe, 0x2e, 0x16f, 0xb, 0x2e, 0x3, 0x2f, 0x3, 0x2f, 
    0x3, 0x2f, 0x3, 0x2f, 0x7, 0x2f, 0x175, 0xa, 0x2f, 0xc, 0x2f, 0xe, 0x2f, 
    0x178, 0xb, 0x2f, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 
    0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 
    0x30, 0x185, 0xa, 0x30, 0x3, 0x31, 0x5, 0x31, 0x188, 0xa, 0x31, 0x3, 
    0x31, 0x3, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 
    0x37, 0x3, 0x37, 0x2, 0x2, 0x38, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 
    0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 0x24, 0x26, 
    0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 0x3a, 0x3c, 0x3e, 
    0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 0x50, 0x52, 0x54, 0x56, 
    0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 0x66, 0x68, 0x6a, 0x6c, 0x2, 
    0x8, 0x3, 0x2, 0xa, 0xb, 0x3, 0x2, 0x20, 0x21, 0x3, 0x2, 0x28, 0x29, 
    0x3, 0x2, 0x11, 0x16, 0x4, 0x2, 0xa, 0xb, 0x1b, 0x1b, 0x4, 0x2, 0x17, 
    0x18, 0x1a, 0x1a, 0x2, 0x189, 0x2, 0x6e, 0x3, 0x2, 0x2, 0x2, 0x4, 0x79, 
    0x3, 0x2, 0x2, 0x2, 0x6, 0x7c, 0x3, 0x2, 0x2, 0x2, 0x8, 0x7e, 0x3, 0x2, 
    0x2, 0x2, 0xa, 0x89, 0x3, 0x2, 0x2, 0x2, 0xc, 0x8d, 0x3, 0x2, 0x2, 0x2, 
    0xe, 0x97, 0x3, 0x2, 0x2, 0x2, 0x10, 0x9a, 0x3, 0x2, 0x2, 0x2, 0x12, 
    0xa4, 0x3, 0x2, 0x2, 0x2, 0x14, 0xa6, 0x3, 0x2, 0x2, 0x2, 0x16, 0xa8, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0xb0, 0x3, 0x2, 0x2, 0x2, 0x1a, 0xb8, 0x3, 
    0x2, 0x2, 0x2, 0x1c, 0xbe, 0x3, 0x2, 0x2, 0x2, 0x1e, 0xc6, 0x3, 0x2, 
    0x2, 0x2, 0x20, 0xc9, 0x3, 0x2, 0x2, 0x2, 0x22, 0xd1, 0x3, 0x2, 0x2, 
    0x2, 0x24, 0xd3, 0x3, 0x2, 0x2, 0x2, 0x26, 0xd5, 0x3, 0x2, 0x2, 0x2, 
    0x28, 0xdc, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xe3, 0x3, 0x2, 0x2, 0x2, 0x2c, 
    0xe7, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xeb, 0x3, 0x2, 0x2, 0x2, 0x30, 0xf3, 
    0x3, 0x2, 0x2, 0x2, 0x32, 0xf6, 0x3, 0x2, 0x2, 0x2, 0x34, 0xf8, 0x3, 
    0x2, 0x2, 0x2, 0x36, 0xfa, 0x3, 0x2, 0x2, 0x2, 0x38, 0x101, 0x3, 0x2, 
    0x2, 0x2, 0x3a, 0x108, 0x3, 0x2, 0x2, 0x2, 0x3c, 0x10a, 0x3, 0x2, 0x2, 
    0x2, 0x3e, 0x116, 0x3, 0x2, 0x2, 0x2, 0x40, 0x120, 0x3, 0x2, 0x2, 0x2, 
    0x42, 0x122, 0x3, 0x2, 0x2, 0x2, 0x44, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x46, 
    0x12d, 0x3, 0x2, 0x2, 0x2, 0x48, 0x131, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x133, 
    0x3, 0x2, 0x2, 0x2, 0x4c, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x141, 0x3, 
    0x2, 0x2, 0x2, 0x50, 0x143, 0x3, 0x2, 0x2, 0x2, 0x52, 0x145, 0x3, 0x2, 
    0x2, 0x2, 0x54, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x56, 0x154, 0x3, 0x2, 0x2, 
    0x2, 0x58, 0x15e, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x165, 0x3, 0x2, 0x2, 0x2, 
    0x5c, 0x170, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x184, 0x3, 0x2, 0x2, 0x2, 0x60, 
    0x187, 0x3, 0x2, 0x2, 0x2, 0x62, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x64, 0x18d, 
    0x3, 0x2, 0x2, 0x2, 0x66, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x68, 0x191, 0x3, 
    0x2, 0x2, 0x2, 0x6a, 0x193, 0x3, 0x2, 0x2, 0x2, 0x6c, 0x195, 0x3, 0x2, 
    0x2, 0x2, 0x6e, 0x74, 0x5, 0x4, 0x3, 0x2, 0x6f, 0x70, 0x7, 0x3, 0x2, 
    0x2, 0x70, 0x71, 0x7, 0x28, 0x2, 0x2, 0x71, 0x72, 0x7, 0x4, 0x2, 0x2, 
    0x72, 0x73, 0x7, 0x28, 0x2, 0x2, 0x73, 0x75, 0x7, 0x5, 0x2, 0x2, 0x74, 
    0x6f, 0x3, 0x2, 0x2, 0x2, 0x74, 0x75, 0x3, 0x2, 0x2, 0x2, 0x75, 0x76, 
    0x3, 0x2, 0x2, 0x2, 0x76, 0x77, 0x7, 0x6, 0x2, 0x2, 0x77, 0x78, 0x5, 
    0x8, 0x5, 0x2, 0x78, 0x3, 0x3, 0x2, 0x2, 0x2, 0x79, 0x7a, 0x7, 0x19, 
    0x2, 0x2, 0x7a, 0x7b, 0x5, 0x6, 0x4, 0x2, 0x7b, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x7c, 0x7d, 0x7, 0x27, 0x2, 0x2, 0x7d, 0x7, 0x3, 0x2, 0x2, 0x2, 
    0x7e, 0x80, 0x5, 0xa, 0x6, 0x2, 0x7f, 0x81, 0x5, 0x16, 0xc, 0x2, 0x80, 
    0x7f, 0x3, 0x2, 0x2, 0x2, 0x80, 0x81, 0x3, 0x2, 0x2, 0x2, 0x81, 0x83, 
    0x3, 0x2, 0x2, 0x2, 0x82, 0x84, 0x5, 0x2e, 0x18, 0x2, 0x83, 0x82, 0x3, 
    0x2, 0x2, 0x2, 0x83, 0x84, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x3, 0x2, 
    0x2, 0x2, 0x85, 0x86, 0x7, 0x25, 0x2, 0x2, 0x86, 0x87, 0x7, 0x7, 0x2, 
    0x2, 0x87, 0x88, 0x5, 0x46, 0x24, 0x2, 0x88, 0x9, 0x3, 0x2, 0x2, 0x2, 
    0x89, 0x8a, 0x7, 0x23, 0x2, 0x2, 0x8a, 0x8b, 0x7, 0x7, 0x2, 0x2, 0x8b, 
    0x8c, 0x5, 0xc, 0x7, 0x2, 0x8c, 0xb, 0x3, 0x2, 0x2, 0x2, 0x8d, 0x92, 
    0x5, 0xe, 0x8, 0x2, 0x8e, 0x8f, 0x7, 0x6, 0x2, 0x2, 0x8f, 0x91, 0x5, 
    0xe, 0x8, 0x2, 0x90, 0x8e, 0x3, 0x2, 0x2, 0x2, 0x91, 0x94, 0x3, 0x2, 
    0x2, 0x2, 0x92, 0x90, 0x3, 0x2, 0x2, 0x2, 0x92, 0x93, 0x3, 0x2, 0x2, 
    0x2, 0x93, 0x95, 0x3, 0x2, 0x2, 0x2, 0x94, 0x92, 0x3, 0x2, 0x2, 0x2, 
    0x95, 0x96, 0x7, 0x6, 0x2, 0x2, 0x96, 0xd, 0x3, 0x2, 0x2, 0x2, 0x97, 
    0x98, 0x5, 0x14, 0xb, 0x2, 0x98, 0x99, 0x5, 0x10, 0x9, 0x2, 0x99, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x9a, 0x9f, 0x5, 0x12, 0xa, 0x2, 0x9b, 0x9c, 0x7, 
    0x4, 0x2, 0x2, 0x9c, 0x9e, 0x5, 0x12, 0xa, 0x2, 0x9d, 0x9b, 0x3, 0x2, 
    0x2, 0x2, 0x9e, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x9f, 0x9d, 0x3, 0x2, 0x2, 
    0x2, 0x9f, 0xa0, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x11, 0x3, 0x2, 0x2, 0x2, 
    0xa1, 0x9f, 0x3, 0x2, 0x2, 0x2, 0xa2, 0xa5, 0x7, 0x27, 0x2, 0x2, 0xa3, 
    0xa5, 0x5, 0x28, 0x15, 0x2, 0xa4, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa4, 0xa3, 
    0x3, 0x2, 0x2, 0x2, 0xa5, 0x13, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x7, 
    0x27, 0x2, 0x2, 0xa7, 0x15, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa9, 0x7, 0x24, 
    0x2, 0x2, 0xa9, 0xad, 0x7, 0x7, 0x2, 0x2, 0xaa, 0xac, 0x5, 0x18, 0xd, 
    0x2, 0xab, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xac, 0xaf, 0x3, 0x2, 0x2, 0x2, 
    0xad, 0xab, 0x3, 0x2, 0x2, 0x2, 0xad, 0xae, 0x3, 0x2, 0x2, 0x2, 0xae, 
    0x17, 0x3, 0x2, 0x2, 0x2, 0xaf, 0xad, 0x3, 0x2, 0x2, 0x2, 0xb0, 0xb1, 
    0x5, 0x24, 0x13, 0x2, 0xb1, 0xb2, 0x5, 0x3a, 0x1e, 0x2, 0xb2, 0xb4, 
    0x5, 0x1a, 0xe, 0x2, 0xb3, 0xb5, 0x5, 0xa, 0x6, 0x2, 0xb4, 0xb3, 0x3, 
    0x2, 0x2, 0x2, 0xb4, 0xb5, 0x3, 0x2, 0x2, 0x2, 0xb5, 0xb6, 0x3, 0x2, 
    0x2, 0x2, 0xb6, 0xb7, 0x5, 0x46, 0x24, 0x2, 0xb7, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0xb8, 0xba, 0x7, 0x3, 0x2, 0x2, 0xb9, 0xbb, 0x5, 0x1c, 0xf, 0x2, 
    0xba, 0xb9, 0x3, 0x2, 0x2, 0x2, 0xba, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbb, 
    0xbc, 0x3, 0x2, 0x2, 0x2, 0xbc, 0xbd, 0x7, 0x5, 0x2, 0x2, 0xbd, 0x1b, 
    0x3, 0x2, 0x2, 0x2, 0xbe, 0xc3, 0x5, 0x1e, 0x10, 0x2, 0xbf, 0xc0, 0x7, 
    0x6, 0x2, 0x2, 0xc0, 0xc2, 0x5, 0x1e, 0x10, 0x2, 0xc1, 0xbf, 0x3, 0x2, 
    0x2, 0x2, 0xc2, 0xc5, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc1, 0x3, 0x2, 0x2, 
    0x2, 0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc4, 0x1d, 0x3, 0x2, 0x2, 0x2, 
    0xc5, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc6, 0xc7, 0x5, 0x14, 0xb, 0x2, 0xc7, 
    0xc8, 0x5, 0x20, 0x11, 0x2, 0xc8, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xce, 
    0x5, 0x22, 0x12, 0x2, 0xca, 0xcb, 0x7, 0x4, 0x2, 0x2, 0xcb, 0xcd, 0x5, 
    0x22, 0x12, 0x2, 0xcc, 0xca, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xd0, 0x3, 0x2, 
    0x2, 0x2, 0xce, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xce, 0xcf, 0x3, 0x2, 0x2, 
    0x2, 0xcf, 0x21, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xce, 0x3, 0x2, 0x2, 0x2, 
    0xd1, 0xd2, 0x7, 0x27, 0x2, 0x2, 0xd2, 0x23, 0x3, 0x2, 0x2, 0x2, 0xd3, 
    0xd4, 0x7, 0x27, 0x2, 0x2, 0xd4, 0x25, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xd9, 
    0x7, 0x27, 0x2, 0x2, 0xd6, 0xd8, 0x5, 0x2c, 0x17, 0x2, 0xd7, 0xd6, 0x3, 
    0x2, 0x2, 0x2, 0xd8, 0xdb, 0x3, 0x2, 0x2, 0x2, 0xd9, 0xd7, 0x3, 0x2, 
    0x2, 0x2, 0xd9, 0xda, 0x3, 0x2, 0x2, 0x2, 0xda, 0x27, 0x3, 0x2, 0x2, 
    0x2, 0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xe0, 0x7, 0x27, 0x2, 0x2, 
    0xdd, 0xdf, 0x5, 0x2a, 0x16, 0x2, 0xde, 0xdd, 0x3, 0x2, 0x2, 0x2, 0xdf, 
    0xe2, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 
    0x3, 0x2, 0x2, 0x2, 0xe1, 0x29, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe0, 0x3, 
    0x2, 0x2, 0x2, 0xe3, 0xe4, 0x7, 0x8, 0x2, 0x2, 0xe4, 0xe5, 0x7, 0x28, 
    0x2, 0x2, 0xe5, 0xe6, 0x7, 0x9, 0x2, 0x2, 0xe6, 0x2b, 0x3, 0x2, 0x2, 
    0x2, 0xe7, 0xe8, 0x7, 0x8, 0x2, 0x2, 0xe8, 0xe9, 0x5, 0x58, 0x2d, 0x2, 
    0xe9, 0xea, 0x7, 0x9, 0x2, 0x2, 0xea, 0x2d, 0x3, 0x2, 0x2, 0x2, 0xeb, 
    0xec, 0x7, 0x26, 0x2, 0x2, 0xec, 0xf0, 0x7, 0x7, 0x2, 0x2, 0xed, 0xef, 
    0x5, 0x30, 0x19, 0x2, 0xee, 0xed, 0x3, 0x2, 0x2, 0x2, 0xef, 0xf2, 0x3, 
    0x2, 0x2, 0x2, 0xf0, 0xee, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf1, 0x3, 0x2, 
    0x2, 0x2, 0xf1, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf0, 0x3, 0x2, 0x2, 
    0x2, 0xf3, 0xf4, 0x5, 0x32, 0x1a, 0x2, 0xf4, 0xf5, 0x5, 0x46, 0x24, 
    0x2, 0xf5, 0x31, 0x3, 0x2, 0x2, 0x2, 0xf6, 0xf7, 0x7, 0x27, 0x2, 0x2, 
    0xf7, 0x33, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x9, 0x2, 0x2, 0x2, 0xf9, 
    0x35, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x5, 0x3a, 0x1e, 0x2, 0xfb, 0xfd, 
    0x7, 0x3, 0x2, 0x2, 0xfc, 0xfe, 0x5, 0x3c, 0x1f, 0x2, 0xfd, 0xfc, 0x3, 
    0x2, 0x2, 0x2, 0xfd, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xfe, 0xff, 0x3, 0x2, 
    0x2, 0x2, 0xff, 0x100, 0x7, 0x5, 0x2, 0x2, 0x100, 0x37, 0x3, 0x2, 0x2, 
    0x2, 0x101, 0x102, 0x5, 0x3a, 0x1e, 0x2, 0x102, 0x104, 0x7, 0x3, 0x2, 
    0x2, 0x103, 0x105, 0x5, 0x3c, 0x1f, 0x2, 0x104, 0x103, 0x3, 0x2, 0x2, 
    0x2, 0x104, 0x105, 0x3, 0x2, 0x2, 0x2, 0x105, 0x106, 0x3, 0x2, 0x2, 
    0x2, 0x106, 0x107, 0x7, 0x5, 0x2, 0x2, 0x107, 0x39, 0x3, 0x2, 0x2, 0x2, 
    0x108, 0x109, 0x7, 0x27, 0x2, 0x2, 0x109, 0x3b, 0x3, 0x2, 0x2, 0x2, 
    0x10a, 0x10f, 0x5, 0x3e, 0x20, 0x2, 0x10b, 0x10c, 0x7, 0x4, 0x2, 0x2, 
    0x10c, 0x10e, 0x5, 0x3e, 0x20, 0x2, 0x10d, 0x10b, 0x3, 0x2, 0x2, 0x2, 
    0x10e, 0x111, 0x3, 0x2, 0x2, 0x2, 0x10f, 0x10d, 0x3, 0x2, 0x2, 0x2, 
    0x10f, 0x110, 0x3, 0x2, 0x2, 0x2, 0x110, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x111, 
    0x10f, 0x3, 0x2, 0x2, 0x2, 0x112, 0x117, 0x5, 0x58, 0x2d, 0x2, 0x113, 
    0x114, 0x5, 0x32, 0x1a, 0x2, 0x114, 0x115, 0x7, 0xc, 0x2, 0x2, 0x115, 
    0x117, 0x3, 0x2, 0x2, 0x2, 0x116, 0x112, 0x3, 0x2, 0x2, 0x2, 0x116, 
    0x113, 0x3, 0x2, 0x2, 0x2, 0x117, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x118, 0x121, 
    0x5, 0x46, 0x24, 0x2, 0x119, 0x121, 0x5, 0x4c, 0x27, 0x2, 0x11a, 0x121, 
    0x5, 0x52, 0x2a, 0x2, 0x11b, 0x121, 0x5, 0x54, 0x2b, 0x2, 0x11c, 0x121, 
    0x5, 0x56, 0x2c, 0x2, 0x11d, 0x121, 0x5, 0x48, 0x25, 0x2, 0x11e, 0x121, 
    0x5, 0x38, 0x1d, 0x2, 0x11f, 0x121, 0x5, 0x42, 0x22, 0x2, 0x120, 0x118, 
    0x3, 0x2, 0x2, 0x2, 0x120, 0x119, 0x3, 0x2, 0x2, 0x2, 0x120, 0x11a, 
    0x3, 0x2, 0x2, 0x2, 0x120, 0x11b, 0x3, 0x2, 0x2, 0x2, 0x120, 0x11c, 
    0x3, 0x2, 0x2, 0x2, 0x120, 0x11d, 0x3, 0x2, 0x2, 0x2, 0x120, 0x11e, 
    0x3, 0x2, 0x2, 0x2, 0x120, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x121, 0x41, 0x3, 
    0x2, 0x2, 0x2, 0x122, 0x123, 0x5, 0x26, 0x14, 0x2, 0x123, 0x124, 0x7, 
    0xc, 0x2, 0x2, 0x124, 0x125, 0x5, 0x44, 0x23, 0x2, 0x125, 0x127, 0x7, 
    0x3, 0x2, 0x2, 0x126, 0x128, 0x5, 0x3c, 0x1f, 0x2, 0x127, 0x126, 0x3, 
    0x2, 0x2, 0x2, 0x127, 0x128, 0x3, 0x2, 0x2, 0x2, 0x128, 0x129, 0x3, 
    0x2, 0x2, 0x2, 0x129, 0x12a, 0x7, 0x5, 0x2, 0x2, 0x12a, 0x43, 0x3, 0x2, 
    0x2, 0x2, 0x12b, 0x12c, 0x7, 0x27, 0x2, 0x2, 0x12c, 0x45, 0x3, 0x2, 
    0x2, 0x2, 0x12d, 0x12e, 0x7, 0xd, 0x2, 0x2, 0x12e, 0x12f, 0x5, 0x4a, 
    0x26, 0x2, 0x12f, 0x130, 0x7, 0xe, 0x2, 0x2, 0x130, 0x47, 0x3, 0x2, 
    0x2, 0x2, 0x131, 0x132, 0x3, 0x2, 0x2, 0x2, 0x132, 0x49, 0x3, 0x2, 0x2, 
    0x2, 0x133, 0x138, 0x5, 0x40, 0x21, 0x2, 0x134, 0x135, 0x7, 0x6, 0x2, 
    0x2, 0x135, 0x137, 0x5, 0x40, 0x21, 0x2, 0x136, 0x134, 0x3, 0x2, 0x2, 
    0x2, 0x137, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x138, 0x136, 0x3, 0x2, 0x2, 
    0x2, 0x138, 0x139, 0x3, 0x2, 0x2, 0x2, 0x139, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x13a, 0x138, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x13c, 0x5, 0x4e, 0x28, 0x2, 
    0x13c, 0x13d, 0x7, 0xf, 0x2, 0x2, 0x13d, 0x13f, 0x5, 0x50, 0x29, 0x2, 
    0x13e, 0x140, 0x7, 0x6, 0x2, 0x2, 0x13f, 0x13e, 0x3, 0x2, 0x2, 0x2, 
    0x13f, 0x140, 0x3, 0x2, 0x2, 0x2, 0x140, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x141, 
    0x142, 0x5, 0x26, 0x14, 0x2, 0x142, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x143, 
    0x144, 0x5, 0x58, 0x2d, 0x2, 0x144, 0x51, 0x3, 0x2, 0x2, 0x2, 0x145, 
    0x146, 0x7, 0x1e, 0x2, 0x2, 0x146, 0x147, 0x7, 0x3, 0x2, 0x2, 0x147, 
    0x148, 0x5, 0x58, 0x2d, 0x2, 0x148, 0x149, 0x7, 0x5, 0x2, 0x2, 0x149, 
    0x14c, 0x5, 0x40, 0x21, 0x2, 0x14a, 0x14b, 0x7, 0x1f, 0x2, 0x2, 0x14b, 
    0x14d, 0x5, 0x40, 0x21, 0x2, 0x14c, 0x14a, 0x3, 0x2, 0x2, 0x2, 0x14c, 
    0x14d, 0x3, 0x2, 0x2, 0x2, 0x14d, 0x53, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14f, 
    0x7, 0x1c, 0x2, 0x2, 0x14f, 0x150, 0x7, 0x3, 0x2, 0x2, 0x150, 0x151, 
    0x5, 0x58, 0x2d, 0x2, 0x151, 0x152, 0x7, 0x5, 0x2, 0x2, 0x152, 0x153, 
    0x5, 0x40, 0x21, 0x2, 0x153, 0x55, 0x3, 0x2, 0x2, 0x2, 0x154, 0x155, 
    0x7, 0x1d, 0x2, 0x2, 0x155, 0x156, 0x7, 0x3, 0x2, 0x2, 0x156, 0x157, 
    0x5, 0x26, 0x14, 0x2, 0x157, 0x158, 0x7, 0xf, 0x2, 0x2, 0x158, 0x159, 
    0x5, 0x58, 0x2d, 0x2, 0x159, 0x15a, 0x9, 0x3, 0x2, 0x2, 0x15a, 0x15b, 
    0x5, 0x58, 0x2d, 0x2, 0x15b, 0x15c, 0x7, 0x5, 0x2, 0x2, 0x15c, 0x15d, 
    0x5, 0x40, 0x21, 0x2, 0x15d, 0x57, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x162, 
    0x5, 0x5a, 0x2e, 0x2, 0x15f, 0x160, 0x5, 0x68, 0x35, 0x2, 0x160, 0x161, 
    0x5, 0x5a, 0x2e, 0x2, 0x161, 0x163, 0x3, 0x2, 0x2, 0x2, 0x162, 0x15f, 
    0x3, 0x2, 0x2, 0x2, 0x162, 0x163, 0x3, 0x2, 0x2, 0x2, 0x163, 0x59, 0x3, 
    0x2, 0x2, 0x2, 0x164, 0x166, 0x5, 0x34, 0x1b, 0x2, 0x165, 0x164, 0x3, 
    0x2, 0x2, 0x2, 0x165, 0x166, 0x3, 0x2, 0x2, 0x2, 0x166, 0x167, 0x3, 
    0x2, 0x2, 0x2, 0x167, 0x16d, 0x5, 0x5c, 0x2f, 0x2, 0x168, 0x169, 0x5, 
    0x6a, 0x36, 0x2, 0x169, 0x16a, 0x5, 0x5c, 0x2f, 0x2, 0x16a, 0x16c, 0x3, 
    0x2, 0x2, 0x2, 0x16b, 0x168, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x16f, 0x3, 
    0x2, 0x2, 0x2, 0x16d, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x16d, 0x16e, 0x3, 
    0x2, 0x2, 0x2, 0x16e, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x16d, 0x3, 0x2, 
    0x2, 0x2, 0x170, 0x176, 0x5, 0x5e, 0x30, 0x2, 0x171, 0x172, 0x5, 0x6c, 
    0x37, 0x2, 0x172, 0x173, 0x5, 0x5e, 0x30, 0x2, 0x173, 0x175, 0x3, 0x2, 
    0x2, 0x2, 0x174, 0x171, 0x3, 0x2, 0x2, 0x2, 0x175, 0x178, 0x3, 0x2, 
    0x2, 0x2, 0x176, 0x174, 0x3, 0x2, 0x2, 0x2, 0x176, 0x177, 0x3, 0x2, 
    0x2, 0x2, 0x177, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x178, 0x176, 0x3, 0x2, 0x2, 
    0x2, 0x179, 0x185, 0x5, 0x26, 0x14, 0x2, 0x17a, 0x185, 0x5, 0x60, 0x31, 
    0x2, 0x17b, 0x185, 0x5, 0x64, 0x33, 0x2, 0x17c, 0x185, 0x5, 0x66, 0x34, 
    0x2, 0x17d, 0x185, 0x5, 0x36, 0x1c, 0x2, 0x17e, 0x17f, 0x7, 0x10, 0x2, 
    0x2, 0x17f, 0x185, 0x5, 0x5e, 0x30, 0x2, 0x180, 0x181, 0x7, 0x3, 0x2, 
    0x2, 0x181, 0x182, 0x5, 0x58, 0x2d, 0x2, 0x182, 0x183, 0x7, 0x5, 0x2, 
    0x2, 0x183, 0x185, 0x3, 0x2, 0x2, 0x2, 0x184, 0x179, 0x3, 0x2, 0x2, 
    0x2, 0x184, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x184, 0x17b, 0x3, 0x2, 0x2, 
    0x2, 0x184, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x184, 0x17d, 0x3, 0x2, 0x2, 
    0x2, 0x184, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x184, 0x180, 0x3, 0x2, 0x2, 
    0x2, 0x185, 0x5f, 0x3, 0x2, 0x2, 0x2, 0x186, 0x188, 0x5, 0x34, 0x1b, 
    0x2, 0x187, 0x186, 0x3, 0x2, 0x2, 0x2, 0x187, 0x188, 0x3, 0x2, 0x2, 
    0x2, 0x188, 0x189, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18a, 0x5, 0x62, 0x32, 
    0x2, 0x18a, 0x61, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x18c, 0x9, 0x4, 0x2, 0x2, 
    0x18c, 0x63, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18e, 0x7, 0x2d, 0x2, 0x2, 
    0x18e, 0x65, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x7, 0x2e, 0x2, 0x2, 
    0x190, 0x67, 0x3, 0x2, 0x2, 0x2, 0x191, 0x192, 0x9, 0x5, 0x2, 0x2, 0x192, 
    0x69, 0x3, 0x2, 0x2, 0x2, 0x193, 0x194, 0x9, 0x6, 0x2, 0x2, 0x194, 0x6b, 
    0x3, 0x2, 0x2, 0x2, 0x195, 0x196, 0x9, 0x7, 0x2, 0x2, 0x196, 0x6d, 0x3, 
    0x2, 0x2, 0x2, 0x1f, 0x74, 0x80, 0x83, 0x92, 0x9f, 0xa4, 0xad, 0xb4, 
    0xba, 0xc3, 0xce, 0xd9, 0xe0, 0xf0, 0xfd, 0x104, 0x10f, 0x116, 0x120, 
    0x127, 0x138, 0x13f, 0x14c, 0x162, 0x165, 0x16d, 0x176, 0x184, 0x187, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

GooeyParser::Initializer GooeyParser::_init;
