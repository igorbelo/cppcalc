
// Generated from Fasd.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "FasdListener.h"


/**
 * This class provides an empty implementation of FasdListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  FasdBaseListener : public FasdListener {
public:

  virtual void enterStart(FasdParser::StartContext * /*ctx*/) override { }
  virtual void exitStart(FasdParser::StartContext * /*ctx*/) override { }

  virtual void enterNumber(FasdParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(FasdParser::NumberContext * /*ctx*/) override { }

  virtual void enterMulDiv(FasdParser::MulDivContext * /*ctx*/) override { }
  virtual void exitMulDiv(FasdParser::MulDivContext * /*ctx*/) override { }

  virtual void enterAddSub(FasdParser::AddSubContext * /*ctx*/) override { }
  virtual void exitAddSub(FasdParser::AddSubContext * /*ctx*/) override { }

  virtual void enterInnerExpr(FasdParser::InnerExprContext * /*ctx*/) override { }
  virtual void exitInnerExpr(FasdParser::InnerExprContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

