#include "codegen.h"

#include "llvm/IR/Module.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/IRBuilder.h"
#include <string>
#include <iostream>

Codegen::Codegen(llvm::LLVMContext& context) : context(context), module("top", context), builder(context) {}

void Codegen::generate_start() {
    llvm::FunctionType* funcType = llvm::FunctionType::get(builder.getInt32Ty(), false);
    llvm::Function* operate_func = llvm::Function::Create(funcType, llvm::Function::ExternalLinkage, "operate", module);
    llvm::BasicBlock* block = llvm::BasicBlock::Create(context, "entrypoint", operate_func);
    builder.SetInsertPoint(block);
    block_stack.push(block);
}

void Codegen::generate_number(int number) {
    ret_stack.push(llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), number));
}

void Codegen::generate_operation(std::string op) {
    llvm::Value* llvm_rhs = ret_stack.pop();
    llvm::Value* llvm_lhs = ret_stack.pop();

    if (op.compare("+") == 0) {
        ret_stack.push(builder.CreateAdd(llvm_lhs, llvm_rhs));
    } else if (op.compare("-") == 0) {
        ret_stack.push(builder.CreateSub(llvm_lhs, llvm_rhs));
    } else if (op.compare("*") == 0) {
        ret_stack.push(builder.CreateMul(llvm_lhs, llvm_rhs));
    } else {
        ret_stack.push(builder.CreateUDiv(llvm_lhs, llvm_rhs));
    }
}

void Codegen::print() {
    builder.CreateRet(ret_stack.pop());
    module.print(llvm::errs(), nullptr);
}