#pragma once

#include "lexer.h"
#include "instruction.h"

class Parser
{
private:
    Lexer *lexer;

public:
	Parser(Lexer *lexer) : lexer(lexer) {}
    ~Parser() {}
    
    ByteStream* parseSimple();
    std::vector<Instruction*> parseProper();
};
