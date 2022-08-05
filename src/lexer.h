#pragma once

#include "bytestream.h"

class Lexer
{
private:
    ByteStream byteStream;
    /* data */
public:
    Lexer(std::string path);
    Lexer(std::vector<uint8_t> stream);
    ~Lexer();

    int lex();
};

Lexer::Lexer(std::string path)
{
}

Lexer::~Lexer()
{
}
