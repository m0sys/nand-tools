// Parser for Hack assembly language.
// Date: 2021/11/24
// Author: @m0sys

#pragma once
#include <string>
#include <vector>

enum class InstrType { A_TYPE, C_TYPE, L_TYPE };

class Parser {
public:
    Parser(std::string fname);
    void advance();
    InstrType instr_type();
    std::string symbol();
    std::string dst();
    std::string comp();
    std::string jump();
    unsigned num_instrs();
    bool has_more_lines();
    void reset(); // go back to beginning of program

private:
    const std::string& curr_instr();
    bool is_ctype_instr();
    bool is_ltype_instr();

    static bool is_comment(std::string line);
    static bool is_white_space(std::string line);
    static void remove_backslash_r(std::string& line);
    static void remove_all_whitespace(std::string& line);
    static void remove_line_comment(std::string& line);

private:
    unsigned curr_instr_idx;
    std::vector<std::string> instrs;
};
