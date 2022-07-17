#pragma once

#include <vector>
#include <utility>
#include <cstdint>
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>

class ByteStream {

    private:
        std::vector<uint8_t> buffer;
        int currentByteIndex;
    public:
        ByteStream();
        ByteStream(std::vector<uint8_t> stream);
        ByteStream(std::string filePath);

        uint8_t readByte(); //reads byte and moves index to next possition
        uint8_t peekByte(); //reads byte but does not move index

        int32_t readInt32();
        uint32_t readUInt32();

        int64_t readInt64();
        uint64_t readUInt64();

        void seek(int offset);

};