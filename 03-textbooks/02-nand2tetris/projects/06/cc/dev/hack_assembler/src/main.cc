#include <iostream>

#include "assembler.h"
#include "parser.h"
#include <stdexcept>

#define LOG(x) std::cout << x << "\n"

int main(int argc, char* argv[])
{
    if (argc < 1)
        throw std::logic_error("must provide fname as arg");

    LOG("Hello, assembler!");
    Assembler a(argv[1]);
    a.assemble();
    LOG("...");
    LOG("Done assembling");
}
