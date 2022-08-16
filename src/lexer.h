#pragma once

#include "bytestream.h"
#include "token.h"

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
    ~Lexer();

    int lex();
};