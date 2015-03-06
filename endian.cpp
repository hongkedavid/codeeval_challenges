#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char* argv[]) { 

    uint32_t endianness = 0xdeadbeef;
    if (((uint8_t)(*(const char *)&endianness)) == 0xef)
        cout << "LittleEndian" << endl;
    else if (((uint8_t)(*(const char *)&endianness)) == 0xde)    
        cout << "BigEndian" << endl;
    
    return 0;
}
 
