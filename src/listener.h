#include "util/stack.h"
#include "codegen.h"
#include "FasdParser.h"
#include "FasdBaseListener.h"
#include "llvm/IR/LLVMContext.h"
#include <string>

static llvm::LLVMContext context;

struct Listener : FasdBaseListener {
    Listener() {
        codegen = new Codegen(context);
    }

    ~Listener() {
        delete codegen;
    }

    void enterStart(FasdParser::StartContext*) override;

    void exitNumber(FasdParser::NumberContext*) override;

    void exitIdentifier(FasdParser::IdentifierContext*) override;

    void exitFnDeclaration(FasdParser::FnDeclarationContext*) override;

    void exitFnExpression(FasdParser::FnExpressionContext*) override;

    void exitFunctionCall(FasdParser::FunctionCallContext*) override;

    void exitAddSub(FasdParser::AddSubContext*) override;

    void exitMulDiv(FasdParser::MulDivContext*) override;

    void exitAssignment(FasdParser::AssignmentContext*) override;

    void exitStart(FasdParser::StartContext*) override;

private:
    Stack<int> number_stack;
    Codegen* codegen;

    void exitBinaryOperation(std::string op);
};