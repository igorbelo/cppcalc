#include "util/stack.h"
#include "codegen.h"
#include "FasdParser.h"
#include "FasdBaseListener.h"
#include "llvm/IR/LLVMContext.h"

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

    void exitAddSub(FasdParser::AddSubContext*) override;

    void exitStart(FasdParser::StartContext*) override;

private:
    Stack<int> number_stack;
    Codegen* codegen;
};