
// Generated from Fasd.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "FasdParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by FasdParser.
 */
class  FasdListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterStart(FasdParser::StartContext *ctx) = 0;
  virtual void exitStart(FasdParser::StartContext *ctx) = 0;

  virtual void enterAssignment(FasdParser::AssignmentContext *ctx) = 0;
  virtual void exitAssignment(FasdParser::AssignmentContext *ctx) = 0;

  virtual void enterFnExpression(FasdParser::FnExpressionContext *ctx) = 0;
  virtual void exitFnExpression(FasdParser::FnExpressionContext *ctx) = 0;

  virtual void enterFnDeclaration(FasdParser::FnDeclarationContext *ctx) = 0;
  virtual void exitFnDeclaration(FasdParser::FnDeclarationContext *ctx) = 0;

  virtual void enterIdentifier(FasdParser::IdentifierContext *ctx) = 0;
  virtual void exitIdentifier(FasdParser::IdentifierContext *ctx) = 0;

  virtual void enterNumber(FasdParser::NumberContext *ctx) = 0;
  virtual void exitNumber(FasdParser::NumberContext *ctx) = 0;

  virtual void enterMulDiv(FasdParser::MulDivContext *ctx) = 0;
  virtual void exitMulDiv(FasdParser::MulDivContext *ctx) = 0;

  virtual void enterAddSub(FasdParser::AddSubContext *ctx) = 0;
  virtual void exitAddSub(FasdParser::AddSubContext *ctx) = 0;

  virtual void enterInnerExpr(FasdParser::InnerExprContext *ctx) = 0;
  virtual void exitInnerExpr(FasdParser::InnerExprContext *ctx) = 0;

  virtual void enterFunctionCall(FasdParser::FunctionCallContext *ctx) = 0;
  virtual void exitFunctionCall(FasdParser::FunctionCallContext *ctx) = 0;


};

