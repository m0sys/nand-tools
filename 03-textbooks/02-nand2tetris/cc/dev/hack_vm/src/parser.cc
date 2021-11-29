#include "parser.h"
#include <algorithm>
#include <fstream>
#include <regex>

// TODO: debug libs - to remove
#include <filesystem>
#include <iostream>

Parser::Parser(std::string fname)
{
    using std::cout;

    std::ifstream infile(fname);
    std::string line;

    // Check that fname exists before processing.
    if (!std::filesystem::exists(fname))
        throw std::logic_error("fname does not exist");

    cout << "Beginning to parse vm file...\n";
    while (std::getline(infile, line)) {
        cout << "Parsing line: " << line << "\n";
        if (is_comment(line) || is_white_space(line))
            continue;

        remove_backslash_r(line);
        // remove_all_whitespace(line);
        remove_line_comment(line);
        cmds.push_back(line);
    }

    for (auto it : cmds)
        cout << it << "\n";
    curr_cmd_idx = 0;
    infile.close();
    cout << "Done parsing vm file!\n";
}

bool Parser::is_comment(std::string line) { return line.substr(0, 2) == "//"; }

bool Parser::is_white_space(std::string line)
{
    //
    return std::all_of(line.begin(), line.end(), isspace);
}

void Parser::remove_backslash_r(std::string& line) { line.erase(line.size() - 1); }

void Parser::remove_all_whitespace(std::string& line)
{
    //
    line.erase(std::remove_if(line.begin(), line.end(), isspace), line.end());
}

void Parser::remove_line_comment(std::string& line)
{
    auto pos = line.find("//");
    if (pos != std::string::npos) {
        line.erase(pos);
    }
}

bool Parser::has_more_lines()
{
    //
    return curr_cmd_idx < cmds.size();
}

void Parser::advance()
{
    if (has_more_lines())
        curr_cmd_idx++;
    else
        throw std::out_of_range("Current index is at last instruction");
}

CommandType Parser::command_type()
{
    using std::string;
    auto ccmd = curr_cmd();

    // Check for push command.
    auto push_pos = ccmd.find("push");
    if (push_pos != string::npos)
        return CommandType::C_PUSH;

    // Check for pop command.
    auto pop_pos = ccmd.find("pop");
    if (pop_pos != string::npos)
        return CommandType::C_POP;

    auto const rgx_arith = std::regex("(add|sub|neg|eq|gt|lt|and|or|not)");
    if (std::regex_match(ccmd.begin(), ccmd.end(), rgx_arith))
        return CommandType::C_ARITH;

    return CommandType::UNKNOWN;
}

const std::string& Parser::curr_cmd() { return cmds[curr_cmd_idx]; }

std::string Parser::arg1() { return ""; }
int Parser::arg2() { return -1; }
