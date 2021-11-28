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

    while (std::getline(infile, line)) {
        if (is_comment(line) || is_white_space(line))
            continue;

        remove_backslash_r(line);
        instrs.push_back(line);
    }

    curr_instr_idx = 0;
    infile.close();
}

bool Parser::is_comment(std::string line) { return line.substr(0, 2) == "//"; }

bool Parser::is_white_space(std::string line)
{
    //
    return std::all_of(line.begin(), line.end(), isspace);
}

void Parser::remove_backslash_r(std::string& line) { line.erase(line.size() - 1); }

void Parser::advance()
{
    if (has_more_lines())
        curr_instr_idx++;
    else
        throw std::out_of_range("Current index is at last instruction");
}
bool Parser::has_more_lines()
{
    //
    return curr_instr_idx < instrs.size();
}

InstrType Parser::instr_type()
{
    switch (curr_instr()[0]) {
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

const std::string& Parser::curr_instr() { return instrs[curr_instr_idx]; }

std::string Parser::symbol()
{
    if (is_ctype_instr())
        throw std::logic_error("Cannot parse symbol for C_TYPE instructions");

    int npos = 0;
    auto cur_instr = curr_instr();
    if (is_ltype_instr())
        npos = cur_instr.length() - 2;
    else
        npos = cur_instr.length() - 1;
    return instrs[curr_instr_idx].substr(1, npos);
}

bool Parser::is_ctype_instr()
{
    auto it = instr_type();
    return it == InstrType::C_TYPE;
}

bool Parser::is_ltype_instr()
{
    auto it = instr_type();
    return it == InstrType::L_TYPE;
}

std::string Parser::dst()
{
    if (!is_ctype_instr())
        throw std::logic_error("Cannot parse dst for non C_TYPE instructions");

    auto cur_instr = curr_instr();
    std::size_t pos = cur_instr.find('=');
    return cur_instr.substr(0, pos);
}

std::string Parser::comp()
{
    if (!is_ctype_instr())
        throw std::logic_error("Cannot parse comp for non C_TYPE instructions");

    auto cur_instr = curr_instr();
    std::size_t eq_nxt_pos = cur_instr.find('=') + 1;
    unsigned npos = 0;
    while (npos + eq_nxt_pos < cur_instr.size() && cur_instr.at(npos + eq_nxt_pos) != ';')
        npos++;
    return cur_instr.substr(eq_nxt_pos, npos);
}

std::string Parser::jump()
{
    if (!is_ctype_instr())
        throw std::logic_error("Cannot parse jump for non C_TYPE instructions");

    auto cur_instr = curr_instr();
    std::size_t pos = cur_instr.find(';');
    if (std::string::npos == pos)
        return "";

    std::size_t pos_nxt = pos++;
    unsigned npos = 0;
    while (npos + pos_nxt < cur_instr.size())
        npos++;
    return cur_instr.substr(pos_nxt, npos);
}

unsigned Parser::num_instrs() { return instrs.size(); }
