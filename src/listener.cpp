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

    if (number_stack.size() < 2) {
        codegen->generate_operation(op, number_stack.pop());
    } else {
        codegen->generate_operation(op, number_stack.pop(), number_stack.pop());
    }
}

void Listener::exitStart(FasdParser::StartContext*) {
    codegen->print();
}