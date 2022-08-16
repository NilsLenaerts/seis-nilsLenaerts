#pragma once

#include <vector>

namespace constants{
    // wat identifiers
    const std::vector<char> WAT_IDENTIFIERS = {'!', '#', '$', '%', '&', '\'', '*', '+', '-', '.', '/', ':', '<', '=', '>', '?', '@', '\\', '^', '_', '`', '|', '~'};


    /*
    * BINARY FORMAT ENCODING SHORTHAND
    */

    const uint8_t NONE = 0x00;

    /*FILE SECTIONS*/
    const uint8_t CUSTOM_SECTION = 0x00;
    const uint8_t TYPE_SECTION = 0x01;
    const uint8_t IMPORT_SECTION = 0x02;
    const uint8_t FUNCTION_SECTION = 0x03;
    const uint8_t TABLE_SECTION = 0x04;
    const uint8_t MEMORY_SECTION = 0x05;
    const uint8_t GLOBAL_SECTION = 0x06;
    const uint8_t EXPORT_SECTION = 0x07;
    const uint8_t START_SECTION = 0x08;
    const uint8_t ELEMENT_SECTION = 0x09;
    const uint8_t CODE_SECTION = 0x0A;
    const uint8_t DATA_SECTION = 0x0B;
    const uint8_t DATACOUNT_SECTION = 0x0C;

	/*NUMBER TYPES*/
	const uint8_t I32 = 0x7F;
    const uint8_t I64 = 0x7E;
    const uint8_t F32 = 0x7D;
    const uint8_t F64 = 0x7C;

    /*VECTOR TYPES*/
    const uint8_t v128 = 0x7B;

    /*REFRENCE TYPES*/
    const uint8_t FUNCREF = 0x70;
    const uint8_t EXTERNREF = 0x6F;

    /*CONTROL INSTRUCTIONS*/
    const uint8_t UNREACHABLE = 0x00;
    const uint8_t NOP = 0X01;
    const uint8_t BLOCK = 0x02;
    const uint8_t LOOP = 0x03;
    const uint8_t IF = 0x04;
    const uint8_t ELSE = 0x05;
    const uint8_t END = 0x0B;
    const uint8_t BREAK = 0x0C;
    const uint8_t BREAK_IF = 0x0D;
    const uint8_t BREAK_TABLE = 0x0F;
    const uint8_t RETURN = 0x10;
    const uint8_t CALL = 0x11;
    const uint8_t CALL_INDIRECT = 0x12;

    /*PARAMETRIC INSTRUCTIONS*/
    const uint8_t DROP = 0x1A;
    const uint8_t SELECT = 0x1B;
    const uint8_t SELECTTYPE = 0x1C;

    /*VARIABLE INSTRUCTIONS*/
    const uint8_t LOCALGET = 0x20;
    const uint8_t LOCALSET = 0x21;
    const uint8_t LOCALTEE = 0x22;
    const uint8_t GLOBALGET = 0x23;
    const uint8_t GLOBALSET = 0x24;

    /*TABLE INSTRUCTIONS*/
    const uint8_t TABLEGET = 0x25;
    const uint8_t TABLESET = 0x26;

    /*MEMORY INSTRUCTIONS*/
    const uint8_t I32LOAD = 0x28;
    const uint8_t I64LOAD = 0x29;
    const uint8_t F32LOAD = 0x2A;
    const uint8_t F64LOAD = 0x2B;

    const uint8_t I32STORE = 0x36;
    const uint8_t I64STORE = 0x37;
    const uint8_t F32STORE = 0x38;
    const uint8_t F64STORE = 0x39;
    
    const uint8_t MEMORYSIZE = 0x3F;
    const uint8_t MEMORYGROW = 0x40;

    /*NUMERIC INSTRUCTIONS WITH IMMEDIATES*/
    const uint8_t I32CONST = 0x41;
    const uint8_t I64CONST = 0x42;
    const uint8_t F32CONST = 0x43;
    const uint8_t F64CONST = 0x44;

    /*NUMERIC INSTRUCTIONS WITHOUT IMMEDIATES*/

    /*I32 COMPARISON INSTUCTIONS*/
    const uint8_t I32EQZ = 0x45;
    const uint8_t I32EQ = 0x46;
    const uint8_t I32NE = 0x47;
    const uint8_t I32LT_S = 0x48;
    const uint8_t I32LT_U = 0x49;
    const uint8_t I32GT_S = 0x4A;
    const uint8_t I32GT_U = 0x4B;
    const uint8_t I32LE_S = 0x4C;
    const uint8_t I32LE_U = 0x4D;
    const uint8_t I32GE_S = 0x4E;
    const uint8_t I32GE_U = 0x4F;

    /*I64 COMPARISON INSTUCTIONS*/
    const uint8_t I64EQZ = 0x50;
    const uint8_t I64EQ = 0x51;
    const uint8_t I64NE = 0x52;
    const uint8_t I64LT_S = 0x53;
    const uint8_t I64LT_U = 0x54;
    const uint8_t I64GT_S = 0x55;
    const uint8_t I64GT_U = 0x56;
    const uint8_t I64LE_S = 0x57;
    const uint8_t I64LE_U = 0x58;
    const uint8_t I64GE_S = 0x59;
    const uint8_t I64GE_U = 0x5A;

    /*F32 COMPARISON INSTUCTIONS*/
    const uint8_t F32EQ = 0x5B;
    const uint8_t F32NE = 0x5C;
    const uint8_t F32LT = 0x5D;
    const uint8_t F32GT = 0x5E;
    const uint8_t F32LE = 0x5F;
    const uint8_t F32GE = 0x60;

    /*F64 COMPARISON INSTUCTIONS*/
    const uint8_t F64EQ = 0x61;
    const uint8_t F64NE = 0x62;
    const uint8_t F64LT = 0x63;
    const uint8_t F64GT = 0x64;
    const uint8_t F64LE = 0x65;
    const uint8_t F64GE = 0x66;

    /*I32 CALC INSTUCTIONS*/
    const uint8_t I32CLZ = 0x67;
    const uint8_t I32CTZ = 0x68;
    const uint8_t I32POPCNT = 0x69;
    const uint8_t I32ADD = 0x6A;
    const uint8_t I32SUB = 0x6B;
    const uint8_t I32MUL = 0x6C;
    const uint8_t I32DIV_S = 0x6D;
    const uint8_t I32DIV_U = 0x6E;
    const uint8_t I32REM_S = 0x6F;
    const uint8_t I32REM_U = 0x70;
    const uint8_t I32AND = 0x71;
    const uint8_t I32OR = 0x72;
    const uint8_t I32XOR = 0x73;
    const uint8_t I32SHL = 0x74;
    const uint8_t I32SHR_S = 0x75;
    const uint8_t I32SHR_U = 0x76;
    const uint8_t I32ROTL = 0x77;
    const uint8_t I32ROTR = 0x78;   

    /*I64 CALC INSTUCTIONS*/
    const uint8_t I64CLZ = 0x79;
    const uint8_t I64CTZ = 0x7A;
    const uint8_t I64POPCNT = 0x7B;
    const uint8_t I64ADD = 0x7C;
    const uint8_t I64SUB = 0x7D;
    const uint8_t I64MUL = 0x7E;
    const uint8_t I64DIV_S = 0x7F;
    const uint8_t I64DIV_U = 0x80;
    const uint8_t I64REM_S = 0x81;
    const uint8_t I64REM_U = 0x82;
    const uint8_t I64AND = 0x83;
    const uint8_t I64OR = 0x84;
    const uint8_t I64XOR = 0x85;
    const uint8_t I64SHL = 0x86;
    const uint8_t I64SHR_S = 0x87;
    const uint8_t I64SHR_U = 0x88;
    const uint8_t I64ROTL = 0x89;
    const uint8_t I64ROTR = 0x8A; 

    /*F32 CALC INSTRUCTIONS*/
    const uint8_t F32ABS = 0x8B;
    const uint8_t F32NEG = 0x8C;
    const uint8_t F32CEIL = 0x8D;
    const uint8_t F32FLOOR = 0x8E;
    const uint8_t F32TRUNC = 0x8F;
    const uint8_t F32NEAREST = 0x90;
    const uint8_t F32SQRT = 0x91;
    const uint8_t F32ADD = 0x92;
    const uint8_t F32SUB = 0x93;
    const uint8_t F32MUL = 0x94;
    const uint8_t F32DIV = 0x95;
    const uint8_t F32MIN = 0x96;
    const uint8_t F32MAX = 0x97;
    const uint8_t F32COPYSIGN = 0x98;

    /*F64 CALC INSTRUCTIONS*/
    const uint8_t F64ABS = 0x99;
    const uint8_t F64NEG = 0x9A;
    const uint8_t F64CEIL = 0x9B;
    const uint8_t F64FLOOR = 0x9C;
    const uint8_t F64TRUNC = 0x9D;
    const uint8_t F64NEAREST = 0x9E;
    const uint8_t F64SQRT = 0x9F;
    const uint8_t F64ADD = 0xA0;
    const uint8_t F64SUB = 0xA1;
    const uint8_t F64MUL = 0xA2;
    const uint8_t F64DIV = 0xA3;
    const uint8_t F64MIN = 0xA4;
    const uint8_t F64MAX = 0xA5;
    const uint8_t F64COPYSIGN = 0xA6;

    /*NUMERICAL CONVERSION INSTRUCTIONS*/
    /*TO I32*/
    const uint8_t I32WRAP_I64 = 0xA7;
    const uint8_t I32TRUNC_F32_S = 0xA8;
    const uint8_t I32TRUNC_F32_U = 0xA9;
    const uint8_t I32TRUNC_F64_S = 0xAA;
    const uint8_t I32TRUNC_F64_U = 0xAB;
    const uint8_t I32REINTERPRET_F32 = 0xBC;

    /*TO I64*/
    const uint8_t I64EXTEND_I32_S = 0xAC;
    const uint8_t I64EXTEND_I32_U = 0xAD;
    const uint8_t I64TRUNC_F32_S = 0xAE;
    const uint8_t I64TRUNC_F32_U = 0xAF;
    const uint8_t I64TRUNC_F64_S = 0xB0;
    const uint8_t I64TRUNC_F64_U = 0xB1;
    const uint8_t I64REINTERPRET_F64 = 0xBD;

    /*TO F32*/
    const uint8_t F32CONVERT_I32_S = 0xB2;
    const uint8_t F32CONVERT_I32_U = 0xB3;
    const uint8_t F32CONVERT_I64_S = 0xB4;
    const uint8_t F32CONVERT_I64_U = 0xB5;
    const uint8_t F32DEMOTE_F64 = 0xB6;
    const uint8_t F32REINTERPRET_I32 = 0xBE;


    /*TO F64*/
    const uint8_t F64CONVERT_I32_S = 0xB7;
    const uint8_t F64CONVERT_I32_U = 0xB8;
    const uint8_t F64CONVERT_I64_S = 0xB9;
    const uint8_t F64CONVERT_I64_U = 0xBA;
    const uint8_t F64PROMOTE_F32 = 0xBB;
    const uint8_t F64REINTERPRET_I64 = 0xBF;


    /*INSTRUCTION LISTS*/
    const std::vector<uint8_t> TYPE_OPS =  {I32, I64,F32,F64};
    const std::vector<uint8_t> CALC_OPS =  {I32ADD, I32SUB, I32MUL, I32DIV_S, I32DIV_U, F32ADD, F32SUB, F32MUL, F32DIV,
                                            I64ADD, I64SUB, I64MUL, I64DIV_S, I64DIV_U, F64ADD, F64SUB, F64MUL, F64DIV
                                            };
    const std::vector<uint8_t> CONSTANT_OPS = {I32CONST, I64CONST, F32CONST, F64CONST};
    
    // TODO: add support for more ops
    const std::vector<uint8_t> NO_PARAM_OPS =  {END,ELSE,
                                                I32ADD, I32SUB, I32MUL, I32DIV_S, I32DIV_U, I32EQZ, I32EQ, I32NE,
                                                I32LT_S, I32LT_U, I32GT_S, I32GT_U, I32LE_S, I32LE_U, I32GE_S, I32GE_U,
                                                I32AND, I32OR, I32XOR, I32SHL, I32SHR_S, I32SHR_U, I32WRAP_I64,
                                                I32TRUNC_F32_S, I32REINTERPRET_F32
                                                };
}