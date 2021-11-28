#include <iostream>

#include "assembler.h"
#include "parser.h"

#define LOG(x) std::cout << x << "\n"

int main()
{
    LOG("Hello, assembler!");
    LOG("");
    // Parser p("../../../add/Add.asm");
    Assembler a("../../../add/Add.asm");
    a.assemble();
    // LOG("");
    // Assembler a2("Add.asm");
    // LOG("");
    // Assembler a3("add/Add.asm");
    // LOG("");
    // Assembler a4("math/Math.asm");
    // LOG("");
    // Assembler a5("Math.asm");
}
