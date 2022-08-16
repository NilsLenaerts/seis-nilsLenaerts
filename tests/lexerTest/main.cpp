#include "../../src/bytestream.h"
#include "../../src/lexer.h"


int main() {
    Lexer lex("./test.wat");
    lex.lex();
    lex.printTokens();
    
    return 0;
}