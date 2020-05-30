#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/LLVMContext.h"
#include "util/stack.h"
#include <string>

struct Codegen {
    Codegen(llvm::LLVMContext& context);
    void generate_start();
    void generate_number(int number);
    void generate_operation(std::string op);
    void print();

private:
    llvm::LLVMContext& context;
    llvm::Module module;
    llvm::IRBuilder<> builder;
    Stack<llvm::BasicBlock*> block_stack;
    Stack<llvm::Value*> ret_stack;
};