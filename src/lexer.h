#pragma once

#include "bytestream.h"
#include "token.h"
#include <iomanip>

class Lexer
{
private:
    ByteStream byteStream;
    std::vector<Token> tokens;
    Token parseNumber();
    Token parseKeyWord();
    Token parseString();
    void parseBlockComment();
    void parseLineComment();

public:
    Lexer(std::string path);
    Lexer(std::vector<uint8_t> stream);

    void printTokens();
    std::vector<Token> getTokens() {return this->tokens;}

    int lex();
};