#include <iostream>

#include "parser.h"

#define LOG(x) std::cout << x << "\n"

int main()
{
    LOG("Hello, assembler!");
    Parser p("../../../add/Add.asm");
}
