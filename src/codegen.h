#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/LLVMContext.h"
#include "util/stack.h"
#include <string>

struct Codegen {
    Codegen(llvm::LLVMContext& context);
    void generate_start();
    void generate_operation(std::string op, int lhs, int rhs);
    void generate_operation(std::string op, int rhs);
    void print();

private:
    llvm::LLVMContext& context;
    llvm::Module module;
    llvm::IRBuilder<> builder;
    Stack<llvm::BasicBlock*> block_stack;
    llvm::Value* ret;

    llvm::Value* create_operation(std::string op, llvm::Value* lhs, llvm::Value* rhs);
};