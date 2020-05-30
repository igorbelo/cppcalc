OUTPUT=output
GENERATED=src/parser
GRAMMAR=Fasd.g4
EXECUTABLE_NAME=fasd

RUNTIME=runtime
CC=clang++
CCARGS=-c `$(LLVMHEADERS)` -I src -I $(RUNTIME)/antlr4-runtime/ -I $(GENERATED)
LDARGS=-g
LLVMHEADERS=llvm-config --cxxflags
LLVMARGS=llvm-config --libs codegen --system-libs --ldflags
LIBS=$(RUNTIME)/lib/libantlr4-runtime.a `$(LLVMARGS)`

all: build_and_run

build_and_run:
	$(CC) $(CCARGS) main.cpp -o $(OUTPUT)/main.o
	$(CC) $(CCARGS) $(GENERATED)/FasdBaseListener.cpp -o $(OUTPUT)/FasdBaseListener.o 
	$(CC) $(CCARGS) $(GENERATED)/FasdLexer.cpp -o $(OUTPUT)/FasdLexer.o 
	$(CC) $(CCARGS) $(GENERATED)/FasdListener.cpp -o $(OUTPUT)/FasdListener.o 
	$(CC) $(CCARGS) $(GENERATED)/FasdParser.cpp -o $(OUTPUT)/FasdParser.o 
	$(CC) $(CCARGS) src/listener.cpp -o $(OUTPUT)/listener.o
	$(CC) $(CCARGS) src/codegen.cpp -o $(OUTPUT)/codegen.o 
	$(CC) $(LDARGS) $(OUTPUT)/main.o $(OUTPUT)/codegen.o $(OUTPUT)/listener.o $(OUTPUT)/FasdBaseListener.o $(OUTPUT)/FasdLexer.o $(OUTPUT)/FasdListener.o $(OUTPUT)/FasdParser.o -I/usr/local/Cellar/llvm/9.0.1/include -std=c++11 -stdlib=libc++   -D__STDC_CONSTANT_MACROS -D__STDC_FORMAT_MACROS -D__STDC_LIMIT_MACROS $(LIBS) -o $(EXECUTABLE_NAME)
	./$(EXECUTABLE_NAME)

generate_parser:
	java -Xmx500M -cp "/usr/local/lib/antlr-4.7.1-complete.jar:$CLASSPATH" org.antlr.v4.Tool -Dlanguage=Cpp -o src/parser Fasd.g4

clean:
	rm output/* $(EXECUTABLE_NAME)