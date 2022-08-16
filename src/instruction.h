/* based on toledo example */
#pragma once

#include <cstdint>
#include <string>
#include "constants.h"

// shamelessly inspired by https://github.com/TimGysen/GysenVanherckSEIS/blob/main/VM/VM/Instruction.h
class InstructionNumber {

public:
    /* enum class Section { TYPE=0x01, IMPORT=0x02, FUNCTION=0X03, TABLE=0x04, MEMORY=0x05, GLOBAL=0x06, EXPORT=0x07, START=0x08, ELEMENT=0x09, CODE=0x0a, DATA=0x0b, CUSTOM=0x00 };
    enum class Type { NONE=0x00, I32=0x7f, I64=0x7e, F32=0x7d, F64=0x7c, FUNC=0x60 };
    enum class Operation{ NONE=0x00, LOCALGET=0x20, LOCALSET=0x21, I32ADD=0x6a, I32SUB = 0x6b, I32MUL=0x6c, I32DIV=0x6d , F32ADD=0x92 , F32SUB = 0x93, F32MUL = 0x94, END=0x0b, CALL=0x10,
                          I32CONST=0x41, I32EQ=0x46, IF=0x04, ELSE=0x05 };
    */

    static uint8_t getOperation(std::string name) {
        if ( name == "local.get" ) return constants::LOCALGET;
        if ( name == "local.set" ) return constants::LOCALSET;
        
        if ( name == "i32.add" ) return constants::I32ADD;
        if ( name == "i32.sub" ) return constants::I32SUB;
        if ( name == "i32.mul" ) return constants::I32MUL;
        if ( name == "i32.div_s" ) return constants::I32DIV_S;
        if ( name == "i32.div_u" ) return constants::I32DIV_U;
        if ( name == "i32.const" ) return constants::I32CONST;
        if ( name == "i32.and" ) return constants::I32AND;
    
        if ( name == "i32.eq" ) return constants::I32EQ;
        if ( name == "i32.eqz" ) return constants::I32EQZ;
        if ( name == "i32.ne" ) return constants::I32NE;
        if ( name == "i32.lt_s" ) return constants::I32LT_S;
        if ( name == "i32.lt_u" ) return constants::I32LT_U;
        if ( name == "i32.gt_s" ) return constants::I32GT_S;
        if ( name == "i32.gt_u" ) return constants::I32GT_U;
        if ( name == "i32.le_s" ) return constants::I32LE_S;
        if ( name == "i32.le_u" ) return constants::I32LE_U;
        if ( name == "i32.ge_s" ) return constants::I32GE_S;
        if ( name == "i32.ge_u" ) return constants::I32GE_U;

        if ( name == "if" ) return constants::IF;
        if ( name == "else" ) return constants::ELSE;
        if ( name == "br" ) return constants::BREAK;
        if ( name == "br_if" ) return constants::BREAK_IF;
        if ( name == "return" ) return constants::RETURN;
        if ( name == "call" ) return constants::CALL;
        if ( name == "end" ) return constants::END;

        if ( name == "i32.load" ) return constants::I32LOAD;
        if ( name == "i32.store") return constants::I32STORE;
        // TODO: support other operations!

        return constants::NONE;
    }

    static uint8_t getType(std::string name) {
        if ( name == "i32" ) return constants::I32;
        if ( name == "i64" ) return constants::I64;
        if ( name == "f32" ) return constants::F32;
        if ( name == "f64" ) return constants::F64;
        return constants::NONE;
    }

    static bool isCalculation( uint8_t op ) {
        for (uint8_t calcOp : constants::CALC_OPS){
            if (calcOp == op) return true;
        }
        return false;
    }

    static bool isConst( uint8_t op ) {
        for (uint8_t constOp : constants::CONSTANT_OPS){
            if (constOp == op) return true;
        }
        return false;
    }

    static bool hasParameter( uint8_t op ) {
        return !InstructionNumber::hasNoParameter(op);
    }

    static bool hasNoParameter( uint8_t op ) {
        for (uint8_t noParamOp : constants::NO_PARAM_OPS){
            if(noParamOp == op) return true;
        }
        return false;
    }
};

// TODO: add proper types that can be used for more than just a single compiler optimization!
// CALCULATION = takes 2 things from the stack and puts result on stack (e.g., i32.add, i32.eq, etc.)
// CONST = places a constant value on the stack (e.g., i32.const 15)
// INSTRUCTION_WITH_PARAMETER = any other instruction that needs to be serialized with its parameter (e.g., local.get)
// INSTRUCTION_WITHOUT_PARAMETER = any other instruction that needs to be serialized without its parameter (e.g., end, i32, if, else )
enum class InstructionType { CALCULATION = 10, CONST = 20, INSTRUCTION_WITH_PARAMETER = 30, INSTRUCTION_WITHOUT_PARAMETER = 40 };

class Instruction
{
public:
    Instruction(InstructionType type) : type(type) {}

    ~Instruction(){};

    InstructionType type;

    uint32_t instruction_code = (uint32_t) constants::NOP;
    uint32_t parameter = 0;
};
