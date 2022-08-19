#include <iostream>
#include <iomanip> // std::setw(), std::setfill()
#include <vector>
#include <string>

#include "lexer.h"
#include "parser.h"
#include "instruction.h"

using namespace std;

std::vector<Instruction*> Parser::parseProper() 
{
	std::vector<Token> tokens = this->lexer->getTokens();

	// Proper parser will map instructions to the main calculations and their operands, if applicable

	std::vector<Instruction*> output = std::vector<Instruction*>();

	int totalLenght = 0;

	// we only want to output the function body for now, to keep it simple
	// HACK: assume that only starts with the first valid "operation" we get
	// TODO: properly parse everything
	bool HACK_inCodeBlock = false;
	try{

	
		for ( int i = 0; i < tokens.size(); ++i ) {
			
			Token token = tokens[i];

			if ( token.type == TokenType::KEYWORD ) {
				uint8_t op = InstructionNumber::getOperation( token.string_value );
				
				// cout << "Parser::ParseProper : token : " << token.string_value << " maps to " << (int) op << endl;

				if ( op != constants::NOP ) {
					HACK_inCodeBlock = true;

					if ( InstructionNumber::isCalculation(op) ) {
						Instruction *instruction = instruction = new Instruction( InstructionType::CALCULATION );
						instruction->instruction_code = (int) op;
						output.push_back( instruction );
					}
					else if ( InstructionNumber::isConst(op) ) {
						Instruction *instruction = instruction = new Instruction( InstructionType::CONST );
						instruction->instruction_code = (int) op;
						Token parameter = tokens[++i]; // parameter MUST be next behind this
						instruction->parameter = parameter.uint32_value;

						output.push_back( instruction );
					}
					else if ( InstructionNumber::hasParameter(op) ) {
						Instruction *instruction = instruction = new Instruction( InstructionType::INSTRUCTION_WITH_PARAMETER );
						instruction->instruction_code = (int) op;
						Token parameter = tokens[++i]; // parameter MUST be next behind this
						instruction->parameter = parameter.uint32_value;

						output.push_back( instruction );
					}
					else if ( InstructionNumber::hasNoParameter(op) ) {
						Instruction *instruction = instruction = new Instruction( InstructionType::INSTRUCTION_WITHOUT_PARAMETER );
						instruction->instruction_code = (int) op;
						output.push_back( instruction );
					}
					else {
						cout << "Parser::ParseProper : unsupported operation found : " << (int) op << endl;
					}

				}
				// KEYWORD is either an instruction or a type (e.g., i32.add or just i32)
				else {
					if ( HACK_inCodeBlock ) {
						uint8_t type = InstructionNumber::getType( token.string_value );

						if ( type != constants::NOP ) {
							// Types are always without parameter
							Instruction *instruction = instruction = new Instruction( InstructionType::INSTRUCTION_WITHOUT_PARAMETER );
							instruction->instruction_code = (int) type;
							output.push_back( instruction );
						}
					}
				}
			}
			else if ( token.type == TokenType::BRACKETS_OPEN || token.type == TokenType::BRACKETS_CLOSED ) {
				// FIXME: TODO: properly support these, some of these should become END instructions!!!
			}
			else {
				if ( !HACK_inCodeBlock ) {
					continue;
				}

				cout << "Parser::ParseProper : unsupported TokenType found : " << token.getTokenType() << " for " << token.uint32_value << " OR " << token.string_value << endl;
			}
		}

		for ( auto instruction : output ) {
			cout << "Instruction " << (int) instruction->type << " for operation " << instruction->instruction_code << " with potential parameter " << instruction->parameter << endl;
		}

		return output;
	}
	catch (std::exception e){
		std::cout << "ERROR while parsing: " << e.what() << "\n";
		return std::vector<Instruction>();
	}
}
