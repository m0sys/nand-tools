// Assembler assembles Hack assembly code into Hack machine code.
// Date: 2021/11/26
// Author: @m0sys

#pragma once
#include <map>
#include <string>

class Assembler {
    using SymbolTable = std::map<std::string, std::string>;

public:
    Assembler(std::string fname);
    void assemble();

private:
    void first_pass();
    void second_pass();
    void create_prog_name();
    void create_init_st();

    static std::string dec_to_bin(int dec);
    static bool is_num(std::string str);

public:
    std::string m_fname;

private:
    SymbolTable st;
    int curr_var_idx = 16;
    std::string fname;
};
