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

    using CT = CommandType;

public:
    Parser(std::string fname);
    bool has_more_lines();
    void advance();
    CommandType command_type();
    std::string arg1();
    int arg2();
    int num_cmds();

private:
    static bool is_comment(std::string line);
    static bool is_white_space(std::string line);
    static void remove_backslash_r(std::string& line);
    static void remove_line_comment(std::string& line);
    const std::string& curr_cmd();

    bool is_push_type();
    bool is_pop_type();
    bool is_arith_type();
    bool is_ret_type();

private:
    unsigned curr_cmd_idx = 0;
    std::vector<std::string> cmds;
};
