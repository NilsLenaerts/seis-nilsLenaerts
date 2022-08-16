#include <iostream>
#include <vector>
#include <string>

#include "../../src/lexer.h"
//#include "../../src/parser.h"
//#include "../../src/compiler.h"

int main(){
    Lexer lexer = Lexer{"./test.wat"};

    int err = lexer.lex();

    std::cout << "DONE LEXING INPUT FILE\n";

    lexer.printTokens();
    //Parser parser = Parser{&lexer};

}