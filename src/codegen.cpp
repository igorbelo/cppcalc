#include "codegen.h"

#include "llvm/IR/Module.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Passes/PassBuilder.h"
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

void Codegen::generate_assignment(std::string identifier) {
    llvm::Value* v = builder.CreateAlloca(llvm::Type::getInt32Ty(context), nullptr, identifier);
    builder.CreateStore(ret_stack.pop(), v);
    assignments[identifier] = v;
}

void Codegen::generate_identifier(std::string identifier) {
    ret_stack.push(assignments[identifier]);
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

void Codegen::generate_function_declaration(std::string identifier, std::string parameter) {
    llvm::FunctionType* funcType = llvm::FunctionType::get(builder.getInt32Ty(), builder.getInt32Ty(), false);
    llvm::Function* func = llvm::Function::Create(
        funcType, 
        llvm::Function::ExternalLinkage, 
        identifier, 
        module
    );

    llvm::Function::arg_iterator args = func->arg_begin();
    llvm::Value* arg1 = args++;
    arg1->setName(parameter);
    assignments[parameter] = arg1;
    functions[identifier] = func;

    llvm::BasicBlock* block = llvm::BasicBlock::Create(context, "entrypoint", func);
    builder.SetInsertPoint(block);
    block_stack.push(block);
}

void Codegen::generate_function_expression() {
    block_stack.pop();
    builder.CreateRet(ret_stack.pop());
    builder.SetInsertPoint(block_stack.get());
}

void Codegen::generate_function_call(std::string identifier) {
    std::vector<llvm::Value*> args;
    args.push_back(ret_stack.pop());
    ret_stack.push(builder.CreateCall(functions[identifier], args));
}

void Codegen::print() {
    builder.CreateRet(ret_stack.pop());
    run_passes();
    module.print(llvm::errs(), nullptr);
}

void Codegen::run_passes() {
    // llvm::PassBuilder passBuilder;
    // llvm::LoopAnalysisManager loopAnalysisManager(true);
    // llvm::FunctionAnalysisManager functionAnalysisManager(true);
    // llvm::CGSCCAnalysisManager cGSCCAnalysisManager(true);
    // llvm::ModuleAnalysisManager moduleAnalysisManager(true);
    // passBuilder.registerModuleAnalyses(moduleAnalysisManager);
    // passBuilder.registerCGSCCAnalyses(cGSCCAnalysisManager);
    // passBuilder.registerFunctionAnalyses(functionAnalysisManager);
    // passBuilder.registerLoopAnalyses(loopAnalysisManager);
    // passBuilder.crossRegisterProxies(loopAnalysisManager, functionAnalysisManager, cGSCCAnalysisManager, moduleAnalysisManager);
    // llvm::ModulePassManager modulePassManager = passBuilder.buildPerModuleDefaultPipeline(llvm::PassBuilder::OptimizationLevel::O1);
    // modulePassManager.run(module, moduleAnalysisManager);
}