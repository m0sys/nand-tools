#include "parser/parser.h"
#include "vm_translator.h"
#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>

#define LOG(x) std::cout << x << "\n"

void regex_playground();

int main(int argc, char* argv[])
{
    if (argc < 1)
        throw std::logic_error("must provide fname as arg");

    LOG("Hello, VM translator!");

    VMTranslator vmt(argv[1]);
    vmt.translate();

    LOG("Done VM translation");
}
