#include <algorithm>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "parser.h"

Parser::Parser(std::string fname)
{
    std::ifstream infile(fname);
    std::string line;
    int i = 0;
    std::string asm_line;
    std::cout << "reading file with name: " << fname << "\n";
    while (std::getline(infile, line)) {
        // std::istringstream iss(line);
        // if (!(iss >> asm_line)) {
        //    std::cout << "error!\n";
        //    break;
        //} // error
        if (line.substr(0, 2) == "//" || std::all_of(line.begin(), line.end(), isspace))
            continue;
        // std::cout << i << ": "
        //           << " found commented line\n";
        instrs.push_back(line);
        std::cout << i << ": " << line << "\n";
        i++;
    }

    std::cout << "\n\nInstructions found: \n";
    i = 0;
    for (auto instr : instrs) {
        std::cout << i << ": " << instr << "\n";
        i++;
    }

    std::cout << "done reading file with " << i << " lines read\n";
    infile.close();
}

void Parser::advance() { }

InstrType Parser::instr_type() { return InstrType::A_TYPE; }

std::string Parser::symbol() { return "todo"; }

std::string Parser::dst() { return "todo"; }

std::string Parser::comp() { return "todo"; }

std::string Parser::jump() { return "todo"; }
