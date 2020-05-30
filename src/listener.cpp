#include <iostream>
#include <string>
#include "listener.h"

using namespace std;

void Listener::enterStart(FasdParser::StartContext*) {
    codegen->generate_start();
}

void Listener::exitNumber(FasdParser::NumberContext* ctx) {
    number_stack.push(stoi(ctx->getText()));
}

void Listener::exitAddSub(FasdParser::AddSubContext* ctx) {
    string op = ctx->op->getText();
    exitBinaryOperation(op);
}

void Listener::exitMulDiv(FasdParser::MulDivContext* ctx) {
    string op = ctx->op->getText();
    exitBinaryOperation(op);
}

void Listener::exitBinaryOperation(string op) {
    if (number_stack.size() == 0) {
        codegen->generate_operation(op);
    } else if (number_stack.size() == 1) {
        codegen->generate_operation(op, number_stack.pop());
    } else {
        int rhs = number_stack.pop();
        codegen->generate_operation(op, number_stack.pop(), rhs);
    }
}

void Listener::exitStart(FasdParser::StartContext*) {
    codegen->print();
}