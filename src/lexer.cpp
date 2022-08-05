#include "lexer.h"

Lexer::Lexer(std::string path): byteStream{path} {}

Lexer::Lexer(std::vector<uint8_t> stream): byteStream{stream}{}