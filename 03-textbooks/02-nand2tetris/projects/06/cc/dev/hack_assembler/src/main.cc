#include <iostream>

#include "assembler.h"
#include "parser.h"

#define LOG(x) std::cout << x << "\n"

int main()
{
    LOG("Hello, assembler!");
    LOG("");
    Assembler a("../../../add/Add.asm");
    a.assemble();
}
