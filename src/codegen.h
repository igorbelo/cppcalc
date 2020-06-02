#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/LLVMContext.h"
#include "util/stack.h"
#include <string>
#include <map>

struct Codegen {
    Codegen(llvm::LLVMContext& context);
    void generate_start();
    void generate_number(int number);
    void generate_operation(std::string op);
    void generate_assignment(std::string identifier);
    void generate_identifier(std::string identifier);
    void generate_function_declaration(std::string identifier, std::string param);
    void generate_function_call(std::string identifier);
    void generate_function_expression();
    void print();

private:
    llvm::LLVMContext& context;
    llvm::Module module;
    llvm::IRBuilder<> builder;
    Stack<llvm::BasicBlock*> block_stack;
    Stack<llvm::Value*> ret_stack;
    std::map<std::string, llvm::Value*> assignments;
    std::map<std::string, llvm::Value*> functions;

    void run_passes();
};