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
    block_stack.push(block);
}

void Codegen::generate_operation(std::string op, int lhs, int rhs) {
    llvm::Value* llvm_lhs = llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), lhs);
    llvm::Value* llvm_rhs = llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), rhs);
    builder.SetInsertPoint(block_stack.get());
    
    ret_stack.push(create_operation(op, llvm_lhs, llvm_rhs));
}

void Codegen::generate_operation(std::string op, int rhs) {
    llvm::Value* llvm_lhs = ret_stack.pop();
    llvm::Value* llvm_rhs = llvm::ConstantInt::get(llvm::Type::getInt32Ty(context), rhs);

    ret_stack.push(create_operation(op, llvm_lhs, llvm_rhs));
}

void Codegen::generate_operation(std::string op) {
    llvm::Value* llvm_rhs = ret_stack.pop();
    llvm::Value* llvm_lhs = ret_stack.pop();

    ret_stack.push(create_operation(op, llvm_lhs, llvm_rhs));
}

void Codegen::print() {
    builder.CreateRet(ret_stack.pop());
    module.print(llvm::errs(), nullptr);
}

llvm::Value* Codegen::create_operation(std::string op, llvm::Value* lhs, llvm::Value* rhs) {
    if (op.compare("+") == 0) {
        return builder.CreateAdd(lhs, rhs);
    } else if (op.compare("-") == 0) {
        return builder.CreateSub(lhs, rhs);
    } else if (op.compare("*") == 0) {
        return builder.CreateMul(lhs, rhs);
    } else {
        return builder.CreateUDiv(lhs, rhs);
    }
}