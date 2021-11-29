// Parser for Hack VM language.
// Date: 2021/11/29
// Author: m0sys

#pragma once
#include <string>
#include <vector>

enum class CommandType {
    UNKNOWN,
    C_ARITH,
    C_PUSH,
    C_POP,
    C_LABEL,
    C_GOTO,
    C_IF,
    C_FUNC,
    C_RET,
    C_CALL,
};

class Parser {

public:
    Parser(std::string fname);
    bool has_more_lines();
    void advance();
    CommandType command_type();
    std::string arg1();
    int arg2();

private:
    static bool is_comment(std::string line);
    static bool is_white_space(std::string line);
    static void remove_backslash_r(std::string& line);
    static void remove_all_whitespace(std::string& line);
    static void remove_line_comment(std::string& line);
    const std::string& curr_cmd();

private:
    unsigned curr_cmd_idx;
    std::vector<std::string> cmds;
};
