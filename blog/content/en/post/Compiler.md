---
title: "The WebAssembly compiler: WAT?"
description: "WAT?"
date: 2022-08-18T15:13:10+02:00
featured_image: ""
disable_share: true
tags: []
---

To be able to run WebAssebly we first have to compile the WebAssembly text file to a WebAssembly binary. To be able to do this we will be writing our own basic compiler from scratch which will translate WebAssembly WAT files to WASM files. 

this will be done in three distinct steps
- Lexing
- Parsing
- Compiling

# The Lexer:

nearly all programming languages are made up of different words and symbols to make a complex program but how does a compiler know what is a class identifier or a string or a comment that is the job of the lexer. A lexer will spilt up the single WebAssembly Text file and split it up into different tokens which will later be used to actual compile the program.

a simple Webassembly program that adds up 2 numbers:

```js
i32.const 10
i32.const 20 (;a Block comment;)
i32.add
```
will become:
```js
i32.const
10
i32.const
20
i32.add
```
as you can see the comment is not included in the tokens.

### tokens
a token can be alot of different things but for this simple compiler we will only be looking at a couple of different types.

```cpp
enum class TokenType { BRACKETS_OPEN, BRACKETS_CLOSED, KEYWORD, STRING, NUMBER };
class Token
{
public:
    Token(TokenType type, std::string string_value) : type( type ), string_value( string_value ) {}
    Token(TokenType type, uint32_t uint32_value) : type( type ), uint32_value( uint32_value ) {}

    ~Token(){};

    TokenType type;

    // union was messing seriously with ability to store in std::vector<Token>, complaining about copy ctor
    // if extending with more types, should probably have a union or inheritance approach!
    // union {
    //     std::string string_value;
    //     uint32_t uint32_value;
    // };

    std::string string_value;
    uint32_t uint32_value;
}
```
the complete code for the token class can be found [here](https://github.com/NilsLenaerts/seis-nilslenaerts/blob/main/src/token.h)

a token can either be:
- brackets
- a keyword: these are words like "i32.add" or "func" 
- a string 
- a number

## the actual lexer

for the lexer to do its job it needs to be able to read characters from a file. to do this we will re-use the [byteStream](https://github.com/NilsLenaerts/seis-nilslenaerts/blob/main/src/bytestream.cpp) we made for the VM. 

