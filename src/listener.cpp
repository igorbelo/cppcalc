#include <iostream>
#include <string>
#include "listener.h"

using namespace std;

void Listener::enterStart(FasdParser::StartContext*) {
    codegen->generate_start();
}

void Listener::exitNumber(FasdParser::NumberContext* ctx) {
    codegen->generate_number(stoi(ctx->getText()));
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
    codegen->generate_operation(op);
}

void Listener::exitStart(FasdParser::StartContext*) {
    codegen->print();
}