#include "antlr4-runtime.h"
#include "FasdLexer.h"
#include "FasdParser.h"
#include "listener.h"
#include <iostream>

using namespace antlr4;

int main() {
    std::ifstream stream;
    stream.open("input.in");
    
    ANTLRInputStream input(stream);
    FasdLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    tokens.fill();
    FasdParser parser(&tokens);
    Listener listener{};
    parser.addParseListener(&listener);
    parser.start();

    return 0;
}