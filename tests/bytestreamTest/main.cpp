#include "../../src/bytestream.h"
#include <iostream>
#include <cstdint>

int main() {
    ByteStream bs("./number");
    std::cout << bs.readInt32() << std::endl;
    return 0;
}