#include "lexer.h"

Lexer::Lexer(std::string path): byteStream{path} {}

Lexer::Lexer(std::vector<uint8_t> stream): byteStream{stream}, tokens{std::vector<Token>()}{}

int Lexer::lex(){

    //stop lexing at end of the file
    while(!byteStream.atEnd()){

        //skip whitespaces
        while(Character::isWhitespace(byteStream.peekByte())){
            byteStream.seek(1); //move 1 byte forward.
        }

        //if we are at the end after skipping whitespaces stop lexing.
        if (byteStream.atEnd()){
            break;
        }

        unsigned char nextCharacter = byteStream.peekByte();

        if(Character::isNumeric(nextCharacter)){
            tokens.push_back(parseNumber());
        }
        else if(Character::isWASMIdentifier(nextCharacter)){
            tokens.push_back(parseKeyWord());
        }
        else switch (nextCharacter)
        {
        case '"':
            tokens.push_back(parseString());
            break;
        
        case '(':
            //check if it is the begin of block comment otherwise just add the bracket type
            byteStream.seek(1);
            if(byteStream.peekByte() == ';'){
                parseBlockComment();
            }else{
                tokens.push_back(Token(TokenType::BRACKETS_OPEN, std::string(1,'(')));
            }
            break;

        case ')':
            tokens.push_back(Token(TokenType::BRACKETS_CLOSED, std::string(1,byteStream.readByte())));
            break;

        case ';':
            //check next byte if it is the begin of a single line comment
            byteStream.seek(1);
            if(byteStream.peekByte() == ';'){
                parseLineComment();
            }else{
                tokens.push_back(Token(TokenType::STRING, std::string(1,';')));
            }
            break;

        default:
            break;
        }

    }

    return 0;
}

Token Lexer::parseNumber(){
    std::string number{};

    while(Character::isNumeric(byteStream.peekByte()) || byteStream.peekByte() == '_'){
        number.append(1,byteStream.readByte());
    }

    //if the string contains _ to seperate digits remove them. 
    if (number.find('_') != std::string::npos){
        number.erase(remove(number.begin(), number.end(), '_'), number.end()); //from https://www.tutorialspoint.com/how-to-remove-certain-characters-from-a-string-in-cplusplus
    }

    return Token(TokenType::NUMBER, std::stoi(number));
}

Token Lexer::parseKeyWord(){
    std::string keyWord{};
    while(Character::isWASMIdentifier(byteStream.peekByte())){
        keyWord.append(1,byteStream.readByte());
    }
    return Token(TokenType::KEYWORD, keyWord);
}

Token Lexer::parseString(){
    std::string string{};
    byteStream.seek(1); //skip upcoming " from beginning of string
    while(byteStream.peekByte() != '"'){
        if (byteStream.peekByte() == '\\'){
            byteStream.seek(1);
            //check for common escape character and deal with them correctly
            unsigned char escapedChar = byteStream.peekByte();
            switch (escapedChar)
            {
            case '"':
                string.append(1,'\"');
                byteStream.seek(1);
                break;
            case 'n':
                string.append(1,'\n');
                byteStream.seek(1);
                break;
            case 't':
                string.append(1,'\t');
                byteStream.seek(1);
                break;
            case 'r':
                string.append(1,'\r');
                byteStream.seek(1);
                break;
            case '\'':
                string.append(1,'\'');
                byteStream.seek(1);
                break;
            case '\\':
                string.append(1,'\\');
                byteStream.seek(1);
                break;
            default:
                string.append(1,byteStream.readByte());
                break;
            }
            
        }else{
            string.append(1,byteStream.readByte());
        }
        
    }

    byteStream.seek(1); //skip " at end of the string
    return Token(TokenType::STRING, string);
}

void Lexer::parseBlockComment(){

    //skip the ; from the start of the block comment
    byteStream.seek(1);

    while(!byteStream.atEnd()){
        if (byteStream.readByte() == ';'){
            if(byteStream.readByte() == ')'){
                return;
            }
        }
    }
}

void Lexer::parseLineComment(){
    //skip the next bytes until we reach an eol
    while (!byteStream.atEnd() &&(byteStream.peekByte() != '\n')){
        byteStream.seek(1);
    }
}

void Lexer::printTokens()
{
	for (Token token : tokens) {
		TokenType tokentype = token.type;
		if (token.type == TokenType::NUMBER) {
			std::cout << std::setw(20) << std::left << token.getTokenType()   << token.uint32_value<<"\n";
		}
		else {
			std::cout << std::setw(20) << std::left << token.getTokenType()  << token.string_value << "\n";
		}
	}
}