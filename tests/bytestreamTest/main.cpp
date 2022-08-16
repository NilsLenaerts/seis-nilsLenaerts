#include "../../src/bytestream.h"
#include <iostream>
#include <cstdint>


int main() {
    ByteStream bs("./string.txt");
    std::string in{"hello with \"escape \n lalala\" en ook nog eens een tab \t over hier, 10\\5 = 2"};
    std::string out{};
    bs.seek(1);
    while(bs.peekByte() != '\"'){
        if (bs.peekByte() == '\\'){
            bs.seek(1);
            unsigned char escapedChar = bs.peekByte();
            switch (escapedChar)
            {
            case '"':
                out.append(1,'\"');
                bs.seek(1);
                break;
            case 'n':
                out.append(1,'\n');
                bs.seek(1);
                break;
            case 't':
                out.append(1,'\t');
                bs.seek(1);
                break;
            case 'r':
                out.append(1,'\r');
                bs.seek(1);
                break;
            case '\'':
                out.append(1,'\'');
                bs.seek(1);
                break;
            case '\\':
                out.append(1,'\\');
                bs.seek(1);
                break;
            default:
                out.append(1,'\\');
                out.append(1,bs.readByte());
                break;
            }
            
        }else{
            out.append(1,bs.readByte());
        }
        
    }
    std::cout << in << std::endl;
    std::cout << out;
    
    return 0;
}