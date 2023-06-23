
// Generated from /home/aurora1/homework3/h3/grammar/GoParser.g4 by ANTLR 4.9.3


#include "GoParserListener.h"

#include "GoParser.h"


using namespace antlrcpp;
using namespace antlr4;

GoParser::GoParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

GoParser::~GoParser() {
  delete _interpreter;
}

std::string GoParser::getGrammarFileName() const {
  return "GoParser.g4";
}

const std::vector<std::string>& GoParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& GoParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- SourceFileContext ------------------------------------------------------------------

GoParser::SourceFileContext::SourceFileContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::PackageClauseContext* GoParser::SourceFileContext::packageClause() {
  return getRuleContext<GoParser::PackageClauseContext>(0);
}

tree::TerminalNode* GoParser::SourceFileContext::EOF() {
  return getToken(GoParser::EOF, 0);
}

std::vector<GoParser::EossContext *> GoParser::SourceFileContext::eoss() {
  return getRuleContexts<GoParser::EossContext>();
}

GoParser::EossContext* GoParser::SourceFileContext::eoss(size_t i) {
  return getRuleContext<GoParser::EossContext>(i);
}

std::vector<GoParser::ImportDeclContext *> GoParser::SourceFileContext::importDecl() {
  return getRuleContexts<GoParser::ImportDeclContext>();
}

GoParser::ImportDeclContext* GoParser::SourceFileContext::importDecl(size_t i) {
  return getRuleContext<GoParser::ImportDeclContext>(i);
}

std::vector<GoParser::FunctionDeclContext *> GoParser::SourceFileContext::functionDecl() {
  return getRuleContexts<GoParser::FunctionDeclContext>();
}

GoParser::FunctionDeclContext* GoParser::SourceFileContext::functionDecl(size_t i) {
  return getRuleContext<GoParser::FunctionDeclContext>(i);
}

std::vector<GoParser::MethodDeclContext *> GoParser::SourceFileContext::methodDecl() {
  return getRuleContexts<GoParser::MethodDeclContext>();
}

GoParser::MethodDeclContext* GoParser::SourceFileContext::methodDecl(size_t i) {
  return getRuleContext<GoParser::MethodDeclContext>(i);
}

std::vector<GoParser::DeclarationContext *> GoParser::SourceFileContext::declaration() {
  return getRuleContexts<GoParser::DeclarationContext>();
}

GoParser::DeclarationContext* GoParser::SourceFileContext::declaration(size_t i) {
  return getRuleContext<GoParser::DeclarationContext>(i);
}


size_t GoParser::SourceFileContext::getRuleIndex() const {
  return GoParser::RuleSourceFile;
}

void GoParser::SourceFileContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSourceFile(this);
}

void GoParser::SourceFileContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSourceFile(this);
}

GoParser::SourceFileContext* GoParser::sourceFile() {
  SourceFileContext *_localctx = _tracker.createInstance<SourceFileContext>(_ctx, getState());
  enterRule(_localctx, 0, GoParser::RuleSourceFile);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198);
    packageClause();
    setState(202);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GoParser::SEMI)
      | (1ULL << GoParser::HUANHANG)
      | (1ULL << GoParser::HUANHANGG)
      | (1ULL << GoParser::EOSSS))) != 0)) {
      setState(199);
      eoss();
      setState(204);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(214);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GoParser::IMPORT) {
      setState(205);
      importDecl();
      setState(209);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GoParser::SEMI)
        | (1ULL << GoParser::HUANHANG)
        | (1ULL << GoParser::HUANHANGG)
        | (1ULL << GoParser::EOSSS))) != 0)) {
        setState(206);
        eoss();
        setState(211);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(216);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(230);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GoParser::FUNC)
      | (1ULL << GoParser::CONST)
      | (1ULL << GoParser::TYPE)
      | (1ULL << GoParser::VAR))) != 0)) {
      setState(220);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
      case 1: {
        setState(217);
        functionDecl();
        break;
      }

      case 2: {
        setState(218);
        methodDecl();
        break;
      }

      case 3: {
        setState(219);
        declaration();
        break;
      }

      default:
        break;
      }
      setState(225);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GoParser::SEMI)
        | (1ULL << GoParser::HUANHANG)
        | (1ULL << GoParser::HUANHANGG)
        | (1ULL << GoParser::EOSSS))) != 0)) {
        setState(222);
        eoss();
        setState(227);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(232);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(233);
    match(GoParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PackageClauseContext ------------------------------------------------------------------

GoParser::PackageClauseContext::PackageClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::PackageClauseContext::PACKAGE() {
  return getToken(GoParser::PACKAGE, 0);
}

tree::TerminalNode* GoParser::PackageClauseContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}


size_t GoParser::PackageClauseContext::getRuleIndex() const {
  return GoParser::RulePackageClause;
}

void GoParser::PackageClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPackageClause(this);
}

void GoParser::PackageClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPackageClause(this);
}

GoParser::PackageClauseContext* GoParser::packageClause() {
  PackageClauseContext *_localctx = _tracker.createInstance<PackageClauseContext>(_ctx, getState());
  enterRule(_localctx, 2, GoParser::RulePackageClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(235);
    match(GoParser::PACKAGE);
    setState(236);
    antlrcpp::downCast<PackageClauseContext *>(_localctx)->packageName = match(GoParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportDeclContext ------------------------------------------------------------------

GoParser::ImportDeclContext::ImportDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::ImportDeclContext::IMPORT() {
  return getToken(GoParser::IMPORT, 0);
}

std::vector<GoParser::ImportSpecContext *> GoParser::ImportDeclContext::importSpec() {
  return getRuleContexts<GoParser::ImportSpecContext>();
}

GoParser::ImportSpecContext* GoParser::ImportDeclContext::importSpec(size_t i) {
  return getRuleContext<GoParser::ImportSpecContext>(i);
}

tree::TerminalNode* GoParser::ImportDeclContext::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

tree::TerminalNode* GoParser::ImportDeclContext::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}

std::vector<GoParser::EossContext *> GoParser::ImportDeclContext::eoss() {
  return getRuleContexts<GoParser::EossContext>();
}

GoParser::EossContext* GoParser::ImportDeclContext::eoss(size_t i) {
  return getRuleContext<GoParser::EossContext>(i);
}


size_t GoParser::ImportDeclContext::getRuleIndex() const {
  return GoParser::RuleImportDecl;
}

void GoParser::ImportDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportDecl(this);
}

void GoParser::ImportDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportDecl(this);
}

GoParser::ImportDeclContext* GoParser::importDecl() {
  ImportDeclContext *_localctx = _tracker.createInstance<ImportDeclContext>(_ctx, getState());
  enterRule(_localctx, 4, GoParser::RuleImportDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(238);
    match(GoParser::IMPORT);
    setState(250);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::IDENTIFIER:
      case GoParser::DOT:
      case GoParser::RAW_STRING_LIT:
      case GoParser::INTERPRETED_STRING_LIT: {
        setState(239);
        importSpec();
        break;
      }

      case GoParser::L_PAREN: {
        setState(240);
        match(GoParser::L_PAREN);
        setState(246);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (((((_la - 27) & ~ 0x3fULL) == 0) &&
          ((1ULL << (_la - 27)) & ((1ULL << (GoParser::IDENTIFIER - 27))
          | (1ULL << (GoParser::DOT - 27))
          | (1ULL << (GoParser::RAW_STRING_LIT - 27))
          | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 27)))) != 0)) {
          setState(241);
          importSpec();
          setState(242);
          eoss();
          setState(248);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(249);
        match(GoParser::R_PAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportSpecContext ------------------------------------------------------------------

GoParser::ImportSpecContext::ImportSpecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ImportPathContext* GoParser::ImportSpecContext::importPath() {
  return getRuleContext<GoParser::ImportPathContext>(0);
}

tree::TerminalNode* GoParser::ImportSpecContext::DOT() {
  return getToken(GoParser::DOT, 0);
}

tree::TerminalNode* GoParser::ImportSpecContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}


size_t GoParser::ImportSpecContext::getRuleIndex() const {
  return GoParser::RuleImportSpec;
}

void GoParser::ImportSpecContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportSpec(this);
}

void GoParser::ImportSpecContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportSpec(this);
}

GoParser::ImportSpecContext* GoParser::importSpec() {
  ImportSpecContext *_localctx = _tracker.createInstance<ImportSpecContext>(_ctx, getState());
  enterRule(_localctx, 6, GoParser::RuleImportSpec);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(253);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GoParser::IDENTIFIER

    || _la == GoParser::DOT) {
      setState(252);
      antlrcpp::downCast<ImportSpecContext *>(_localctx)->alias = _input->LT(1);
      _la = _input->LA(1);
      if (!(_la == GoParser::IDENTIFIER

      || _la == GoParser::DOT)) {
        antlrcpp::downCast<ImportSpecContext *>(_localctx)->alias = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(255);
    importPath();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportPathContext ------------------------------------------------------------------

GoParser::ImportPathContext::ImportPathContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::String_Context* GoParser::ImportPathContext::string_() {
  return getRuleContext<GoParser::String_Context>(0);
}


size_t GoParser::ImportPathContext::getRuleIndex() const {
  return GoParser::RuleImportPath;
}

void GoParser::ImportPathContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportPath(this);
}

void GoParser::ImportPathContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportPath(this);
}

GoParser::ImportPathContext* GoParser::importPath() {
  ImportPathContext *_localctx = _tracker.createInstance<ImportPathContext>(_ctx, getState());
  enterRule(_localctx, 8, GoParser::RuleImportPath);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(257);
    string_();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

GoParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ConstDeclContext* GoParser::DeclarationContext::constDecl() {
  return getRuleContext<GoParser::ConstDeclContext>(0);
}

GoParser::TypeDeclContext* GoParser::DeclarationContext::typeDecl() {
  return getRuleContext<GoParser::TypeDeclContext>(0);
}

GoParser::VarDeclContext* GoParser::DeclarationContext::varDecl() {
  return getRuleContext<GoParser::VarDeclContext>(0);
}


size_t GoParser::DeclarationContext::getRuleIndex() const {
  return GoParser::RuleDeclaration;
}

void GoParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void GoParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}

GoParser::DeclarationContext* GoParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 10, GoParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(262);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::CONST: {
        enterOuterAlt(_localctx, 1);
        setState(259);
        constDecl();
        break;
      }

      case GoParser::TYPE: {
        enterOuterAlt(_localctx, 2);
        setState(260);
        typeDecl();
        break;
      }

      case GoParser::VAR: {
        enterOuterAlt(_localctx, 3);
        setState(261);
        varDecl();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstDeclContext ------------------------------------------------------------------

GoParser::ConstDeclContext::ConstDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::ConstDeclContext::CONST() {
  return getToken(GoParser::CONST, 0);
}

std::vector<GoParser::ConstSpecContext *> GoParser::ConstDeclContext::constSpec() {
  return getRuleContexts<GoParser::ConstSpecContext>();
}

GoParser::ConstSpecContext* GoParser::ConstDeclContext::constSpec(size_t i) {
  return getRuleContext<GoParser::ConstSpecContext>(i);
}

tree::TerminalNode* GoParser::ConstDeclContext::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

tree::TerminalNode* GoParser::ConstDeclContext::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}

std::vector<GoParser::EossContext *> GoParser::ConstDeclContext::eoss() {
  return getRuleContexts<GoParser::EossContext>();
}

GoParser::EossContext* GoParser::ConstDeclContext::eoss(size_t i) {
  return getRuleContext<GoParser::EossContext>(i);
}


size_t GoParser::ConstDeclContext::getRuleIndex() const {
  return GoParser::RuleConstDecl;
}

void GoParser::ConstDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstDecl(this);
}

void GoParser::ConstDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstDecl(this);
}

GoParser::ConstDeclContext* GoParser::constDecl() {
  ConstDeclContext *_localctx = _tracker.createInstance<ConstDeclContext>(_ctx, getState());
  enterRule(_localctx, 12, GoParser::RuleConstDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(264);
    match(GoParser::CONST);
    setState(276);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::IDENTIFIER: {
        setState(265);
        constSpec();
        break;
      }

      case GoParser::L_PAREN: {
        setState(266);
        match(GoParser::L_PAREN);
        setState(272);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == GoParser::IDENTIFIER) {
          setState(267);
          constSpec();
          setState(268);
          eoss();
          setState(274);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(275);
        match(GoParser::R_PAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstSpecContext ------------------------------------------------------------------

GoParser::ConstSpecContext::ConstSpecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::IdentifierListContext* GoParser::ConstSpecContext::identifierList() {
  return getRuleContext<GoParser::IdentifierListContext>(0);
}

tree::TerminalNode* GoParser::ConstSpecContext::ASSIGN() {
  return getToken(GoParser::ASSIGN, 0);
}

GoParser::ExpressionListContext* GoParser::ConstSpecContext::expressionList() {
  return getRuleContext<GoParser::ExpressionListContext>(0);
}

GoParser::Type_Context* GoParser::ConstSpecContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}


size_t GoParser::ConstSpecContext::getRuleIndex() const {
  return GoParser::RuleConstSpec;
}

void GoParser::ConstSpecContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConstSpec(this);
}

void GoParser::ConstSpecContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConstSpec(this);
}

GoParser::ConstSpecContext* GoParser::constSpec() {
  ConstSpecContext *_localctx = _tracker.createInstance<ConstSpecContext>(_ctx, getState());
  enterRule(_localctx, 14, GoParser::RuleConstSpec);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(278);
    identifierList();
    setState(284);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 13, _ctx)) {
    case 1: {
      setState(280);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (((((_la - 3) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 3)) & ((1ULL << (GoParser::FUNC - 3))
        | (1ULL << (GoParser::INTERFACE - 3))
        | (1ULL << (GoParser::MAP - 3))
        | (1ULL << (GoParser::STRUCT - 3))
        | (1ULL << (GoParser::CHAN - 3))
        | (1ULL << (GoParser::IDENTIFIER - 3))
        | (1ULL << (GoParser::L_PAREN - 3))
        | (1ULL << (GoParser::L_BRACKET - 3))
        | (1ULL << (GoParser::STAR - 3))
        | (1ULL << (GoParser::RECEIVE - 3)))) != 0)) {
        setState(279);
        type_();
      }
      setState(282);
      match(GoParser::ASSIGN);
      setState(283);
      expressionList();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentifierListContext ------------------------------------------------------------------

GoParser::IdentifierListContext::IdentifierListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> GoParser::IdentifierListContext::IDENTIFIER() {
  return getTokens(GoParser::IDENTIFIER);
}

tree::TerminalNode* GoParser::IdentifierListContext::IDENTIFIER(size_t i) {
  return getToken(GoParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> GoParser::IdentifierListContext::COMMA() {
  return getTokens(GoParser::COMMA);
}

tree::TerminalNode* GoParser::IdentifierListContext::COMMA(size_t i) {
  return getToken(GoParser::COMMA, i);
}


size_t GoParser::IdentifierListContext::getRuleIndex() const {
  return GoParser::RuleIdentifierList;
}

void GoParser::IdentifierListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdentifierList(this);
}

void GoParser::IdentifierListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdentifierList(this);
}

GoParser::IdentifierListContext* GoParser::identifierList() {
  IdentifierListContext *_localctx = _tracker.createInstance<IdentifierListContext>(_ctx, getState());
  enterRule(_localctx, 16, GoParser::RuleIdentifierList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(286);
    match(GoParser::IDENTIFIER);
    setState(291);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GoParser::COMMA) {
      setState(287);
      match(GoParser::COMMA);
      setState(288);
      match(GoParser::IDENTIFIER);
      setState(293);
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

//----------------- ExpressionListContext ------------------------------------------------------------------

GoParser::ExpressionListContext::ExpressionListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GoParser::ExpressionContext *> GoParser::ExpressionListContext::expression() {
  return getRuleContexts<GoParser::ExpressionContext>();
}

GoParser::ExpressionContext* GoParser::ExpressionListContext::expression(size_t i) {
  return getRuleContext<GoParser::ExpressionContext>(i);
}

std::vector<tree::TerminalNode *> GoParser::ExpressionListContext::COMMA() {
  return getTokens(GoParser::COMMA);
}

tree::TerminalNode* GoParser::ExpressionListContext::COMMA(size_t i) {
  return getToken(GoParser::COMMA, i);
}


size_t GoParser::ExpressionListContext::getRuleIndex() const {
  return GoParser::RuleExpressionList;
}

void GoParser::ExpressionListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionList(this);
}

void GoParser::ExpressionListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionList(this);
}

GoParser::ExpressionListContext* GoParser::expressionList() {
  ExpressionListContext *_localctx = _tracker.createInstance<ExpressionListContext>(_ctx, getState());
  enterRule(_localctx, 18, GoParser::RuleExpressionList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(294);
    expression(0);
    setState(299);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(295);
        match(GoParser::COMMA);
        setState(296);
        expression(0); 
      }
      setState(301);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeDeclContext ------------------------------------------------------------------

GoParser::TypeDeclContext::TypeDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::TypeDeclContext::TYPE() {
  return getToken(GoParser::TYPE, 0);
}

std::vector<GoParser::TypeSpecContext *> GoParser::TypeDeclContext::typeSpec() {
  return getRuleContexts<GoParser::TypeSpecContext>();
}

GoParser::TypeSpecContext* GoParser::TypeDeclContext::typeSpec(size_t i) {
  return getRuleContext<GoParser::TypeSpecContext>(i);
}

tree::TerminalNode* GoParser::TypeDeclContext::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

tree::TerminalNode* GoParser::TypeDeclContext::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}

std::vector<GoParser::EossContext *> GoParser::TypeDeclContext::eoss() {
  return getRuleContexts<GoParser::EossContext>();
}

GoParser::EossContext* GoParser::TypeDeclContext::eoss(size_t i) {
  return getRuleContext<GoParser::EossContext>(i);
}


size_t GoParser::TypeDeclContext::getRuleIndex() const {
  return GoParser::RuleTypeDecl;
}

void GoParser::TypeDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeDecl(this);
}

void GoParser::TypeDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeDecl(this);
}

GoParser::TypeDeclContext* GoParser::typeDecl() {
  TypeDeclContext *_localctx = _tracker.createInstance<TypeDeclContext>(_ctx, getState());
  enterRule(_localctx, 20, GoParser::RuleTypeDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(302);
    match(GoParser::TYPE);
    setState(314);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::IDENTIFIER: {
        setState(303);
        typeSpec();
        break;
      }

      case GoParser::L_PAREN: {
        setState(304);
        match(GoParser::L_PAREN);
        setState(310);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == GoParser::IDENTIFIER) {
          setState(305);
          typeSpec();
          setState(306);
          eoss();
          setState(312);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(313);
        match(GoParser::R_PAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSpecContext ------------------------------------------------------------------

GoParser::TypeSpecContext::TypeSpecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::TypeSpecContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}

GoParser::Type_Context* GoParser::TypeSpecContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}

tree::TerminalNode* GoParser::TypeSpecContext::ASSIGN() {
  return getToken(GoParser::ASSIGN, 0);
}


size_t GoParser::TypeSpecContext::getRuleIndex() const {
  return GoParser::RuleTypeSpec;
}

void GoParser::TypeSpecContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeSpec(this);
}

void GoParser::TypeSpecContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeSpec(this);
}

GoParser::TypeSpecContext* GoParser::typeSpec() {
  TypeSpecContext *_localctx = _tracker.createInstance<TypeSpecContext>(_ctx, getState());
  enterRule(_localctx, 22, GoParser::RuleTypeSpec);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(316);
    match(GoParser::IDENTIFIER);
    setState(318);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GoParser::ASSIGN) {
      setState(317);
      match(GoParser::ASSIGN);
    }
    setState(320);
    type_();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclContext ------------------------------------------------------------------

GoParser::FunctionDeclContext::FunctionDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::FunctionDeclContext::FUNC() {
  return getToken(GoParser::FUNC, 0);
}

tree::TerminalNode* GoParser::FunctionDeclContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}

GoParser::SignatureContext* GoParser::FunctionDeclContext::signature() {
  return getRuleContext<GoParser::SignatureContext>(0);
}

GoParser::BlockContext* GoParser::FunctionDeclContext::block() {
  return getRuleContext<GoParser::BlockContext>(0);
}


size_t GoParser::FunctionDeclContext::getRuleIndex() const {
  return GoParser::RuleFunctionDecl;
}

void GoParser::FunctionDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDecl(this);
}

void GoParser::FunctionDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDecl(this);
}

GoParser::FunctionDeclContext* GoParser::functionDecl() {
  FunctionDeclContext *_localctx = _tracker.createInstance<FunctionDeclContext>(_ctx, getState());
  enterRule(_localctx, 24, GoParser::RuleFunctionDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(322);
    match(GoParser::FUNC);
    setState(323);
    match(GoParser::IDENTIFIER);

    setState(324);
    signature();
    setState(326);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GoParser::L_CURLY) {
      setState(325);
      block();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodDeclContext ------------------------------------------------------------------

GoParser::MethodDeclContext::MethodDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::MethodDeclContext::FUNC() {
  return getToken(GoParser::FUNC, 0);
}

GoParser::ReceiverContext* GoParser::MethodDeclContext::receiver() {
  return getRuleContext<GoParser::ReceiverContext>(0);
}

tree::TerminalNode* GoParser::MethodDeclContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}

GoParser::SignatureContext* GoParser::MethodDeclContext::signature() {
  return getRuleContext<GoParser::SignatureContext>(0);
}

GoParser::BlockContext* GoParser::MethodDeclContext::block() {
  return getRuleContext<GoParser::BlockContext>(0);
}


size_t GoParser::MethodDeclContext::getRuleIndex() const {
  return GoParser::RuleMethodDecl;
}

void GoParser::MethodDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodDecl(this);
}

void GoParser::MethodDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodDecl(this);
}

GoParser::MethodDeclContext* GoParser::methodDecl() {
  MethodDeclContext *_localctx = _tracker.createInstance<MethodDeclContext>(_ctx, getState());
  enterRule(_localctx, 26, GoParser::RuleMethodDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(328);
    match(GoParser::FUNC);
    setState(329);
    receiver();
    setState(330);
    match(GoParser::IDENTIFIER);

    setState(331);
    signature();
    setState(333);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GoParser::L_CURLY) {
      setState(332);
      block();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReceiverContext ------------------------------------------------------------------

GoParser::ReceiverContext::ReceiverContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ParametersContext* GoParser::ReceiverContext::parameters() {
  return getRuleContext<GoParser::ParametersContext>(0);
}


size_t GoParser::ReceiverContext::getRuleIndex() const {
  return GoParser::RuleReceiver;
}

void GoParser::ReceiverContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReceiver(this);
}

void GoParser::ReceiverContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReceiver(this);
}

GoParser::ReceiverContext* GoParser::receiver() {
  ReceiverContext *_localctx = _tracker.createInstance<ReceiverContext>(_ctx, getState());
  enterRule(_localctx, 28, GoParser::RuleReceiver);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(335);
    parameters();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclContext ------------------------------------------------------------------

GoParser::VarDeclContext::VarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::VarDeclContext::VAR() {
  return getToken(GoParser::VAR, 0);
}

std::vector<GoParser::VarSpecContext *> GoParser::VarDeclContext::varSpec() {
  return getRuleContexts<GoParser::VarSpecContext>();
}

GoParser::VarSpecContext* GoParser::VarDeclContext::varSpec(size_t i) {
  return getRuleContext<GoParser::VarSpecContext>(i);
}

tree::TerminalNode* GoParser::VarDeclContext::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

tree::TerminalNode* GoParser::VarDeclContext::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}

std::vector<GoParser::EossContext *> GoParser::VarDeclContext::eoss() {
  return getRuleContexts<GoParser::EossContext>();
}

GoParser::EossContext* GoParser::VarDeclContext::eoss(size_t i) {
  return getRuleContext<GoParser::EossContext>(i);
}


size_t GoParser::VarDeclContext::getRuleIndex() const {
  return GoParser::RuleVarDecl;
}

void GoParser::VarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDecl(this);
}

void GoParser::VarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDecl(this);
}

GoParser::VarDeclContext* GoParser::varDecl() {
  VarDeclContext *_localctx = _tracker.createInstance<VarDeclContext>(_ctx, getState());
  enterRule(_localctx, 30, GoParser::RuleVarDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(337);
    match(GoParser::VAR);
    setState(349);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::IDENTIFIER: {
        setState(338);
        varSpec();
        break;
      }

      case GoParser::L_PAREN: {
        setState(339);
        match(GoParser::L_PAREN);
        setState(345);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == GoParser::IDENTIFIER) {
          setState(340);
          varSpec();
          setState(341);
          eoss();
          setState(347);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(348);
        match(GoParser::R_PAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarSpecContext ------------------------------------------------------------------

GoParser::VarSpecContext::VarSpecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::IdentifierListContext* GoParser::VarSpecContext::identifierList() {
  return getRuleContext<GoParser::IdentifierListContext>(0);
}

GoParser::Type_Context* GoParser::VarSpecContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}

tree::TerminalNode* GoParser::VarSpecContext::ASSIGN() {
  return getToken(GoParser::ASSIGN, 0);
}

GoParser::ExpressionListContext* GoParser::VarSpecContext::expressionList() {
  return getRuleContext<GoParser::ExpressionListContext>(0);
}


size_t GoParser::VarSpecContext::getRuleIndex() const {
  return GoParser::RuleVarSpec;
}

void GoParser::VarSpecContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarSpec(this);
}

void GoParser::VarSpecContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarSpec(this);
}

GoParser::VarSpecContext* GoParser::varSpec() {
  VarSpecContext *_localctx = _tracker.createInstance<VarSpecContext>(_ctx, getState());
  enterRule(_localctx, 32, GoParser::RuleVarSpec);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(351);
    identifierList();
    setState(359);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::FUNC:
      case GoParser::INTERFACE:
      case GoParser::MAP:
      case GoParser::STRUCT:
      case GoParser::CHAN:
      case GoParser::IDENTIFIER:
      case GoParser::L_PAREN:
      case GoParser::L_BRACKET:
      case GoParser::STAR:
      case GoParser::RECEIVE: {
        setState(352);
        type_();
        setState(355);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == GoParser::ASSIGN) {
          setState(353);
          match(GoParser::ASSIGN);
          setState(354);
          expressionList();
        }
        break;
      }

      case GoParser::ASSIGN: {
        setState(357);
        match(GoParser::ASSIGN);
        setState(358);
        expressionList();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BlockContext ------------------------------------------------------------------

GoParser::BlockContext::BlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::BlockContext::L_CURLY() {
  return getToken(GoParser::L_CURLY, 0);
}

tree::TerminalNode* GoParser::BlockContext::R_CURLY() {
  return getToken(GoParser::R_CURLY, 0);
}

std::vector<GoParser::EossContext *> GoParser::BlockContext::eoss() {
  return getRuleContexts<GoParser::EossContext>();
}

GoParser::EossContext* GoParser::BlockContext::eoss(size_t i) {
  return getRuleContext<GoParser::EossContext>(i);
}

GoParser::StatementListContext* GoParser::BlockContext::statementList() {
  return getRuleContext<GoParser::StatementListContext>(0);
}


size_t GoParser::BlockContext::getRuleIndex() const {
  return GoParser::RuleBlock;
}

void GoParser::BlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBlock(this);
}

void GoParser::BlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBlock(this);
}

GoParser::BlockContext* GoParser::block() {
  BlockContext *_localctx = _tracker.createInstance<BlockContext>(_ctx, getState());
  enterRule(_localctx, 34, GoParser::RuleBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(361);
    match(GoParser::L_CURLY);
    setState(365);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GoParser::SEMI)
      | (1ULL << GoParser::HUANHANG)
      | (1ULL << GoParser::HUANHANGG)
      | (1ULL << GoParser::EOSSS))) != 0)) {
      setState(362);
      eoss();
      setState(367);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(369);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GoParser::BREAK)
      | (1ULL << GoParser::FUNC)
      | (1ULL << GoParser::INTERFACE)
      | (1ULL << GoParser::SELECT)
      | (1ULL << GoParser::DEFER)
      | (1ULL << GoParser::GO)
      | (1ULL << GoParser::MAP)
      | (1ULL << GoParser::STRUCT)
      | (1ULL << GoParser::CHAN)
      | (1ULL << GoParser::GOTO)
      | (1ULL << GoParser::SWITCH)
      | (1ULL << GoParser::CONST)
      | (1ULL << GoParser::FALLTHROUGH)
      | (1ULL << GoParser::IF)
      | (1ULL << GoParser::TYPE)
      | (1ULL << GoParser::CONTINUE)
      | (1ULL << GoParser::FOR)
      | (1ULL << GoParser::RETURN)
      | (1ULL << GoParser::VAR)
      | (1ULL << GoParser::NIL_LIT)
      | (1ULL << GoParser::IDENTIFIER)
      | (1ULL << GoParser::L_PAREN)
      | (1ULL << GoParser::L_CURLY)
      | (1ULL << GoParser::L_BRACKET)
      | (1ULL << GoParser::EXCLAMATION)
      | (1ULL << GoParser::PLUS)
      | (1ULL << GoParser::MINUS)
      | (1ULL << GoParser::CARET))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GoParser::STAR - 64))
      | (1ULL << (GoParser::AMPERSAND - 64))
      | (1ULL << (GoParser::RECEIVE - 64))
      | (1ULL << (GoParser::DECIMAL_LIT - 64))
      | (1ULL << (GoParser::BINARY_LIT - 64))
      | (1ULL << (GoParser::OCTAL_LIT - 64))
      | (1ULL << (GoParser::HEX_LIT - 64))
      | (1ULL << (GoParser::FLOAT_LIT - 64))
      | (1ULL << (GoParser::IMAGINARY_LIT - 64))
      | (1ULL << (GoParser::RUNE_LIT - 64))
      | (1ULL << (GoParser::RAW_STRING_LIT - 64))
      | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
      setState(368);
      statementList();
    }
    setState(371);
    match(GoParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementListContext ------------------------------------------------------------------

GoParser::StatementListContext::StatementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GoParser::StatementContext *> GoParser::StatementListContext::statement() {
  return getRuleContexts<GoParser::StatementContext>();
}

GoParser::StatementContext* GoParser::StatementListContext::statement(size_t i) {
  return getRuleContext<GoParser::StatementContext>(i);
}

std::vector<GoParser::EossContext *> GoParser::StatementListContext::eoss() {
  return getRuleContexts<GoParser::EossContext>();
}

GoParser::EossContext* GoParser::StatementListContext::eoss(size_t i) {
  return getRuleContext<GoParser::EossContext>(i);
}


size_t GoParser::StatementListContext::getRuleIndex() const {
  return GoParser::RuleStatementList;
}

void GoParser::StatementListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatementList(this);
}

void GoParser::StatementListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatementList(this);
}

GoParser::StatementListContext* GoParser::statementList() {
  StatementListContext *_localctx = _tracker.createInstance<StatementListContext>(_ctx, getState());
  enterRule(_localctx, 36, GoParser::RuleStatementList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(379); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(373);
      statement();
      setState(375); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(374);
        eoss();
        setState(377); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GoParser::SEMI)
        | (1ULL << GoParser::HUANHANG)
        | (1ULL << GoParser::HUANHANGG)
        | (1ULL << GoParser::EOSSS))) != 0));
      setState(381); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GoParser::BREAK)
      | (1ULL << GoParser::FUNC)
      | (1ULL << GoParser::INTERFACE)
      | (1ULL << GoParser::SELECT)
      | (1ULL << GoParser::DEFER)
      | (1ULL << GoParser::GO)
      | (1ULL << GoParser::MAP)
      | (1ULL << GoParser::STRUCT)
      | (1ULL << GoParser::CHAN)
      | (1ULL << GoParser::GOTO)
      | (1ULL << GoParser::SWITCH)
      | (1ULL << GoParser::CONST)
      | (1ULL << GoParser::FALLTHROUGH)
      | (1ULL << GoParser::IF)
      | (1ULL << GoParser::TYPE)
      | (1ULL << GoParser::CONTINUE)
      | (1ULL << GoParser::FOR)
      | (1ULL << GoParser::RETURN)
      | (1ULL << GoParser::VAR)
      | (1ULL << GoParser::NIL_LIT)
      | (1ULL << GoParser::IDENTIFIER)
      | (1ULL << GoParser::L_PAREN)
      | (1ULL << GoParser::L_CURLY)
      | (1ULL << GoParser::L_BRACKET)
      | (1ULL << GoParser::EXCLAMATION)
      | (1ULL << GoParser::PLUS)
      | (1ULL << GoParser::MINUS)
      | (1ULL << GoParser::CARET))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GoParser::STAR - 64))
      | (1ULL << (GoParser::AMPERSAND - 64))
      | (1ULL << (GoParser::RECEIVE - 64))
      | (1ULL << (GoParser::DECIMAL_LIT - 64))
      | (1ULL << (GoParser::BINARY_LIT - 64))
      | (1ULL << (GoParser::OCTAL_LIT - 64))
      | (1ULL << (GoParser::HEX_LIT - 64))
      | (1ULL << (GoParser::FLOAT_LIT - 64))
      | (1ULL << (GoParser::IMAGINARY_LIT - 64))
      | (1ULL << (GoParser::RUNE_LIT - 64))
      | (1ULL << (GoParser::RAW_STRING_LIT - 64))
      | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0));
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

GoParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::DeclarationContext* GoParser::StatementContext::declaration() {
  return getRuleContext<GoParser::DeclarationContext>(0);
}

GoParser::LabeledStmtContext* GoParser::StatementContext::labeledStmt() {
  return getRuleContext<GoParser::LabeledStmtContext>(0);
}

GoParser::SimpleStmtContext* GoParser::StatementContext::simpleStmt() {
  return getRuleContext<GoParser::SimpleStmtContext>(0);
}

GoParser::GoStmtContext* GoParser::StatementContext::goStmt() {
  return getRuleContext<GoParser::GoStmtContext>(0);
}

GoParser::ReturnStmtContext* GoParser::StatementContext::returnStmt() {
  return getRuleContext<GoParser::ReturnStmtContext>(0);
}

GoParser::BreakStmtContext* GoParser::StatementContext::breakStmt() {
  return getRuleContext<GoParser::BreakStmtContext>(0);
}

GoParser::ContinueStmtContext* GoParser::StatementContext::continueStmt() {
  return getRuleContext<GoParser::ContinueStmtContext>(0);
}

GoParser::GotoStmtContext* GoParser::StatementContext::gotoStmt() {
  return getRuleContext<GoParser::GotoStmtContext>(0);
}

GoParser::FallthroughStmtContext* GoParser::StatementContext::fallthroughStmt() {
  return getRuleContext<GoParser::FallthroughStmtContext>(0);
}

GoParser::BlockContext* GoParser::StatementContext::block() {
  return getRuleContext<GoParser::BlockContext>(0);
}

GoParser::IfStmtContext* GoParser::StatementContext::ifStmt() {
  return getRuleContext<GoParser::IfStmtContext>(0);
}

GoParser::SwitchStmtContext* GoParser::StatementContext::switchStmt() {
  return getRuleContext<GoParser::SwitchStmtContext>(0);
}

GoParser::SelectStmtContext* GoParser::StatementContext::selectStmt() {
  return getRuleContext<GoParser::SelectStmtContext>(0);
}

GoParser::ForStmtContext* GoParser::StatementContext::forStmt() {
  return getRuleContext<GoParser::ForStmtContext>(0);
}

GoParser::DeferStmtContext* GoParser::StatementContext::deferStmt() {
  return getRuleContext<GoParser::DeferStmtContext>(0);
}


size_t GoParser::StatementContext::getRuleIndex() const {
  return GoParser::RuleStatement;
}

void GoParser::StatementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStatement(this);
}

void GoParser::StatementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStatement(this);
}

GoParser::StatementContext* GoParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 38, GoParser::RuleStatement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(398);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(383);
      declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(384);
      labeledStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(385);
      simpleStmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(386);
      goStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(387);
      returnStmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(388);
      breakStmt();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(389);
      continueStmt();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(390);
      gotoStmt();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(391);
      fallthroughStmt();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(392);
      block();
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(393);
      ifStmt();
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(394);
      switchStmt();
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(395);
      selectStmt();
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(396);
      forStmt();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(397);
      deferStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpleStmtContext ------------------------------------------------------------------

GoParser::SimpleStmtContext::SimpleStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::SendStmtContext* GoParser::SimpleStmtContext::sendStmt() {
  return getRuleContext<GoParser::SendStmtContext>(0);
}

GoParser::IncDecStmtContext* GoParser::SimpleStmtContext::incDecStmt() {
  return getRuleContext<GoParser::IncDecStmtContext>(0);
}

GoParser::AssignmentContext* GoParser::SimpleStmtContext::assignment() {
  return getRuleContext<GoParser::AssignmentContext>(0);
}

GoParser::ExpressionStmtContext* GoParser::SimpleStmtContext::expressionStmt() {
  return getRuleContext<GoParser::ExpressionStmtContext>(0);
}

GoParser::ShortVarDeclContext* GoParser::SimpleStmtContext::shortVarDecl() {
  return getRuleContext<GoParser::ShortVarDeclContext>(0);
}


size_t GoParser::SimpleStmtContext::getRuleIndex() const {
  return GoParser::RuleSimpleStmt;
}

void GoParser::SimpleStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSimpleStmt(this);
}

void GoParser::SimpleStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSimpleStmt(this);
}

GoParser::SimpleStmtContext* GoParser::simpleStmt() {
  SimpleStmtContext *_localctx = _tracker.createInstance<SimpleStmtContext>(_ctx, getState());
  enterRule(_localctx, 40, GoParser::RuleSimpleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(405);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(400);
      sendStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(401);
      incDecStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(402);
      assignment();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(403);
      expressionStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(404);
      shortVarDecl();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionStmtContext ------------------------------------------------------------------

GoParser::ExpressionStmtContext::ExpressionStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ExpressionContext* GoParser::ExpressionStmtContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}


size_t GoParser::ExpressionStmtContext::getRuleIndex() const {
  return GoParser::RuleExpressionStmt;
}

void GoParser::ExpressionStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpressionStmt(this);
}

void GoParser::ExpressionStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpressionStmt(this);
}

GoParser::ExpressionStmtContext* GoParser::expressionStmt() {
  ExpressionStmtContext *_localctx = _tracker.createInstance<ExpressionStmtContext>(_ctx, getState());
  enterRule(_localctx, 42, GoParser::RuleExpressionStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(407);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SendStmtContext ------------------------------------------------------------------

GoParser::SendStmtContext::SendStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::SendStmtContext::RECEIVE() {
  return getToken(GoParser::RECEIVE, 0);
}

std::vector<GoParser::ExpressionContext *> GoParser::SendStmtContext::expression() {
  return getRuleContexts<GoParser::ExpressionContext>();
}

GoParser::ExpressionContext* GoParser::SendStmtContext::expression(size_t i) {
  return getRuleContext<GoParser::ExpressionContext>(i);
}


size_t GoParser::SendStmtContext::getRuleIndex() const {
  return GoParser::RuleSendStmt;
}

void GoParser::SendStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSendStmt(this);
}

void GoParser::SendStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSendStmt(this);
}

GoParser::SendStmtContext* GoParser::sendStmt() {
  SendStmtContext *_localctx = _tracker.createInstance<SendStmtContext>(_ctx, getState());
  enterRule(_localctx, 44, GoParser::RuleSendStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(409);
    antlrcpp::downCast<SendStmtContext *>(_localctx)->channel = expression(0);
    setState(410);
    match(GoParser::RECEIVE);
    setState(411);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IncDecStmtContext ------------------------------------------------------------------

GoParser::IncDecStmtContext::IncDecStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ExpressionContext* GoParser::IncDecStmtContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

tree::TerminalNode* GoParser::IncDecStmtContext::PLUS_PLUS() {
  return getToken(GoParser::PLUS_PLUS, 0);
}

tree::TerminalNode* GoParser::IncDecStmtContext::MINUS_MINUS() {
  return getToken(GoParser::MINUS_MINUS, 0);
}


size_t GoParser::IncDecStmtContext::getRuleIndex() const {
  return GoParser::RuleIncDecStmt;
}

void GoParser::IncDecStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIncDecStmt(this);
}

void GoParser::IncDecStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIncDecStmt(this);
}

GoParser::IncDecStmtContext* GoParser::incDecStmt() {
  IncDecStmtContext *_localctx = _tracker.createInstance<IncDecStmtContext>(_ctx, getState());
  enterRule(_localctx, 46, GoParser::RuleIncDecStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(413);
    expression(0);
    setState(414);
    _la = _input->LA(1);
    if (!(_la == GoParser::PLUS_PLUS

    || _la == GoParser::MINUS_MINUS)) {
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

//----------------- AssignmentContext ------------------------------------------------------------------

GoParser::AssignmentContext::AssignmentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GoParser::ExpressionListContext *> GoParser::AssignmentContext::expressionList() {
  return getRuleContexts<GoParser::ExpressionListContext>();
}

GoParser::ExpressionListContext* GoParser::AssignmentContext::expressionList(size_t i) {
  return getRuleContext<GoParser::ExpressionListContext>(i);
}

GoParser::Assign_opContext* GoParser::AssignmentContext::assign_op() {
  return getRuleContext<GoParser::Assign_opContext>(0);
}


size_t GoParser::AssignmentContext::getRuleIndex() const {
  return GoParser::RuleAssignment;
}

void GoParser::AssignmentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignment(this);
}

void GoParser::AssignmentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignment(this);
}

GoParser::AssignmentContext* GoParser::assignment() {
  AssignmentContext *_localctx = _tracker.createInstance<AssignmentContext>(_ctx, getState());
  enterRule(_localctx, 48, GoParser::RuleAssignment);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(416);
    expressionList();
    setState(417);
    assign_op();
    setState(418);
    expressionList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assign_opContext ------------------------------------------------------------------

GoParser::Assign_opContext::Assign_opContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::Assign_opContext::ASSIGN() {
  return getToken(GoParser::ASSIGN, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::PLUS() {
  return getToken(GoParser::PLUS, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::MINUS() {
  return getToken(GoParser::MINUS, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::OR() {
  return getToken(GoParser::OR, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::CARET() {
  return getToken(GoParser::CARET, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::STAR() {
  return getToken(GoParser::STAR, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::DIV() {
  return getToken(GoParser::DIV, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::MOD() {
  return getToken(GoParser::MOD, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::LSHIFT() {
  return getToken(GoParser::LSHIFT, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::RSHIFT() {
  return getToken(GoParser::RSHIFT, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::AMPERSAND() {
  return getToken(GoParser::AMPERSAND, 0);
}

tree::TerminalNode* GoParser::Assign_opContext::BIT_CLEAR() {
  return getToken(GoParser::BIT_CLEAR, 0);
}


size_t GoParser::Assign_opContext::getRuleIndex() const {
  return GoParser::RuleAssign_op;
}

void GoParser::Assign_opContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign_op(this);
}

void GoParser::Assign_opContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign_op(this);
}

GoParser::Assign_opContext* GoParser::assign_op() {
  Assign_opContext *_localctx = _tracker.createInstance<Assign_opContext>(_ctx, getState());
  enterRule(_localctx, 50, GoParser::RuleAssign_op);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(421);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 54) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 54)) & ((1ULL << (GoParser::OR - 54))
      | (1ULL << (GoParser::DIV - 54))
      | (1ULL << (GoParser::MOD - 54))
      | (1ULL << (GoParser::LSHIFT - 54))
      | (1ULL << (GoParser::RSHIFT - 54))
      | (1ULL << (GoParser::BIT_CLEAR - 54))
      | (1ULL << (GoParser::PLUS - 54))
      | (1ULL << (GoParser::MINUS - 54))
      | (1ULL << (GoParser::CARET - 54))
      | (1ULL << (GoParser::STAR - 54))
      | (1ULL << (GoParser::AMPERSAND - 54)))) != 0)) {
      setState(420);
      _la = _input->LA(1);
      if (!(((((_la - 54) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 54)) & ((1ULL << (GoParser::OR - 54))
        | (1ULL << (GoParser::DIV - 54))
        | (1ULL << (GoParser::MOD - 54))
        | (1ULL << (GoParser::LSHIFT - 54))
        | (1ULL << (GoParser::RSHIFT - 54))
        | (1ULL << (GoParser::BIT_CLEAR - 54))
        | (1ULL << (GoParser::PLUS - 54))
        | (1ULL << (GoParser::MINUS - 54))
        | (1ULL << (GoParser::CARET - 54))
        | (1ULL << (GoParser::STAR - 54))
        | (1ULL << (GoParser::AMPERSAND - 54)))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(423);
    match(GoParser::ASSIGN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ShortVarDeclContext ------------------------------------------------------------------

GoParser::ShortVarDeclContext::ShortVarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::IdentifierListContext* GoParser::ShortVarDeclContext::identifierList() {
  return getRuleContext<GoParser::IdentifierListContext>(0);
}

tree::TerminalNode* GoParser::ShortVarDeclContext::DECLARE_ASSIGN() {
  return getToken(GoParser::DECLARE_ASSIGN, 0);
}

GoParser::ExpressionListContext* GoParser::ShortVarDeclContext::expressionList() {
  return getRuleContext<GoParser::ExpressionListContext>(0);
}


size_t GoParser::ShortVarDeclContext::getRuleIndex() const {
  return GoParser::RuleShortVarDecl;
}

void GoParser::ShortVarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterShortVarDecl(this);
}

void GoParser::ShortVarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitShortVarDecl(this);
}

GoParser::ShortVarDeclContext* GoParser::shortVarDecl() {
  ShortVarDeclContext *_localctx = _tracker.createInstance<ShortVarDeclContext>(_ctx, getState());
  enterRule(_localctx, 52, GoParser::RuleShortVarDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(425);
    identifierList();
    setState(426);
    match(GoParser::DECLARE_ASSIGN);
    setState(427);
    expressionList();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EmptyStmtContext ------------------------------------------------------------------

GoParser::EmptyStmtContext::EmptyStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::EmptyStmtContext::EOSSS() {
  return getToken(GoParser::EOSSS, 0);
}

tree::TerminalNode* GoParser::EmptyStmtContext::SEMI() {
  return getToken(GoParser::SEMI, 0);
}


size_t GoParser::EmptyStmtContext::getRuleIndex() const {
  return GoParser::RuleEmptyStmt;
}

void GoParser::EmptyStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmptyStmt(this);
}

void GoParser::EmptyStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmptyStmt(this);
}

GoParser::EmptyStmtContext* GoParser::emptyStmt() {
  EmptyStmtContext *_localctx = _tracker.createInstance<EmptyStmtContext>(_ctx, getState());
  enterRule(_localctx, 54, GoParser::RuleEmptyStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(429);
    _la = _input->LA(1);
    if (!(_la == GoParser::SEMI

    || _la == GoParser::EOSSS)) {
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

//----------------- LabeledStmtContext ------------------------------------------------------------------

GoParser::LabeledStmtContext::LabeledStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::LabeledStmtContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}

tree::TerminalNode* GoParser::LabeledStmtContext::COLON() {
  return getToken(GoParser::COLON, 0);
}

GoParser::StatementContext* GoParser::LabeledStmtContext::statement() {
  return getRuleContext<GoParser::StatementContext>(0);
}


size_t GoParser::LabeledStmtContext::getRuleIndex() const {
  return GoParser::RuleLabeledStmt;
}

void GoParser::LabeledStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLabeledStmt(this);
}

void GoParser::LabeledStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLabeledStmt(this);
}

GoParser::LabeledStmtContext* GoParser::labeledStmt() {
  LabeledStmtContext *_localctx = _tracker.createInstance<LabeledStmtContext>(_ctx, getState());
  enterRule(_localctx, 56, GoParser::RuleLabeledStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(431);
    match(GoParser::IDENTIFIER);
    setState(432);
    match(GoParser::COLON);
    setState(434);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GoParser::BREAK)
      | (1ULL << GoParser::FUNC)
      | (1ULL << GoParser::INTERFACE)
      | (1ULL << GoParser::SELECT)
      | (1ULL << GoParser::DEFER)
      | (1ULL << GoParser::GO)
      | (1ULL << GoParser::MAP)
      | (1ULL << GoParser::STRUCT)
      | (1ULL << GoParser::CHAN)
      | (1ULL << GoParser::GOTO)
      | (1ULL << GoParser::SWITCH)
      | (1ULL << GoParser::CONST)
      | (1ULL << GoParser::FALLTHROUGH)
      | (1ULL << GoParser::IF)
      | (1ULL << GoParser::TYPE)
      | (1ULL << GoParser::CONTINUE)
      | (1ULL << GoParser::FOR)
      | (1ULL << GoParser::RETURN)
      | (1ULL << GoParser::VAR)
      | (1ULL << GoParser::NIL_LIT)
      | (1ULL << GoParser::IDENTIFIER)
      | (1ULL << GoParser::L_PAREN)
      | (1ULL << GoParser::L_CURLY)
      | (1ULL << GoParser::L_BRACKET)
      | (1ULL << GoParser::EXCLAMATION)
      | (1ULL << GoParser::PLUS)
      | (1ULL << GoParser::MINUS)
      | (1ULL << GoParser::CARET))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GoParser::STAR - 64))
      | (1ULL << (GoParser::AMPERSAND - 64))
      | (1ULL << (GoParser::RECEIVE - 64))
      | (1ULL << (GoParser::DECIMAL_LIT - 64))
      | (1ULL << (GoParser::BINARY_LIT - 64))
      | (1ULL << (GoParser::OCTAL_LIT - 64))
      | (1ULL << (GoParser::HEX_LIT - 64))
      | (1ULL << (GoParser::FLOAT_LIT - 64))
      | (1ULL << (GoParser::IMAGINARY_LIT - 64))
      | (1ULL << (GoParser::RUNE_LIT - 64))
      | (1ULL << (GoParser::RAW_STRING_LIT - 64))
      | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
      setState(433);
      statement();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

GoParser::ReturnStmtContext::ReturnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::ReturnStmtContext::RETURN() {
  return getToken(GoParser::RETURN, 0);
}

GoParser::ExpressionListContext* GoParser::ReturnStmtContext::expressionList() {
  return getRuleContext<GoParser::ExpressionListContext>(0);
}


size_t GoParser::ReturnStmtContext::getRuleIndex() const {
  return GoParser::RuleReturnStmt;
}

void GoParser::ReturnStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStmt(this);
}

void GoParser::ReturnStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStmt(this);
}

GoParser::ReturnStmtContext* GoParser::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 58, GoParser::RuleReturnStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(436);
    match(GoParser::RETURN);
    setState(438);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GoParser::FUNC)
      | (1ULL << GoParser::INTERFACE)
      | (1ULL << GoParser::MAP)
      | (1ULL << GoParser::STRUCT)
      | (1ULL << GoParser::CHAN)
      | (1ULL << GoParser::NIL_LIT)
      | (1ULL << GoParser::IDENTIFIER)
      | (1ULL << GoParser::L_PAREN)
      | (1ULL << GoParser::L_BRACKET)
      | (1ULL << GoParser::EXCLAMATION)
      | (1ULL << GoParser::PLUS)
      | (1ULL << GoParser::MINUS)
      | (1ULL << GoParser::CARET))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GoParser::STAR - 64))
      | (1ULL << (GoParser::AMPERSAND - 64))
      | (1ULL << (GoParser::RECEIVE - 64))
      | (1ULL << (GoParser::DECIMAL_LIT - 64))
      | (1ULL << (GoParser::BINARY_LIT - 64))
      | (1ULL << (GoParser::OCTAL_LIT - 64))
      | (1ULL << (GoParser::HEX_LIT - 64))
      | (1ULL << (GoParser::FLOAT_LIT - 64))
      | (1ULL << (GoParser::IMAGINARY_LIT - 64))
      | (1ULL << (GoParser::RUNE_LIT - 64))
      | (1ULL << (GoParser::RAW_STRING_LIT - 64))
      | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
      setState(437);
      expressionList();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BreakStmtContext ------------------------------------------------------------------

GoParser::BreakStmtContext::BreakStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::BreakStmtContext::BREAK() {
  return getToken(GoParser::BREAK, 0);
}

tree::TerminalNode* GoParser::BreakStmtContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}


size_t GoParser::BreakStmtContext::getRuleIndex() const {
  return GoParser::RuleBreakStmt;
}

void GoParser::BreakStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBreakStmt(this);
}

void GoParser::BreakStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBreakStmt(this);
}

GoParser::BreakStmtContext* GoParser::breakStmt() {
  BreakStmtContext *_localctx = _tracker.createInstance<BreakStmtContext>(_ctx, getState());
  enterRule(_localctx, 60, GoParser::RuleBreakStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(440);
    match(GoParser::BREAK);
    setState(442);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GoParser::IDENTIFIER) {
      setState(441);
      match(GoParser::IDENTIFIER);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ContinueStmtContext ------------------------------------------------------------------

GoParser::ContinueStmtContext::ContinueStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::ContinueStmtContext::CONTINUE() {
  return getToken(GoParser::CONTINUE, 0);
}

tree::TerminalNode* GoParser::ContinueStmtContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}


size_t GoParser::ContinueStmtContext::getRuleIndex() const {
  return GoParser::RuleContinueStmt;
}

void GoParser::ContinueStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterContinueStmt(this);
}

void GoParser::ContinueStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitContinueStmt(this);
}

GoParser::ContinueStmtContext* GoParser::continueStmt() {
  ContinueStmtContext *_localctx = _tracker.createInstance<ContinueStmtContext>(_ctx, getState());
  enterRule(_localctx, 62, GoParser::RuleContinueStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(444);
    match(GoParser::CONTINUE);
    setState(446);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GoParser::IDENTIFIER) {
      setState(445);
      match(GoParser::IDENTIFIER);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GotoStmtContext ------------------------------------------------------------------

GoParser::GotoStmtContext::GotoStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::GotoStmtContext::GOTO() {
  return getToken(GoParser::GOTO, 0);
}

tree::TerminalNode* GoParser::GotoStmtContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}


size_t GoParser::GotoStmtContext::getRuleIndex() const {
  return GoParser::RuleGotoStmt;
}

void GoParser::GotoStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGotoStmt(this);
}

void GoParser::GotoStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGotoStmt(this);
}

GoParser::GotoStmtContext* GoParser::gotoStmt() {
  GotoStmtContext *_localctx = _tracker.createInstance<GotoStmtContext>(_ctx, getState());
  enterRule(_localctx, 64, GoParser::RuleGotoStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(448);
    match(GoParser::GOTO);
    setState(449);
    match(GoParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FallthroughStmtContext ------------------------------------------------------------------

GoParser::FallthroughStmtContext::FallthroughStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::FallthroughStmtContext::FALLTHROUGH() {
  return getToken(GoParser::FALLTHROUGH, 0);
}


size_t GoParser::FallthroughStmtContext::getRuleIndex() const {
  return GoParser::RuleFallthroughStmt;
}

void GoParser::FallthroughStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFallthroughStmt(this);
}

void GoParser::FallthroughStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFallthroughStmt(this);
}

GoParser::FallthroughStmtContext* GoParser::fallthroughStmt() {
  FallthroughStmtContext *_localctx = _tracker.createInstance<FallthroughStmtContext>(_ctx, getState());
  enterRule(_localctx, 66, GoParser::RuleFallthroughStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(451);
    match(GoParser::FALLTHROUGH);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeferStmtContext ------------------------------------------------------------------

GoParser::DeferStmtContext::DeferStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::DeferStmtContext::DEFER() {
  return getToken(GoParser::DEFER, 0);
}

GoParser::ExpressionContext* GoParser::DeferStmtContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}


size_t GoParser::DeferStmtContext::getRuleIndex() const {
  return GoParser::RuleDeferStmt;
}

void GoParser::DeferStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeferStmt(this);
}

void GoParser::DeferStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeferStmt(this);
}

GoParser::DeferStmtContext* GoParser::deferStmt() {
  DeferStmtContext *_localctx = _tracker.createInstance<DeferStmtContext>(_ctx, getState());
  enterRule(_localctx, 68, GoParser::RuleDeferStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(453);
    match(GoParser::DEFER);
    setState(454);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

GoParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::IfStmtContext::IF() {
  return getToken(GoParser::IF, 0);
}

std::vector<GoParser::BlockContext *> GoParser::IfStmtContext::block() {
  return getRuleContexts<GoParser::BlockContext>();
}

GoParser::BlockContext* GoParser::IfStmtContext::block(size_t i) {
  return getRuleContext<GoParser::BlockContext>(i);
}

GoParser::ExpressionContext* GoParser::IfStmtContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

GoParser::EossContext* GoParser::IfStmtContext::eoss() {
  return getRuleContext<GoParser::EossContext>(0);
}

GoParser::SimpleStmtContext* GoParser::IfStmtContext::simpleStmt() {
  return getRuleContext<GoParser::SimpleStmtContext>(0);
}

tree::TerminalNode* GoParser::IfStmtContext::ELSE() {
  return getToken(GoParser::ELSE, 0);
}

GoParser::IfStmtContext* GoParser::IfStmtContext::ifStmt() {
  return getRuleContext<GoParser::IfStmtContext>(0);
}


size_t GoParser::IfStmtContext::getRuleIndex() const {
  return GoParser::RuleIfStmt;
}

void GoParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}

void GoParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}

GoParser::IfStmtContext* GoParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 70, GoParser::RuleIfStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(456);
    match(GoParser::IF);
    setState(465);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
    case 1: {
      setState(457);
      expression(0);
      break;
    }

    case 2: {
      setState(458);
      eoss();
      setState(459);
      expression(0);
      break;
    }

    case 3: {
      setState(461);
      simpleStmt();
      setState(462);
      eoss();
      setState(463);
      expression(0);
      break;
    }

    default:
      break;
    }
    setState(467);
    block();
    setState(473);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GoParser::ELSE) {
      setState(468);
      match(GoParser::ELSE);
      setState(471);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case GoParser::IF: {
          setState(469);
          ifStmt();
          break;
        }

        case GoParser::L_CURLY: {
          setState(470);
          block();
          break;
        }

      default:
        throw NoViableAltException(this);
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

//----------------- SwitchStmtContext ------------------------------------------------------------------

GoParser::SwitchStmtContext::SwitchStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ExprSwitchStmtContext* GoParser::SwitchStmtContext::exprSwitchStmt() {
  return getRuleContext<GoParser::ExprSwitchStmtContext>(0);
}

GoParser::TypeSwitchStmtContext* GoParser::SwitchStmtContext::typeSwitchStmt() {
  return getRuleContext<GoParser::TypeSwitchStmtContext>(0);
}


size_t GoParser::SwitchStmtContext::getRuleIndex() const {
  return GoParser::RuleSwitchStmt;
}

void GoParser::SwitchStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSwitchStmt(this);
}

void GoParser::SwitchStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSwitchStmt(this);
}

GoParser::SwitchStmtContext* GoParser::switchStmt() {
  SwitchStmtContext *_localctx = _tracker.createInstance<SwitchStmtContext>(_ctx, getState());
  enterRule(_localctx, 72, GoParser::RuleSwitchStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(477);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(475);
      exprSwitchStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(476);
      typeSwitchStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprSwitchStmtContext ------------------------------------------------------------------

GoParser::ExprSwitchStmtContext::ExprSwitchStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::ExprSwitchStmtContext::SWITCH() {
  return getToken(GoParser::SWITCH, 0);
}

tree::TerminalNode* GoParser::ExprSwitchStmtContext::L_CURLY() {
  return getToken(GoParser::L_CURLY, 0);
}

tree::TerminalNode* GoParser::ExprSwitchStmtContext::R_CURLY() {
  return getToken(GoParser::R_CURLY, 0);
}

GoParser::EossContext* GoParser::ExprSwitchStmtContext::eoss() {
  return getRuleContext<GoParser::EossContext>(0);
}

std::vector<GoParser::ExprCaseClauseContext *> GoParser::ExprSwitchStmtContext::exprCaseClause() {
  return getRuleContexts<GoParser::ExprCaseClauseContext>();
}

GoParser::ExprCaseClauseContext* GoParser::ExprSwitchStmtContext::exprCaseClause(size_t i) {
  return getRuleContext<GoParser::ExprCaseClauseContext>(i);
}

GoParser::ExpressionContext* GoParser::ExprSwitchStmtContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

GoParser::SimpleStmtContext* GoParser::ExprSwitchStmtContext::simpleStmt() {
  return getRuleContext<GoParser::SimpleStmtContext>(0);
}


size_t GoParser::ExprSwitchStmtContext::getRuleIndex() const {
  return GoParser::RuleExprSwitchStmt;
}

void GoParser::ExprSwitchStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprSwitchStmt(this);
}

void GoParser::ExprSwitchStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprSwitchStmt(this);
}

GoParser::ExprSwitchStmtContext* GoParser::exprSwitchStmt() {
  ExprSwitchStmtContext *_localctx = _tracker.createInstance<ExprSwitchStmtContext>(_ctx, getState());
  enterRule(_localctx, 74, GoParser::RuleExprSwitchStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(479);
    match(GoParser::SWITCH);
    setState(490);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      setState(481);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GoParser::FUNC)
        | (1ULL << GoParser::INTERFACE)
        | (1ULL << GoParser::MAP)
        | (1ULL << GoParser::STRUCT)
        | (1ULL << GoParser::CHAN)
        | (1ULL << GoParser::NIL_LIT)
        | (1ULL << GoParser::IDENTIFIER)
        | (1ULL << GoParser::L_PAREN)
        | (1ULL << GoParser::L_BRACKET)
        | (1ULL << GoParser::EXCLAMATION)
        | (1ULL << GoParser::PLUS)
        | (1ULL << GoParser::MINUS)
        | (1ULL << GoParser::CARET))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (GoParser::STAR - 64))
        | (1ULL << (GoParser::AMPERSAND - 64))
        | (1ULL << (GoParser::RECEIVE - 64))
        | (1ULL << (GoParser::DECIMAL_LIT - 64))
        | (1ULL << (GoParser::BINARY_LIT - 64))
        | (1ULL << (GoParser::OCTAL_LIT - 64))
        | (1ULL << (GoParser::HEX_LIT - 64))
        | (1ULL << (GoParser::FLOAT_LIT - 64))
        | (1ULL << (GoParser::IMAGINARY_LIT - 64))
        | (1ULL << (GoParser::RUNE_LIT - 64))
        | (1ULL << (GoParser::RAW_STRING_LIT - 64))
        | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
        setState(480);
        expression(0);
      }
      break;
    }

    case 2: {
      setState(484);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GoParser::FUNC)
        | (1ULL << GoParser::INTERFACE)
        | (1ULL << GoParser::MAP)
        | (1ULL << GoParser::STRUCT)
        | (1ULL << GoParser::CHAN)
        | (1ULL << GoParser::NIL_LIT)
        | (1ULL << GoParser::IDENTIFIER)
        | (1ULL << GoParser::L_PAREN)
        | (1ULL << GoParser::L_BRACKET)
        | (1ULL << GoParser::EXCLAMATION)
        | (1ULL << GoParser::PLUS)
        | (1ULL << GoParser::MINUS)
        | (1ULL << GoParser::CARET))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (GoParser::STAR - 64))
        | (1ULL << (GoParser::AMPERSAND - 64))
        | (1ULL << (GoParser::RECEIVE - 64))
        | (1ULL << (GoParser::DECIMAL_LIT - 64))
        | (1ULL << (GoParser::BINARY_LIT - 64))
        | (1ULL << (GoParser::OCTAL_LIT - 64))
        | (1ULL << (GoParser::HEX_LIT - 64))
        | (1ULL << (GoParser::FLOAT_LIT - 64))
        | (1ULL << (GoParser::IMAGINARY_LIT - 64))
        | (1ULL << (GoParser::RUNE_LIT - 64))
        | (1ULL << (GoParser::RAW_STRING_LIT - 64))
        | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
        setState(483);
        simpleStmt();
      }
      setState(486);
      eoss();
      setState(488);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GoParser::FUNC)
        | (1ULL << GoParser::INTERFACE)
        | (1ULL << GoParser::MAP)
        | (1ULL << GoParser::STRUCT)
        | (1ULL << GoParser::CHAN)
        | (1ULL << GoParser::NIL_LIT)
        | (1ULL << GoParser::IDENTIFIER)
        | (1ULL << GoParser::L_PAREN)
        | (1ULL << GoParser::L_BRACKET)
        | (1ULL << GoParser::EXCLAMATION)
        | (1ULL << GoParser::PLUS)
        | (1ULL << GoParser::MINUS)
        | (1ULL << GoParser::CARET))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (GoParser::STAR - 64))
        | (1ULL << (GoParser::AMPERSAND - 64))
        | (1ULL << (GoParser::RECEIVE - 64))
        | (1ULL << (GoParser::DECIMAL_LIT - 64))
        | (1ULL << (GoParser::BINARY_LIT - 64))
        | (1ULL << (GoParser::OCTAL_LIT - 64))
        | (1ULL << (GoParser::HEX_LIT - 64))
        | (1ULL << (GoParser::FLOAT_LIT - 64))
        | (1ULL << (GoParser::IMAGINARY_LIT - 64))
        | (1ULL << (GoParser::RUNE_LIT - 64))
        | (1ULL << (GoParser::RAW_STRING_LIT - 64))
        | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
        setState(487);
        expression(0);
      }
      break;
    }

    default:
      break;
    }
    setState(492);
    match(GoParser::L_CURLY);
    setState(496);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GoParser::DEFAULT

    || _la == GoParser::CASE) {
      setState(493);
      exprCaseClause();
      setState(498);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(499);
    match(GoParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprCaseClauseContext ------------------------------------------------------------------

GoParser::ExprCaseClauseContext::ExprCaseClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ExprSwitchCaseContext* GoParser::ExprCaseClauseContext::exprSwitchCase() {
  return getRuleContext<GoParser::ExprSwitchCaseContext>(0);
}

tree::TerminalNode* GoParser::ExprCaseClauseContext::COLON() {
  return getToken(GoParser::COLON, 0);
}

GoParser::StatementListContext* GoParser::ExprCaseClauseContext::statementList() {
  return getRuleContext<GoParser::StatementListContext>(0);
}


size_t GoParser::ExprCaseClauseContext::getRuleIndex() const {
  return GoParser::RuleExprCaseClause;
}

void GoParser::ExprCaseClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprCaseClause(this);
}

void GoParser::ExprCaseClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprCaseClause(this);
}

GoParser::ExprCaseClauseContext* GoParser::exprCaseClause() {
  ExprCaseClauseContext *_localctx = _tracker.createInstance<ExprCaseClauseContext>(_ctx, getState());
  enterRule(_localctx, 76, GoParser::RuleExprCaseClause);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(501);
    exprSwitchCase();
    setState(502);
    match(GoParser::COLON);
    setState(504);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GoParser::BREAK)
      | (1ULL << GoParser::FUNC)
      | (1ULL << GoParser::INTERFACE)
      | (1ULL << GoParser::SELECT)
      | (1ULL << GoParser::DEFER)
      | (1ULL << GoParser::GO)
      | (1ULL << GoParser::MAP)
      | (1ULL << GoParser::STRUCT)
      | (1ULL << GoParser::CHAN)
      | (1ULL << GoParser::GOTO)
      | (1ULL << GoParser::SWITCH)
      | (1ULL << GoParser::CONST)
      | (1ULL << GoParser::FALLTHROUGH)
      | (1ULL << GoParser::IF)
      | (1ULL << GoParser::TYPE)
      | (1ULL << GoParser::CONTINUE)
      | (1ULL << GoParser::FOR)
      | (1ULL << GoParser::RETURN)
      | (1ULL << GoParser::VAR)
      | (1ULL << GoParser::NIL_LIT)
      | (1ULL << GoParser::IDENTIFIER)
      | (1ULL << GoParser::L_PAREN)
      | (1ULL << GoParser::L_CURLY)
      | (1ULL << GoParser::L_BRACKET)
      | (1ULL << GoParser::EXCLAMATION)
      | (1ULL << GoParser::PLUS)
      | (1ULL << GoParser::MINUS)
      | (1ULL << GoParser::CARET))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GoParser::STAR - 64))
      | (1ULL << (GoParser::AMPERSAND - 64))
      | (1ULL << (GoParser::RECEIVE - 64))
      | (1ULL << (GoParser::DECIMAL_LIT - 64))
      | (1ULL << (GoParser::BINARY_LIT - 64))
      | (1ULL << (GoParser::OCTAL_LIT - 64))
      | (1ULL << (GoParser::HEX_LIT - 64))
      | (1ULL << (GoParser::FLOAT_LIT - 64))
      | (1ULL << (GoParser::IMAGINARY_LIT - 64))
      | (1ULL << (GoParser::RUNE_LIT - 64))
      | (1ULL << (GoParser::RAW_STRING_LIT - 64))
      | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
      setState(503);
      statementList();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprSwitchCaseContext ------------------------------------------------------------------

GoParser::ExprSwitchCaseContext::ExprSwitchCaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::ExprSwitchCaseContext::CASE() {
  return getToken(GoParser::CASE, 0);
}

GoParser::ExpressionListContext* GoParser::ExprSwitchCaseContext::expressionList() {
  return getRuleContext<GoParser::ExpressionListContext>(0);
}

tree::TerminalNode* GoParser::ExprSwitchCaseContext::DEFAULT() {
  return getToken(GoParser::DEFAULT, 0);
}


size_t GoParser::ExprSwitchCaseContext::getRuleIndex() const {
  return GoParser::RuleExprSwitchCase;
}

void GoParser::ExprSwitchCaseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprSwitchCase(this);
}

void GoParser::ExprSwitchCaseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprSwitchCase(this);
}

GoParser::ExprSwitchCaseContext* GoParser::exprSwitchCase() {
  ExprSwitchCaseContext *_localctx = _tracker.createInstance<ExprSwitchCaseContext>(_ctx, getState());
  enterRule(_localctx, 78, GoParser::RuleExprSwitchCase);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(509);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::CASE: {
        enterOuterAlt(_localctx, 1);
        setState(506);
        match(GoParser::CASE);
        setState(507);
        expressionList();
        break;
      }

      case GoParser::DEFAULT: {
        enterOuterAlt(_localctx, 2);
        setState(508);
        match(GoParser::DEFAULT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSwitchStmtContext ------------------------------------------------------------------

GoParser::TypeSwitchStmtContext::TypeSwitchStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::TypeSwitchStmtContext::SWITCH() {
  return getToken(GoParser::SWITCH, 0);
}

tree::TerminalNode* GoParser::TypeSwitchStmtContext::L_CURLY() {
  return getToken(GoParser::L_CURLY, 0);
}

tree::TerminalNode* GoParser::TypeSwitchStmtContext::R_CURLY() {
  return getToken(GoParser::R_CURLY, 0);
}

GoParser::TypeSwitchGuardContext* GoParser::TypeSwitchStmtContext::typeSwitchGuard() {
  return getRuleContext<GoParser::TypeSwitchGuardContext>(0);
}

GoParser::EossContext* GoParser::TypeSwitchStmtContext::eoss() {
  return getRuleContext<GoParser::EossContext>(0);
}

GoParser::SimpleStmtContext* GoParser::TypeSwitchStmtContext::simpleStmt() {
  return getRuleContext<GoParser::SimpleStmtContext>(0);
}

std::vector<GoParser::TypeCaseClauseContext *> GoParser::TypeSwitchStmtContext::typeCaseClause() {
  return getRuleContexts<GoParser::TypeCaseClauseContext>();
}

GoParser::TypeCaseClauseContext* GoParser::TypeSwitchStmtContext::typeCaseClause(size_t i) {
  return getRuleContext<GoParser::TypeCaseClauseContext>(i);
}


size_t GoParser::TypeSwitchStmtContext::getRuleIndex() const {
  return GoParser::RuleTypeSwitchStmt;
}

void GoParser::TypeSwitchStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeSwitchStmt(this);
}

void GoParser::TypeSwitchStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeSwitchStmt(this);
}

GoParser::TypeSwitchStmtContext* GoParser::typeSwitchStmt() {
  TypeSwitchStmtContext *_localctx = _tracker.createInstance<TypeSwitchStmtContext>(_ctx, getState());
  enterRule(_localctx, 80, GoParser::RuleTypeSwitchStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(511);
    match(GoParser::SWITCH);
    setState(520);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 47, _ctx)) {
    case 1: {
      setState(512);
      typeSwitchGuard();
      break;
    }

    case 2: {
      setState(513);
      eoss();
      setState(514);
      typeSwitchGuard();
      break;
    }

    case 3: {
      setState(516);
      simpleStmt();
      setState(517);
      eoss();
      setState(518);
      typeSwitchGuard();
      break;
    }

    default:
      break;
    }
    setState(522);
    match(GoParser::L_CURLY);
    setState(526);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GoParser::DEFAULT

    || _la == GoParser::CASE) {
      setState(523);
      typeCaseClause();
      setState(528);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(529);
    match(GoParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSwitchGuardContext ------------------------------------------------------------------

GoParser::TypeSwitchGuardContext::TypeSwitchGuardContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::PrimaryExprContext* GoParser::TypeSwitchGuardContext::primaryExpr() {
  return getRuleContext<GoParser::PrimaryExprContext>(0);
}

tree::TerminalNode* GoParser::TypeSwitchGuardContext::DOT() {
  return getToken(GoParser::DOT, 0);
}

tree::TerminalNode* GoParser::TypeSwitchGuardContext::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

tree::TerminalNode* GoParser::TypeSwitchGuardContext::TYPE() {
  return getToken(GoParser::TYPE, 0);
}

tree::TerminalNode* GoParser::TypeSwitchGuardContext::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}

tree::TerminalNode* GoParser::TypeSwitchGuardContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}

tree::TerminalNode* GoParser::TypeSwitchGuardContext::DECLARE_ASSIGN() {
  return getToken(GoParser::DECLARE_ASSIGN, 0);
}


size_t GoParser::TypeSwitchGuardContext::getRuleIndex() const {
  return GoParser::RuleTypeSwitchGuard;
}

void GoParser::TypeSwitchGuardContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeSwitchGuard(this);
}

void GoParser::TypeSwitchGuardContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeSwitchGuard(this);
}

GoParser::TypeSwitchGuardContext* GoParser::typeSwitchGuard() {
  TypeSwitchGuardContext *_localctx = _tracker.createInstance<TypeSwitchGuardContext>(_ctx, getState());
  enterRule(_localctx, 82, GoParser::RuleTypeSwitchGuard);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(533);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 49, _ctx)) {
    case 1: {
      setState(531);
      match(GoParser::IDENTIFIER);
      setState(532);
      match(GoParser::DECLARE_ASSIGN);
      break;
    }

    default:
      break;
    }
    setState(535);
    primaryExpr(0);
    setState(536);
    match(GoParser::DOT);
    setState(537);
    match(GoParser::L_PAREN);
    setState(538);
    match(GoParser::TYPE);
    setState(539);
    match(GoParser::R_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeCaseClauseContext ------------------------------------------------------------------

GoParser::TypeCaseClauseContext::TypeCaseClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::TypeSwitchCaseContext* GoParser::TypeCaseClauseContext::typeSwitchCase() {
  return getRuleContext<GoParser::TypeSwitchCaseContext>(0);
}

tree::TerminalNode* GoParser::TypeCaseClauseContext::COLON() {
  return getToken(GoParser::COLON, 0);
}

GoParser::StatementListContext* GoParser::TypeCaseClauseContext::statementList() {
  return getRuleContext<GoParser::StatementListContext>(0);
}


size_t GoParser::TypeCaseClauseContext::getRuleIndex() const {
  return GoParser::RuleTypeCaseClause;
}

void GoParser::TypeCaseClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeCaseClause(this);
}

void GoParser::TypeCaseClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeCaseClause(this);
}

GoParser::TypeCaseClauseContext* GoParser::typeCaseClause() {
  TypeCaseClauseContext *_localctx = _tracker.createInstance<TypeCaseClauseContext>(_ctx, getState());
  enterRule(_localctx, 84, GoParser::RuleTypeCaseClause);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(541);
    typeSwitchCase();
    setState(542);
    match(GoParser::COLON);
    setState(544);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GoParser::BREAK)
      | (1ULL << GoParser::FUNC)
      | (1ULL << GoParser::INTERFACE)
      | (1ULL << GoParser::SELECT)
      | (1ULL << GoParser::DEFER)
      | (1ULL << GoParser::GO)
      | (1ULL << GoParser::MAP)
      | (1ULL << GoParser::STRUCT)
      | (1ULL << GoParser::CHAN)
      | (1ULL << GoParser::GOTO)
      | (1ULL << GoParser::SWITCH)
      | (1ULL << GoParser::CONST)
      | (1ULL << GoParser::FALLTHROUGH)
      | (1ULL << GoParser::IF)
      | (1ULL << GoParser::TYPE)
      | (1ULL << GoParser::CONTINUE)
      | (1ULL << GoParser::FOR)
      | (1ULL << GoParser::RETURN)
      | (1ULL << GoParser::VAR)
      | (1ULL << GoParser::NIL_LIT)
      | (1ULL << GoParser::IDENTIFIER)
      | (1ULL << GoParser::L_PAREN)
      | (1ULL << GoParser::L_CURLY)
      | (1ULL << GoParser::L_BRACKET)
      | (1ULL << GoParser::EXCLAMATION)
      | (1ULL << GoParser::PLUS)
      | (1ULL << GoParser::MINUS)
      | (1ULL << GoParser::CARET))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GoParser::STAR - 64))
      | (1ULL << (GoParser::AMPERSAND - 64))
      | (1ULL << (GoParser::RECEIVE - 64))
      | (1ULL << (GoParser::DECIMAL_LIT - 64))
      | (1ULL << (GoParser::BINARY_LIT - 64))
      | (1ULL << (GoParser::OCTAL_LIT - 64))
      | (1ULL << (GoParser::HEX_LIT - 64))
      | (1ULL << (GoParser::FLOAT_LIT - 64))
      | (1ULL << (GoParser::IMAGINARY_LIT - 64))
      | (1ULL << (GoParser::RUNE_LIT - 64))
      | (1ULL << (GoParser::RAW_STRING_LIT - 64))
      | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
      setState(543);
      statementList();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeSwitchCaseContext ------------------------------------------------------------------

GoParser::TypeSwitchCaseContext::TypeSwitchCaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::TypeSwitchCaseContext::CASE() {
  return getToken(GoParser::CASE, 0);
}

GoParser::TypeListContext* GoParser::TypeSwitchCaseContext::typeList() {
  return getRuleContext<GoParser::TypeListContext>(0);
}

tree::TerminalNode* GoParser::TypeSwitchCaseContext::DEFAULT() {
  return getToken(GoParser::DEFAULT, 0);
}


size_t GoParser::TypeSwitchCaseContext::getRuleIndex() const {
  return GoParser::RuleTypeSwitchCase;
}

void GoParser::TypeSwitchCaseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeSwitchCase(this);
}

void GoParser::TypeSwitchCaseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeSwitchCase(this);
}

GoParser::TypeSwitchCaseContext* GoParser::typeSwitchCase() {
  TypeSwitchCaseContext *_localctx = _tracker.createInstance<TypeSwitchCaseContext>(_ctx, getState());
  enterRule(_localctx, 86, GoParser::RuleTypeSwitchCase);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(549);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::CASE: {
        enterOuterAlt(_localctx, 1);
        setState(546);
        match(GoParser::CASE);
        setState(547);
        typeList();
        break;
      }

      case GoParser::DEFAULT: {
        enterOuterAlt(_localctx, 2);
        setState(548);
        match(GoParser::DEFAULT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeListContext ------------------------------------------------------------------

GoParser::TypeListContext::TypeListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GoParser::Type_Context *> GoParser::TypeListContext::type_() {
  return getRuleContexts<GoParser::Type_Context>();
}

GoParser::Type_Context* GoParser::TypeListContext::type_(size_t i) {
  return getRuleContext<GoParser::Type_Context>(i);
}

std::vector<tree::TerminalNode *> GoParser::TypeListContext::NIL_LIT() {
  return getTokens(GoParser::NIL_LIT);
}

tree::TerminalNode* GoParser::TypeListContext::NIL_LIT(size_t i) {
  return getToken(GoParser::NIL_LIT, i);
}

std::vector<tree::TerminalNode *> GoParser::TypeListContext::COMMA() {
  return getTokens(GoParser::COMMA);
}

tree::TerminalNode* GoParser::TypeListContext::COMMA(size_t i) {
  return getToken(GoParser::COMMA, i);
}


size_t GoParser::TypeListContext::getRuleIndex() const {
  return GoParser::RuleTypeList;
}

void GoParser::TypeListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeList(this);
}

void GoParser::TypeListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeList(this);
}

GoParser::TypeListContext* GoParser::typeList() {
  TypeListContext *_localctx = _tracker.createInstance<TypeListContext>(_ctx, getState());
  enterRule(_localctx, 88, GoParser::RuleTypeList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(553);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::FUNC:
      case GoParser::INTERFACE:
      case GoParser::MAP:
      case GoParser::STRUCT:
      case GoParser::CHAN:
      case GoParser::IDENTIFIER:
      case GoParser::L_PAREN:
      case GoParser::L_BRACKET:
      case GoParser::STAR:
      case GoParser::RECEIVE: {
        setState(551);
        type_();
        break;
      }

      case GoParser::NIL_LIT: {
        setState(552);
        match(GoParser::NIL_LIT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(562);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GoParser::COMMA) {
      setState(555);
      match(GoParser::COMMA);
      setState(558);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case GoParser::FUNC:
        case GoParser::INTERFACE:
        case GoParser::MAP:
        case GoParser::STRUCT:
        case GoParser::CHAN:
        case GoParser::IDENTIFIER:
        case GoParser::L_PAREN:
        case GoParser::L_BRACKET:
        case GoParser::STAR:
        case GoParser::RECEIVE: {
          setState(556);
          type_();
          break;
        }

        case GoParser::NIL_LIT: {
          setState(557);
          match(GoParser::NIL_LIT);
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(564);
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

//----------------- SelectStmtContext ------------------------------------------------------------------

GoParser::SelectStmtContext::SelectStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::SelectStmtContext::SELECT() {
  return getToken(GoParser::SELECT, 0);
}

tree::TerminalNode* GoParser::SelectStmtContext::L_CURLY() {
  return getToken(GoParser::L_CURLY, 0);
}

tree::TerminalNode* GoParser::SelectStmtContext::R_CURLY() {
  return getToken(GoParser::R_CURLY, 0);
}

std::vector<GoParser::CommClauseContext *> GoParser::SelectStmtContext::commClause() {
  return getRuleContexts<GoParser::CommClauseContext>();
}

GoParser::CommClauseContext* GoParser::SelectStmtContext::commClause(size_t i) {
  return getRuleContext<GoParser::CommClauseContext>(i);
}


size_t GoParser::SelectStmtContext::getRuleIndex() const {
  return GoParser::RuleSelectStmt;
}

void GoParser::SelectStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelectStmt(this);
}

void GoParser::SelectStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelectStmt(this);
}

GoParser::SelectStmtContext* GoParser::selectStmt() {
  SelectStmtContext *_localctx = _tracker.createInstance<SelectStmtContext>(_ctx, getState());
  enterRule(_localctx, 90, GoParser::RuleSelectStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(565);
    match(GoParser::SELECT);
    setState(566);
    match(GoParser::L_CURLY);
    setState(570);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GoParser::DEFAULT

    || _la == GoParser::CASE) {
      setState(567);
      commClause();
      setState(572);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(573);
    match(GoParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommClauseContext ------------------------------------------------------------------

GoParser::CommClauseContext::CommClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::CommCaseContext* GoParser::CommClauseContext::commCase() {
  return getRuleContext<GoParser::CommCaseContext>(0);
}

tree::TerminalNode* GoParser::CommClauseContext::COLON() {
  return getToken(GoParser::COLON, 0);
}

GoParser::StatementListContext* GoParser::CommClauseContext::statementList() {
  return getRuleContext<GoParser::StatementListContext>(0);
}


size_t GoParser::CommClauseContext::getRuleIndex() const {
  return GoParser::RuleCommClause;
}

void GoParser::CommClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommClause(this);
}

void GoParser::CommClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommClause(this);
}

GoParser::CommClauseContext* GoParser::commClause() {
  CommClauseContext *_localctx = _tracker.createInstance<CommClauseContext>(_ctx, getState());
  enterRule(_localctx, 92, GoParser::RuleCommClause);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(575);
    commCase();
    setState(576);
    match(GoParser::COLON);
    setState(578);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GoParser::BREAK)
      | (1ULL << GoParser::FUNC)
      | (1ULL << GoParser::INTERFACE)
      | (1ULL << GoParser::SELECT)
      | (1ULL << GoParser::DEFER)
      | (1ULL << GoParser::GO)
      | (1ULL << GoParser::MAP)
      | (1ULL << GoParser::STRUCT)
      | (1ULL << GoParser::CHAN)
      | (1ULL << GoParser::GOTO)
      | (1ULL << GoParser::SWITCH)
      | (1ULL << GoParser::CONST)
      | (1ULL << GoParser::FALLTHROUGH)
      | (1ULL << GoParser::IF)
      | (1ULL << GoParser::TYPE)
      | (1ULL << GoParser::CONTINUE)
      | (1ULL << GoParser::FOR)
      | (1ULL << GoParser::RETURN)
      | (1ULL << GoParser::VAR)
      | (1ULL << GoParser::NIL_LIT)
      | (1ULL << GoParser::IDENTIFIER)
      | (1ULL << GoParser::L_PAREN)
      | (1ULL << GoParser::L_CURLY)
      | (1ULL << GoParser::L_BRACKET)
      | (1ULL << GoParser::EXCLAMATION)
      | (1ULL << GoParser::PLUS)
      | (1ULL << GoParser::MINUS)
      | (1ULL << GoParser::CARET))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GoParser::STAR - 64))
      | (1ULL << (GoParser::AMPERSAND - 64))
      | (1ULL << (GoParser::RECEIVE - 64))
      | (1ULL << (GoParser::DECIMAL_LIT - 64))
      | (1ULL << (GoParser::BINARY_LIT - 64))
      | (1ULL << (GoParser::OCTAL_LIT - 64))
      | (1ULL << (GoParser::HEX_LIT - 64))
      | (1ULL << (GoParser::FLOAT_LIT - 64))
      | (1ULL << (GoParser::IMAGINARY_LIT - 64))
      | (1ULL << (GoParser::RUNE_LIT - 64))
      | (1ULL << (GoParser::RAW_STRING_LIT - 64))
      | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
      setState(577);
      statementList();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CommCaseContext ------------------------------------------------------------------

GoParser::CommCaseContext::CommCaseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::CommCaseContext::CASE() {
  return getToken(GoParser::CASE, 0);
}

GoParser::SendStmtContext* GoParser::CommCaseContext::sendStmt() {
  return getRuleContext<GoParser::SendStmtContext>(0);
}

GoParser::RecvStmtContext* GoParser::CommCaseContext::recvStmt() {
  return getRuleContext<GoParser::RecvStmtContext>(0);
}

tree::TerminalNode* GoParser::CommCaseContext::DEFAULT() {
  return getToken(GoParser::DEFAULT, 0);
}


size_t GoParser::CommCaseContext::getRuleIndex() const {
  return GoParser::RuleCommCase;
}

void GoParser::CommCaseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCommCase(this);
}

void GoParser::CommCaseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCommCase(this);
}

GoParser::CommCaseContext* GoParser::commCase() {
  CommCaseContext *_localctx = _tracker.createInstance<CommCaseContext>(_ctx, getState());
  enterRule(_localctx, 94, GoParser::RuleCommCase);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(586);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::CASE: {
        enterOuterAlt(_localctx, 1);
        setState(580);
        match(GoParser::CASE);
        setState(583);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 57, _ctx)) {
        case 1: {
          setState(581);
          sendStmt();
          break;
        }

        case 2: {
          setState(582);
          recvStmt();
          break;
        }

        default:
          break;
        }
        break;
      }

      case GoParser::DEFAULT: {
        enterOuterAlt(_localctx, 2);
        setState(585);
        match(GoParser::DEFAULT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RecvStmtContext ------------------------------------------------------------------

GoParser::RecvStmtContext::RecvStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ExpressionContext* GoParser::RecvStmtContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

GoParser::ExpressionListContext* GoParser::RecvStmtContext::expressionList() {
  return getRuleContext<GoParser::ExpressionListContext>(0);
}

tree::TerminalNode* GoParser::RecvStmtContext::ASSIGN() {
  return getToken(GoParser::ASSIGN, 0);
}

GoParser::IdentifierListContext* GoParser::RecvStmtContext::identifierList() {
  return getRuleContext<GoParser::IdentifierListContext>(0);
}

tree::TerminalNode* GoParser::RecvStmtContext::DECLARE_ASSIGN() {
  return getToken(GoParser::DECLARE_ASSIGN, 0);
}


size_t GoParser::RecvStmtContext::getRuleIndex() const {
  return GoParser::RuleRecvStmt;
}

void GoParser::RecvStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRecvStmt(this);
}

void GoParser::RecvStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRecvStmt(this);
}

GoParser::RecvStmtContext* GoParser::recvStmt() {
  RecvStmtContext *_localctx = _tracker.createInstance<RecvStmtContext>(_ctx, getState());
  enterRule(_localctx, 96, GoParser::RuleRecvStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(594);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 59, _ctx)) {
    case 1: {
      setState(588);
      expressionList();
      setState(589);
      match(GoParser::ASSIGN);
      break;
    }

    case 2: {
      setState(591);
      identifierList();
      setState(592);
      match(GoParser::DECLARE_ASSIGN);
      break;
    }

    default:
      break;
    }
    setState(596);
    antlrcpp::downCast<RecvStmtContext *>(_localctx)->recvExpr = expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStmtContext ------------------------------------------------------------------

GoParser::ForStmtContext::ForStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::ForStmtContext::FOR() {
  return getToken(GoParser::FOR, 0);
}

GoParser::BlockContext* GoParser::ForStmtContext::block() {
  return getRuleContext<GoParser::BlockContext>(0);
}

GoParser::ExpressionContext* GoParser::ForStmtContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

GoParser::ForClauseContext* GoParser::ForStmtContext::forClause() {
  return getRuleContext<GoParser::ForClauseContext>(0);
}

GoParser::RangeClauseContext* GoParser::ForStmtContext::rangeClause() {
  return getRuleContext<GoParser::RangeClauseContext>(0);
}


size_t GoParser::ForStmtContext::getRuleIndex() const {
  return GoParser::RuleForStmt;
}

void GoParser::ForStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStmt(this);
}

void GoParser::ForStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStmt(this);
}

GoParser::ForStmtContext* GoParser::forStmt() {
  ForStmtContext *_localctx = _tracker.createInstance<ForStmtContext>(_ctx, getState());
  enterRule(_localctx, 98, GoParser::RuleForStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(598);
    match(GoParser::FOR);
    setState(602);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 60, _ctx)) {
    case 1: {
      setState(599);
      expression(0);
      break;
    }

    case 2: {
      setState(600);
      forClause();
      break;
    }

    case 3: {
      setState(601);
      rangeClause();
      break;
    }

    default:
      break;
    }
    setState(604);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForClauseContext ------------------------------------------------------------------

GoParser::ForClauseContext::ForClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GoParser::EossContext *> GoParser::ForClauseContext::eoss() {
  return getRuleContexts<GoParser::EossContext>();
}

GoParser::EossContext* GoParser::ForClauseContext::eoss(size_t i) {
  return getRuleContext<GoParser::EossContext>(i);
}

GoParser::ExpressionContext* GoParser::ForClauseContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

std::vector<GoParser::SimpleStmtContext *> GoParser::ForClauseContext::simpleStmt() {
  return getRuleContexts<GoParser::SimpleStmtContext>();
}

GoParser::SimpleStmtContext* GoParser::ForClauseContext::simpleStmt(size_t i) {
  return getRuleContext<GoParser::SimpleStmtContext>(i);
}


size_t GoParser::ForClauseContext::getRuleIndex() const {
  return GoParser::RuleForClause;
}

void GoParser::ForClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForClause(this);
}

void GoParser::ForClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForClause(this);
}

GoParser::ForClauseContext* GoParser::forClause() {
  ForClauseContext *_localctx = _tracker.createInstance<ForClauseContext>(_ctx, getState());
  enterRule(_localctx, 100, GoParser::RuleForClause);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(607);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GoParser::FUNC)
      | (1ULL << GoParser::INTERFACE)
      | (1ULL << GoParser::MAP)
      | (1ULL << GoParser::STRUCT)
      | (1ULL << GoParser::CHAN)
      | (1ULL << GoParser::NIL_LIT)
      | (1ULL << GoParser::IDENTIFIER)
      | (1ULL << GoParser::L_PAREN)
      | (1ULL << GoParser::L_BRACKET)
      | (1ULL << GoParser::EXCLAMATION)
      | (1ULL << GoParser::PLUS)
      | (1ULL << GoParser::MINUS)
      | (1ULL << GoParser::CARET))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GoParser::STAR - 64))
      | (1ULL << (GoParser::AMPERSAND - 64))
      | (1ULL << (GoParser::RECEIVE - 64))
      | (1ULL << (GoParser::DECIMAL_LIT - 64))
      | (1ULL << (GoParser::BINARY_LIT - 64))
      | (1ULL << (GoParser::OCTAL_LIT - 64))
      | (1ULL << (GoParser::HEX_LIT - 64))
      | (1ULL << (GoParser::FLOAT_LIT - 64))
      | (1ULL << (GoParser::IMAGINARY_LIT - 64))
      | (1ULL << (GoParser::RUNE_LIT - 64))
      | (1ULL << (GoParser::RAW_STRING_LIT - 64))
      | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
      setState(606);
      antlrcpp::downCast<ForClauseContext *>(_localctx)->initStmt = simpleStmt();
    }
    setState(609);
    eoss();
    setState(611);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GoParser::FUNC)
      | (1ULL << GoParser::INTERFACE)
      | (1ULL << GoParser::MAP)
      | (1ULL << GoParser::STRUCT)
      | (1ULL << GoParser::CHAN)
      | (1ULL << GoParser::NIL_LIT)
      | (1ULL << GoParser::IDENTIFIER)
      | (1ULL << GoParser::L_PAREN)
      | (1ULL << GoParser::L_BRACKET)
      | (1ULL << GoParser::EXCLAMATION)
      | (1ULL << GoParser::PLUS)
      | (1ULL << GoParser::MINUS)
      | (1ULL << GoParser::CARET))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GoParser::STAR - 64))
      | (1ULL << (GoParser::AMPERSAND - 64))
      | (1ULL << (GoParser::RECEIVE - 64))
      | (1ULL << (GoParser::DECIMAL_LIT - 64))
      | (1ULL << (GoParser::BINARY_LIT - 64))
      | (1ULL << (GoParser::OCTAL_LIT - 64))
      | (1ULL << (GoParser::HEX_LIT - 64))
      | (1ULL << (GoParser::FLOAT_LIT - 64))
      | (1ULL << (GoParser::IMAGINARY_LIT - 64))
      | (1ULL << (GoParser::RUNE_LIT - 64))
      | (1ULL << (GoParser::RAW_STRING_LIT - 64))
      | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
      setState(610);
      expression(0);
    }
    setState(613);
    eoss();
    setState(615);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GoParser::FUNC)
      | (1ULL << GoParser::INTERFACE)
      | (1ULL << GoParser::MAP)
      | (1ULL << GoParser::STRUCT)
      | (1ULL << GoParser::CHAN)
      | (1ULL << GoParser::NIL_LIT)
      | (1ULL << GoParser::IDENTIFIER)
      | (1ULL << GoParser::L_PAREN)
      | (1ULL << GoParser::L_BRACKET)
      | (1ULL << GoParser::EXCLAMATION)
      | (1ULL << GoParser::PLUS)
      | (1ULL << GoParser::MINUS)
      | (1ULL << GoParser::CARET))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GoParser::STAR - 64))
      | (1ULL << (GoParser::AMPERSAND - 64))
      | (1ULL << (GoParser::RECEIVE - 64))
      | (1ULL << (GoParser::DECIMAL_LIT - 64))
      | (1ULL << (GoParser::BINARY_LIT - 64))
      | (1ULL << (GoParser::OCTAL_LIT - 64))
      | (1ULL << (GoParser::HEX_LIT - 64))
      | (1ULL << (GoParser::FLOAT_LIT - 64))
      | (1ULL << (GoParser::IMAGINARY_LIT - 64))
      | (1ULL << (GoParser::RUNE_LIT - 64))
      | (1ULL << (GoParser::RAW_STRING_LIT - 64))
      | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
      setState(614);
      antlrcpp::downCast<ForClauseContext *>(_localctx)->postStmt = simpleStmt();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RangeClauseContext ------------------------------------------------------------------

GoParser::RangeClauseContext::RangeClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::RangeClauseContext::RANGE() {
  return getToken(GoParser::RANGE, 0);
}

GoParser::ExpressionContext* GoParser::RangeClauseContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

GoParser::ExpressionListContext* GoParser::RangeClauseContext::expressionList() {
  return getRuleContext<GoParser::ExpressionListContext>(0);
}

tree::TerminalNode* GoParser::RangeClauseContext::ASSIGN() {
  return getToken(GoParser::ASSIGN, 0);
}

GoParser::IdentifierListContext* GoParser::RangeClauseContext::identifierList() {
  return getRuleContext<GoParser::IdentifierListContext>(0);
}

tree::TerminalNode* GoParser::RangeClauseContext::DECLARE_ASSIGN() {
  return getToken(GoParser::DECLARE_ASSIGN, 0);
}


size_t GoParser::RangeClauseContext::getRuleIndex() const {
  return GoParser::RuleRangeClause;
}

void GoParser::RangeClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRangeClause(this);
}

void GoParser::RangeClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRangeClause(this);
}

GoParser::RangeClauseContext* GoParser::rangeClause() {
  RangeClauseContext *_localctx = _tracker.createInstance<RangeClauseContext>(_ctx, getState());
  enterRule(_localctx, 102, GoParser::RuleRangeClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(623);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 64, _ctx)) {
    case 1: {
      setState(617);
      expressionList();
      setState(618);
      match(GoParser::ASSIGN);
      break;
    }

    case 2: {
      setState(620);
      identifierList();
      setState(621);
      match(GoParser::DECLARE_ASSIGN);
      break;
    }

    default:
      break;
    }
    setState(625);
    match(GoParser::RANGE);
    setState(626);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- GoStmtContext ------------------------------------------------------------------

GoParser::GoStmtContext::GoStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::GoStmtContext::GO() {
  return getToken(GoParser::GO, 0);
}

GoParser::ExpressionContext* GoParser::GoStmtContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}


size_t GoParser::GoStmtContext::getRuleIndex() const {
  return GoParser::RuleGoStmt;
}

void GoParser::GoStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGoStmt(this);
}

void GoParser::GoStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGoStmt(this);
}

GoParser::GoStmtContext* GoParser::goStmt() {
  GoStmtContext *_localctx = _tracker.createInstance<GoStmtContext>(_ctx, getState());
  enterRule(_localctx, 104, GoParser::RuleGoStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(628);
    match(GoParser::GO);
    setState(629);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_Context ------------------------------------------------------------------

GoParser::Type_Context::Type_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::TypeNameContext* GoParser::Type_Context::typeName() {
  return getRuleContext<GoParser::TypeNameContext>(0);
}

GoParser::TypeLitContext* GoParser::Type_Context::typeLit() {
  return getRuleContext<GoParser::TypeLitContext>(0);
}

tree::TerminalNode* GoParser::Type_Context::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

GoParser::Type_Context* GoParser::Type_Context::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}

tree::TerminalNode* GoParser::Type_Context::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}


size_t GoParser::Type_Context::getRuleIndex() const {
  return GoParser::RuleType_;
}

void GoParser::Type_Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType_(this);
}

void GoParser::Type_Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType_(this);
}

GoParser::Type_Context* GoParser::type_() {
  Type_Context *_localctx = _tracker.createInstance<Type_Context>(_ctx, getState());
  enterRule(_localctx, 106, GoParser::RuleType_);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(637);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(631);
        typeName();
        break;
      }

      case GoParser::FUNC:
      case GoParser::INTERFACE:
      case GoParser::MAP:
      case GoParser::STRUCT:
      case GoParser::CHAN:
      case GoParser::L_BRACKET:
      case GoParser::STAR:
      case GoParser::RECEIVE: {
        enterOuterAlt(_localctx, 2);
        setState(632);
        typeLit();
        break;
      }

      case GoParser::L_PAREN: {
        enterOuterAlt(_localctx, 3);
        setState(633);
        match(GoParser::L_PAREN);
        setState(634);
        type_();
        setState(635);
        match(GoParser::R_PAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeNameContext ------------------------------------------------------------------

GoParser::TypeNameContext::TypeNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::QualifiedIdentContext* GoParser::TypeNameContext::qualifiedIdent() {
  return getRuleContext<GoParser::QualifiedIdentContext>(0);
}

tree::TerminalNode* GoParser::TypeNameContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}


size_t GoParser::TypeNameContext::getRuleIndex() const {
  return GoParser::RuleTypeName;
}

void GoParser::TypeNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeName(this);
}

void GoParser::TypeNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeName(this);
}

GoParser::TypeNameContext* GoParser::typeName() {
  TypeNameContext *_localctx = _tracker.createInstance<TypeNameContext>(_ctx, getState());
  enterRule(_localctx, 108, GoParser::RuleTypeName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(641);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 66, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(639);
      qualifiedIdent();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(640);
      match(GoParser::IDENTIFIER);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeLitContext ------------------------------------------------------------------

GoParser::TypeLitContext::TypeLitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ArrayTypeContext* GoParser::TypeLitContext::arrayType() {
  return getRuleContext<GoParser::ArrayTypeContext>(0);
}

GoParser::StructTypeContext* GoParser::TypeLitContext::structType() {
  return getRuleContext<GoParser::StructTypeContext>(0);
}

GoParser::PointerTypeContext* GoParser::TypeLitContext::pointerType() {
  return getRuleContext<GoParser::PointerTypeContext>(0);
}

GoParser::FunctionTypeContext* GoParser::TypeLitContext::functionType() {
  return getRuleContext<GoParser::FunctionTypeContext>(0);
}

GoParser::InterfaceTypeContext* GoParser::TypeLitContext::interfaceType() {
  return getRuleContext<GoParser::InterfaceTypeContext>(0);
}

GoParser::SliceTypeContext* GoParser::TypeLitContext::sliceType() {
  return getRuleContext<GoParser::SliceTypeContext>(0);
}

GoParser::MapTypeContext* GoParser::TypeLitContext::mapType() {
  return getRuleContext<GoParser::MapTypeContext>(0);
}

GoParser::ChannelTypeContext* GoParser::TypeLitContext::channelType() {
  return getRuleContext<GoParser::ChannelTypeContext>(0);
}


size_t GoParser::TypeLitContext::getRuleIndex() const {
  return GoParser::RuleTypeLit;
}

void GoParser::TypeLitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeLit(this);
}

void GoParser::TypeLitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeLit(this);
}

GoParser::TypeLitContext* GoParser::typeLit() {
  TypeLitContext *_localctx = _tracker.createInstance<TypeLitContext>(_ctx, getState());
  enterRule(_localctx, 110, GoParser::RuleTypeLit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(651);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 67, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(643);
      arrayType();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(644);
      structType();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(645);
      pointerType();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(646);
      functionType();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(647);
      interfaceType();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(648);
      sliceType();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(649);
      mapType();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(650);
      channelType();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayTypeContext ------------------------------------------------------------------

GoParser::ArrayTypeContext::ArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::ArrayTypeContext::L_BRACKET() {
  return getToken(GoParser::L_BRACKET, 0);
}

GoParser::ArrayLengthContext* GoParser::ArrayTypeContext::arrayLength() {
  return getRuleContext<GoParser::ArrayLengthContext>(0);
}

tree::TerminalNode* GoParser::ArrayTypeContext::R_BRACKET() {
  return getToken(GoParser::R_BRACKET, 0);
}

GoParser::ElementTypeContext* GoParser::ArrayTypeContext::elementType() {
  return getRuleContext<GoParser::ElementTypeContext>(0);
}


size_t GoParser::ArrayTypeContext::getRuleIndex() const {
  return GoParser::RuleArrayType;
}

void GoParser::ArrayTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayType(this);
}

void GoParser::ArrayTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayType(this);
}

GoParser::ArrayTypeContext* GoParser::arrayType() {
  ArrayTypeContext *_localctx = _tracker.createInstance<ArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 112, GoParser::RuleArrayType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(653);
    match(GoParser::L_BRACKET);
    setState(654);
    arrayLength();
    setState(655);
    match(GoParser::R_BRACKET);
    setState(656);
    elementType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayLengthContext ------------------------------------------------------------------

GoParser::ArrayLengthContext::ArrayLengthContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ExpressionContext* GoParser::ArrayLengthContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}


size_t GoParser::ArrayLengthContext::getRuleIndex() const {
  return GoParser::RuleArrayLength;
}

void GoParser::ArrayLengthContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayLength(this);
}

void GoParser::ArrayLengthContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayLength(this);
}

GoParser::ArrayLengthContext* GoParser::arrayLength() {
  ArrayLengthContext *_localctx = _tracker.createInstance<ArrayLengthContext>(_ctx, getState());
  enterRule(_localctx, 114, GoParser::RuleArrayLength);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(658);
    expression(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementTypeContext ------------------------------------------------------------------

GoParser::ElementTypeContext::ElementTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::Type_Context* GoParser::ElementTypeContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}


size_t GoParser::ElementTypeContext::getRuleIndex() const {
  return GoParser::RuleElementType;
}

void GoParser::ElementTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElementType(this);
}

void GoParser::ElementTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElementType(this);
}

GoParser::ElementTypeContext* GoParser::elementType() {
  ElementTypeContext *_localctx = _tracker.createInstance<ElementTypeContext>(_ctx, getState());
  enterRule(_localctx, 116, GoParser::RuleElementType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(660);
    type_();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PointerTypeContext ------------------------------------------------------------------

GoParser::PointerTypeContext::PointerTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::PointerTypeContext::STAR() {
  return getToken(GoParser::STAR, 0);
}

GoParser::Type_Context* GoParser::PointerTypeContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}


size_t GoParser::PointerTypeContext::getRuleIndex() const {
  return GoParser::RulePointerType;
}

void GoParser::PointerTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPointerType(this);
}

void GoParser::PointerTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPointerType(this);
}

GoParser::PointerTypeContext* GoParser::pointerType() {
  PointerTypeContext *_localctx = _tracker.createInstance<PointerTypeContext>(_ctx, getState());
  enterRule(_localctx, 118, GoParser::RulePointerType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(662);
    match(GoParser::STAR);
    setState(663);
    type_();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- InterfaceTypeContext ------------------------------------------------------------------

GoParser::InterfaceTypeContext::InterfaceTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::InterfaceTypeContext::INTERFACE() {
  return getToken(GoParser::INTERFACE, 0);
}

tree::TerminalNode* GoParser::InterfaceTypeContext::L_CURLY() {
  return getToken(GoParser::L_CURLY, 0);
}

tree::TerminalNode* GoParser::InterfaceTypeContext::R_CURLY() {
  return getToken(GoParser::R_CURLY, 0);
}

std::vector<GoParser::EossContext *> GoParser::InterfaceTypeContext::eoss() {
  return getRuleContexts<GoParser::EossContext>();
}

GoParser::EossContext* GoParser::InterfaceTypeContext::eoss(size_t i) {
  return getRuleContext<GoParser::EossContext>(i);
}

std::vector<GoParser::MethodSpecContext *> GoParser::InterfaceTypeContext::methodSpec() {
  return getRuleContexts<GoParser::MethodSpecContext>();
}

GoParser::MethodSpecContext* GoParser::InterfaceTypeContext::methodSpec(size_t i) {
  return getRuleContext<GoParser::MethodSpecContext>(i);
}

std::vector<GoParser::TypeNameContext *> GoParser::InterfaceTypeContext::typeName() {
  return getRuleContexts<GoParser::TypeNameContext>();
}

GoParser::TypeNameContext* GoParser::InterfaceTypeContext::typeName(size_t i) {
  return getRuleContext<GoParser::TypeNameContext>(i);
}


size_t GoParser::InterfaceTypeContext::getRuleIndex() const {
  return GoParser::RuleInterfaceType;
}

void GoParser::InterfaceTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInterfaceType(this);
}

void GoParser::InterfaceTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInterfaceType(this);
}

GoParser::InterfaceTypeContext* GoParser::interfaceType() {
  InterfaceTypeContext *_localctx = _tracker.createInstance<InterfaceTypeContext>(_ctx, getState());
  enterRule(_localctx, 120, GoParser::RuleInterfaceType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(665);
    match(GoParser::INTERFACE);
    setState(666);
    match(GoParser::L_CURLY);
    setState(675);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GoParser::IDENTIFIER) {
      setState(669);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx)) {
      case 1: {
        setState(667);
        methodSpec();
        break;
      }

      case 2: {
        setState(668);
        typeName();
        break;
      }

      default:
        break;
      }
      setState(671);
      eoss();
      setState(677);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(678);
    match(GoParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SliceTypeContext ------------------------------------------------------------------

GoParser::SliceTypeContext::SliceTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::SliceTypeContext::L_BRACKET() {
  return getToken(GoParser::L_BRACKET, 0);
}

tree::TerminalNode* GoParser::SliceTypeContext::R_BRACKET() {
  return getToken(GoParser::R_BRACKET, 0);
}

GoParser::ElementTypeContext* GoParser::SliceTypeContext::elementType() {
  return getRuleContext<GoParser::ElementTypeContext>(0);
}


size_t GoParser::SliceTypeContext::getRuleIndex() const {
  return GoParser::RuleSliceType;
}

void GoParser::SliceTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSliceType(this);
}

void GoParser::SliceTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSliceType(this);
}

GoParser::SliceTypeContext* GoParser::sliceType() {
  SliceTypeContext *_localctx = _tracker.createInstance<SliceTypeContext>(_ctx, getState());
  enterRule(_localctx, 122, GoParser::RuleSliceType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(680);
    match(GoParser::L_BRACKET);
    setState(681);
    match(GoParser::R_BRACKET);
    setState(682);
    elementType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MapTypeContext ------------------------------------------------------------------

GoParser::MapTypeContext::MapTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::MapTypeContext::MAP() {
  return getToken(GoParser::MAP, 0);
}

tree::TerminalNode* GoParser::MapTypeContext::L_BRACKET() {
  return getToken(GoParser::L_BRACKET, 0);
}

GoParser::Type_Context* GoParser::MapTypeContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}

tree::TerminalNode* GoParser::MapTypeContext::R_BRACKET() {
  return getToken(GoParser::R_BRACKET, 0);
}

GoParser::ElementTypeContext* GoParser::MapTypeContext::elementType() {
  return getRuleContext<GoParser::ElementTypeContext>(0);
}


size_t GoParser::MapTypeContext::getRuleIndex() const {
  return GoParser::RuleMapType;
}

void GoParser::MapTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMapType(this);
}

void GoParser::MapTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMapType(this);
}

GoParser::MapTypeContext* GoParser::mapType() {
  MapTypeContext *_localctx = _tracker.createInstance<MapTypeContext>(_ctx, getState());
  enterRule(_localctx, 124, GoParser::RuleMapType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(684);
    match(GoParser::MAP);
    setState(685);
    match(GoParser::L_BRACKET);
    setState(686);
    type_();
    setState(687);
    match(GoParser::R_BRACKET);
    setState(688);
    elementType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ChannelTypeContext ------------------------------------------------------------------

GoParser::ChannelTypeContext::ChannelTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ElementTypeContext* GoParser::ChannelTypeContext::elementType() {
  return getRuleContext<GoParser::ElementTypeContext>(0);
}

tree::TerminalNode* GoParser::ChannelTypeContext::CHAN() {
  return getToken(GoParser::CHAN, 0);
}

tree::TerminalNode* GoParser::ChannelTypeContext::RECEIVE() {
  return getToken(GoParser::RECEIVE, 0);
}


size_t GoParser::ChannelTypeContext::getRuleIndex() const {
  return GoParser::RuleChannelType;
}

void GoParser::ChannelTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterChannelType(this);
}

void GoParser::ChannelTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitChannelType(this);
}

GoParser::ChannelTypeContext* GoParser::channelType() {
  ChannelTypeContext *_localctx = _tracker.createInstance<ChannelTypeContext>(_ctx, getState());
  enterRule(_localctx, 126, GoParser::RuleChannelType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(695);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
    case 1: {
      setState(690);
      match(GoParser::CHAN);
      break;
    }

    case 2: {
      setState(691);
      match(GoParser::CHAN);
      setState(692);
      match(GoParser::RECEIVE);
      break;
    }

    case 3: {
      setState(693);
      match(GoParser::RECEIVE);
      setState(694);
      match(GoParser::CHAN);
      break;
    }

    default:
      break;
    }
    setState(697);
    elementType();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodSpecContext ------------------------------------------------------------------

GoParser::MethodSpecContext::MethodSpecContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::MethodSpecContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}

GoParser::ParametersContext* GoParser::MethodSpecContext::parameters() {
  return getRuleContext<GoParser::ParametersContext>(0);
}

GoParser::ResultContext* GoParser::MethodSpecContext::result() {
  return getRuleContext<GoParser::ResultContext>(0);
}


size_t GoParser::MethodSpecContext::getRuleIndex() const {
  return GoParser::RuleMethodSpec;
}

void GoParser::MethodSpecContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodSpec(this);
}

void GoParser::MethodSpecContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodSpec(this);
}

GoParser::MethodSpecContext* GoParser::methodSpec() {
  MethodSpecContext *_localctx = _tracker.createInstance<MethodSpecContext>(_ctx, getState());
  enterRule(_localctx, 128, GoParser::RuleMethodSpec);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(705);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(699);
      match(GoParser::IDENTIFIER);
      setState(700);
      parameters();
      setState(701);
      result();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(703);
      match(GoParser::IDENTIFIER);
      setState(704);
      parameters();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionTypeContext ------------------------------------------------------------------

GoParser::FunctionTypeContext::FunctionTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::FunctionTypeContext::FUNC() {
  return getToken(GoParser::FUNC, 0);
}

GoParser::SignatureContext* GoParser::FunctionTypeContext::signature() {
  return getRuleContext<GoParser::SignatureContext>(0);
}


size_t GoParser::FunctionTypeContext::getRuleIndex() const {
  return GoParser::RuleFunctionType;
}

void GoParser::FunctionTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionType(this);
}

void GoParser::FunctionTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionType(this);
}

GoParser::FunctionTypeContext* GoParser::functionType() {
  FunctionTypeContext *_localctx = _tracker.createInstance<FunctionTypeContext>(_ctx, getState());
  enterRule(_localctx, 130, GoParser::RuleFunctionType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(707);
    match(GoParser::FUNC);
    setState(708);
    signature();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SignatureContext ------------------------------------------------------------------

GoParser::SignatureContext::SignatureContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ParametersContext* GoParser::SignatureContext::parameters() {
  return getRuleContext<GoParser::ParametersContext>(0);
}

GoParser::ResultContext* GoParser::SignatureContext::result() {
  return getRuleContext<GoParser::ResultContext>(0);
}


size_t GoParser::SignatureContext::getRuleIndex() const {
  return GoParser::RuleSignature;
}

void GoParser::SignatureContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSignature(this);
}

void GoParser::SignatureContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSignature(this);
}

GoParser::SignatureContext* GoParser::signature() {
  SignatureContext *_localctx = _tracker.createInstance<SignatureContext>(_ctx, getState());
  enterRule(_localctx, 132, GoParser::RuleSignature);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(714);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 72, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(710);
      parameters();
      setState(711);
      result();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(713);
      parameters();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ResultContext ------------------------------------------------------------------

GoParser::ResultContext::ResultContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ParametersContext* GoParser::ResultContext::parameters() {
  return getRuleContext<GoParser::ParametersContext>(0);
}

GoParser::Type_Context* GoParser::ResultContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}


size_t GoParser::ResultContext::getRuleIndex() const {
  return GoParser::RuleResult;
}

void GoParser::ResultContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterResult(this);
}

void GoParser::ResultContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitResult(this);
}

GoParser::ResultContext* GoParser::result() {
  ResultContext *_localctx = _tracker.createInstance<ResultContext>(_ctx, getState());
  enterRule(_localctx, 134, GoParser::RuleResult);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(718);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 73, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(716);
      parameters();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(717);
      type_();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

GoParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::ParametersContext::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

tree::TerminalNode* GoParser::ParametersContext::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}

std::vector<GoParser::ParameterDeclContext *> GoParser::ParametersContext::parameterDecl() {
  return getRuleContexts<GoParser::ParameterDeclContext>();
}

GoParser::ParameterDeclContext* GoParser::ParametersContext::parameterDecl(size_t i) {
  return getRuleContext<GoParser::ParameterDeclContext>(i);
}

std::vector<tree::TerminalNode *> GoParser::ParametersContext::COMMA() {
  return getTokens(GoParser::COMMA);
}

tree::TerminalNode* GoParser::ParametersContext::COMMA(size_t i) {
  return getToken(GoParser::COMMA, i);
}


size_t GoParser::ParametersContext::getRuleIndex() const {
  return GoParser::RuleParameters;
}

void GoParser::ParametersContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameters(this);
}

void GoParser::ParametersContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameters(this);
}

GoParser::ParametersContext* GoParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 136, GoParser::RuleParameters);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(720);
    match(GoParser::L_PAREN);
    setState(732);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 3) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 3)) & ((1ULL << (GoParser::FUNC - 3))
      | (1ULL << (GoParser::INTERFACE - 3))
      | (1ULL << (GoParser::MAP - 3))
      | (1ULL << (GoParser::STRUCT - 3))
      | (1ULL << (GoParser::CHAN - 3))
      | (1ULL << (GoParser::IDENTIFIER - 3))
      | (1ULL << (GoParser::L_PAREN - 3))
      | (1ULL << (GoParser::L_BRACKET - 3))
      | (1ULL << (GoParser::ELLIPSIS - 3))
      | (1ULL << (GoParser::STAR - 3))
      | (1ULL << (GoParser::RECEIVE - 3)))) != 0)) {
      setState(721);
      parameterDecl();
      setState(726);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(722);
          match(GoParser::COMMA);
          setState(723);
          parameterDecl(); 
        }
        setState(728);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 74, _ctx);
      }
      setState(730);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == GoParser::COMMA) {
        setState(729);
        match(GoParser::COMMA);
      }
    }
    setState(734);
    match(GoParser::R_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParameterDeclContext ------------------------------------------------------------------

GoParser::ParameterDeclContext::ParameterDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::Type_Context* GoParser::ParameterDeclContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}

GoParser::IdentifierListContext* GoParser::ParameterDeclContext::identifierList() {
  return getRuleContext<GoParser::IdentifierListContext>(0);
}

tree::TerminalNode* GoParser::ParameterDeclContext::ELLIPSIS() {
  return getToken(GoParser::ELLIPSIS, 0);
}


size_t GoParser::ParameterDeclContext::getRuleIndex() const {
  return GoParser::RuleParameterDecl;
}

void GoParser::ParameterDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParameterDecl(this);
}

void GoParser::ParameterDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParameterDecl(this);
}

GoParser::ParameterDeclContext* GoParser::parameterDecl() {
  ParameterDeclContext *_localctx = _tracker.createInstance<ParameterDeclContext>(_ctx, getState());
  enterRule(_localctx, 138, GoParser::RuleParameterDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(737);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 77, _ctx)) {
    case 1: {
      setState(736);
      identifierList();
      break;
    }

    default:
      break;
    }
    setState(740);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GoParser::ELLIPSIS) {
      setState(739);
      match(GoParser::ELLIPSIS);
    }
    setState(742);
    type_();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

GoParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t GoParser::ExpressionContext::getRuleIndex() const {
  return GoParser::RuleExpression;
}

void GoParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- LogicalAndOperationContext ------------------------------------------------------------------

std::vector<GoParser::ExpressionContext *> GoParser::LogicalAndOperationContext::expression() {
  return getRuleContexts<GoParser::ExpressionContext>();
}

GoParser::ExpressionContext* GoParser::LogicalAndOperationContext::expression(size_t i) {
  return getRuleContext<GoParser::ExpressionContext>(i);
}

tree::TerminalNode* GoParser::LogicalAndOperationContext::LOGICAL_AND() {
  return getToken(GoParser::LOGICAL_AND, 0);
}

GoParser::LogicalAndOperationContext::LogicalAndOperationContext(ExpressionContext *ctx) { copyFrom(ctx); }

void GoParser::LogicalAndOperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalAndOperation(this);
}
void GoParser::LogicalAndOperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalAndOperation(this);
}
//----------------- UnaryOperationContext ------------------------------------------------------------------

GoParser::ExpressionContext* GoParser::UnaryOperationContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

tree::TerminalNode* GoParser::UnaryOperationContext::PLUS() {
  return getToken(GoParser::PLUS, 0);
}

tree::TerminalNode* GoParser::UnaryOperationContext::MINUS() {
  return getToken(GoParser::MINUS, 0);
}

tree::TerminalNode* GoParser::UnaryOperationContext::EXCLAMATION() {
  return getToken(GoParser::EXCLAMATION, 0);
}

tree::TerminalNode* GoParser::UnaryOperationContext::CARET() {
  return getToken(GoParser::CARET, 0);
}

tree::TerminalNode* GoParser::UnaryOperationContext::STAR() {
  return getToken(GoParser::STAR, 0);
}

tree::TerminalNode* GoParser::UnaryOperationContext::AMPERSAND() {
  return getToken(GoParser::AMPERSAND, 0);
}

tree::TerminalNode* GoParser::UnaryOperationContext::RECEIVE() {
  return getToken(GoParser::RECEIVE, 0);
}

GoParser::UnaryOperationContext::UnaryOperationContext(ExpressionContext *ctx) { copyFrom(ctx); }

void GoParser::UnaryOperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOperation(this);
}
void GoParser::UnaryOperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOperation(this);
}
//----------------- PrimaryExpressionContext ------------------------------------------------------------------

GoParser::PrimaryExprContext* GoParser::PrimaryExpressionContext::primaryExpr() {
  return getRuleContext<GoParser::PrimaryExprContext>(0);
}

GoParser::PrimaryExpressionContext::PrimaryExpressionContext(ExpressionContext *ctx) { copyFrom(ctx); }

void GoParser::PrimaryExpressionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpression(this);
}
void GoParser::PrimaryExpressionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpression(this);
}
//----------------- PlusMinusOperationContext ------------------------------------------------------------------

std::vector<GoParser::ExpressionContext *> GoParser::PlusMinusOperationContext::expression() {
  return getRuleContexts<GoParser::ExpressionContext>();
}

GoParser::ExpressionContext* GoParser::PlusMinusOperationContext::expression(size_t i) {
  return getRuleContext<GoParser::ExpressionContext>(i);
}

tree::TerminalNode* GoParser::PlusMinusOperationContext::PLUS() {
  return getToken(GoParser::PLUS, 0);
}

tree::TerminalNode* GoParser::PlusMinusOperationContext::MINUS() {
  return getToken(GoParser::MINUS, 0);
}

tree::TerminalNode* GoParser::PlusMinusOperationContext::OR() {
  return getToken(GoParser::OR, 0);
}

tree::TerminalNode* GoParser::PlusMinusOperationContext::CARET() {
  return getToken(GoParser::CARET, 0);
}

GoParser::PlusMinusOperationContext::PlusMinusOperationContext(ExpressionContext *ctx) { copyFrom(ctx); }

void GoParser::PlusMinusOperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPlusMinusOperation(this);
}
void GoParser::PlusMinusOperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPlusMinusOperation(this);
}
//----------------- RelationOperationContext ------------------------------------------------------------------

std::vector<GoParser::ExpressionContext *> GoParser::RelationOperationContext::expression() {
  return getRuleContexts<GoParser::ExpressionContext>();
}

GoParser::ExpressionContext* GoParser::RelationOperationContext::expression(size_t i) {
  return getRuleContext<GoParser::ExpressionContext>(i);
}

tree::TerminalNode* GoParser::RelationOperationContext::EQUALS() {
  return getToken(GoParser::EQUALS, 0);
}

tree::TerminalNode* GoParser::RelationOperationContext::NOT_EQUALS() {
  return getToken(GoParser::NOT_EQUALS, 0);
}

tree::TerminalNode* GoParser::RelationOperationContext::LESS() {
  return getToken(GoParser::LESS, 0);
}

tree::TerminalNode* GoParser::RelationOperationContext::LESS_OR_EQUALS() {
  return getToken(GoParser::LESS_OR_EQUALS, 0);
}

tree::TerminalNode* GoParser::RelationOperationContext::GREATER() {
  return getToken(GoParser::GREATER, 0);
}

tree::TerminalNode* GoParser::RelationOperationContext::GREATER_OR_EQUALS() {
  return getToken(GoParser::GREATER_OR_EQUALS, 0);
}

GoParser::RelationOperationContext::RelationOperationContext(ExpressionContext *ctx) { copyFrom(ctx); }

void GoParser::RelationOperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterRelationOperation(this);
}
void GoParser::RelationOperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitRelationOperation(this);
}
//----------------- MulDivOperationContext ------------------------------------------------------------------

std::vector<GoParser::ExpressionContext *> GoParser::MulDivOperationContext::expression() {
  return getRuleContexts<GoParser::ExpressionContext>();
}

GoParser::ExpressionContext* GoParser::MulDivOperationContext::expression(size_t i) {
  return getRuleContext<GoParser::ExpressionContext>(i);
}

tree::TerminalNode* GoParser::MulDivOperationContext::STAR() {
  return getToken(GoParser::STAR, 0);
}

tree::TerminalNode* GoParser::MulDivOperationContext::DIV() {
  return getToken(GoParser::DIV, 0);
}

tree::TerminalNode* GoParser::MulDivOperationContext::MOD() {
  return getToken(GoParser::MOD, 0);
}

tree::TerminalNode* GoParser::MulDivOperationContext::LSHIFT() {
  return getToken(GoParser::LSHIFT, 0);
}

tree::TerminalNode* GoParser::MulDivOperationContext::RSHIFT() {
  return getToken(GoParser::RSHIFT, 0);
}

tree::TerminalNode* GoParser::MulDivOperationContext::AMPERSAND() {
  return getToken(GoParser::AMPERSAND, 0);
}

tree::TerminalNode* GoParser::MulDivOperationContext::BIT_CLEAR() {
  return getToken(GoParser::BIT_CLEAR, 0);
}

GoParser::MulDivOperationContext::MulDivOperationContext(ExpressionContext *ctx) { copyFrom(ctx); }

void GoParser::MulDivOperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulDivOperation(this);
}
void GoParser::MulDivOperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulDivOperation(this);
}
//----------------- LogicalOrOperationContext ------------------------------------------------------------------

std::vector<GoParser::ExpressionContext *> GoParser::LogicalOrOperationContext::expression() {
  return getRuleContexts<GoParser::ExpressionContext>();
}

GoParser::ExpressionContext* GoParser::LogicalOrOperationContext::expression(size_t i) {
  return getRuleContext<GoParser::ExpressionContext>(i);
}

tree::TerminalNode* GoParser::LogicalOrOperationContext::LOGICAL_OR() {
  return getToken(GoParser::LOGICAL_OR, 0);
}

GoParser::LogicalOrOperationContext::LogicalOrOperationContext(ExpressionContext *ctx) { copyFrom(ctx); }

void GoParser::LogicalOrOperationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLogicalOrOperation(this);
}
void GoParser::LogicalOrOperationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLogicalOrOperation(this);
}

GoParser::ExpressionContext* GoParser::expression() {
   return expression(0);
}

GoParser::ExpressionContext* GoParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  GoParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  GoParser::ExpressionContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 140;
  enterRecursionRule(_localctx, 140, GoParser::RuleExpression, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(748);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 79, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<PrimaryExpressionContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(745);
      primaryExpr(0);
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<UnaryOperationContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(746);
      antlrcpp::downCast<UnaryOperationContext *>(_localctx)->unary_op = _input->LT(1);
      _la = _input->LA(1);
      if (!(((((_la - 60) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 60)) & ((1ULL << (GoParser::EXCLAMATION - 60))
        | (1ULL << (GoParser::PLUS - 60))
        | (1ULL << (GoParser::MINUS - 60))
        | (1ULL << (GoParser::CARET - 60))
        | (1ULL << (GoParser::STAR - 60))
        | (1ULL << (GoParser::AMPERSAND - 60))
        | (1ULL << (GoParser::RECEIVE - 60)))) != 0))) {
        antlrcpp::downCast<UnaryOperationContext *>(_localctx)->unary_op = _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(747);
      expression(6);
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(767);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(765);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 80, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivOperationContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(750);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(751);
          antlrcpp::downCast<MulDivOperationContext *>(_localctx)->mul_op = _input->LT(1);
          _la = _input->LA(1);
          if (!(((((_la - 55) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 55)) & ((1ULL << (GoParser::DIV - 55))
            | (1ULL << (GoParser::MOD - 55))
            | (1ULL << (GoParser::LSHIFT - 55))
            | (1ULL << (GoParser::RSHIFT - 55))
            | (1ULL << (GoParser::BIT_CLEAR - 55))
            | (1ULL << (GoParser::STAR - 55))
            | (1ULL << (GoParser::AMPERSAND - 55)))) != 0))) {
            antlrcpp::downCast<MulDivOperationContext *>(_localctx)->mul_op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(752);
          expression(6);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<PlusMinusOperationContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(753);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(754);
          antlrcpp::downCast<PlusMinusOperationContext *>(_localctx)->add_op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << GoParser::OR)
            | (1ULL << GoParser::PLUS)
            | (1ULL << GoParser::MINUS)
            | (1ULL << GoParser::CARET))) != 0))) {
            antlrcpp::downCast<PlusMinusOperationContext *>(_localctx)->add_op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(755);
          expression(5);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<RelationOperationContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(756);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(757);
          antlrcpp::downCast<RelationOperationContext *>(_localctx)->rel_op = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << GoParser::EQUALS)
            | (1ULL << GoParser::NOT_EQUALS)
            | (1ULL << GoParser::LESS)
            | (1ULL << GoParser::LESS_OR_EQUALS)
            | (1ULL << GoParser::GREATER)
            | (1ULL << GoParser::GREATER_OR_EQUALS))) != 0))) {
            antlrcpp::downCast<RelationOperationContext *>(_localctx)->rel_op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(758);
          expression(4);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<LogicalAndOperationContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(759);

          if (!(precpred(_ctx, 2))) throw FailedPredicateException(this, "precpred(_ctx, 2)");
          setState(760);
          match(GoParser::LOGICAL_AND);
          setState(761);
          expression(3);
          break;
        }

        case 5: {
          auto newContext = _tracker.createInstance<LogicalOrOperationContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(762);

          if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
          setState(763);
          match(GoParser::LOGICAL_OR);
          setState(764);
          expression(2);
          break;
        }

        default:
          break;
        } 
      }
      setState(769);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 81, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- PrimaryExprContext ------------------------------------------------------------------

GoParser::PrimaryExprContext::PrimaryExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::OperandContext* GoParser::PrimaryExprContext::operand() {
  return getRuleContext<GoParser::OperandContext>(0);
}

GoParser::ConversionContext* GoParser::PrimaryExprContext::conversion() {
  return getRuleContext<GoParser::ConversionContext>(0);
}

GoParser::MethodExprContext* GoParser::PrimaryExprContext::methodExpr() {
  return getRuleContext<GoParser::MethodExprContext>(0);
}

GoParser::PrimaryExprContext* GoParser::PrimaryExprContext::primaryExpr() {
  return getRuleContext<GoParser::PrimaryExprContext>(0);
}

GoParser::IndexContext* GoParser::PrimaryExprContext::index() {
  return getRuleContext<GoParser::IndexContext>(0);
}

GoParser::Slice_Context* GoParser::PrimaryExprContext::slice_() {
  return getRuleContext<GoParser::Slice_Context>(0);
}

GoParser::TypeAssertionContext* GoParser::PrimaryExprContext::typeAssertion() {
  return getRuleContext<GoParser::TypeAssertionContext>(0);
}

GoParser::ArgumentsContext* GoParser::PrimaryExprContext::arguments() {
  return getRuleContext<GoParser::ArgumentsContext>(0);
}

tree::TerminalNode* GoParser::PrimaryExprContext::DOT() {
  return getToken(GoParser::DOT, 0);
}

tree::TerminalNode* GoParser::PrimaryExprContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}


size_t GoParser::PrimaryExprContext::getRuleIndex() const {
  return GoParser::RulePrimaryExpr;
}

void GoParser::PrimaryExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPrimaryExpr(this);
}

void GoParser::PrimaryExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPrimaryExpr(this);
}


GoParser::PrimaryExprContext* GoParser::primaryExpr() {
   return primaryExpr(0);
}

GoParser::PrimaryExprContext* GoParser::primaryExpr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  GoParser::PrimaryExprContext *_localctx = _tracker.createInstance<PrimaryExprContext>(_ctx, parentState);
  GoParser::PrimaryExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 142;
  enterRecursionRule(_localctx, 142, GoParser::RulePrimaryExpr, precedence);

    

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(774);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 82, _ctx)) {
    case 1: {
      setState(771);
      operand();
      break;
    }

    case 2: {
      setState(772);
      conversion();
      break;
    }

    case 3: {
      setState(773);
      methodExpr();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(787);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        _localctx = _tracker.createInstance<PrimaryExprContext>(parentContext, parentState);
        pushNewRecursionContext(_localctx, startState, RulePrimaryExpr);
        setState(776);

        if (!(precpred(_ctx, 1))) throw FailedPredicateException(this, "precpred(_ctx, 1)");
        setState(783);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 83, _ctx)) {
        case 1: {
          setState(777);
          match(GoParser::DOT);
          setState(778);
          match(GoParser::IDENTIFIER);
          break;
        }

        case 2: {
          setState(779);
          index();
          break;
        }

        case 3: {
          setState(780);
          slice_();
          break;
        }

        case 4: {
          setState(781);
          typeAssertion();
          break;
        }

        case 5: {
          setState(782);
          arguments();
          break;
        }

        default:
          break;
        } 
      }
      setState(789);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 84, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ConversionContext ------------------------------------------------------------------

GoParser::ConversionContext::ConversionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::NonNamedTypeContext* GoParser::ConversionContext::nonNamedType() {
  return getRuleContext<GoParser::NonNamedTypeContext>(0);
}

tree::TerminalNode* GoParser::ConversionContext::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

GoParser::ExpressionContext* GoParser::ConversionContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

tree::TerminalNode* GoParser::ConversionContext::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}

tree::TerminalNode* GoParser::ConversionContext::COMMA() {
  return getToken(GoParser::COMMA, 0);
}


size_t GoParser::ConversionContext::getRuleIndex() const {
  return GoParser::RuleConversion;
}

void GoParser::ConversionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterConversion(this);
}

void GoParser::ConversionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitConversion(this);
}

GoParser::ConversionContext* GoParser::conversion() {
  ConversionContext *_localctx = _tracker.createInstance<ConversionContext>(_ctx, getState());
  enterRule(_localctx, 144, GoParser::RuleConversion);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(790);
    nonNamedType();
    setState(791);
    match(GoParser::L_PAREN);
    setState(792);
    expression(0);
    setState(794);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GoParser::COMMA) {
      setState(793);
      match(GoParser::COMMA);
    }
    setState(796);
    match(GoParser::R_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NonNamedTypeContext ------------------------------------------------------------------

GoParser::NonNamedTypeContext::NonNamedTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::TypeLitContext* GoParser::NonNamedTypeContext::typeLit() {
  return getRuleContext<GoParser::TypeLitContext>(0);
}

tree::TerminalNode* GoParser::NonNamedTypeContext::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

GoParser::NonNamedTypeContext* GoParser::NonNamedTypeContext::nonNamedType() {
  return getRuleContext<GoParser::NonNamedTypeContext>(0);
}

tree::TerminalNode* GoParser::NonNamedTypeContext::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}


size_t GoParser::NonNamedTypeContext::getRuleIndex() const {
  return GoParser::RuleNonNamedType;
}

void GoParser::NonNamedTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNonNamedType(this);
}

void GoParser::NonNamedTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNonNamedType(this);
}

GoParser::NonNamedTypeContext* GoParser::nonNamedType() {
  NonNamedTypeContext *_localctx = _tracker.createInstance<NonNamedTypeContext>(_ctx, getState());
  enterRule(_localctx, 146, GoParser::RuleNonNamedType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(803);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::FUNC:
      case GoParser::INTERFACE:
      case GoParser::MAP:
      case GoParser::STRUCT:
      case GoParser::CHAN:
      case GoParser::L_BRACKET:
      case GoParser::STAR:
      case GoParser::RECEIVE: {
        enterOuterAlt(_localctx, 1);
        setState(798);
        typeLit();
        break;
      }

      case GoParser::L_PAREN: {
        enterOuterAlt(_localctx, 2);
        setState(799);
        match(GoParser::L_PAREN);
        setState(800);
        nonNamedType();
        setState(801);
        match(GoParser::R_PAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- OperandContext ------------------------------------------------------------------

GoParser::OperandContext::OperandContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::LiteralContext* GoParser::OperandContext::literal() {
  return getRuleContext<GoParser::LiteralContext>(0);
}

GoParser::OperandNameContext* GoParser::OperandContext::operandName() {
  return getRuleContext<GoParser::OperandNameContext>(0);
}

tree::TerminalNode* GoParser::OperandContext::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

GoParser::ExpressionContext* GoParser::OperandContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

tree::TerminalNode* GoParser::OperandContext::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}


size_t GoParser::OperandContext::getRuleIndex() const {
  return GoParser::RuleOperand;
}

void GoParser::OperandContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperand(this);
}

void GoParser::OperandContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperand(this);
}

GoParser::OperandContext* GoParser::operand() {
  OperandContext *_localctx = _tracker.createInstance<OperandContext>(_ctx, getState());
  enterRule(_localctx, 148, GoParser::RuleOperand);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(811);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 87, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(805);
      literal();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(806);
      operandName();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(807);
      match(GoParser::L_PAREN);
      setState(808);
      expression(0);
      setState(809);
      match(GoParser::R_PAREN);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

GoParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::BasicLitContext* GoParser::LiteralContext::basicLit() {
  return getRuleContext<GoParser::BasicLitContext>(0);
}

GoParser::CompositeLitContext* GoParser::LiteralContext::compositeLit() {
  return getRuleContext<GoParser::CompositeLitContext>(0);
}

GoParser::FunctionLitContext* GoParser::LiteralContext::functionLit() {
  return getRuleContext<GoParser::FunctionLitContext>(0);
}


size_t GoParser::LiteralContext::getRuleIndex() const {
  return GoParser::RuleLiteral;
}

void GoParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void GoParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}

GoParser::LiteralContext* GoParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 150, GoParser::RuleLiteral);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(816);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::NIL_LIT:
      case GoParser::DECIMAL_LIT:
      case GoParser::BINARY_LIT:
      case GoParser::OCTAL_LIT:
      case GoParser::HEX_LIT:
      case GoParser::FLOAT_LIT:
      case GoParser::IMAGINARY_LIT:
      case GoParser::RUNE_LIT:
      case GoParser::RAW_STRING_LIT:
      case GoParser::INTERPRETED_STRING_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(813);
        basicLit();
        break;
      }

      case GoParser::MAP:
      case GoParser::STRUCT:
      case GoParser::IDENTIFIER:
      case GoParser::L_BRACKET: {
        enterOuterAlt(_localctx, 2);
        setState(814);
        compositeLit();
        break;
      }

      case GoParser::FUNC: {
        enterOuterAlt(_localctx, 3);
        setState(815);
        functionLit();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BasicLitContext ------------------------------------------------------------------

GoParser::BasicLitContext::BasicLitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::BasicLitContext::NIL_LIT() {
  return getToken(GoParser::NIL_LIT, 0);
}

GoParser::IntegerContext* GoParser::BasicLitContext::integer() {
  return getRuleContext<GoParser::IntegerContext>(0);
}

GoParser::String_Context* GoParser::BasicLitContext::string_() {
  return getRuleContext<GoParser::String_Context>(0);
}

tree::TerminalNode* GoParser::BasicLitContext::FLOAT_LIT() {
  return getToken(GoParser::FLOAT_LIT, 0);
}


size_t GoParser::BasicLitContext::getRuleIndex() const {
  return GoParser::RuleBasicLit;
}

void GoParser::BasicLitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBasicLit(this);
}

void GoParser::BasicLitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBasicLit(this);
}

GoParser::BasicLitContext* GoParser::basicLit() {
  BasicLitContext *_localctx = _tracker.createInstance<BasicLitContext>(_ctx, getState());
  enterRule(_localctx, 152, GoParser::RuleBasicLit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(822);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::NIL_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(818);
        match(GoParser::NIL_LIT);
        break;
      }

      case GoParser::DECIMAL_LIT:
      case GoParser::BINARY_LIT:
      case GoParser::OCTAL_LIT:
      case GoParser::HEX_LIT:
      case GoParser::IMAGINARY_LIT:
      case GoParser::RUNE_LIT: {
        enterOuterAlt(_localctx, 2);
        setState(819);
        integer();
        break;
      }

      case GoParser::RAW_STRING_LIT:
      case GoParser::INTERPRETED_STRING_LIT: {
        enterOuterAlt(_localctx, 3);
        setState(820);
        string_();
        break;
      }

      case GoParser::FLOAT_LIT: {
        enterOuterAlt(_localctx, 4);
        setState(821);
        match(GoParser::FLOAT_LIT);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IntegerContext ------------------------------------------------------------------

GoParser::IntegerContext::IntegerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::IntegerContext::DECIMAL_LIT() {
  return getToken(GoParser::DECIMAL_LIT, 0);
}

tree::TerminalNode* GoParser::IntegerContext::BINARY_LIT() {
  return getToken(GoParser::BINARY_LIT, 0);
}

tree::TerminalNode* GoParser::IntegerContext::OCTAL_LIT() {
  return getToken(GoParser::OCTAL_LIT, 0);
}

tree::TerminalNode* GoParser::IntegerContext::HEX_LIT() {
  return getToken(GoParser::HEX_LIT, 0);
}

tree::TerminalNode* GoParser::IntegerContext::IMAGINARY_LIT() {
  return getToken(GoParser::IMAGINARY_LIT, 0);
}

tree::TerminalNode* GoParser::IntegerContext::RUNE_LIT() {
  return getToken(GoParser::RUNE_LIT, 0);
}


size_t GoParser::IntegerContext::getRuleIndex() const {
  return GoParser::RuleInteger;
}

void GoParser::IntegerContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInteger(this);
}

void GoParser::IntegerContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInteger(this);
}

GoParser::IntegerContext* GoParser::integer() {
  IntegerContext *_localctx = _tracker.createInstance<IntegerContext>(_ctx, getState());
  enterRule(_localctx, 154, GoParser::RuleInteger);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(824);
    _la = _input->LA(1);
    if (!(((((_la - 67) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 67)) & ((1ULL << (GoParser::DECIMAL_LIT - 67))
      | (1ULL << (GoParser::BINARY_LIT - 67))
      | (1ULL << (GoParser::OCTAL_LIT - 67))
      | (1ULL << (GoParser::HEX_LIT - 67))
      | (1ULL << (GoParser::IMAGINARY_LIT - 67))
      | (1ULL << (GoParser::RUNE_LIT - 67)))) != 0))) {
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

//----------------- OperandNameContext ------------------------------------------------------------------

GoParser::OperandNameContext::OperandNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::OperandNameContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}


size_t GoParser::OperandNameContext::getRuleIndex() const {
  return GoParser::RuleOperandName;
}

void GoParser::OperandNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterOperandName(this);
}

void GoParser::OperandNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitOperandName(this);
}

GoParser::OperandNameContext* GoParser::operandName() {
  OperandNameContext *_localctx = _tracker.createInstance<OperandNameContext>(_ctx, getState());
  enterRule(_localctx, 156, GoParser::RuleOperandName);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(826);
    match(GoParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- QualifiedIdentContext ------------------------------------------------------------------

GoParser::QualifiedIdentContext::QualifiedIdentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> GoParser::QualifiedIdentContext::IDENTIFIER() {
  return getTokens(GoParser::IDENTIFIER);
}

tree::TerminalNode* GoParser::QualifiedIdentContext::IDENTIFIER(size_t i) {
  return getToken(GoParser::IDENTIFIER, i);
}

tree::TerminalNode* GoParser::QualifiedIdentContext::DOT() {
  return getToken(GoParser::DOT, 0);
}


size_t GoParser::QualifiedIdentContext::getRuleIndex() const {
  return GoParser::RuleQualifiedIdent;
}

void GoParser::QualifiedIdentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterQualifiedIdent(this);
}

void GoParser::QualifiedIdentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitQualifiedIdent(this);
}

GoParser::QualifiedIdentContext* GoParser::qualifiedIdent() {
  QualifiedIdentContext *_localctx = _tracker.createInstance<QualifiedIdentContext>(_ctx, getState());
  enterRule(_localctx, 158, GoParser::RuleQualifiedIdent);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(828);
    match(GoParser::IDENTIFIER);
    setState(829);
    match(GoParser::DOT);
    setState(830);
    match(GoParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CompositeLitContext ------------------------------------------------------------------

GoParser::CompositeLitContext::CompositeLitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::LiteralTypeContext* GoParser::CompositeLitContext::literalType() {
  return getRuleContext<GoParser::LiteralTypeContext>(0);
}

GoParser::LiteralValueContext* GoParser::CompositeLitContext::literalValue() {
  return getRuleContext<GoParser::LiteralValueContext>(0);
}


size_t GoParser::CompositeLitContext::getRuleIndex() const {
  return GoParser::RuleCompositeLit;
}

void GoParser::CompositeLitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCompositeLit(this);
}

void GoParser::CompositeLitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCompositeLit(this);
}

GoParser::CompositeLitContext* GoParser::compositeLit() {
  CompositeLitContext *_localctx = _tracker.createInstance<CompositeLitContext>(_ctx, getState());
  enterRule(_localctx, 160, GoParser::RuleCompositeLit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(832);
    literalType();
    setState(833);
    literalValue();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralTypeContext ------------------------------------------------------------------

GoParser::LiteralTypeContext::LiteralTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::StructTypeContext* GoParser::LiteralTypeContext::structType() {
  return getRuleContext<GoParser::StructTypeContext>(0);
}

GoParser::ArrayTypeContext* GoParser::LiteralTypeContext::arrayType() {
  return getRuleContext<GoParser::ArrayTypeContext>(0);
}

tree::TerminalNode* GoParser::LiteralTypeContext::L_BRACKET() {
  return getToken(GoParser::L_BRACKET, 0);
}

tree::TerminalNode* GoParser::LiteralTypeContext::ELLIPSIS() {
  return getToken(GoParser::ELLIPSIS, 0);
}

tree::TerminalNode* GoParser::LiteralTypeContext::R_BRACKET() {
  return getToken(GoParser::R_BRACKET, 0);
}

GoParser::ElementTypeContext* GoParser::LiteralTypeContext::elementType() {
  return getRuleContext<GoParser::ElementTypeContext>(0);
}

GoParser::SliceTypeContext* GoParser::LiteralTypeContext::sliceType() {
  return getRuleContext<GoParser::SliceTypeContext>(0);
}

GoParser::MapTypeContext* GoParser::LiteralTypeContext::mapType() {
  return getRuleContext<GoParser::MapTypeContext>(0);
}

GoParser::TypeNameContext* GoParser::LiteralTypeContext::typeName() {
  return getRuleContext<GoParser::TypeNameContext>(0);
}


size_t GoParser::LiteralTypeContext::getRuleIndex() const {
  return GoParser::RuleLiteralType;
}

void GoParser::LiteralTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralType(this);
}

void GoParser::LiteralTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralType(this);
}

GoParser::LiteralTypeContext* GoParser::literalType() {
  LiteralTypeContext *_localctx = _tracker.createInstance<LiteralTypeContext>(_ctx, getState());
  enterRule(_localctx, 162, GoParser::RuleLiteralType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(844);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 90, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(835);
      structType();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(836);
      arrayType();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(837);
      match(GoParser::L_BRACKET);
      setState(838);
      match(GoParser::ELLIPSIS);
      setState(839);
      match(GoParser::R_BRACKET);
      setState(840);
      elementType();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(841);
      sliceType();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(842);
      mapType();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(843);
      typeName();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralValueContext ------------------------------------------------------------------

GoParser::LiteralValueContext::LiteralValueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::LiteralValueContext::L_CURLY() {
  return getToken(GoParser::L_CURLY, 0);
}

tree::TerminalNode* GoParser::LiteralValueContext::R_CURLY() {
  return getToken(GoParser::R_CURLY, 0);
}

GoParser::ElementListContext* GoParser::LiteralValueContext::elementList() {
  return getRuleContext<GoParser::ElementListContext>(0);
}

tree::TerminalNode* GoParser::LiteralValueContext::COMMA() {
  return getToken(GoParser::COMMA, 0);
}


size_t GoParser::LiteralValueContext::getRuleIndex() const {
  return GoParser::RuleLiteralValue;
}

void GoParser::LiteralValueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteralValue(this);
}

void GoParser::LiteralValueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteralValue(this);
}

GoParser::LiteralValueContext* GoParser::literalValue() {
  LiteralValueContext *_localctx = _tracker.createInstance<LiteralValueContext>(_ctx, getState());
  enterRule(_localctx, 164, GoParser::RuleLiteralValue);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(846);
    match(GoParser::L_CURLY);
    setState(851);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GoParser::FUNC)
      | (1ULL << GoParser::INTERFACE)
      | (1ULL << GoParser::MAP)
      | (1ULL << GoParser::STRUCT)
      | (1ULL << GoParser::CHAN)
      | (1ULL << GoParser::NIL_LIT)
      | (1ULL << GoParser::IDENTIFIER)
      | (1ULL << GoParser::L_PAREN)
      | (1ULL << GoParser::L_CURLY)
      | (1ULL << GoParser::L_BRACKET)
      | (1ULL << GoParser::EXCLAMATION)
      | (1ULL << GoParser::PLUS)
      | (1ULL << GoParser::MINUS)
      | (1ULL << GoParser::CARET))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GoParser::STAR - 64))
      | (1ULL << (GoParser::AMPERSAND - 64))
      | (1ULL << (GoParser::RECEIVE - 64))
      | (1ULL << (GoParser::DECIMAL_LIT - 64))
      | (1ULL << (GoParser::BINARY_LIT - 64))
      | (1ULL << (GoParser::OCTAL_LIT - 64))
      | (1ULL << (GoParser::HEX_LIT - 64))
      | (1ULL << (GoParser::FLOAT_LIT - 64))
      | (1ULL << (GoParser::IMAGINARY_LIT - 64))
      | (1ULL << (GoParser::RUNE_LIT - 64))
      | (1ULL << (GoParser::RAW_STRING_LIT - 64))
      | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
      setState(847);
      elementList();
      setState(849);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == GoParser::COMMA) {
        setState(848);
        match(GoParser::COMMA);
      }
    }
    setState(853);
    match(GoParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementListContext ------------------------------------------------------------------

GoParser::ElementListContext::ElementListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<GoParser::KeyedElementContext *> GoParser::ElementListContext::keyedElement() {
  return getRuleContexts<GoParser::KeyedElementContext>();
}

GoParser::KeyedElementContext* GoParser::ElementListContext::keyedElement(size_t i) {
  return getRuleContext<GoParser::KeyedElementContext>(i);
}

std::vector<tree::TerminalNode *> GoParser::ElementListContext::COMMA() {
  return getTokens(GoParser::COMMA);
}

tree::TerminalNode* GoParser::ElementListContext::COMMA(size_t i) {
  return getToken(GoParser::COMMA, i);
}


size_t GoParser::ElementListContext::getRuleIndex() const {
  return GoParser::RuleElementList;
}

void GoParser::ElementListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElementList(this);
}

void GoParser::ElementListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElementList(this);
}

GoParser::ElementListContext* GoParser::elementList() {
  ElementListContext *_localctx = _tracker.createInstance<ElementListContext>(_ctx, getState());
  enterRule(_localctx, 166, GoParser::RuleElementList);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(855);
    keyedElement();
    setState(860);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(856);
        match(GoParser::COMMA);
        setState(857);
        keyedElement(); 
      }
      setState(862);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 93, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeyedElementContext ------------------------------------------------------------------

GoParser::KeyedElementContext::KeyedElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ElementContext* GoParser::KeyedElementContext::element() {
  return getRuleContext<GoParser::ElementContext>(0);
}

GoParser::KeyContext* GoParser::KeyedElementContext::key() {
  return getRuleContext<GoParser::KeyContext>(0);
}

tree::TerminalNode* GoParser::KeyedElementContext::COLON() {
  return getToken(GoParser::COLON, 0);
}


size_t GoParser::KeyedElementContext::getRuleIndex() const {
  return GoParser::RuleKeyedElement;
}

void GoParser::KeyedElementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyedElement(this);
}

void GoParser::KeyedElementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyedElement(this);
}

GoParser::KeyedElementContext* GoParser::keyedElement() {
  KeyedElementContext *_localctx = _tracker.createInstance<KeyedElementContext>(_ctx, getState());
  enterRule(_localctx, 168, GoParser::RuleKeyedElement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(866);
    _errHandler->sync(this);

    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 94, _ctx)) {
    case 1: {
      setState(863);
      key();
      setState(864);
      match(GoParser::COLON);
      break;
    }

    default:
      break;
    }
    setState(868);
    element();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeyContext ------------------------------------------------------------------

GoParser::KeyContext::KeyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ExpressionContext* GoParser::KeyContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

GoParser::LiteralValueContext* GoParser::KeyContext::literalValue() {
  return getRuleContext<GoParser::LiteralValueContext>(0);
}


size_t GoParser::KeyContext::getRuleIndex() const {
  return GoParser::RuleKey;
}

void GoParser::KeyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKey(this);
}

void GoParser::KeyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKey(this);
}

GoParser::KeyContext* GoParser::key() {
  KeyContext *_localctx = _tracker.createInstance<KeyContext>(_ctx, getState());
  enterRule(_localctx, 170, GoParser::RuleKey);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(872);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::FUNC:
      case GoParser::INTERFACE:
      case GoParser::MAP:
      case GoParser::STRUCT:
      case GoParser::CHAN:
      case GoParser::NIL_LIT:
      case GoParser::IDENTIFIER:
      case GoParser::L_PAREN:
      case GoParser::L_BRACKET:
      case GoParser::EXCLAMATION:
      case GoParser::PLUS:
      case GoParser::MINUS:
      case GoParser::CARET:
      case GoParser::STAR:
      case GoParser::AMPERSAND:
      case GoParser::RECEIVE:
      case GoParser::DECIMAL_LIT:
      case GoParser::BINARY_LIT:
      case GoParser::OCTAL_LIT:
      case GoParser::HEX_LIT:
      case GoParser::FLOAT_LIT:
      case GoParser::IMAGINARY_LIT:
      case GoParser::RUNE_LIT:
      case GoParser::RAW_STRING_LIT:
      case GoParser::INTERPRETED_STRING_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(870);
        expression(0);
        break;
      }

      case GoParser::L_CURLY: {
        enterOuterAlt(_localctx, 2);
        setState(871);
        literalValue();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementContext ------------------------------------------------------------------

GoParser::ElementContext::ElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::ExpressionContext* GoParser::ElementContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

GoParser::LiteralValueContext* GoParser::ElementContext::literalValue() {
  return getRuleContext<GoParser::LiteralValueContext>(0);
}


size_t GoParser::ElementContext::getRuleIndex() const {
  return GoParser::RuleElement;
}

void GoParser::ElementContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElement(this);
}

void GoParser::ElementContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElement(this);
}

GoParser::ElementContext* GoParser::element() {
  ElementContext *_localctx = _tracker.createInstance<ElementContext>(_ctx, getState());
  enterRule(_localctx, 172, GoParser::RuleElement);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(876);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case GoParser::FUNC:
      case GoParser::INTERFACE:
      case GoParser::MAP:
      case GoParser::STRUCT:
      case GoParser::CHAN:
      case GoParser::NIL_LIT:
      case GoParser::IDENTIFIER:
      case GoParser::L_PAREN:
      case GoParser::L_BRACKET:
      case GoParser::EXCLAMATION:
      case GoParser::PLUS:
      case GoParser::MINUS:
      case GoParser::CARET:
      case GoParser::STAR:
      case GoParser::AMPERSAND:
      case GoParser::RECEIVE:
      case GoParser::DECIMAL_LIT:
      case GoParser::BINARY_LIT:
      case GoParser::OCTAL_LIT:
      case GoParser::HEX_LIT:
      case GoParser::FLOAT_LIT:
      case GoParser::IMAGINARY_LIT:
      case GoParser::RUNE_LIT:
      case GoParser::RAW_STRING_LIT:
      case GoParser::INTERPRETED_STRING_LIT: {
        enterOuterAlt(_localctx, 1);
        setState(874);
        expression(0);
        break;
      }

      case GoParser::L_CURLY: {
        enterOuterAlt(_localctx, 2);
        setState(875);
        literalValue();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructTypeContext ------------------------------------------------------------------

GoParser::StructTypeContext::StructTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::StructTypeContext::STRUCT() {
  return getToken(GoParser::STRUCT, 0);
}

tree::TerminalNode* GoParser::StructTypeContext::L_CURLY() {
  return getToken(GoParser::L_CURLY, 0);
}

tree::TerminalNode* GoParser::StructTypeContext::R_CURLY() {
  return getToken(GoParser::R_CURLY, 0);
}

std::vector<GoParser::FieldDeclContext *> GoParser::StructTypeContext::fieldDecl() {
  return getRuleContexts<GoParser::FieldDeclContext>();
}

GoParser::FieldDeclContext* GoParser::StructTypeContext::fieldDecl(size_t i) {
  return getRuleContext<GoParser::FieldDeclContext>(i);
}

std::vector<GoParser::EossContext *> GoParser::StructTypeContext::eoss() {
  return getRuleContexts<GoParser::EossContext>();
}

GoParser::EossContext* GoParser::StructTypeContext::eoss(size_t i) {
  return getRuleContext<GoParser::EossContext>(i);
}


size_t GoParser::StructTypeContext::getRuleIndex() const {
  return GoParser::RuleStructType;
}

void GoParser::StructTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructType(this);
}

void GoParser::StructTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructType(this);
}

GoParser::StructTypeContext* GoParser::structType() {
  StructTypeContext *_localctx = _tracker.createInstance<StructTypeContext>(_ctx, getState());
  enterRule(_localctx, 174, GoParser::RuleStructType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(878);
    match(GoParser::STRUCT);
    setState(879);
    match(GoParser::L_CURLY);
    setState(885);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == GoParser::IDENTIFIER

    || _la == GoParser::STAR) {
      setState(880);
      fieldDecl();
      setState(881);
      eoss();
      setState(887);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(888);
    match(GoParser::R_CURLY);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FieldDeclContext ------------------------------------------------------------------

GoParser::FieldDeclContext::FieldDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::IdentifierListContext* GoParser::FieldDeclContext::identifierList() {
  return getRuleContext<GoParser::IdentifierListContext>(0);
}

GoParser::Type_Context* GoParser::FieldDeclContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}

GoParser::EmbeddedFieldContext* GoParser::FieldDeclContext::embeddedField() {
  return getRuleContext<GoParser::EmbeddedFieldContext>(0);
}

GoParser::String_Context* GoParser::FieldDeclContext::string_() {
  return getRuleContext<GoParser::String_Context>(0);
}


size_t GoParser::FieldDeclContext::getRuleIndex() const {
  return GoParser::RuleFieldDecl;
}

void GoParser::FieldDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFieldDecl(this);
}

void GoParser::FieldDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFieldDecl(this);
}

GoParser::FieldDeclContext* GoParser::fieldDecl() {
  FieldDeclContext *_localctx = _tracker.createInstance<FieldDeclContext>(_ctx, getState());
  enterRule(_localctx, 176, GoParser::RuleFieldDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(894);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 98, _ctx)) {
    case 1: {
      setState(890);
      identifierList();
      setState(891);
      type_();
      break;
    }

    case 2: {
      setState(893);
      embeddedField();
      break;
    }

    default:
      break;
    }
    setState(897);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GoParser::RAW_STRING_LIT

    || _la == GoParser::INTERPRETED_STRING_LIT) {
      setState(896);
      antlrcpp::downCast<FieldDeclContext *>(_localctx)->tag = string_();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- String_Context ------------------------------------------------------------------

GoParser::String_Context::String_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::String_Context::RAW_STRING_LIT() {
  return getToken(GoParser::RAW_STRING_LIT, 0);
}

tree::TerminalNode* GoParser::String_Context::INTERPRETED_STRING_LIT() {
  return getToken(GoParser::INTERPRETED_STRING_LIT, 0);
}


size_t GoParser::String_Context::getRuleIndex() const {
  return GoParser::RuleString_;
}

void GoParser::String_Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterString_(this);
}

void GoParser::String_Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitString_(this);
}

GoParser::String_Context* GoParser::string_() {
  String_Context *_localctx = _tracker.createInstance<String_Context>(_ctx, getState());
  enterRule(_localctx, 178, GoParser::RuleString_);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(899);
    _la = _input->LA(1);
    if (!(_la == GoParser::RAW_STRING_LIT

    || _la == GoParser::INTERPRETED_STRING_LIT)) {
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

//----------------- EmbeddedFieldContext ------------------------------------------------------------------

GoParser::EmbeddedFieldContext::EmbeddedFieldContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::TypeNameContext* GoParser::EmbeddedFieldContext::typeName() {
  return getRuleContext<GoParser::TypeNameContext>(0);
}

tree::TerminalNode* GoParser::EmbeddedFieldContext::STAR() {
  return getToken(GoParser::STAR, 0);
}


size_t GoParser::EmbeddedFieldContext::getRuleIndex() const {
  return GoParser::RuleEmbeddedField;
}

void GoParser::EmbeddedFieldContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEmbeddedField(this);
}

void GoParser::EmbeddedFieldContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEmbeddedField(this);
}

GoParser::EmbeddedFieldContext* GoParser::embeddedField() {
  EmbeddedFieldContext *_localctx = _tracker.createInstance<EmbeddedFieldContext>(_ctx, getState());
  enterRule(_localctx, 180, GoParser::RuleEmbeddedField);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(902);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == GoParser::STAR) {
      setState(901);
      match(GoParser::STAR);
    }
    setState(904);
    typeName();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionLitContext ------------------------------------------------------------------

GoParser::FunctionLitContext::FunctionLitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::FunctionLitContext::FUNC() {
  return getToken(GoParser::FUNC, 0);
}

GoParser::SignatureContext* GoParser::FunctionLitContext::signature() {
  return getRuleContext<GoParser::SignatureContext>(0);
}

GoParser::BlockContext* GoParser::FunctionLitContext::block() {
  return getRuleContext<GoParser::BlockContext>(0);
}


size_t GoParser::FunctionLitContext::getRuleIndex() const {
  return GoParser::RuleFunctionLit;
}

void GoParser::FunctionLitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionLit(this);
}

void GoParser::FunctionLitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionLit(this);
}

GoParser::FunctionLitContext* GoParser::functionLit() {
  FunctionLitContext *_localctx = _tracker.createInstance<FunctionLitContext>(_ctx, getState());
  enterRule(_localctx, 182, GoParser::RuleFunctionLit);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(906);
    match(GoParser::FUNC);
    setState(907);
    signature();
    setState(908);
    block();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IndexContext ------------------------------------------------------------------

GoParser::IndexContext::IndexContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::IndexContext::L_BRACKET() {
  return getToken(GoParser::L_BRACKET, 0);
}

GoParser::ExpressionContext* GoParser::IndexContext::expression() {
  return getRuleContext<GoParser::ExpressionContext>(0);
}

tree::TerminalNode* GoParser::IndexContext::R_BRACKET() {
  return getToken(GoParser::R_BRACKET, 0);
}


size_t GoParser::IndexContext::getRuleIndex() const {
  return GoParser::RuleIndex;
}

void GoParser::IndexContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndex(this);
}

void GoParser::IndexContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndex(this);
}

GoParser::IndexContext* GoParser::index() {
  IndexContext *_localctx = _tracker.createInstance<IndexContext>(_ctx, getState());
  enterRule(_localctx, 184, GoParser::RuleIndex);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(910);
    match(GoParser::L_BRACKET);
    setState(911);
    expression(0);
    setState(912);
    match(GoParser::R_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Slice_Context ------------------------------------------------------------------

GoParser::Slice_Context::Slice_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::Slice_Context::L_BRACKET() {
  return getToken(GoParser::L_BRACKET, 0);
}

tree::TerminalNode* GoParser::Slice_Context::R_BRACKET() {
  return getToken(GoParser::R_BRACKET, 0);
}

std::vector<tree::TerminalNode *> GoParser::Slice_Context::COLON() {
  return getTokens(GoParser::COLON);
}

tree::TerminalNode* GoParser::Slice_Context::COLON(size_t i) {
  return getToken(GoParser::COLON, i);
}

std::vector<GoParser::ExpressionContext *> GoParser::Slice_Context::expression() {
  return getRuleContexts<GoParser::ExpressionContext>();
}

GoParser::ExpressionContext* GoParser::Slice_Context::expression(size_t i) {
  return getRuleContext<GoParser::ExpressionContext>(i);
}


size_t GoParser::Slice_Context::getRuleIndex() const {
  return GoParser::RuleSlice_;
}

void GoParser::Slice_Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSlice_(this);
}

void GoParser::Slice_Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSlice_(this);
}

GoParser::Slice_Context* GoParser::slice_() {
  Slice_Context *_localctx = _tracker.createInstance<Slice_Context>(_ctx, getState());
  enterRule(_localctx, 186, GoParser::RuleSlice_);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(914);
    match(GoParser::L_BRACKET);
    setState(930);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 104, _ctx)) {
    case 1: {
      setState(916);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GoParser::FUNC)
        | (1ULL << GoParser::INTERFACE)
        | (1ULL << GoParser::MAP)
        | (1ULL << GoParser::STRUCT)
        | (1ULL << GoParser::CHAN)
        | (1ULL << GoParser::NIL_LIT)
        | (1ULL << GoParser::IDENTIFIER)
        | (1ULL << GoParser::L_PAREN)
        | (1ULL << GoParser::L_BRACKET)
        | (1ULL << GoParser::EXCLAMATION)
        | (1ULL << GoParser::PLUS)
        | (1ULL << GoParser::MINUS)
        | (1ULL << GoParser::CARET))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (GoParser::STAR - 64))
        | (1ULL << (GoParser::AMPERSAND - 64))
        | (1ULL << (GoParser::RECEIVE - 64))
        | (1ULL << (GoParser::DECIMAL_LIT - 64))
        | (1ULL << (GoParser::BINARY_LIT - 64))
        | (1ULL << (GoParser::OCTAL_LIT - 64))
        | (1ULL << (GoParser::HEX_LIT - 64))
        | (1ULL << (GoParser::FLOAT_LIT - 64))
        | (1ULL << (GoParser::IMAGINARY_LIT - 64))
        | (1ULL << (GoParser::RUNE_LIT - 64))
        | (1ULL << (GoParser::RAW_STRING_LIT - 64))
        | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
        setState(915);
        expression(0);
      }
      setState(918);
      match(GoParser::COLON);
      setState(920);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GoParser::FUNC)
        | (1ULL << GoParser::INTERFACE)
        | (1ULL << GoParser::MAP)
        | (1ULL << GoParser::STRUCT)
        | (1ULL << GoParser::CHAN)
        | (1ULL << GoParser::NIL_LIT)
        | (1ULL << GoParser::IDENTIFIER)
        | (1ULL << GoParser::L_PAREN)
        | (1ULL << GoParser::L_BRACKET)
        | (1ULL << GoParser::EXCLAMATION)
        | (1ULL << GoParser::PLUS)
        | (1ULL << GoParser::MINUS)
        | (1ULL << GoParser::CARET))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (GoParser::STAR - 64))
        | (1ULL << (GoParser::AMPERSAND - 64))
        | (1ULL << (GoParser::RECEIVE - 64))
        | (1ULL << (GoParser::DECIMAL_LIT - 64))
        | (1ULL << (GoParser::BINARY_LIT - 64))
        | (1ULL << (GoParser::OCTAL_LIT - 64))
        | (1ULL << (GoParser::HEX_LIT - 64))
        | (1ULL << (GoParser::FLOAT_LIT - 64))
        | (1ULL << (GoParser::IMAGINARY_LIT - 64))
        | (1ULL << (GoParser::RUNE_LIT - 64))
        | (1ULL << (GoParser::RAW_STRING_LIT - 64))
        | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
        setState(919);
        expression(0);
      }
      break;
    }

    case 2: {
      setState(923);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << GoParser::FUNC)
        | (1ULL << GoParser::INTERFACE)
        | (1ULL << GoParser::MAP)
        | (1ULL << GoParser::STRUCT)
        | (1ULL << GoParser::CHAN)
        | (1ULL << GoParser::NIL_LIT)
        | (1ULL << GoParser::IDENTIFIER)
        | (1ULL << GoParser::L_PAREN)
        | (1ULL << GoParser::L_BRACKET)
        | (1ULL << GoParser::EXCLAMATION)
        | (1ULL << GoParser::PLUS)
        | (1ULL << GoParser::MINUS)
        | (1ULL << GoParser::CARET))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 64)) & ((1ULL << (GoParser::STAR - 64))
        | (1ULL << (GoParser::AMPERSAND - 64))
        | (1ULL << (GoParser::RECEIVE - 64))
        | (1ULL << (GoParser::DECIMAL_LIT - 64))
        | (1ULL << (GoParser::BINARY_LIT - 64))
        | (1ULL << (GoParser::OCTAL_LIT - 64))
        | (1ULL << (GoParser::HEX_LIT - 64))
        | (1ULL << (GoParser::FLOAT_LIT - 64))
        | (1ULL << (GoParser::IMAGINARY_LIT - 64))
        | (1ULL << (GoParser::RUNE_LIT - 64))
        | (1ULL << (GoParser::RAW_STRING_LIT - 64))
        | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
        setState(922);
        expression(0);
      }
      setState(925);
      match(GoParser::COLON);
      setState(926);
      expression(0);
      setState(927);
      match(GoParser::COLON);
      setState(928);
      expression(0);
      break;
    }

    default:
      break;
    }
    setState(932);
    match(GoParser::R_BRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeAssertionContext ------------------------------------------------------------------

GoParser::TypeAssertionContext::TypeAssertionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::TypeAssertionContext::DOT() {
  return getToken(GoParser::DOT, 0);
}

tree::TerminalNode* GoParser::TypeAssertionContext::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

GoParser::Type_Context* GoParser::TypeAssertionContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}

tree::TerminalNode* GoParser::TypeAssertionContext::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}


size_t GoParser::TypeAssertionContext::getRuleIndex() const {
  return GoParser::RuleTypeAssertion;
}

void GoParser::TypeAssertionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTypeAssertion(this);
}

void GoParser::TypeAssertionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTypeAssertion(this);
}

GoParser::TypeAssertionContext* GoParser::typeAssertion() {
  TypeAssertionContext *_localctx = _tracker.createInstance<TypeAssertionContext>(_ctx, getState());
  enterRule(_localctx, 188, GoParser::RuleTypeAssertion);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(934);
    match(GoParser::DOT);
    setState(935);
    match(GoParser::L_PAREN);
    setState(936);
    type_();
    setState(937);
    match(GoParser::R_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgumentsContext ------------------------------------------------------------------

GoParser::ArgumentsContext::ArgumentsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::ArgumentsContext::L_PAREN() {
  return getToken(GoParser::L_PAREN, 0);
}

tree::TerminalNode* GoParser::ArgumentsContext::R_PAREN() {
  return getToken(GoParser::R_PAREN, 0);
}

GoParser::ExpressionListContext* GoParser::ArgumentsContext::expressionList() {
  return getRuleContext<GoParser::ExpressionListContext>(0);
}

GoParser::NonNamedTypeContext* GoParser::ArgumentsContext::nonNamedType() {
  return getRuleContext<GoParser::NonNamedTypeContext>(0);
}

tree::TerminalNode* GoParser::ArgumentsContext::ELLIPSIS() {
  return getToken(GoParser::ELLIPSIS, 0);
}

std::vector<tree::TerminalNode *> GoParser::ArgumentsContext::COMMA() {
  return getTokens(GoParser::COMMA);
}

tree::TerminalNode* GoParser::ArgumentsContext::COMMA(size_t i) {
  return getToken(GoParser::COMMA, i);
}


size_t GoParser::ArgumentsContext::getRuleIndex() const {
  return GoParser::RuleArguments;
}

void GoParser::ArgumentsContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArguments(this);
}

void GoParser::ArgumentsContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArguments(this);
}

GoParser::ArgumentsContext* GoParser::arguments() {
  ArgumentsContext *_localctx = _tracker.createInstance<ArgumentsContext>(_ctx, getState());
  enterRule(_localctx, 190, GoParser::RuleArguments);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(939);
    match(GoParser::L_PAREN);
    setState(954);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GoParser::FUNC)
      | (1ULL << GoParser::INTERFACE)
      | (1ULL << GoParser::MAP)
      | (1ULL << GoParser::STRUCT)
      | (1ULL << GoParser::CHAN)
      | (1ULL << GoParser::NIL_LIT)
      | (1ULL << GoParser::IDENTIFIER)
      | (1ULL << GoParser::L_PAREN)
      | (1ULL << GoParser::L_BRACKET)
      | (1ULL << GoParser::EXCLAMATION)
      | (1ULL << GoParser::PLUS)
      | (1ULL << GoParser::MINUS)
      | (1ULL << GoParser::CARET))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (GoParser::STAR - 64))
      | (1ULL << (GoParser::AMPERSAND - 64))
      | (1ULL << (GoParser::RECEIVE - 64))
      | (1ULL << (GoParser::DECIMAL_LIT - 64))
      | (1ULL << (GoParser::BINARY_LIT - 64))
      | (1ULL << (GoParser::OCTAL_LIT - 64))
      | (1ULL << (GoParser::HEX_LIT - 64))
      | (1ULL << (GoParser::FLOAT_LIT - 64))
      | (1ULL << (GoParser::IMAGINARY_LIT - 64))
      | (1ULL << (GoParser::RUNE_LIT - 64))
      | (1ULL << (GoParser::RAW_STRING_LIT - 64))
      | (1ULL << (GoParser::INTERPRETED_STRING_LIT - 64)))) != 0)) {
      setState(946);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 106, _ctx)) {
      case 1: {
        setState(940);
        expressionList();
        break;
      }

      case 2: {
        setState(941);
        nonNamedType();
        setState(944);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 105, _ctx)) {
        case 1: {
          setState(942);
          match(GoParser::COMMA);
          setState(943);
          expressionList();
          break;
        }

        default:
          break;
        }
        break;
      }

      default:
        break;
      }
      setState(949);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == GoParser::ELLIPSIS) {
        setState(948);
        match(GoParser::ELLIPSIS);
      }
      setState(952);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == GoParser::COMMA) {
        setState(951);
        match(GoParser::COMMA);
      }
    }
    setState(956);
    match(GoParser::R_PAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MethodExprContext ------------------------------------------------------------------

GoParser::MethodExprContext::MethodExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::NonNamedTypeContext* GoParser::MethodExprContext::nonNamedType() {
  return getRuleContext<GoParser::NonNamedTypeContext>(0);
}

tree::TerminalNode* GoParser::MethodExprContext::DOT() {
  return getToken(GoParser::DOT, 0);
}

tree::TerminalNode* GoParser::MethodExprContext::IDENTIFIER() {
  return getToken(GoParser::IDENTIFIER, 0);
}


size_t GoParser::MethodExprContext::getRuleIndex() const {
  return GoParser::RuleMethodExpr;
}

void GoParser::MethodExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMethodExpr(this);
}

void GoParser::MethodExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMethodExpr(this);
}

GoParser::MethodExprContext* GoParser::methodExpr() {
  MethodExprContext *_localctx = _tracker.createInstance<MethodExprContext>(_ctx, getState());
  enterRule(_localctx, 192, GoParser::RuleMethodExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(958);
    nonNamedType();
    setState(959);
    match(GoParser::DOT);
    setState(960);
    match(GoParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReceiverTypeContext ------------------------------------------------------------------

GoParser::ReceiverTypeContext::ReceiverTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

GoParser::Type_Context* GoParser::ReceiverTypeContext::type_() {
  return getRuleContext<GoParser::Type_Context>(0);
}


size_t GoParser::ReceiverTypeContext::getRuleIndex() const {
  return GoParser::RuleReceiverType;
}

void GoParser::ReceiverTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReceiverType(this);
}

void GoParser::ReceiverTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReceiverType(this);
}

GoParser::ReceiverTypeContext* GoParser::receiverType() {
  ReceiverTypeContext *_localctx = _tracker.createInstance<ReceiverTypeContext>(_ctx, getState());
  enterRule(_localctx, 194, GoParser::RuleReceiverType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(962);
    type_();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- EossContext ------------------------------------------------------------------

GoParser::EossContext::EossContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* GoParser::EossContext::SEMI() {
  return getToken(GoParser::SEMI, 0);
}

tree::TerminalNode* GoParser::EossContext::EOSSS() {
  return getToken(GoParser::EOSSS, 0);
}

tree::TerminalNode* GoParser::EossContext::HUANHANG() {
  return getToken(GoParser::HUANHANG, 0);
}

tree::TerminalNode* GoParser::EossContext::HUANHANGG() {
  return getToken(GoParser::HUANHANGG, 0);
}


size_t GoParser::EossContext::getRuleIndex() const {
  return GoParser::RuleEoss;
}

void GoParser::EossContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterEoss(this);
}

void GoParser::EossContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<GoParserListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitEoss(this);
}

GoParser::EossContext* GoParser::eoss() {
  EossContext *_localctx = _tracker.createInstance<EossContext>(_ctx, getState());
  enterRule(_localctx, 196, GoParser::RuleEoss);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(964);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << GoParser::SEMI)
      | (1ULL << GoParser::HUANHANG)
      | (1ULL << GoParser::HUANHANGG)
      | (1ULL << GoParser::EOSSS))) != 0))) {
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

bool GoParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 70: return expressionSempred(antlrcpp::downCast<ExpressionContext *>(context), predicateIndex);
    case 71: return primaryExprSempred(antlrcpp::downCast<PrimaryExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool GoParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 5);
    case 1: return precpred(_ctx, 4);
    case 2: return precpred(_ctx, 3);
    case 3: return precpred(_ctx, 2);
    case 4: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

bool GoParser::primaryExprSempred(PrimaryExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 5: return precpred(_ctx, 1);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> GoParser::_decisionToDFA;
atn::PredictionContextCache GoParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN GoParser::_atn;
std::vector<uint16_t> GoParser::_serializedATN;

std::vector<std::string> GoParser::_ruleNames = {
  "sourceFile", "packageClause", "importDecl", "importSpec", "importPath", 
  "declaration", "constDecl", "constSpec", "identifierList", "expressionList", 
  "typeDecl", "typeSpec", "functionDecl", "methodDecl", "receiver", "varDecl", 
  "varSpec", "block", "statementList", "statement", "simpleStmt", "expressionStmt", 
  "sendStmt", "incDecStmt", "assignment", "assign_op", "shortVarDecl", "emptyStmt", 
  "labeledStmt", "returnStmt", "breakStmt", "continueStmt", "gotoStmt", 
  "fallthroughStmt", "deferStmt", "ifStmt", "switchStmt", "exprSwitchStmt", 
  "exprCaseClause", "exprSwitchCase", "typeSwitchStmt", "typeSwitchGuard", 
  "typeCaseClause", "typeSwitchCase", "typeList", "selectStmt", "commClause", 
  "commCase", "recvStmt", "forStmt", "forClause", "rangeClause", "goStmt", 
  "type_", "typeName", "typeLit", "arrayType", "arrayLength", "elementType", 
  "pointerType", "interfaceType", "sliceType", "mapType", "channelType", 
  "methodSpec", "functionType", "signature", "result", "parameters", "parameterDecl", 
  "expression", "primaryExpr", "conversion", "nonNamedType", "operand", 
  "literal", "basicLit", "integer", "operandName", "qualifiedIdent", "compositeLit", 
  "literalType", "literalValue", "elementList", "keyedElement", "key", "element", 
  "structType", "fieldDecl", "string_", "embeddedField", "functionLit", 
  "index", "slice_", "typeAssertion", "arguments", "methodExpr", "receiverType", 
  "eoss"
};

std::vector<std::string> GoParser::_literalNames = {
  "", "'break'", "'default'", "'func'", "'interface'", "'select'", "'case'", 
  "'defer'", "'go'", "'map'", "'struct'", "'chan'", "'else'", "'goto'", 
  "'package'", "'switch'", "'const'", "'fallthrough'", "'if'", "'range'", 
  "'type'", "'continue'", "'for'", "'import'", "'return'", "'var'", "'nil'", 
  "", "'('", "')'", "'{'", "'}'", "'['", "']'", "'='", "','", "';'", "'\n'", 
  "'\r\n'", "':'", "'.'", "'++'", "'--'", "':='", "'...'", "", "'||'", "'&&'", 
  "'=='", "'!='", "'<'", "'<='", "'>'", "'>='", "'|'", "'/'", "'%'", "'<<'", 
  "'>>'", "'&^'", "'!'", "'+'", "'-'", "'^'", "'*'", "'&'", "'<-'"
};

std::vector<std::string> GoParser::_symbolicNames = {
  "", "BREAK", "DEFAULT", "FUNC", "INTERFACE", "SELECT", "CASE", "DEFER", 
  "GO", "MAP", "STRUCT", "CHAN", "ELSE", "GOTO", "PACKAGE", "SWITCH", "CONST", 
  "FALLTHROUGH", "IF", "RANGE", "TYPE", "CONTINUE", "FOR", "IMPORT", "RETURN", 
  "VAR", "NIL_LIT", "IDENTIFIER", "L_PAREN", "R_PAREN", "L_CURLY", "R_CURLY", 
  "L_BRACKET", "R_BRACKET", "ASSIGN", "COMMA", "SEMI", "HUANHANG", "HUANHANGG", 
  "COLON", "DOT", "PLUS_PLUS", "MINUS_MINUS", "DECLARE_ASSIGN", "ELLIPSIS", 
  "EOSSS", "LOGICAL_OR", "LOGICAL_AND", "EQUALS", "NOT_EQUALS", "LESS", 
  "LESS_OR_EQUALS", "GREATER", "GREATER_OR_EQUALS", "OR", "DIV", "MOD", 
  "LSHIFT", "RSHIFT", "BIT_CLEAR", "EXCLAMATION", "PLUS", "MINUS", "CARET", 
  "STAR", "AMPERSAND", "RECEIVE", "DECIMAL_LIT", "BINARY_LIT", "OCTAL_LIT", 
  "HEX_LIT", "FLOAT_LIT", "DECIMAL_FLOAT_LIT", "HEX_FLOAT_LIT", "IMAGINARY_LIT", 
  "RUNE_LIT", "BYTE_VALUE", "OCTAL_BYTE_VALUE", "HEX_BYTE_VALUE", "LITTLE_U_VALUE", 
  "BIG_U_VALUE", "RAW_STRING_LIT", "INTERPRETED_STRING_LIT", "WS", "COMMENT", 
  "TERMINATOR", "LINE_COMMENT", "WS_NLSEMI", "COMMENT_NLSEMI", "LINE_COMMENT_NLSEMI"
};

dfa::Vocabulary GoParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> GoParser::_tokenNames;

GoParser::Initializer::Initializer() {
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

  static const uint16_t serializedATNSegment0[] = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
       0x3, 0x5b, 0x3c9, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
       0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 
       0x7, 0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 
       0x4, 0xb, 0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 
       0xe, 0x9, 0xe, 0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 
       0x9, 0x11, 0x4, 0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 
       0x9, 0x14, 0x4, 0x15, 0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 
       0x9, 0x17, 0x4, 0x18, 0x9, 0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 
       0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 
       0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 0x1f, 0x9, 0x1f, 0x4, 0x20, 
       0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 0x9, 0x22, 0x4, 0x23, 
       0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 0x25, 0x4, 0x26, 
       0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 0x4, 0x29, 
       0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 0x2c, 
       0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
       0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 
       0x9, 0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 
       0x9, 0x35, 0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 
       0x9, 0x38, 0x4, 0x39, 0x9, 0x39, 0x4, 0x3a, 0x9, 0x3a, 0x4, 0x3b, 
       0x9, 0x3b, 0x4, 0x3c, 0x9, 0x3c, 0x4, 0x3d, 0x9, 0x3d, 0x4, 0x3e, 
       0x9, 0x3e, 0x4, 0x3f, 0x9, 0x3f, 0x4, 0x40, 0x9, 0x40, 0x4, 0x41, 
       0x9, 0x41, 0x4, 0x42, 0x9, 0x42, 0x4, 0x43, 0x9, 0x43, 0x4, 0x44, 
       0x9, 0x44, 0x4, 0x45, 0x9, 0x45, 0x4, 0x46, 0x9, 0x46, 0x4, 0x47, 
       0x9, 0x47, 0x4, 0x48, 0x9, 0x48, 0x4, 0x49, 0x9, 0x49, 0x4, 0x4a, 
       0x9, 0x4a, 0x4, 0x4b, 0x9, 0x4b, 0x4, 0x4c, 0x9, 0x4c, 0x4, 0x4d, 
       0x9, 0x4d, 0x4, 0x4e, 0x9, 0x4e, 0x4, 0x4f, 0x9, 0x4f, 0x4, 0x50, 
       0x9, 0x50, 0x4, 0x51, 0x9, 0x51, 0x4, 0x52, 0x9, 0x52, 0x4, 0x53, 
       0x9, 0x53, 0x4, 0x54, 0x9, 0x54, 0x4, 0x55, 0x9, 0x55, 0x4, 0x56, 
       0x9, 0x56, 0x4, 0x57, 0x9, 0x57, 0x4, 0x58, 0x9, 0x58, 0x4, 0x59, 
       0x9, 0x59, 0x4, 0x5a, 0x9, 0x5a, 0x4, 0x5b, 0x9, 0x5b, 0x4, 0x5c, 
       0x9, 0x5c, 0x4, 0x5d, 0x9, 0x5d, 0x4, 0x5e, 0x9, 0x5e, 0x4, 0x5f, 
       0x9, 0x5f, 0x4, 0x60, 0x9, 0x60, 0x4, 0x61, 0x9, 0x61, 0x4, 0x62, 
       0x9, 0x62, 0x4, 0x63, 0x9, 0x63, 0x4, 0x64, 0x9, 0x64, 0x3, 0x2, 
       0x3, 0x2, 0x7, 0x2, 0xcb, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xce, 0xb, 
       0x2, 0x3, 0x2, 0x3, 0x2, 0x7, 0x2, 0xd2, 0xa, 0x2, 0xc, 0x2, 0xe, 
       0x2, 0xd5, 0xb, 0x2, 0x7, 0x2, 0xd7, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 
       0xda, 0xb, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x5, 0x2, 0xdf, 0xa, 
       0x2, 0x3, 0x2, 0x7, 0x2, 0xe2, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xe5, 
       0xb, 0x2, 0x7, 0x2, 0xe7, 0xa, 0x2, 0xc, 0x2, 0xe, 0x2, 0xea, 0xb, 
       0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x4, 
       0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0xf7, 
       0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0xfa, 0xb, 0x4, 0x3, 0x4, 0x5, 0x4, 
       0xfd, 0xa, 0x4, 0x3, 0x5, 0x5, 0x5, 0x100, 0xa, 0x5, 0x3, 0x5, 0x3, 
       0x5, 0x3, 0x6, 0x3, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x5, 0x7, 
       0x109, 0xa, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 
       0x3, 0x8, 0x7, 0x8, 0x111, 0xa, 0x8, 0xc, 0x8, 0xe, 0x8, 0x114, 0xb, 
       0x8, 0x3, 0x8, 0x5, 0x8, 0x117, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x5, 
       0x9, 0x11b, 0xa, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x11f, 0xa, 0x9, 
       0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x124, 0xa, 0xa, 0xc, 0xa, 
       0xe, 0xa, 0x127, 0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x7, 0xb, 
       0x12c, 0xa, 0xb, 0xc, 0xb, 0xe, 0xb, 0x12f, 0xb, 0xb, 0x3, 0xc, 0x3, 
       0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x137, 0xa, 
       0xc, 0xc, 0xc, 0xe, 0xc, 0x13a, 0xb, 0xc, 0x3, 0xc, 0x5, 0xc, 0x13d, 
       0xa, 0xc, 0x3, 0xd, 0x3, 0xd, 0x5, 0xd, 0x141, 0xa, 0xd, 0x3, 0xd, 
       0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x3, 0xe, 0x5, 0xe, 0x149, 
       0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x3, 0xf, 0x5, 
       0xf, 0x150, 0xa, 0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 
       0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x7, 0x11, 0x15a, 0xa, 
       0x11, 0xc, 0x11, 0xe, 0x11, 0x15d, 0xb, 0x11, 0x3, 0x11, 0x5, 0x11, 
       0x160, 0xa, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 
       0x12, 0x166, 0xa, 0x12, 0x3, 0x12, 0x3, 0x12, 0x5, 0x12, 0x16a, 0xa, 
       0x12, 0x3, 0x13, 0x3, 0x13, 0x7, 0x13, 0x16e, 0xa, 0x13, 0xc, 0x13, 
       0xe, 0x13, 0x171, 0xb, 0x13, 0x3, 0x13, 0x5, 0x13, 0x174, 0xa, 0x13, 
       0x3, 0x13, 0x3, 0x13, 0x3, 0x14, 0x3, 0x14, 0x6, 0x14, 0x17a, 0xa, 
       0x14, 0xd, 0x14, 0xe, 0x14, 0x17b, 0x6, 0x14, 0x17e, 0xa, 0x14, 0xd, 
       0x14, 0xe, 0x14, 0x17f, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
       0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 
       0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x5, 0x15, 
       0x191, 0xa, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 0x16, 0x3, 
       0x16, 0x5, 0x16, 0x198, 0xa, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 
       0x3, 0x18, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x19, 
       0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1b, 0x5, 0x1b, 
       0x1a8, 0xa, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 
       0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 
       0x1e, 0x5, 0x1e, 0x1b5, 0xa, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x5, 0x1f, 
       0x1b9, 0xa, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x5, 0x20, 0x1bd, 0xa, 0x20, 
       0x3, 0x21, 0x3, 0x21, 0x5, 0x21, 0x1c1, 0xa, 0x21, 0x3, 0x22, 0x3, 
       0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x3, 0x24, 0x3, 
       0x24, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 
       0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x1d4, 0xa, 0x25, 
       0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 0x25, 0x1da, 0xa, 
       0x25, 0x5, 0x25, 0x1dc, 0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x5, 0x26, 
       0x1e0, 0xa, 0x26, 0x3, 0x27, 0x3, 0x27, 0x5, 0x27, 0x1e4, 0xa, 0x27, 
       0x3, 0x27, 0x5, 0x27, 0x1e7, 0xa, 0x27, 0x3, 0x27, 0x3, 0x27, 0x5, 
       0x27, 0x1eb, 0xa, 0x27, 0x5, 0x27, 0x1ed, 0xa, 0x27, 0x3, 0x27, 0x3, 
       0x27, 0x7, 0x27, 0x1f1, 0xa, 0x27, 0xc, 0x27, 0xe, 0x27, 0x1f4, 0xb, 
       0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 0x28, 0x5, 
       0x28, 0x1fb, 0xa, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 
       0x200, 0xa, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 
       0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x5, 0x2a, 0x20b, 
       0xa, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x7, 0x2a, 0x20f, 0xa, 0x2a, 0xc, 
       0x2a, 0xe, 0x2a, 0x212, 0xb, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 
       0x3, 0x2b, 0x5, 0x2b, 0x218, 0xa, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
       0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 0x3, 0x2c, 0x3, 
       0x2c, 0x5, 0x2c, 0x223, 0xa, 0x2c, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 
       0x5, 0x2d, 0x228, 0xa, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x22c, 
       0xa, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x5, 0x2e, 0x231, 0xa, 
       0x2e, 0x7, 0x2e, 0x233, 0xa, 0x2e, 0xc, 0x2e, 0xe, 0x2e, 0x236, 0xb, 
       0x2e, 0x3, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x7, 0x2f, 0x23b, 0xa, 0x2f, 
       0xc, 0x2f, 0xe, 0x2f, 0x23e, 0xb, 0x2f, 0x3, 0x2f, 0x3, 0x2f, 0x3, 
       0x30, 0x3, 0x30, 0x3, 0x30, 0x5, 0x30, 0x245, 0xa, 0x30, 0x3, 0x31, 
       0x3, 0x31, 0x3, 0x31, 0x5, 0x31, 0x24a, 0xa, 0x31, 0x3, 0x31, 0x5, 
       0x31, 0x24d, 0xa, 0x31, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 0x3, 0x32, 
       0x3, 0x32, 0x3, 0x32, 0x5, 0x32, 0x255, 0xa, 0x32, 0x3, 0x32, 0x3, 
       0x32, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x33, 0x5, 0x33, 0x25d, 
       0xa, 0x33, 0x3, 0x33, 0x3, 0x33, 0x3, 0x34, 0x5, 0x34, 0x262, 0xa, 
       0x34, 0x3, 0x34, 0x3, 0x34, 0x5, 0x34, 0x266, 0xa, 0x34, 0x3, 0x34, 
       0x3, 0x34, 0x5, 0x34, 0x26a, 0xa, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 
       0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x272, 0xa, 0x35, 
       0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x36, 
       0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 0x3, 0x37, 
       0x5, 0x37, 0x280, 0xa, 0x37, 0x3, 0x38, 0x3, 0x38, 0x5, 0x38, 0x284, 
       0xa, 0x38, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 
       0x3, 0x39, 0x3, 0x39, 0x3, 0x39, 0x5, 0x39, 0x28e, 0xa, 0x39, 0x3, 
       0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3a, 0x3, 0x3b, 0x3, 
       0x3b, 0x3, 0x3c, 0x3, 0x3c, 0x3, 0x3d, 0x3, 0x3d, 0x3, 0x3d, 0x3, 
       0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x5, 0x3e, 0x2a0, 0xa, 0x3e, 
       0x3, 0x3e, 0x3, 0x3e, 0x7, 0x3e, 0x2a4, 0xa, 0x3e, 0xc, 0x3e, 0xe, 
       0x3e, 0x2a7, 0xb, 0x3e, 0x3, 0x3e, 0x3, 0x3e, 0x3, 0x3f, 0x3, 0x3f, 
       0x3, 0x3f, 0x3, 0x3f, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 0x3, 0x40, 
       0x3, 0x40, 0x3, 0x40, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 0x41, 
       0x3, 0x41, 0x5, 0x41, 0x2ba, 0xa, 0x41, 0x3, 0x41, 0x3, 0x41, 0x3, 
       0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x3, 0x42, 0x5, 
       0x42, 0x2c4, 0xa, 0x42, 0x3, 0x43, 0x3, 0x43, 0x3, 0x43, 0x3, 0x44, 
       0x3, 0x44, 0x3, 0x44, 0x3, 0x44, 0x5, 0x44, 0x2cd, 0xa, 0x44, 0x3, 
       0x45, 0x3, 0x45, 0x5, 0x45, 0x2d1, 0xa, 0x45, 0x3, 0x46, 0x3, 0x46, 
       0x3, 0x46, 0x3, 0x46, 0x7, 0x46, 0x2d7, 0xa, 0x46, 0xc, 0x46, 0xe, 
       0x46, 0x2da, 0xb, 0x46, 0x3, 0x46, 0x5, 0x46, 0x2dd, 0xa, 0x46, 0x5, 
       0x46, 0x2df, 0xa, 0x46, 0x3, 0x46, 0x3, 0x46, 0x3, 0x47, 0x5, 0x47, 
       0x2e4, 0xa, 0x47, 0x3, 0x47, 0x5, 0x47, 0x2e7, 0xa, 0x47, 0x3, 0x47, 
       0x3, 0x47, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x5, 0x48, 
       0x2ef, 0xa, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 
       0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 
       0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x3, 0x48, 0x7, 0x48, 0x300, 
       0xa, 0x48, 0xc, 0x48, 0xe, 0x48, 0x303, 0xb, 0x48, 0x3, 0x49, 0x3, 
       0x49, 0x3, 0x49, 0x3, 0x49, 0x5, 0x49, 0x309, 0xa, 0x49, 0x3, 0x49, 
       0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 0x3, 0x49, 
       0x5, 0x49, 0x312, 0xa, 0x49, 0x7, 0x49, 0x314, 0xa, 0x49, 0xc, 0x49, 
       0xe, 0x49, 0x317, 0xb, 0x49, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 
       0x4a, 0x5, 0x4a, 0x31d, 0xa, 0x4a, 0x3, 0x4a, 0x3, 0x4a, 0x3, 0x4b, 
       0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x3, 0x4b, 0x5, 0x4b, 0x326, 0xa, 
       0x4b, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 0x4c, 0x3, 
       0x4c, 0x5, 0x4c, 0x32e, 0xa, 0x4c, 0x3, 0x4d, 0x3, 0x4d, 0x3, 0x4d, 
       0x5, 0x4d, 0x333, 0xa, 0x4d, 0x3, 0x4e, 0x3, 0x4e, 0x3, 0x4e, 0x3, 
       0x4e, 0x5, 0x4e, 0x339, 0xa, 0x4e, 0x3, 0x4f, 0x3, 0x4f, 0x3, 0x50, 
       0x3, 0x50, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x51, 0x3, 0x52, 
       0x3, 0x52, 0x3, 0x52, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 
       0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x3, 0x53, 0x5, 0x53, 
       0x34f, 0xa, 0x53, 0x3, 0x54, 0x3, 0x54, 0x3, 0x54, 0x5, 0x54, 0x354, 
       0xa, 0x54, 0x5, 0x54, 0x356, 0xa, 0x54, 0x3, 0x54, 0x3, 0x54, 0x3, 
       0x55, 0x3, 0x55, 0x3, 0x55, 0x7, 0x55, 0x35d, 0xa, 0x55, 0xc, 0x55, 
       0xe, 0x55, 0x360, 0xb, 0x55, 0x3, 0x56, 0x3, 0x56, 0x3, 0x56, 0x5, 
       0x56, 0x365, 0xa, 0x56, 0x3, 0x56, 0x3, 0x56, 0x3, 0x57, 0x3, 0x57, 
       0x5, 0x57, 0x36b, 0xa, 0x57, 0x3, 0x58, 0x3, 0x58, 0x5, 0x58, 0x36f, 
       0xa, 0x58, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 0x3, 0x59, 
       0x7, 0x59, 0x376, 0xa, 0x59, 0xc, 0x59, 0xe, 0x59, 0x379, 0xb, 0x59, 
       0x3, 0x59, 0x3, 0x59, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 0x3, 0x5a, 
       0x5, 0x5a, 0x381, 0xa, 0x5a, 0x3, 0x5a, 0x5, 0x5a, 0x384, 0xa, 0x5a, 
       0x3, 0x5b, 0x3, 0x5b, 0x3, 0x5c, 0x5, 0x5c, 0x389, 0xa, 0x5c, 0x3, 
       0x5c, 0x3, 0x5c, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 0x5d, 0x3, 
       0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5e, 0x3, 0x5f, 0x3, 0x5f, 0x5, 
       0x5f, 0x397, 0xa, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x5, 0x5f, 0x39b, 0xa, 
       0x5f, 0x3, 0x5f, 0x5, 0x5f, 0x39e, 0xa, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 
       0x3, 0x5f, 0x3, 0x5f, 0x3, 0x5f, 0x5, 0x5f, 0x3a5, 0xa, 0x5f, 0x3, 
       0x5f, 0x3, 0x5f, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 0x60, 0x3, 
       0x60, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 0x61, 0x5, 
       0x61, 0x3b3, 0xa, 0x61, 0x5, 0x61, 0x3b5, 0xa, 0x61, 0x3, 0x61, 0x5, 
       0x61, 0x3b8, 0xa, 0x61, 0x3, 0x61, 0x5, 0x61, 0x3bb, 0xa, 0x61, 0x5, 
       0x61, 0x3bd, 0xa, 0x61, 0x3, 0x61, 0x3, 0x61, 0x3, 0x62, 0x3, 0x62, 
       0x3, 0x62, 0x3, 0x62, 0x3, 0x63, 0x3, 0x63, 0x3, 0x64, 0x3, 0x64, 
       0x3, 0x64, 0x2, 0x4, 0x8e, 0x90, 0x65, 0x2, 0x4, 0x6, 0x8, 0xa, 0xc, 
       0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 0x20, 0x22, 
       0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 0x38, 
       0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 0x4e, 
       0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 
       0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x70, 0x72, 0x74, 0x76, 0x78, 0x7a, 
       0x7c, 0x7e, 0x80, 0x82, 0x84, 0x86, 0x88, 0x8a, 0x8c, 0x8e, 0x90, 
       0x92, 0x94, 0x96, 0x98, 0x9a, 0x9c, 0x9e, 0xa0, 0xa2, 0xa4, 0xa6, 
       0xa8, 0xaa, 0xac, 0xae, 0xb0, 0xb2, 0xb4, 0xb6, 0xb8, 0xba, 0xbc, 
       0xbe, 0xc0, 0xc2, 0xc4, 0xc6, 0x2, 0xd, 0x4, 0x2, 0x1d, 0x1d, 0x2a, 
       0x2a, 0x3, 0x2, 0x2b, 0x2c, 0x4, 0x2, 0x38, 0x3d, 0x3f, 0x43, 0x4, 
       0x2, 0x26, 0x26, 0x2f, 0x2f, 0x3, 0x2, 0x3e, 0x44, 0x4, 0x2, 0x39, 
       0x3d, 0x42, 0x43, 0x4, 0x2, 0x38, 0x38, 0x3f, 0x41, 0x3, 0x2, 0x32, 
       0x37, 0x4, 0x2, 0x45, 0x48, 0x4c, 0x4d, 0x3, 0x2, 0x53, 0x54, 0x4, 
       0x2, 0x26, 0x28, 0x2f, 0x2f, 0x2, 0x402, 0x2, 0xc8, 0x3, 0x2, 0x2, 
       0x2, 0x4, 0xed, 0x3, 0x2, 0x2, 0x2, 0x6, 0xf0, 0x3, 0x2, 0x2, 0x2, 
       0x8, 0xff, 0x3, 0x2, 0x2, 0x2, 0xa, 0x103, 0x3, 0x2, 0x2, 0x2, 0xc, 
       0x108, 0x3, 0x2, 0x2, 0x2, 0xe, 0x10a, 0x3, 0x2, 0x2, 0x2, 0x10, 
       0x118, 0x3, 0x2, 0x2, 0x2, 0x12, 0x120, 0x3, 0x2, 0x2, 0x2, 0x14, 
       0x128, 0x3, 0x2, 0x2, 0x2, 0x16, 0x130, 0x3, 0x2, 0x2, 0x2, 0x18, 
       0x13e, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x144, 0x3, 0x2, 0x2, 0x2, 0x1c, 
       0x14a, 0x3, 0x2, 0x2, 0x2, 0x1e, 0x151, 0x3, 0x2, 0x2, 0x2, 0x20, 
       0x153, 0x3, 0x2, 0x2, 0x2, 0x22, 0x161, 0x3, 0x2, 0x2, 0x2, 0x24, 
       0x16b, 0x3, 0x2, 0x2, 0x2, 0x26, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x28, 
       0x190, 0x3, 0x2, 0x2, 0x2, 0x2a, 0x197, 0x3, 0x2, 0x2, 0x2, 0x2c, 
       0x199, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x30, 
       0x19f, 0x3, 0x2, 0x2, 0x2, 0x32, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x34, 
       0x1a7, 0x3, 0x2, 0x2, 0x2, 0x36, 0x1ab, 0x3, 0x2, 0x2, 0x2, 0x38, 
       0x1af, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x1b1, 0x3, 0x2, 0x2, 0x2, 0x3c, 
       0x1b6, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x40, 
       0x1be, 0x3, 0x2, 0x2, 0x2, 0x42, 0x1c2, 0x3, 0x2, 0x2, 0x2, 0x44, 
       0x1c5, 0x3, 0x2, 0x2, 0x2, 0x46, 0x1c7, 0x3, 0x2, 0x2, 0x2, 0x48, 
       0x1ca, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x1df, 0x3, 0x2, 0x2, 0x2, 0x4c, 
       0x1e1, 0x3, 0x2, 0x2, 0x2, 0x4e, 0x1f7, 0x3, 0x2, 0x2, 0x2, 0x50, 
       0x1ff, 0x3, 0x2, 0x2, 0x2, 0x52, 0x201, 0x3, 0x2, 0x2, 0x2, 0x54, 
       0x217, 0x3, 0x2, 0x2, 0x2, 0x56, 0x21f, 0x3, 0x2, 0x2, 0x2, 0x58, 
       0x227, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x22b, 0x3, 0x2, 0x2, 0x2, 0x5c, 
       0x237, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x241, 0x3, 0x2, 0x2, 0x2, 0x60, 
       0x24c, 0x3, 0x2, 0x2, 0x2, 0x62, 0x254, 0x3, 0x2, 0x2, 0x2, 0x64, 
       0x258, 0x3, 0x2, 0x2, 0x2, 0x66, 0x261, 0x3, 0x2, 0x2, 0x2, 0x68, 
       0x271, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x276, 0x3, 0x2, 0x2, 0x2, 0x6c, 
       0x27f, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x283, 0x3, 0x2, 0x2, 0x2, 0x70, 
       0x28d, 0x3, 0x2, 0x2, 0x2, 0x72, 0x28f, 0x3, 0x2, 0x2, 0x2, 0x74, 
       0x294, 0x3, 0x2, 0x2, 0x2, 0x76, 0x296, 0x3, 0x2, 0x2, 0x2, 0x78, 
       0x298, 0x3, 0x2, 0x2, 0x2, 0x7a, 0x29b, 0x3, 0x2, 0x2, 0x2, 0x7c, 
       0x2aa, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x2ae, 0x3, 0x2, 0x2, 0x2, 0x80, 
       0x2b9, 0x3, 0x2, 0x2, 0x2, 0x82, 0x2c3, 0x3, 0x2, 0x2, 0x2, 0x84, 
       0x2c5, 0x3, 0x2, 0x2, 0x2, 0x86, 0x2cc, 0x3, 0x2, 0x2, 0x2, 0x88, 
       0x2d0, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x2d2, 0x3, 0x2, 0x2, 0x2, 0x8c, 
       0x2e3, 0x3, 0x2, 0x2, 0x2, 0x8e, 0x2ee, 0x3, 0x2, 0x2, 0x2, 0x90, 
       0x308, 0x3, 0x2, 0x2, 0x2, 0x92, 0x318, 0x3, 0x2, 0x2, 0x2, 0x94, 
       0x325, 0x3, 0x2, 0x2, 0x2, 0x96, 0x32d, 0x3, 0x2, 0x2, 0x2, 0x98, 
       0x332, 0x3, 0x2, 0x2, 0x2, 0x9a, 0x338, 0x3, 0x2, 0x2, 0x2, 0x9c, 
       0x33a, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x33c, 0x3, 0x2, 0x2, 0x2, 0xa0, 
       0x33e, 0x3, 0x2, 0x2, 0x2, 0xa2, 0x342, 0x3, 0x2, 0x2, 0x2, 0xa4, 
       0x34e, 0x3, 0x2, 0x2, 0x2, 0xa6, 0x350, 0x3, 0x2, 0x2, 0x2, 0xa8, 
       0x359, 0x3, 0x2, 0x2, 0x2, 0xaa, 0x364, 0x3, 0x2, 0x2, 0x2, 0xac, 
       0x36a, 0x3, 0x2, 0x2, 0x2, 0xae, 0x36e, 0x3, 0x2, 0x2, 0x2, 0xb0, 
       0x370, 0x3, 0x2, 0x2, 0x2, 0xb2, 0x380, 0x3, 0x2, 0x2, 0x2, 0xb4, 
       0x385, 0x3, 0x2, 0x2, 0x2, 0xb6, 0x388, 0x3, 0x2, 0x2, 0x2, 0xb8, 
       0x38c, 0x3, 0x2, 0x2, 0x2, 0xba, 0x390, 0x3, 0x2, 0x2, 0x2, 0xbc, 
       0x394, 0x3, 0x2, 0x2, 0x2, 0xbe, 0x3a8, 0x3, 0x2, 0x2, 0x2, 0xc0, 
       0x3ad, 0x3, 0x2, 0x2, 0x2, 0xc2, 0x3c0, 0x3, 0x2, 0x2, 0x2, 0xc4, 
       0x3c4, 0x3, 0x2, 0x2, 0x2, 0xc6, 0x3c6, 0x3, 0x2, 0x2, 0x2, 0xc8, 
       0xcc, 0x5, 0x4, 0x3, 0x2, 0xc9, 0xcb, 0x5, 0xc6, 0x64, 0x2, 0xca, 
       0xc9, 0x3, 0x2, 0x2, 0x2, 0xcb, 0xce, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xca, 
       0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcd, 0xd8, 0x3, 
       0x2, 0x2, 0x2, 0xce, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xcf, 0xd3, 0x5, 0x6, 
       0x4, 0x2, 0xd0, 0xd2, 0x5, 0xc6, 0x64, 0x2, 0xd1, 0xd0, 0x3, 0x2, 
       0x2, 0x2, 0xd2, 0xd5, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd1, 0x3, 0x2, 0x2, 
       0x2, 0xd3, 0xd4, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd7, 0x3, 0x2, 0x2, 0x2, 
       0xd5, 0xd3, 0x3, 0x2, 0x2, 0x2, 0xd6, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd7, 
       0xda, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd6, 0x3, 0x2, 0x2, 0x2, 0xd8, 0xd9, 
       0x3, 0x2, 0x2, 0x2, 0xd9, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xda, 0xd8, 0x3, 
       0x2, 0x2, 0x2, 0xdb, 0xdf, 0x5, 0x1a, 0xe, 0x2, 0xdc, 0xdf, 0x5, 
       0x1c, 0xf, 0x2, 0xdd, 0xdf, 0x5, 0xc, 0x7, 0x2, 0xde, 0xdb, 0x3, 
       0x2, 0x2, 0x2, 0xde, 0xdc, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdd, 0x3, 0x2, 
       0x2, 0x2, 0xdf, 0xe3, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe2, 0x5, 0xc6, 
       0x64, 0x2, 0xe1, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xe2, 0xe5, 0x3, 0x2, 
       0x2, 0x2, 0xe3, 0xe1, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x3, 0x2, 0x2, 
       0x2, 0xe4, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe5, 0xe3, 0x3, 0x2, 0x2, 0x2, 
       0xe6, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xea, 0x3, 0x2, 0x2, 0x2, 0xe8, 
       0xe6, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 0x3, 0x2, 0x2, 0x2, 0xe9, 0xeb, 
       0x3, 0x2, 0x2, 0x2, 0xea, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xeb, 0xec, 0x7, 
       0x2, 0x2, 0x3, 0xec, 0x3, 0x3, 0x2, 0x2, 0x2, 0xed, 0xee, 0x7, 0x10, 
       0x2, 0x2, 0xee, 0xef, 0x7, 0x1d, 0x2, 0x2, 0xef, 0x5, 0x3, 0x2, 0x2, 
       0x2, 0xf0, 0xfc, 0x7, 0x19, 0x2, 0x2, 0xf1, 0xfd, 0x5, 0x8, 0x5, 
       0x2, 0xf2, 0xf8, 0x7, 0x1e, 0x2, 0x2, 0xf3, 0xf4, 0x5, 0x8, 0x5, 
       0x2, 0xf4, 0xf5, 0x5, 0xc6, 0x64, 0x2, 0xf5, 0xf7, 0x3, 0x2, 0x2, 
       0x2, 0xf6, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xfa, 0x3, 0x2, 0x2, 0x2, 
       0xf8, 0xf6, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf9, 
       0xfb, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xfb, 0xfd, 
       0x7, 0x1f, 0x2, 0x2, 0xfc, 0xf1, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xf2, 
       0x3, 0x2, 0x2, 0x2, 0xfd, 0x7, 0x3, 0x2, 0x2, 0x2, 0xfe, 0x100, 0x9, 
       0x2, 0x2, 0x2, 0xff, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 0x3, 
       0x2, 0x2, 0x2, 0x100, 0x101, 0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x5, 
       0xa, 0x6, 0x2, 0x102, 0x9, 0x3, 0x2, 0x2, 0x2, 0x103, 0x104, 0x5, 
       0xb4, 0x5b, 0x2, 0x104, 0xb, 0x3, 0x2, 0x2, 0x2, 0x105, 0x109, 0x5, 
       0xe, 0x8, 0x2, 0x106, 0x109, 0x5, 0x16, 0xc, 0x2, 0x107, 0x109, 0x5, 
       0x20, 0x11, 0x2, 0x108, 0x105, 0x3, 0x2, 0x2, 0x2, 0x108, 0x106, 
       0x3, 0x2, 0x2, 0x2, 0x108, 0x107, 0x3, 0x2, 0x2, 0x2, 0x109, 0xd, 
       0x3, 0x2, 0x2, 0x2, 0x10a, 0x116, 0x7, 0x12, 0x2, 0x2, 0x10b, 0x117, 
       0x5, 0x10, 0x9, 0x2, 0x10c, 0x112, 0x7, 0x1e, 0x2, 0x2, 0x10d, 0x10e, 
       0x5, 0x10, 0x9, 0x2, 0x10e, 0x10f, 0x5, 0xc6, 0x64, 0x2, 0x10f, 0x111, 
       0x3, 0x2, 0x2, 0x2, 0x110, 0x10d, 0x3, 0x2, 0x2, 0x2, 0x111, 0x114, 
       0x3, 0x2, 0x2, 0x2, 0x112, 0x110, 0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 
       0x3, 0x2, 0x2, 0x2, 0x113, 0x115, 0x3, 0x2, 0x2, 0x2, 0x114, 0x112, 
       0x3, 0x2, 0x2, 0x2, 0x115, 0x117, 0x7, 0x1f, 0x2, 0x2, 0x116, 0x10b, 
       0x3, 0x2, 0x2, 0x2, 0x116, 0x10c, 0x3, 0x2, 0x2, 0x2, 0x117, 0xf, 
       0x3, 0x2, 0x2, 0x2, 0x118, 0x11e, 0x5, 0x12, 0xa, 0x2, 0x119, 0x11b, 
       0x5, 0x6c, 0x37, 0x2, 0x11a, 0x119, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 
       0x3, 0x2, 0x2, 0x2, 0x11b, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 
       0x7, 0x24, 0x2, 0x2, 0x11d, 0x11f, 0x5, 0x14, 0xb, 0x2, 0x11e, 0x11a, 
       0x3, 0x2, 0x2, 0x2, 0x11e, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x11f, 0x11, 
       0x3, 0x2, 0x2, 0x2, 0x120, 0x125, 0x7, 0x1d, 0x2, 0x2, 0x121, 0x122, 
       0x7, 0x25, 0x2, 0x2, 0x122, 0x124, 0x7, 0x1d, 0x2, 0x2, 0x123, 0x121, 
       0x3, 0x2, 0x2, 0x2, 0x124, 0x127, 0x3, 0x2, 0x2, 0x2, 0x125, 0x123, 
       0x3, 0x2, 0x2, 0x2, 0x125, 0x126, 0x3, 0x2, 0x2, 0x2, 0x126, 0x13, 
       0x3, 0x2, 0x2, 0x2, 0x127, 0x125, 0x3, 0x2, 0x2, 0x2, 0x128, 0x12d, 
       0x5, 0x8e, 0x48, 0x2, 0x129, 0x12a, 0x7, 0x25, 0x2, 0x2, 0x12a, 0x12c, 
       0x5, 0x8e, 0x48, 0x2, 0x12b, 0x129, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12f, 
       0x3, 0x2, 0x2, 0x2, 0x12d, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12d, 0x12e, 
       0x3, 0x2, 0x2, 0x2, 0x12e, 0x15, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12d, 
       0x3, 0x2, 0x2, 0x2, 0x130, 0x13c, 0x7, 0x16, 0x2, 0x2, 0x131, 0x13d, 
       0x5, 0x18, 0xd, 0x2, 0x132, 0x138, 0x7, 0x1e, 0x2, 0x2, 0x133, 0x134, 
       0x5, 0x18, 0xd, 0x2, 0x134, 0x135, 0x5, 0xc6, 0x64, 0x2, 0x135, 0x137, 
       0x3, 0x2, 0x2, 0x2, 0x136, 0x133, 0x3, 0x2, 0x2, 0x2, 0x137, 0x13a, 
       0x3, 0x2, 0x2, 0x2, 0x138, 0x136, 0x3, 0x2, 0x2, 0x2, 0x138, 0x139, 
       0x3, 0x2, 0x2, 0x2, 0x139, 0x13b, 0x3, 0x2, 0x2, 0x2, 0x13a, 0x138, 
       0x3, 0x2, 0x2, 0x2, 0x13b, 0x13d, 0x7, 0x1f, 0x2, 0x2, 0x13c, 0x131, 
       0x3, 0x2, 0x2, 0x2, 0x13c, 0x132, 0x3, 0x2, 0x2, 0x2, 0x13d, 0x17, 
       0x3, 0x2, 0x2, 0x2, 0x13e, 0x140, 0x7, 0x1d, 0x2, 0x2, 0x13f, 0x141, 
       0x7, 0x24, 0x2, 0x2, 0x140, 0x13f, 0x3, 0x2, 0x2, 0x2, 0x140, 0x141, 
       0x3, 0x2, 0x2, 0x2, 0x141, 0x142, 0x3, 0x2, 0x2, 0x2, 0x142, 0x143, 
       0x5, 0x6c, 0x37, 0x2, 0x143, 0x19, 0x3, 0x2, 0x2, 0x2, 0x144, 0x145, 
       0x7, 0x5, 0x2, 0x2, 0x145, 0x146, 0x7, 0x1d, 0x2, 0x2, 0x146, 0x148, 
       0x5, 0x86, 0x44, 0x2, 0x147, 0x149, 0x5, 0x24, 0x13, 0x2, 0x148, 
       0x147, 0x3, 0x2, 0x2, 0x2, 0x148, 0x149, 0x3, 0x2, 0x2, 0x2, 0x149, 
       0x1b, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 0x7, 0x5, 0x2, 0x2, 0x14b, 
       0x14c, 0x5, 0x1e, 0x10, 0x2, 0x14c, 0x14d, 0x7, 0x1d, 0x2, 0x2, 0x14d, 
       0x14f, 0x5, 0x86, 0x44, 0x2, 0x14e, 0x150, 0x5, 0x24, 0x13, 0x2, 
       0x14f, 0x14e, 0x3, 0x2, 0x2, 0x2, 0x14f, 0x150, 0x3, 0x2, 0x2, 0x2, 
       0x150, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x151, 0x152, 0x5, 0x8a, 0x46, 0x2, 
       0x152, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x153, 0x15f, 0x7, 0x1b, 0x2, 0x2, 
       0x154, 0x160, 0x5, 0x22, 0x12, 0x2, 0x155, 0x15b, 0x7, 0x1e, 0x2, 
       0x2, 0x156, 0x157, 0x5, 0x22, 0x12, 0x2, 0x157, 0x158, 0x5, 0xc6, 
       0x64, 0x2, 0x158, 0x15a, 0x3, 0x2, 0x2, 0x2, 0x159, 0x156, 0x3, 0x2, 
       0x2, 0x2, 0x15a, 0x15d, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x159, 0x3, 0x2, 
       0x2, 0x2, 0x15b, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15e, 0x3, 0x2, 
       0x2, 0x2, 0x15d, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15e, 0x160, 0x7, 0x1f, 
       0x2, 0x2, 0x15f, 0x154, 0x3, 0x2, 0x2, 0x2, 0x15f, 0x155, 0x3, 0x2, 
       0x2, 0x2, 0x160, 0x21, 0x3, 0x2, 0x2, 0x2, 0x161, 0x169, 0x5, 0x12, 
       0xa, 0x2, 0x162, 0x165, 0x5, 0x6c, 0x37, 0x2, 0x163, 0x164, 0x7, 
       0x24, 0x2, 0x2, 0x164, 0x166, 0x5, 0x14, 0xb, 0x2, 0x165, 0x163, 
       0x3, 0x2, 0x2, 0x2, 0x165, 0x166, 0x3, 0x2, 0x2, 0x2, 0x166, 0x16a, 
       0x3, 0x2, 0x2, 0x2, 0x167, 0x168, 0x7, 0x24, 0x2, 0x2, 0x168, 0x16a, 
       0x5, 0x14, 0xb, 0x2, 0x169, 0x162, 0x3, 0x2, 0x2, 0x2, 0x169, 0x167, 
       0x3, 0x2, 0x2, 0x2, 0x16a, 0x23, 0x3, 0x2, 0x2, 0x2, 0x16b, 0x16f, 
       0x7, 0x20, 0x2, 0x2, 0x16c, 0x16e, 0x5, 0xc6, 0x64, 0x2, 0x16d, 0x16c, 
       0x3, 0x2, 0x2, 0x2, 0x16e, 0x171, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x16d, 
       0x3, 0x2, 0x2, 0x2, 0x16f, 0x170, 0x3, 0x2, 0x2, 0x2, 0x170, 0x173, 
       0x3, 0x2, 0x2, 0x2, 0x171, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x172, 0x174, 
       0x5, 0x26, 0x14, 0x2, 0x173, 0x172, 0x3, 0x2, 0x2, 0x2, 0x173, 0x174, 
       0x3, 0x2, 0x2, 0x2, 0x174, 0x175, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 
       0x7, 0x21, 0x2, 0x2, 0x176, 0x25, 0x3, 0x2, 0x2, 0x2, 0x177, 0x179, 
       0x5, 0x28, 0x15, 0x2, 0x178, 0x17a, 0x5, 0xc6, 0x64, 0x2, 0x179, 
       0x178, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17b, 0x3, 0x2, 0x2, 0x2, 0x17b, 
       0x179, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17c, 0x3, 0x2, 0x2, 0x2, 0x17c, 
       0x17e, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x177, 0x3, 0x2, 0x2, 0x2, 0x17e, 
       0x17f, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x17f, 
       0x180, 0x3, 0x2, 0x2, 0x2, 0x180, 0x27, 0x3, 0x2, 0x2, 0x2, 0x181, 
       0x191, 0x5, 0xc, 0x7, 0x2, 0x182, 0x191, 0x5, 0x3a, 0x1e, 0x2, 0x183, 
       0x191, 0x5, 0x2a, 0x16, 0x2, 0x184, 0x191, 0x5, 0x6a, 0x36, 0x2, 
       0x185, 0x191, 0x5, 0x3c, 0x1f, 0x2, 0x186, 0x191, 0x5, 0x3e, 0x20, 
       0x2, 0x187, 0x191, 0x5, 0x40, 0x21, 0x2, 0x188, 0x191, 0x5, 0x42, 
       0x22, 0x2, 0x189, 0x191, 0x5, 0x44, 0x23, 0x2, 0x18a, 0x191, 0x5, 
       0x24, 0x13, 0x2, 0x18b, 0x191, 0x5, 0x48, 0x25, 0x2, 0x18c, 0x191, 
       0x5, 0x4a, 0x26, 0x2, 0x18d, 0x191, 0x5, 0x5c, 0x2f, 0x2, 0x18e, 
       0x191, 0x5, 0x64, 0x33, 0x2, 0x18f, 0x191, 0x5, 0x46, 0x24, 0x2, 
       0x190, 0x181, 0x3, 0x2, 0x2, 0x2, 0x190, 0x182, 0x3, 0x2, 0x2, 0x2, 
       0x190, 0x183, 0x3, 0x2, 0x2, 0x2, 0x190, 0x184, 0x3, 0x2, 0x2, 0x2, 
       0x190, 0x185, 0x3, 0x2, 0x2, 0x2, 0x190, 0x186, 0x3, 0x2, 0x2, 0x2, 
       0x190, 0x187, 0x3, 0x2, 0x2, 0x2, 0x190, 0x188, 0x3, 0x2, 0x2, 0x2, 
       0x190, 0x189, 0x3, 0x2, 0x2, 0x2, 0x190, 0x18a, 0x3, 0x2, 0x2, 0x2, 
       0x190, 0x18b, 0x3, 0x2, 0x2, 0x2, 0x190, 0x18c, 0x3, 0x2, 0x2, 0x2, 
       0x190, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x190, 0x18e, 0x3, 0x2, 0x2, 0x2, 
       0x190, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x191, 0x29, 0x3, 0x2, 0x2, 0x2, 
       0x192, 0x198, 0x5, 0x2e, 0x18, 0x2, 0x193, 0x198, 0x5, 0x30, 0x19, 
       0x2, 0x194, 0x198, 0x5, 0x32, 0x1a, 0x2, 0x195, 0x198, 0x5, 0x2c, 
       0x17, 0x2, 0x196, 0x198, 0x5, 0x36, 0x1c, 0x2, 0x197, 0x192, 0x3, 
       0x2, 0x2, 0x2, 0x197, 0x193, 0x3, 0x2, 0x2, 0x2, 0x197, 0x194, 0x3, 
       0x2, 0x2, 0x2, 0x197, 0x195, 0x3, 0x2, 0x2, 0x2, 0x197, 0x196, 0x3, 
       0x2, 0x2, 0x2, 0x198, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x199, 0x19a, 0x5, 
       0x8e, 0x48, 0x2, 0x19a, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x19b, 0x19c, 0x5, 
       0x8e, 0x48, 0x2, 0x19c, 0x19d, 0x7, 0x44, 0x2, 0x2, 0x19d, 0x19e, 
       0x5, 0x8e, 0x48, 0x2, 0x19e, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 
       0x5, 0x8e, 0x48, 0x2, 0x1a0, 0x1a1, 0x9, 0x3, 0x2, 0x2, 0x1a1, 0x31, 
       0x3, 0x2, 0x2, 0x2, 0x1a2, 0x1a3, 0x5, 0x14, 0xb, 0x2, 0x1a3, 0x1a4, 
       0x5, 0x34, 0x1b, 0x2, 0x1a4, 0x1a5, 0x5, 0x14, 0xb, 0x2, 0x1a5, 0x33, 
       0x3, 0x2, 0x2, 0x2, 0x1a6, 0x1a8, 0x9, 0x4, 0x2, 0x2, 0x1a7, 0x1a6, 
       0x3, 0x2, 0x2, 0x2, 0x1a7, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1a8, 0x1a9, 
       0x3, 0x2, 0x2, 0x2, 0x1a9, 0x1aa, 0x7, 0x24, 0x2, 0x2, 0x1aa, 0x35, 
       0x3, 0x2, 0x2, 0x2, 0x1ab, 0x1ac, 0x5, 0x12, 0xa, 0x2, 0x1ac, 0x1ad, 
       0x7, 0x2d, 0x2, 0x2, 0x1ad, 0x1ae, 0x5, 0x14, 0xb, 0x2, 0x1ae, 0x37, 
       0x3, 0x2, 0x2, 0x2, 0x1af, 0x1b0, 0x9, 0x5, 0x2, 0x2, 0x1b0, 0x39, 
       0x3, 0x2, 0x2, 0x2, 0x1b1, 0x1b2, 0x7, 0x1d, 0x2, 0x2, 0x1b2, 0x1b4, 
       0x7, 0x29, 0x2, 0x2, 0x1b3, 0x1b5, 0x5, 0x28, 0x15, 0x2, 0x1b4, 0x1b3, 
       0x3, 0x2, 0x2, 0x2, 0x1b4, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x1b5, 0x3b, 
       0x3, 0x2, 0x2, 0x2, 0x1b6, 0x1b8, 0x7, 0x1a, 0x2, 0x2, 0x1b7, 0x1b9, 
       0x5, 0x14, 0xb, 0x2, 0x1b8, 0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b9, 
       0x3, 0x2, 0x2, 0x2, 0x1b9, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x1ba, 0x1bc, 
       0x7, 0x3, 0x2, 0x2, 0x1bb, 0x1bd, 0x7, 0x1d, 0x2, 0x2, 0x1bc, 0x1bb, 
       0x3, 0x2, 0x2, 0x2, 0x1bc, 0x1bd, 0x3, 0x2, 0x2, 0x2, 0x1bd, 0x3f, 
       0x3, 0x2, 0x2, 0x2, 0x1be, 0x1c0, 0x7, 0x17, 0x2, 0x2, 0x1bf, 0x1c1, 
       0x7, 0x1d, 0x2, 0x2, 0x1c0, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x1c0, 0x1c1, 
       0x3, 0x2, 0x2, 0x2, 0x1c1, 0x41, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c3, 
       0x7, 0xf, 0x2, 0x2, 0x1c3, 0x1c4, 0x7, 0x1d, 0x2, 0x2, 0x1c4, 0x43, 
       0x3, 0x2, 0x2, 0x2, 0x1c5, 0x1c6, 0x7, 0x13, 0x2, 0x2, 0x1c6, 0x45, 
       0x3, 0x2, 0x2, 0x2, 0x1c7, 0x1c8, 0x7, 0x9, 0x2, 0x2, 0x1c8, 0x1c9, 
       0x5, 0x8e, 0x48, 0x2, 0x1c9, 0x47, 0x3, 0x2, 0x2, 0x2, 0x1ca, 0x1d3, 
       0x7, 0x14, 0x2, 0x2, 0x1cb, 0x1d4, 0x5, 0x8e, 0x48, 0x2, 0x1cc, 0x1cd, 
       0x5, 0xc6, 0x64, 0x2, 0x1cd, 0x1ce, 0x5, 0x8e, 0x48, 0x2, 0x1ce, 
       0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1d0, 0x5, 0x2a, 0x16, 0x2, 0x1d0, 
       0x1d1, 0x5, 0xc6, 0x64, 0x2, 0x1d1, 0x1d2, 0x5, 0x8e, 0x48, 0x2, 
       0x1d2, 0x1d4, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1cb, 0x3, 0x2, 0x2, 0x2, 
       0x1d3, 0x1cc, 0x3, 0x2, 0x2, 0x2, 0x1d3, 0x1cf, 0x3, 0x2, 0x2, 0x2, 
       0x1d4, 0x1d5, 0x3, 0x2, 0x2, 0x2, 0x1d5, 0x1db, 0x5, 0x24, 0x13, 
       0x2, 0x1d6, 0x1d9, 0x7, 0xe, 0x2, 0x2, 0x1d7, 0x1da, 0x5, 0x48, 0x25, 
       0x2, 0x1d8, 0x1da, 0x5, 0x24, 0x13, 0x2, 0x1d9, 0x1d7, 0x3, 0x2, 
       0x2, 0x2, 0x1d9, 0x1d8, 0x3, 0x2, 0x2, 0x2, 0x1da, 0x1dc, 0x3, 0x2, 
       0x2, 0x2, 0x1db, 0x1d6, 0x3, 0x2, 0x2, 0x2, 0x1db, 0x1dc, 0x3, 0x2, 
       0x2, 0x2, 0x1dc, 0x49, 0x3, 0x2, 0x2, 0x2, 0x1dd, 0x1e0, 0x5, 0x4c, 
       0x27, 0x2, 0x1de, 0x1e0, 0x5, 0x52, 0x2a, 0x2, 0x1df, 0x1dd, 0x3, 
       0x2, 0x2, 0x2, 0x1df, 0x1de, 0x3, 0x2, 0x2, 0x2, 0x1e0, 0x4b, 0x3, 
       0x2, 0x2, 0x2, 0x1e1, 0x1ec, 0x7, 0x11, 0x2, 0x2, 0x1e2, 0x1e4, 0x5, 
       0x8e, 0x48, 0x2, 0x1e3, 0x1e2, 0x3, 0x2, 0x2, 0x2, 0x1e3, 0x1e4, 
       0x3, 0x2, 0x2, 0x2, 0x1e4, 0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1e5, 0x1e7, 
       0x5, 0x2a, 0x16, 0x2, 0x1e6, 0x1e5, 0x3, 0x2, 0x2, 0x2, 0x1e6, 0x1e7, 
       0x3, 0x2, 0x2, 0x2, 0x1e7, 0x1e8, 0x3, 0x2, 0x2, 0x2, 0x1e8, 0x1ea, 
       0x5, 0xc6, 0x64, 0x2, 0x1e9, 0x1eb, 0x5, 0x8e, 0x48, 0x2, 0x1ea, 
       0x1e9, 0x3, 0x2, 0x2, 0x2, 0x1ea, 0x1eb, 0x3, 0x2, 0x2, 0x2, 0x1eb, 
       0x1ed, 0x3, 0x2, 0x2, 0x2, 0x1ec, 0x1e3, 0x3, 0x2, 0x2, 0x2, 0x1ec, 
       0x1e6, 0x3, 0x2, 0x2, 0x2, 0x1ed, 0x1ee, 0x3, 0x2, 0x2, 0x2, 0x1ee, 
       0x1f2, 0x7, 0x20, 0x2, 0x2, 0x1ef, 0x1f1, 0x5, 0x4e, 0x28, 0x2, 0x1f0, 
       0x1ef, 0x3, 0x2, 0x2, 0x2, 0x1f1, 0x1f4, 0x3, 0x2, 0x2, 0x2, 0x1f2, 
       0x1f0, 0x3, 0x2, 0x2, 0x2, 0x1f2, 0x1f3, 0x3, 0x2, 0x2, 0x2, 0x1f3, 
       0x1f5, 0x3, 0x2, 0x2, 0x2, 0x1f4, 0x1f2, 0x3, 0x2, 0x2, 0x2, 0x1f5, 
       0x1f6, 0x7, 0x21, 0x2, 0x2, 0x1f6, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x1f7, 
       0x1f8, 0x5, 0x50, 0x29, 0x2, 0x1f8, 0x1fa, 0x7, 0x29, 0x2, 0x2, 0x1f9, 
       0x1fb, 0x5, 0x26, 0x14, 0x2, 0x1fa, 0x1f9, 0x3, 0x2, 0x2, 0x2, 0x1fa, 
       0x1fb, 0x3, 0x2, 0x2, 0x2, 0x1fb, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x1fc, 
       0x1fd, 0x7, 0x8, 0x2, 0x2, 0x1fd, 0x200, 0x5, 0x14, 0xb, 0x2, 0x1fe, 
       0x200, 0x7, 0x4, 0x2, 0x2, 0x1ff, 0x1fc, 0x3, 0x2, 0x2, 0x2, 0x1ff, 
       0x1fe, 0x3, 0x2, 0x2, 0x2, 0x200, 0x51, 0x3, 0x2, 0x2, 0x2, 0x201, 
       0x20a, 0x7, 0x11, 0x2, 0x2, 0x202, 0x20b, 0x5, 0x54, 0x2b, 0x2, 0x203, 
       0x204, 0x5, 0xc6, 0x64, 0x2, 0x204, 0x205, 0x5, 0x54, 0x2b, 0x2, 
       0x205, 0x20b, 0x3, 0x2, 0x2, 0x2, 0x206, 0x207, 0x5, 0x2a, 0x16, 
       0x2, 0x207, 0x208, 0x5, 0xc6, 0x64, 0x2, 0x208, 0x209, 0x5, 0x54, 
       0x2b, 0x2, 0x209, 0x20b, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x202, 0x3, 0x2, 
       0x2, 0x2, 0x20a, 0x203, 0x3, 0x2, 0x2, 0x2, 0x20a, 0x206, 0x3, 0x2, 
       0x2, 0x2, 0x20b, 0x20c, 0x3, 0x2, 0x2, 0x2, 0x20c, 0x210, 0x7, 0x20, 
       0x2, 0x2, 0x20d, 0x20f, 0x5, 0x56, 0x2c, 0x2, 0x20e, 0x20d, 0x3, 
       0x2, 0x2, 0x2, 0x20f, 0x212, 0x3, 0x2, 0x2, 0x2, 0x210, 0x20e, 0x3, 
       0x2, 0x2, 0x2, 0x210, 0x211, 0x3, 0x2, 0x2, 0x2, 0x211, 0x213, 0x3, 
       0x2, 0x2, 0x2, 0x212, 0x210, 0x3, 0x2, 0x2, 0x2, 0x213, 0x214, 0x7, 
       0x21, 0x2, 0x2, 0x214, 0x53, 0x3, 0x2, 0x2, 0x2, 0x215, 0x216, 0x7, 
       0x1d, 0x2, 0x2, 0x216, 0x218, 0x7, 0x2d, 0x2, 0x2, 0x217, 0x215, 
       0x3, 0x2, 0x2, 0x2, 0x217, 0x218, 0x3, 0x2, 0x2, 0x2, 0x218, 0x219, 
       0x3, 0x2, 0x2, 0x2, 0x219, 0x21a, 0x5, 0x90, 0x49, 0x2, 0x21a, 0x21b, 
       0x7, 0x2a, 0x2, 0x2, 0x21b, 0x21c, 0x7, 0x1e, 0x2, 0x2, 0x21c, 0x21d, 
       0x7, 0x16, 0x2, 0x2, 0x21d, 0x21e, 0x7, 0x1f, 0x2, 0x2, 0x21e, 0x55, 
       0x3, 0x2, 0x2, 0x2, 0x21f, 0x220, 0x5, 0x58, 0x2d, 0x2, 0x220, 0x222, 
       0x7, 0x29, 0x2, 0x2, 0x221, 0x223, 0x5, 0x26, 0x14, 0x2, 0x222, 0x221, 
       0x3, 0x2, 0x2, 0x2, 0x222, 0x223, 0x3, 0x2, 0x2, 0x2, 0x223, 0x57, 
       0x3, 0x2, 0x2, 0x2, 0x224, 0x225, 0x7, 0x8, 0x2, 0x2, 0x225, 0x228, 
       0x5, 0x5a, 0x2e, 0x2, 0x226, 0x228, 0x7, 0x4, 0x2, 0x2, 0x227, 0x224, 
       0x3, 0x2, 0x2, 0x2, 0x227, 0x226, 0x3, 0x2, 0x2, 0x2, 0x228, 0x59, 
       0x3, 0x2, 0x2, 0x2, 0x229, 0x22c, 0x5, 0x6c, 0x37, 0x2, 0x22a, 0x22c, 
       0x7, 0x1c, 0x2, 0x2, 0x22b, 0x229, 0x3, 0x2, 0x2, 0x2, 0x22b, 0x22a, 
       0x3, 0x2, 0x2, 0x2, 0x22c, 0x234, 0x3, 0x2, 0x2, 0x2, 0x22d, 0x230, 
       0x7, 0x25, 0x2, 0x2, 0x22e, 0x231, 0x5, 0x6c, 0x37, 0x2, 0x22f, 0x231, 
       0x7, 0x1c, 0x2, 0x2, 0x230, 0x22e, 0x3, 0x2, 0x2, 0x2, 0x230, 0x22f, 
       0x3, 0x2, 0x2, 0x2, 0x231, 0x233, 0x3, 0x2, 0x2, 0x2, 0x232, 0x22d, 
       0x3, 0x2, 0x2, 0x2, 0x233, 0x236, 0x3, 0x2, 0x2, 0x2, 0x234, 0x232, 
       0x3, 0x2, 0x2, 0x2, 0x234, 0x235, 0x3, 0x2, 0x2, 0x2, 0x235, 0x5b, 
       0x3, 0x2, 0x2, 0x2, 0x236, 0x234, 0x3, 0x2, 0x2, 0x2, 0x237, 0x238, 
       0x7, 0x7, 0x2, 0x2, 0x238, 0x23c, 0x7, 0x20, 0x2, 0x2, 0x239, 0x23b, 
       0x5, 0x5e, 0x30, 0x2, 0x23a, 0x239, 0x3, 0x2, 0x2, 0x2, 0x23b, 0x23e, 
       0x3, 0x2, 0x2, 0x2, 0x23c, 0x23a, 0x3, 0x2, 0x2, 0x2, 0x23c, 0x23d, 
       0x3, 0x2, 0x2, 0x2, 0x23d, 0x23f, 0x3, 0x2, 0x2, 0x2, 0x23e, 0x23c, 
       0x3, 0x2, 0x2, 0x2, 0x23f, 0x240, 0x7, 0x21, 0x2, 0x2, 0x240, 0x5d, 
       0x3, 0x2, 0x2, 0x2, 0x241, 0x242, 0x5, 0x60, 0x31, 0x2, 0x242, 0x244, 
       0x7, 0x29, 0x2, 0x2, 0x243, 0x245, 0x5, 0x26, 0x14, 0x2, 0x244, 0x243, 
       0x3, 0x2, 0x2, 0x2, 0x244, 0x245, 0x3, 0x2, 0x2, 0x2, 0x245, 0x5f, 
       0x3, 0x2, 0x2, 0x2, 0x246, 0x249, 0x7, 0x8, 0x2, 0x2, 0x247, 0x24a, 
       0x5, 0x2e, 0x18, 0x2, 0x248, 0x24a, 0x5, 0x62, 0x32, 0x2, 0x249, 
       0x247, 0x3, 0x2, 0x2, 0x2, 0x249, 0x248, 0x3, 0x2, 0x2, 0x2, 0x24a, 
       0x24d, 0x3, 0x2, 0x2, 0x2, 0x24b, 0x24d, 0x7, 0x4, 0x2, 0x2, 0x24c, 
       0x246, 0x3, 0x2, 0x2, 0x2, 0x24c, 0x24b, 0x3, 0x2, 0x2, 0x2, 0x24d, 
       0x61, 0x3, 0x2, 0x2, 0x2, 0x24e, 0x24f, 0x5, 0x14, 0xb, 0x2, 0x24f, 
       0x250, 0x7, 0x24, 0x2, 0x2, 0x250, 0x255, 0x3, 0x2, 0x2, 0x2, 0x251, 
       0x252, 0x5, 0x12, 0xa, 0x2, 0x252, 0x253, 0x7, 0x2d, 0x2, 0x2, 0x253, 
       0x255, 0x3, 0x2, 0x2, 0x2, 0x254, 0x24e, 0x3, 0x2, 0x2, 0x2, 0x254, 
       0x251, 0x3, 0x2, 0x2, 0x2, 0x254, 0x255, 0x3, 0x2, 0x2, 0x2, 0x255, 
       0x256, 0x3, 0x2, 0x2, 0x2, 0x256, 0x257, 0x5, 0x8e, 0x48, 0x2, 0x257, 
       0x63, 0x3, 0x2, 0x2, 0x2, 0x258, 0x25c, 0x7, 0x18, 0x2, 0x2, 0x259, 
       0x25d, 0x5, 0x8e, 0x48, 0x2, 0x25a, 0x25d, 0x5, 0x66, 0x34, 0x2, 
       0x25b, 0x25d, 0x5, 0x68, 0x35, 0x2, 0x25c, 0x259, 0x3, 0x2, 0x2, 
       0x2, 0x25c, 0x25a, 0x3, 0x2, 0x2, 0x2, 0x25c, 0x25b, 0x3, 0x2, 0x2, 
       0x2, 0x25c, 0x25d, 0x3, 0x2, 0x2, 0x2, 0x25d, 0x25e, 0x3, 0x2, 0x2, 
       0x2, 0x25e, 0x25f, 0x5, 0x24, 0x13, 0x2, 0x25f, 0x65, 0x3, 0x2, 0x2, 
       0x2, 0x260, 0x262, 0x5, 0x2a, 0x16, 0x2, 0x261, 0x260, 0x3, 0x2, 
       0x2, 0x2, 0x261, 0x262, 0x3, 0x2, 0x2, 0x2, 0x262, 0x263, 0x3, 0x2, 
       0x2, 0x2, 0x263, 0x265, 0x5, 0xc6, 0x64, 0x2, 0x264, 0x266, 0x5, 
       0x8e, 0x48, 0x2, 0x265, 0x264, 0x3, 0x2, 0x2, 0x2, 0x265, 0x266, 
       0x3, 0x2, 0x2, 0x2, 0x266, 0x267, 0x3, 0x2, 0x2, 0x2, 0x267, 0x269, 
       0x5, 0xc6, 0x64, 0x2, 0x268, 0x26a, 0x5, 0x2a, 0x16, 0x2, 0x269, 
       0x268, 0x3, 0x2, 0x2, 0x2, 0x269, 0x26a, 0x3, 0x2, 0x2, 0x2, 0x26a, 
       0x67, 0x3, 0x2, 0x2, 0x2, 0x26b, 0x26c, 0x5, 0x14, 0xb, 0x2, 0x26c, 
       0x26d, 0x7, 0x24, 0x2, 0x2, 0x26d, 0x272, 0x3, 0x2, 0x2, 0x2, 0x26e, 
       0x26f, 0x5, 0x12, 0xa, 0x2, 0x26f, 0x270, 0x7, 0x2d, 0x2, 0x2, 0x270, 
       0x272, 0x3, 0x2, 0x2, 0x2, 0x271, 0x26b, 0x3, 0x2, 0x2, 0x2, 0x271, 
       0x26e, 0x3, 0x2, 0x2, 0x2, 0x271, 0x272, 0x3, 0x2, 0x2, 0x2, 0x272, 
       0x273, 0x3, 0x2, 0x2, 0x2, 0x273, 0x274, 0x7, 0x15, 0x2, 0x2, 0x274, 
       0x275, 0x5, 0x8e, 0x48, 0x2, 0x275, 0x69, 0x3, 0x2, 0x2, 0x2, 0x276, 
       0x277, 0x7, 0xa, 0x2, 0x2, 0x277, 0x278, 0x5, 0x8e, 0x48, 0x2, 0x278, 
       0x6b, 0x3, 0x2, 0x2, 0x2, 0x279, 0x280, 0x5, 0x6e, 0x38, 0x2, 0x27a, 
       0x280, 0x5, 0x70, 0x39, 0x2, 0x27b, 0x27c, 0x7, 0x1e, 0x2, 0x2, 0x27c, 
       0x27d, 0x5, 0x6c, 0x37, 0x2, 0x27d, 0x27e, 0x7, 0x1f, 0x2, 0x2, 0x27e, 
       0x280, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x279, 0x3, 0x2, 0x2, 0x2, 0x27f, 
       0x27a, 0x3, 0x2, 0x2, 0x2, 0x27f, 0x27b, 0x3, 0x2, 0x2, 0x2, 0x280, 
       0x6d, 0x3, 0x2, 0x2, 0x2, 0x281, 0x284, 0x5, 0xa0, 0x51, 0x2, 0x282, 
       0x284, 0x7, 0x1d, 0x2, 0x2, 0x283, 0x281, 0x3, 0x2, 0x2, 0x2, 0x283, 
       0x282, 0x3, 0x2, 0x2, 0x2, 0x284, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x285, 
       0x28e, 0x5, 0x72, 0x3a, 0x2, 0x286, 0x28e, 0x5, 0xb0, 0x59, 0x2, 
       0x287, 0x28e, 0x5, 0x78, 0x3d, 0x2, 0x288, 0x28e, 0x5, 0x84, 0x43, 
       0x2, 0x289, 0x28e, 0x5, 0x7a, 0x3e, 0x2, 0x28a, 0x28e, 0x5, 0x7c, 
       0x3f, 0x2, 0x28b, 0x28e, 0x5, 0x7e, 0x40, 0x2, 0x28c, 0x28e, 0x5, 
       0x80, 0x41, 0x2, 0x28d, 0x285, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x286, 
       0x3, 0x2, 0x2, 0x2, 0x28d, 0x287, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x288, 
       0x3, 0x2, 0x2, 0x2, 0x28d, 0x289, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x28a, 
       0x3, 0x2, 0x2, 0x2, 0x28d, 0x28b, 0x3, 0x2, 0x2, 0x2, 0x28d, 0x28c, 
       0x3, 0x2, 0x2, 0x2, 0x28e, 0x71, 0x3, 0x2, 0x2, 0x2, 0x28f, 0x290, 
       0x7, 0x22, 0x2, 0x2, 0x290, 0x291, 0x5, 0x74, 0x3b, 0x2, 0x291, 0x292, 
       0x7, 0x23, 0x2, 0x2, 0x292, 0x293, 0x5, 0x76, 0x3c, 0x2, 0x293, 0x73, 
       0x3, 0x2, 0x2, 0x2, 0x294, 0x295, 0x5, 0x8e, 0x48, 0x2, 0x295, 0x75, 
       0x3, 0x2, 0x2, 0x2, 0x296, 0x297, 0x5, 0x6c, 0x37, 0x2, 0x297, 0x77, 
       0x3, 0x2, 0x2, 0x2, 0x298, 0x299, 0x7, 0x42, 0x2, 0x2, 0x299, 0x29a, 
       0x5, 0x6c, 0x37, 0x2, 0x29a, 0x79, 0x3, 0x2, 0x2, 0x2, 0x29b, 0x29c, 
       0x7, 0x6, 0x2, 0x2, 0x29c, 0x2a5, 0x7, 0x20, 0x2, 0x2, 0x29d, 0x2a0, 
       0x5, 0x82, 0x42, 0x2, 0x29e, 0x2a0, 0x5, 0x6e, 0x38, 0x2, 0x29f, 
       0x29d, 0x3, 0x2, 0x2, 0x2, 0x29f, 0x29e, 0x3, 0x2, 0x2, 0x2, 0x2a0, 
       0x2a1, 0x3, 0x2, 0x2, 0x2, 0x2a1, 0x2a2, 0x5, 0xc6, 0x64, 0x2, 0x2a2, 
       0x2a4, 0x3, 0x2, 0x2, 0x2, 0x2a3, 0x29f, 0x3, 0x2, 0x2, 0x2, 0x2a4, 
       0x2a7, 0x3, 0x2, 0x2, 0x2, 0x2a5, 0x2a3, 0x3, 0x2, 0x2, 0x2, 0x2a5, 
       0x2a6, 0x3, 0x2, 0x2, 0x2, 0x2a6, 0x2a8, 0x3, 0x2, 0x2, 0x2, 0x2a7, 
       0x2a5, 0x3, 0x2, 0x2, 0x2, 0x2a8, 0x2a9, 0x7, 0x21, 0x2, 0x2, 0x2a9, 
       0x7b, 0x3, 0x2, 0x2, 0x2, 0x2aa, 0x2ab, 0x7, 0x22, 0x2, 0x2, 0x2ab, 
       0x2ac, 0x7, 0x23, 0x2, 0x2, 0x2ac, 0x2ad, 0x5, 0x76, 0x3c, 0x2, 0x2ad, 
       0x7d, 0x3, 0x2, 0x2, 0x2, 0x2ae, 0x2af, 0x7, 0xb, 0x2, 0x2, 0x2af, 
       0x2b0, 0x7, 0x22, 0x2, 0x2, 0x2b0, 0x2b1, 0x5, 0x6c, 0x37, 0x2, 0x2b1, 
       0x2b2, 0x7, 0x23, 0x2, 0x2, 0x2b2, 0x2b3, 0x5, 0x76, 0x3c, 0x2, 0x2b3, 
       0x7f, 0x3, 0x2, 0x2, 0x2, 0x2b4, 0x2ba, 0x7, 0xd, 0x2, 0x2, 0x2b5, 
       0x2b6, 0x7, 0xd, 0x2, 0x2, 0x2b6, 0x2ba, 0x7, 0x44, 0x2, 0x2, 0x2b7, 
       0x2b8, 0x7, 0x44, 0x2, 0x2, 0x2b8, 0x2ba, 0x7, 0xd, 0x2, 0x2, 0x2b9, 
       0x2b4, 0x3, 0x2, 0x2, 0x2, 0x2b9, 0x2b5, 0x3, 0x2, 0x2, 0x2, 0x2b9, 
       0x2b7, 0x3, 0x2, 0x2, 0x2, 0x2ba, 0x2bb, 0x3, 0x2, 0x2, 0x2, 0x2bb, 
       0x2bc, 0x5, 0x76, 0x3c, 0x2, 0x2bc, 0x81, 0x3, 0x2, 0x2, 0x2, 0x2bd, 
       0x2be, 0x7, 0x1d, 0x2, 0x2, 0x2be, 0x2bf, 0x5, 0x8a, 0x46, 0x2, 0x2bf, 
       0x2c0, 0x5, 0x88, 0x45, 0x2, 0x2c0, 0x2c4, 0x3, 0x2, 0x2, 0x2, 0x2c1, 
       0x2c2, 0x7, 0x1d, 0x2, 0x2, 0x2c2, 0x2c4, 0x5, 0x8a, 0x46, 0x2, 0x2c3, 
       0x2bd, 0x3, 0x2, 0x2, 0x2, 0x2c3, 0x2c1, 0x3, 0x2, 0x2, 0x2, 0x2c4, 
       0x83, 0x3, 0x2, 0x2, 0x2, 0x2c5, 0x2c6, 0x7, 0x5, 0x2, 0x2, 0x2c6, 
       0x2c7, 0x5, 0x86, 0x44, 0x2, 0x2c7, 0x85, 0x3, 0x2, 0x2, 0x2, 0x2c8, 
       0x2c9, 0x5, 0x8a, 0x46, 0x2, 0x2c9, 0x2ca, 0x5, 0x88, 0x45, 0x2, 
       0x2ca, 0x2cd, 0x3, 0x2, 0x2, 0x2, 0x2cb, 0x2cd, 0x5, 0x8a, 0x46, 
       0x2, 0x2cc, 0x2c8, 0x3, 0x2, 0x2, 0x2, 0x2cc, 0x2cb, 0x3, 0x2, 0x2, 
       0x2, 0x2cd, 0x87, 0x3, 0x2, 0x2, 0x2, 0x2ce, 0x2d1, 0x5, 0x8a, 0x46, 
       0x2, 0x2cf, 0x2d1, 0x5, 0x6c, 0x37, 0x2, 0x2d0, 0x2ce, 0x3, 0x2, 
       0x2, 0x2, 0x2d0, 0x2cf, 0x3, 0x2, 0x2, 0x2, 0x2d1, 0x89, 0x3, 0x2, 
       0x2, 0x2, 0x2d2, 0x2de, 0x7, 0x1e, 0x2, 0x2, 0x2d3, 0x2d8, 0x5, 0x8c, 
       0x47, 0x2, 0x2d4, 0x2d5, 0x7, 0x25, 0x2, 0x2, 0x2d5, 0x2d7, 0x5, 
       0x8c, 0x47, 0x2, 0x2d6, 0x2d4, 0x3, 0x2, 0x2, 0x2, 0x2d7, 0x2da, 
       0x3, 0x2, 0x2, 0x2, 0x2d8, 0x2d6, 0x3, 0x2, 0x2, 0x2, 0x2d8, 0x2d9, 
       0x3, 0x2, 0x2, 0x2, 0x2d9, 0x2dc, 0x3, 0x2, 0x2, 0x2, 0x2da, 0x2d8, 
       0x3, 0x2, 0x2, 0x2, 0x2db, 0x2dd, 0x7, 0x25, 0x2, 0x2, 0x2dc, 0x2db, 
       0x3, 0x2, 0x2, 0x2, 0x2dc, 0x2dd, 0x3, 0x2, 0x2, 0x2, 0x2dd, 0x2df, 
       0x3, 0x2, 0x2, 0x2, 0x2de, 0x2d3, 0x3, 0x2, 0x2, 0x2, 0x2de, 0x2df, 
       0x3, 0x2, 0x2, 0x2, 0x2df, 0x2e0, 0x3, 0x2, 0x2, 0x2, 0x2e0, 0x2e1, 
       0x7, 0x1f, 0x2, 0x2, 0x2e1, 0x8b, 0x3, 0x2, 0x2, 0x2, 0x2e2, 0x2e4, 
       0x5, 0x12, 0xa, 0x2, 0x2e3, 0x2e2, 0x3, 0x2, 0x2, 0x2, 0x2e3, 0x2e4, 
       0x3, 0x2, 0x2, 0x2, 0x2e4, 0x2e6, 0x3, 0x2, 0x2, 0x2, 0x2e5, 0x2e7, 
       0x7, 0x2e, 0x2, 0x2, 0x2e6, 0x2e5, 0x3, 0x2, 0x2, 0x2, 0x2e6, 0x2e7, 
       0x3, 0x2, 0x2, 0x2, 0x2e7, 0x2e8, 0x3, 0x2, 0x2, 0x2, 0x2e8, 0x2e9, 
       0x5, 0x6c, 0x37, 0x2, 0x2e9, 0x8d, 0x3, 0x2, 0x2, 0x2, 0x2ea, 0x2eb, 
       0x8, 0x48, 0x1, 0x2, 0x2eb, 0x2ef, 0x5, 0x90, 0x49, 0x2, 0x2ec, 0x2ed, 
       0x9, 0x6, 0x2, 0x2, 0x2ed, 0x2ef, 0x5, 0x8e, 0x48, 0x8, 0x2ee, 0x2ea, 
       0x3, 0x2, 0x2, 0x2, 0x2ee, 0x2ec, 0x3, 0x2, 0x2, 0x2, 0x2ef, 0x301, 
       0x3, 0x2, 0x2, 0x2, 0x2f0, 0x2f1, 0xc, 0x7, 0x2, 0x2, 0x2f1, 0x2f2, 
       0x9, 0x7, 0x2, 0x2, 0x2f2, 0x300, 0x5, 0x8e, 0x48, 0x8, 0x2f3, 0x2f4, 
       0xc, 0x6, 0x2, 0x2, 0x2f4, 0x2f5, 0x9, 0x8, 0x2, 0x2, 0x2f5, 0x300, 
       0x5, 0x8e, 0x48, 0x7, 0x2f6, 0x2f7, 0xc, 0x5, 0x2, 0x2, 0x2f7, 0x2f8, 
       0x9, 0x9, 0x2, 0x2, 0x2f8, 0x300, 0x5, 0x8e, 0x48, 0x6, 0x2f9, 0x2fa, 
       0xc, 0x4, 0x2, 0x2, 0x2fa, 0x2fb, 0x7, 0x31, 0x2, 0x2, 0x2fb, 0x300, 
       0x5, 0x8e, 0x48, 0x5, 0x2fc, 0x2fd, 0xc, 0x3, 0x2, 0x2, 0x2fd, 0x2fe, 
       0x7, 0x30, 0x2, 0x2, 0x2fe, 0x300, 0x5, 0x8e, 0x48, 0x4, 0x2ff, 0x2f0, 
       0x3, 0x2, 0x2, 0x2, 0x2ff, 0x2f3, 0x3, 0x2, 0x2, 0x2, 0x2ff, 0x2f6, 
       0x3, 0x2, 0x2, 0x2, 0x2ff, 0x2f9, 0x3, 0x2, 0x2, 0x2, 0x2ff, 0x2fc, 
       0x3, 0x2, 0x2, 0x2, 0x300, 0x303, 0x3, 0x2, 0x2, 0x2, 0x301, 0x2ff, 
       0x3, 0x2, 0x2, 0x2, 0x301, 0x302, 0x3, 0x2, 0x2, 0x2, 0x302, 0x8f, 
       0x3, 0x2, 0x2, 0x2, 0x303, 0x301, 0x3, 0x2, 0x2, 0x2, 0x304, 0x305, 
       0x8, 0x49, 0x1, 0x2, 0x305, 0x309, 0x5, 0x96, 0x4c, 0x2, 0x306, 0x309, 
       0x5, 0x92, 0x4a, 0x2, 0x307, 0x309, 0x5, 0xc2, 0x62, 0x2, 0x308, 
       0x304, 0x3, 0x2, 0x2, 0x2, 0x308, 0x306, 0x3, 0x2, 0x2, 0x2, 0x308, 
       0x307, 0x3, 0x2, 0x2, 0x2, 0x309, 0x315, 0x3, 0x2, 0x2, 0x2, 0x30a, 
       0x311, 0xc, 0x3, 0x2, 0x2, 0x30b, 0x30c, 0x7, 0x2a, 0x2, 0x2, 0x30c, 
       0x312, 0x7, 0x1d, 0x2, 0x2, 0x30d, 0x312, 0x5, 0xba, 0x5e, 0x2, 0x30e, 
       0x312, 0x5, 0xbc, 0x5f, 0x2, 0x30f, 0x312, 0x5, 0xbe, 0x60, 0x2, 
       0x310, 0x312, 0x5, 0xc0, 0x61, 0x2, 0x311, 0x30b, 0x3, 0x2, 0x2, 
       0x2, 0x311, 0x30d, 0x3, 0x2, 0x2, 0x2, 0x311, 0x30e, 0x3, 0x2, 0x2, 
       0x2, 0x311, 0x30f, 0x3, 0x2, 0x2, 0x2, 0x311, 0x310, 0x3, 0x2, 0x2, 
       0x2, 0x312, 0x314, 0x3, 0x2, 0x2, 0x2, 0x313, 0x30a, 0x3, 0x2, 0x2, 
       0x2, 0x314, 0x317, 0x3, 0x2, 0x2, 0x2, 0x315, 0x313, 0x3, 0x2, 0x2, 
       0x2, 0x315, 0x316, 0x3, 0x2, 0x2, 0x2, 0x316, 0x91, 0x3, 0x2, 0x2, 
       0x2, 0x317, 0x315, 0x3, 0x2, 0x2, 0x2, 0x318, 0x319, 0x5, 0x94, 0x4b, 
       0x2, 0x319, 0x31a, 0x7, 0x1e, 0x2, 0x2, 0x31a, 0x31c, 0x5, 0x8e, 
       0x48, 0x2, 0x31b, 0x31d, 0x7, 0x25, 0x2, 0x2, 0x31c, 0x31b, 0x3, 
       0x2, 0x2, 0x2, 0x31c, 0x31d, 0x3, 0x2, 0x2, 0x2, 0x31d, 0x31e, 0x3, 
       0x2, 0x2, 0x2, 0x31e, 0x31f, 0x7, 0x1f, 0x2, 0x2, 0x31f, 0x93, 0x3, 
       0x2, 0x2, 0x2, 0x320, 0x326, 0x5, 0x70, 0x39, 0x2, 0x321, 0x322, 
       0x7, 0x1e, 0x2, 0x2, 0x322, 0x323, 0x5, 0x94, 0x4b, 0x2, 0x323, 0x324, 
       0x7, 0x1f, 0x2, 0x2, 0x324, 0x326, 0x3, 0x2, 0x2, 0x2, 0x325, 0x320, 
       0x3, 0x2, 0x2, 0x2, 0x325, 0x321, 0x3, 0x2, 0x2, 0x2, 0x326, 0x95, 
       0x3, 0x2, 0x2, 0x2, 0x327, 0x32e, 0x5, 0x98, 0x4d, 0x2, 0x328, 0x32e, 
       0x5, 0x9e, 0x50, 0x2, 0x329, 0x32a, 0x7, 0x1e, 0x2, 0x2, 0x32a, 0x32b, 
       0x5, 0x8e, 0x48, 0x2, 0x32b, 0x32c, 0x7, 0x1f, 0x2, 0x2, 0x32c, 0x32e, 
       0x3, 0x2, 0x2, 0x2, 0x32d, 0x327, 0x3, 0x2, 0x2, 0x2, 0x32d, 0x328, 
       0x3, 0x2, 0x2, 0x2, 0x32d, 0x329, 0x3, 0x2, 0x2, 0x2, 0x32e, 0x97, 
       0x3, 0x2, 0x2, 0x2, 0x32f, 0x333, 0x5, 0x9a, 0x4e, 0x2, 0x330, 0x333, 
       0x5, 0xa2, 0x52, 0x2, 0x331, 0x333, 0x5, 0xb8, 0x5d, 0x2, 0x332, 
       0x32f, 0x3, 0x2, 0x2, 0x2, 0x332, 0x330, 0x3, 0x2, 0x2, 0x2, 0x332, 
       0x331, 0x3, 0x2, 0x2, 0x2, 0x333, 0x99, 0x3, 0x2, 0x2, 0x2, 0x334, 
       0x339, 0x7, 0x1c, 0x2, 0x2, 0x335, 0x339, 0x5, 0x9c, 0x4f, 0x2, 0x336, 
       0x339, 0x5, 0xb4, 0x5b, 0x2, 0x337, 0x339, 0x7, 0x49, 0x2, 0x2, 0x338, 
       0x334, 0x3, 0x2, 0x2, 0x2, 0x338, 0x335, 0x3, 0x2, 0x2, 0x2, 0x338, 
       0x336, 0x3, 0x2, 0x2, 0x2, 0x338, 0x337, 0x3, 0x2, 0x2, 0x2, 0x339, 
       0x9b, 0x3, 0x2, 0x2, 0x2, 0x33a, 0x33b, 0x9, 0xa, 0x2, 0x2, 0x33b, 
       0x9d, 0x3, 0x2, 0x2, 0x2, 0x33c, 0x33d, 0x7, 0x1d, 0x2, 0x2, 0x33d, 
       0x9f, 0x3, 0x2, 0x2, 0x2, 0x33e, 0x33f, 0x7, 0x1d, 0x2, 0x2, 0x33f, 
       0x340, 0x7, 0x2a, 0x2, 0x2, 0x340, 0x341, 0x7, 0x1d, 0x2, 0x2, 0x341, 
       0xa1, 0x3, 0x2, 0x2, 0x2, 0x342, 0x343, 0x5, 0xa4, 0x53, 0x2, 0x343, 
       0x344, 0x5, 0xa6, 0x54, 0x2, 0x344, 0xa3, 0x3, 0x2, 0x2, 0x2, 0x345, 
       0x34f, 0x5, 0xb0, 0x59, 0x2, 0x346, 0x34f, 0x5, 0x72, 0x3a, 0x2, 
       0x347, 0x348, 0x7, 0x22, 0x2, 0x2, 0x348, 0x349, 0x7, 0x2e, 0x2, 
       0x2, 0x349, 0x34a, 0x7, 0x23, 0x2, 0x2, 0x34a, 0x34f, 0x5, 0x76, 
       0x3c, 0x2, 0x34b, 0x34f, 0x5, 0x7c, 0x3f, 0x2, 0x34c, 0x34f, 0x5, 
       0x7e, 0x40, 0x2, 0x34d, 0x34f, 0x5, 0x6e, 0x38, 0x2, 0x34e, 0x345, 
       0x3, 0x2, 0x2, 0x2, 0x34e, 0x346, 0x3, 0x2, 0x2, 0x2, 0x34e, 0x347, 
       0x3, 0x2, 0x2, 0x2, 0x34e, 0x34b, 0x3, 0x2, 0x2, 0x2, 0x34e, 0x34c, 
       0x3, 0x2, 0x2, 0x2, 0x34e, 0x34d, 0x3, 0x2, 0x2, 0x2, 0x34f, 0xa5, 
       0x3, 0x2, 0x2, 0x2, 0x350, 0x355, 0x7, 0x20, 0x2, 0x2, 0x351, 0x353, 
       0x5, 0xa8, 0x55, 0x2, 0x352, 0x354, 0x7, 0x25, 0x2, 0x2, 0x353, 0x352, 
       0x3, 0x2, 0x2, 0x2, 0x353, 0x354, 0x3, 0x2, 0x2, 0x2, 0x354, 0x356, 
       0x3, 0x2, 0x2, 0x2, 0x355, 0x351, 0x3, 0x2, 0x2, 0x2, 0x355, 0x356, 
       0x3, 0x2, 0x2, 0x2, 0x356, 0x357, 0x3, 0x2, 0x2, 0x2, 0x357, 0x358, 
       0x7, 0x21, 0x2, 0x2, 0x358, 0xa7, 0x3, 0x2, 0x2, 0x2, 0x359, 0x35e, 
       0x5, 0xaa, 0x56, 0x2, 0x35a, 0x35b, 0x7, 0x25, 0x2, 0x2, 0x35b, 0x35d, 
       0x5, 0xaa, 0x56, 0x2, 0x35c, 0x35a, 0x3, 0x2, 0x2, 0x2, 0x35d, 0x360, 
       0x3, 0x2, 0x2, 0x2, 0x35e, 0x35c, 0x3, 0x2, 0x2, 0x2, 0x35e, 0x35f, 
       0x3, 0x2, 0x2, 0x2, 0x35f, 0xa9, 0x3, 0x2, 0x2, 0x2, 0x360, 0x35e, 
       0x3, 0x2, 0x2, 0x2, 0x361, 0x362, 0x5, 0xac, 0x57, 0x2, 0x362, 0x363, 
       0x7, 0x29, 0x2, 0x2, 0x363, 0x365, 0x3, 0x2, 0x2, 0x2, 0x364, 0x361, 
       0x3, 0x2, 0x2, 0x2, 0x364, 0x365, 0x3, 0x2, 0x2, 0x2, 0x365, 0x366, 
       0x3, 0x2, 0x2, 0x2, 0x366, 0x367, 0x5, 0xae, 0x58, 0x2, 0x367, 0xab, 
       0x3, 0x2, 0x2, 0x2, 0x368, 0x36b, 0x5, 0x8e, 0x48, 0x2, 0x369, 0x36b, 
       0x5, 0xa6, 0x54, 0x2, 0x36a, 0x368, 0x3, 0x2, 0x2, 0x2, 0x36a, 0x369, 
       0x3, 0x2, 0x2, 0x2, 0x36b, 0xad, 0x3, 0x2, 0x2, 0x2, 0x36c, 0x36f, 
       0x5, 0x8e, 0x48, 0x2, 0x36d, 0x36f, 0x5, 0xa6, 0x54, 0x2, 0x36e, 
       0x36c, 0x3, 0x2, 0x2, 0x2, 0x36e, 0x36d, 0x3, 0x2, 0x2, 0x2, 0x36f, 
       0xaf, 0x3, 0x2, 0x2, 0x2, 0x370, 0x371, 0x7, 0xc, 0x2, 0x2, 0x371, 
       0x377, 0x7, 0x20, 0x2, 0x2, 0x372, 0x373, 0x5, 0xb2, 0x5a, 0x2, 0x373, 
       0x374, 0x5, 0xc6, 0x64, 0x2, 0x374, 0x376, 0x3, 0x2, 0x2, 0x2, 0x375, 
       0x372, 0x3, 0x2, 0x2, 0x2, 0x376, 0x379, 0x3, 0x2, 0x2, 0x2, 0x377, 
       0x375, 0x3, 0x2, 0x2, 0x2, 0x377, 0x378, 0x3, 0x2, 0x2, 0x2, 0x378, 
       0x37a, 0x3, 0x2, 0x2, 0x2, 0x379, 0x377, 0x3, 0x2, 0x2, 0x2, 0x37a, 
       0x37b, 0x7, 0x21, 0x2, 0x2, 0x37b, 0xb1, 0x3, 0x2, 0x2, 0x2, 0x37c, 
       0x37d, 0x5, 0x12, 0xa, 0x2, 0x37d, 0x37e, 0x5, 0x6c, 0x37, 0x2, 0x37e, 
       0x381, 0x3, 0x2, 0x2, 0x2, 0x37f, 0x381, 0x5, 0xb6, 0x5c, 0x2, 0x380, 
       0x37c, 0x3, 0x2, 0x2, 0x2, 0x380, 0x37f, 0x3, 0x2, 0x2, 0x2, 0x381, 
       0x383, 0x3, 0x2, 0x2, 0x2, 0x382, 0x384, 0x5, 0xb4, 0x5b, 0x2, 0x383, 
       0x382, 0x3, 0x2, 0x2, 0x2, 0x383, 0x384, 0x3, 0x2, 0x2, 0x2, 0x384, 
       0xb3, 0x3, 0x2, 0x2, 0x2, 0x385, 0x386, 0x9, 0xb, 0x2, 0x2, 0x386, 
       0xb5, 0x3, 0x2, 0x2, 0x2, 0x387, 0x389, 0x7, 0x42, 0x2, 0x2, 0x388, 
       0x387, 0x3, 0x2, 0x2, 0x2, 0x388, 0x389, 0x3, 0x2, 0x2, 0x2, 0x389, 
       0x38a, 0x3, 0x2, 0x2, 0x2, 0x38a, 0x38b, 0x5, 0x6e, 0x38, 0x2, 0x38b, 
       0xb7, 0x3, 0x2, 0x2, 0x2, 0x38c, 0x38d, 0x7, 0x5, 0x2, 0x2, 0x38d, 
       0x38e, 0x5, 0x86, 0x44, 0x2, 0x38e, 0x38f, 0x5, 0x24, 0x13, 0x2, 
       0x38f, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x390, 0x391, 0x7, 0x22, 0x2, 0x2, 
       0x391, 0x392, 0x5, 0x8e, 0x48, 0x2, 0x392, 0x393, 0x7, 0x23, 0x2, 
       0x2, 0x393, 0xbb, 0x3, 0x2, 0x2, 0x2, 0x394, 0x3a4, 0x7, 0x22, 0x2, 
       0x2, 0x395, 0x397, 0x5, 0x8e, 0x48, 0x2, 0x396, 0x395, 0x3, 0x2, 
       0x2, 0x2, 0x396, 0x397, 0x3, 0x2, 0x2, 0x2, 0x397, 0x398, 0x3, 0x2, 
       0x2, 0x2, 0x398, 0x39a, 0x7, 0x29, 0x2, 0x2, 0x399, 0x39b, 0x5, 0x8e, 
       0x48, 0x2, 0x39a, 0x399, 0x3, 0x2, 0x2, 0x2, 0x39a, 0x39b, 0x3, 0x2, 
       0x2, 0x2, 0x39b, 0x3a5, 0x3, 0x2, 0x2, 0x2, 0x39c, 0x39e, 0x5, 0x8e, 
       0x48, 0x2, 0x39d, 0x39c, 0x3, 0x2, 0x2, 0x2, 0x39d, 0x39e, 0x3, 0x2, 
       0x2, 0x2, 0x39e, 0x39f, 0x3, 0x2, 0x2, 0x2, 0x39f, 0x3a0, 0x7, 0x29, 
       0x2, 0x2, 0x3a0, 0x3a1, 0x5, 0x8e, 0x48, 0x2, 0x3a1, 0x3a2, 0x7, 
       0x29, 0x2, 0x2, 0x3a2, 0x3a3, 0x5, 0x8e, 0x48, 0x2, 0x3a3, 0x3a5, 
       0x3, 0x2, 0x2, 0x2, 0x3a4, 0x396, 0x3, 0x2, 0x2, 0x2, 0x3a4, 0x39d, 
       0x3, 0x2, 0x2, 0x2, 0x3a5, 0x3a6, 0x3, 0x2, 0x2, 0x2, 0x3a6, 0x3a7, 
       0x7, 0x23, 0x2, 0x2, 0x3a7, 0xbd, 0x3, 0x2, 0x2, 0x2, 0x3a8, 0x3a9, 
       0x7, 0x2a, 0x2, 0x2, 0x3a9, 0x3aa, 0x7, 0x1e, 0x2, 0x2, 0x3aa, 0x3ab, 
       0x5, 0x6c, 0x37, 0x2, 0x3ab, 0x3ac, 0x7, 0x1f, 0x2, 0x2, 0x3ac, 0xbf, 
       0x3, 0x2, 0x2, 0x2, 0x3ad, 0x3bc, 0x7, 0x1e, 0x2, 0x2, 0x3ae, 0x3b5, 
       0x5, 0x14, 0xb, 0x2, 0x3af, 0x3b2, 0x5, 0x94, 0x4b, 0x2, 0x3b0, 0x3b1, 
       0x7, 0x25, 0x2, 0x2, 0x3b1, 0x3b3, 0x5, 0x14, 0xb, 0x2, 0x3b2, 0x3b0, 
       0x3, 0x2, 0x2, 0x2, 0x3b2, 0x3b3, 0x3, 0x2, 0x2, 0x2, 0x3b3, 0x3b5, 
       0x3, 0x2, 0x2, 0x2, 0x3b4, 0x3ae, 0x3, 0x2, 0x2, 0x2, 0x3b4, 0x3af, 
       0x3, 0x2, 0x2, 0x2, 0x3b5, 0x3b7, 0x3, 0x2, 0x2, 0x2, 0x3b6, 0x3b8, 
       0x7, 0x2e, 0x2, 0x2, 0x3b7, 0x3b6, 0x3, 0x2, 0x2, 0x2, 0x3b7, 0x3b8, 
       0x3, 0x2, 0x2, 0x2, 0x3b8, 0x3ba, 0x3, 0x2, 0x2, 0x2, 0x3b9, 0x3bb, 
       0x7, 0x25, 0x2, 0x2, 0x3ba, 0x3b9, 0x3, 0x2, 0x2, 0x2, 0x3ba, 0x3bb, 
       0x3, 0x2, 0x2, 0x2, 0x3bb, 0x3bd, 0x3, 0x2, 0x2, 0x2, 0x3bc, 0x3b4, 
       0x3, 0x2, 0x2, 0x2, 0x3bc, 0x3bd, 0x3, 0x2, 0x2, 0x2, 0x3bd, 0x3be, 
       0x3, 0x2, 0x2, 0x2, 0x3be, 0x3bf, 0x7, 0x1f, 0x2, 0x2, 0x3bf, 0xc1, 
       0x3, 0x2, 0x2, 0x2, 0x3c0, 0x3c1, 0x5, 0x94, 0x4b, 0x2, 0x3c1, 0x3c2, 
       0x7, 0x2a, 0x2, 0x2, 0x3c2, 0x3c3, 0x7, 0x1d, 0x2, 0x2, 0x3c3, 0xc3, 
       0x3, 0x2, 0x2, 0x2, 0x3c4, 0x3c5, 0x5, 0x6c, 0x37, 0x2, 0x3c5, 0xc5, 
       0x3, 0x2, 0x2, 0x2, 0x3c6, 0x3c7, 0x9, 0xc, 0x2, 0x2, 0x3c7, 0xc7, 
       0x3, 0x2, 0x2, 0x2, 0x70, 0xcc, 0xd3, 0xd8, 0xde, 0xe3, 0xe8, 0xf8, 
       0xfc, 0xff, 0x108, 0x112, 0x116, 0x11a, 0x11e, 0x125, 0x12d, 0x138, 
       0x13c, 0x140, 0x148, 0x14f, 0x15b, 0x15f, 0x165, 0x169, 0x16f, 0x173, 
       0x17b, 0x17f, 0x190, 0x197, 0x1a7, 0x1b4, 0x1b8, 0x1bc, 0x1c0, 0x1d3, 
       0x1d9, 0x1db, 0x1df, 0x1e3, 0x1e6, 0x1ea, 0x1ec, 0x1f2, 0x1fa, 0x1ff, 
       0x20a, 0x210, 0x217, 0x222, 0x227, 0x22b, 0x230, 0x234, 0x23c, 0x244, 
       0x249, 0x24c, 0x254, 0x25c, 0x261, 0x265, 0x269, 0x271, 0x27f, 0x283, 
       0x28d, 0x29f, 0x2a5, 0x2b9, 0x2c3, 0x2cc, 0x2d0, 0x2d8, 0x2dc, 0x2de, 
       0x2e3, 0x2e6, 0x2ee, 0x2ff, 0x301, 0x308, 0x311, 0x315, 0x31c, 0x325, 
       0x32d, 0x332, 0x338, 0x34e, 0x353, 0x355, 0x35e, 0x364, 0x36a, 0x36e, 
       0x377, 0x380, 0x383, 0x388, 0x396, 0x39a, 0x39d, 0x3a4, 0x3b2, 0x3b4, 
       0x3b7, 0x3ba, 0x3bc, 
  };

  _serializedATN.insert(_serializedATN.end(), serializedATNSegment0,
    serializedATNSegment0 + sizeof(serializedATNSegment0) / sizeof(serializedATNSegment0[0]));


  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

GoParser::Initializer GoParser::_init;
