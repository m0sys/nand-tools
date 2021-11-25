#include <algorithm>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
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
        if (line.substr(0, 2) == "//" || std::all_of(line.begin(), line.end(), isspace))
            continue;
        instrs.push_back(line);
        i++;
    }

    std::cout << "\n\nInstructions found: \n";
    i = 0;
    for (auto instr : instrs) {
        std::cout << i << ": " << instr << "\n";
        i++;
    }

    curr_instr_idx = 0;
    std::cout << "done reading file with " << i << " lines read\n";
    infile.close();
}

void Parser::advance()
{
    if (curr_instr_idx < instrs.size())
        curr_instr_idx++;
    throw std::out_of_range("Current index is at last instruction");
}

InstrType Parser::instr_type()
{
    switch (instrs[curr_instr_idx][0]) {
    case '(':
        return InstrType::L_TYPE;
        break;
    case '@':
        return InstrType::A_TYPE;
        break;
    default:
        return InstrType::C_TYPE;
        break;
    }
}

std::string Parser::symbol()
{
    auto it = instr_type();
    if (it != InstrType::L_TYPE || it != InstrType::A_TYPE)
        std::logic_error("Cannot parse symbol for C_TYPE instructions");

    int npos = 0;
    auto cur_instr = instrs[curr_instr_idx];
    if (it == InstrType::L_TYPE)
        npos = cur_instr.length() - 2;
    else
        npos = cur_instr.length() - 1;
    return instrs[curr_instr_idx].substr(1, npos);
}

std::string Parser::dst()
{
    auto it = instr_type();
    if (it != InstrType::C_TYPE)
        std::logic_error("Cannot parse dst for non C_TYPE instructions");

    return "todo";
}

std::string Parser::comp() { return "todo"; }

std::string Parser::jump() { return "todo"; }
