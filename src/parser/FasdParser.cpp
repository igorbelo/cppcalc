
// Generated from Fasd.g4 by ANTLR 4.7.1


#include "FasdListener.h"

#include "FasdParser.h"


using namespace antlrcpp;
using namespace antlr4;

FasdParser::FasdParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

FasdParser::~FasdParser() {
  delete _interpreter;
}

std::string FasdParser::getGrammarFileName() const {
  return "Fasd.g4";
}

const std::vector<std::string>& FasdParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& FasdParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- StartContext ------------------------------------------------------------------

FasdParser::StartContext::StartContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

FasdParser::ExpressionContext* FasdParser::StartContext::expression() {
  return getRuleContext<FasdParser::ExpressionContext>(0);
}

tree::TerminalNode* FasdParser::StartContext::EOF() {
  return getToken(FasdParser::EOF, 0);
}


size_t FasdParser::StartContext::getRuleIndex() const {
  return FasdParser::RuleStart;
}

void FasdParser::StartContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FasdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStart(this);
}

void FasdParser::StartContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FasdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStart(this);
}

FasdParser::StartContext* FasdParser::start() {
  StartContext *_localctx = _tracker.createInstance<StartContext>(_ctx, getState());
  enterRule(_localctx, 0, FasdParser::RuleStart);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(4);
    expression(0);
    setState(5);
    match(FasdParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

FasdParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t FasdParser::ExpressionContext::getRuleIndex() const {
  return FasdParser::RuleExpression;
}

void FasdParser::ExpressionContext::copyFrom(ExpressionContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- NumberContext ------------------------------------------------------------------

tree::TerminalNode* FasdParser::NumberContext::NUMBER() {
  return getToken(FasdParser::NUMBER, 0);
}

FasdParser::NumberContext::NumberContext(ExpressionContext *ctx) { copyFrom(ctx); }

void FasdParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FasdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}
void FasdParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FasdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}
//----------------- MulDivContext ------------------------------------------------------------------

std::vector<FasdParser::ExpressionContext *> FasdParser::MulDivContext::expression() {
  return getRuleContexts<FasdParser::ExpressionContext>();
}

FasdParser::ExpressionContext* FasdParser::MulDivContext::expression(size_t i) {
  return getRuleContext<FasdParser::ExpressionContext>(i);
}

FasdParser::MulDivContext::MulDivContext(ExpressionContext *ctx) { copyFrom(ctx); }

void FasdParser::MulDivContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FasdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMulDiv(this);
}
void FasdParser::MulDivContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FasdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMulDiv(this);
}
//----------------- AddSubContext ------------------------------------------------------------------

std::vector<FasdParser::ExpressionContext *> FasdParser::AddSubContext::expression() {
  return getRuleContexts<FasdParser::ExpressionContext>();
}

FasdParser::ExpressionContext* FasdParser::AddSubContext::expression(size_t i) {
  return getRuleContext<FasdParser::ExpressionContext>(i);
}

FasdParser::AddSubContext::AddSubContext(ExpressionContext *ctx) { copyFrom(ctx); }

void FasdParser::AddSubContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FasdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAddSub(this);
}
void FasdParser::AddSubContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FasdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAddSub(this);
}
//----------------- InnerExprContext ------------------------------------------------------------------

FasdParser::ExpressionContext* FasdParser::InnerExprContext::expression() {
  return getRuleContext<FasdParser::ExpressionContext>(0);
}

FasdParser::InnerExprContext::InnerExprContext(ExpressionContext *ctx) { copyFrom(ctx); }

void FasdParser::InnerExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FasdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterInnerExpr(this);
}
void FasdParser::InnerExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<FasdListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitInnerExpr(this);
}

FasdParser::ExpressionContext* FasdParser::expression() {
   return expression(0);
}

FasdParser::ExpressionContext* FasdParser::expression(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  FasdParser::ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, parentState);
  FasdParser::ExpressionContext *previousContext = _localctx;
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, FasdParser::RuleExpression, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(13);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case FasdParser::NUMBER: {
        _localctx = _tracker.createInstance<NumberContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;

        setState(8);
        match(FasdParser::NUMBER);
        break;
      }

      case FasdParser::T__0: {
        _localctx = _tracker.createInstance<InnerExprContext>(_localctx);
        _ctx = _localctx;
        previousContext = _localctx;
        setState(9);
        match(FasdParser::T__0);
        setState(10);
        expression(0);
        setState(11);
        match(FasdParser::T__1);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    _ctx->stop = _input->LT(-1);
    setState(23);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(21);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<MulDivContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(15);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(16);
          dynamic_cast<MulDivContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == FasdParser::MUL

          || _la == FasdParser::DIV)) {
            dynamic_cast<MulDivContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(17);
          expression(5);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<AddSubContext>(_tracker.createInstance<ExpressionContext>(parentContext, parentState));
          _localctx = newContext;
          pushNewRecursionContext(newContext, startState, RuleExpression);
          setState(18);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(19);
          dynamic_cast<AddSubContext *>(_localctx)->op = _input->LT(1);
          _la = _input->LA(1);
          if (!(_la == FasdParser::ADD

          || _la == FasdParser::SUB)) {
            dynamic_cast<AddSubContext *>(_localctx)->op = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(20);
          expression(4);
          break;
        }

        } 
      }
      setState(25);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

bool FasdParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return expressionSempred(dynamic_cast<ExpressionContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool FasdParser::expressionSempred(ExpressionContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 4);
    case 1: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> FasdParser::_decisionToDFA;
atn::PredictionContextCache FasdParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN FasdParser::_atn;
std::vector<uint16_t> FasdParser::_serializedATN;

std::vector<std::string> FasdParser::_ruleNames = {
  "start", "expression"
};

std::vector<std::string> FasdParser::_literalNames = {
  "", "'('", "')'", "'*'", "'/'", "'+'", "'-'"
};

std::vector<std::string> FasdParser::_symbolicNames = {
  "", "", "", "MUL", "DIV", "ADD", "SUB", "NUMBER", "WHITESPACE"
};

dfa::Vocabulary FasdParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> FasdParser::_tokenNames;

FasdParser::Initializer::Initializer() {
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
    0x3, 0xa, 0x1d, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x3, 0x2, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x5, 0x3, 0x10, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x18, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x1b, 
    0xb, 0x3, 0x3, 0x3, 0x2, 0x3, 0x4, 0x4, 0x2, 0x4, 0x2, 0x4, 0x3, 0x2, 
    0x5, 0x6, 0x3, 0x2, 0x7, 0x8, 0x2, 0x1d, 0x2, 0x6, 0x3, 0x2, 0x2, 0x2, 
    0x4, 0xf, 0x3, 0x2, 0x2, 0x2, 0x6, 0x7, 0x5, 0x4, 0x3, 0x2, 0x7, 0x8, 
    0x7, 0x2, 0x2, 0x3, 0x8, 0x3, 0x3, 0x2, 0x2, 0x2, 0x9, 0xa, 0x8, 0x3, 
    0x1, 0x2, 0xa, 0x10, 0x7, 0x9, 0x2, 0x2, 0xb, 0xc, 0x7, 0x3, 0x2, 0x2, 
    0xc, 0xd, 0x5, 0x4, 0x3, 0x2, 0xd, 0xe, 0x7, 0x4, 0x2, 0x2, 0xe, 0x10, 
    0x3, 0x2, 0x2, 0x2, 0xf, 0x9, 0x3, 0x2, 0x2, 0x2, 0xf, 0xb, 0x3, 0x2, 
    0x2, 0x2, 0x10, 0x19, 0x3, 0x2, 0x2, 0x2, 0x11, 0x12, 0xc, 0x6, 0x2, 
    0x2, 0x12, 0x13, 0x9, 0x2, 0x2, 0x2, 0x13, 0x18, 0x5, 0x4, 0x3, 0x7, 
    0x14, 0x15, 0xc, 0x5, 0x2, 0x2, 0x15, 0x16, 0x9, 0x3, 0x2, 0x2, 0x16, 
    0x18, 0x5, 0x4, 0x3, 0x6, 0x17, 0x11, 0x3, 0x2, 0x2, 0x2, 0x17, 0x14, 
    0x3, 0x2, 0x2, 0x2, 0x18, 0x1b, 0x3, 0x2, 0x2, 0x2, 0x19, 0x17, 0x3, 
    0x2, 0x2, 0x2, 0x19, 0x1a, 0x3, 0x2, 0x2, 0x2, 0x1a, 0x5, 0x3, 0x2, 
    0x2, 0x2, 0x1b, 0x19, 0x3, 0x2, 0x2, 0x2, 0x5, 0xf, 0x17, 0x19, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

FasdParser::Initializer FasdParser::_init;
