#include "bytestream.h"

ByteStream::ByteStream() : currentByteIndex{0}, buffer{0} {}

ByteStream::ByteStream(std::string filePath) : currentByteIndex{0} {
    std::ifstream f(filePath,  std::ios::binary);
    if (f.is_open()){
        //source: ubuntuforumes.org/showthread.php?t=67867
        f >> std::noskipws; 
        std::copy(
            std::istream_iterator<uint8_t>(f),
            std::istream_iterator<uint8_t>(),
            std::back_inserter(buffer));
        
    }else{
        throw std::invalid_argument("could not read file: " + filePath);
    }
    f.close();
}

ByteStream::ByteStream(std::vector<uint8_t> stream) : buffer{stream}{}

uint8_t ByteStream::readByte()
{
    uint8_t byte = peekByte();

    ++currentByteIndex;
    return byte;
}

uint8_t ByteStream::peekByte()
{
    if (currentByteIndex > buffer.size()){
        //throw std::out_of_range("Reached end of bytestream");
        return 0;
    }
    return buffer[currentByteIndex];
}
//based on: https://en.wikipedia.org/wiki/LEB128
int32_t ByteStream::readInt32()
{
    int32_t result{0};
    int shift{0};
    uint8_t byte;

    do
    {
        byte = readByte();
        result |= ((byte & 0b01111111) << shift );
        shift += 7;
    } while ((byte & 0b10000000) != 0);

    if ((shift < 32) && (byte & 0x40) == 0x40){
        result |= (~0 << shift);
    }

    return result;
}

uint32_t ByteStream::readUInt32()
{
	uint32_t result{0};
	uint8_t byte;
	int shift{ 0 };
	
	while (true){
        byte = readByte();
        result |= ((byte & 0b01111111) << shift);
        if ((byte & 0b10000000) == 0) break;
        shift += 7;
    }

	return result;
}

int64_t ByteStream::readInt64()
{
	int64_t result{0};
    int shift{0};
    uint8_t byte;

    do
    {
        byte = readByte();
        result |= ((byte & 0b01111111) << shift );
        shift += 7;
    } while ((byte & 0b10000000) != 0);

    if ((shift < 64) && (byte & 0x40) == 0x40){
        result |= (~0 << shift);
    }

    return result;
}

uint64_t ByteStream::readUInt64()
{
	uint64_t result{0};
	uint8_t byte;
	int shift{ 0 };
	
	while (true){
        byte = readByte();
        result |= ((byte & 0b01111111) << shift);
        if ((byte & 0b10000000) == 0) break;
        shift += 7;
    }

	return result;
}

void ByteStream::seek(int offset){
    currentByteIndex += offset;
}

bool ByteStream::atEnd(){
    return currentByteIndex >= buffer.size();
}