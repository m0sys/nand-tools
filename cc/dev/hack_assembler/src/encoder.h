// Encoder translates parsed pieces of Hack assembly into Hack binary equivalents.
// Date: 2021/11/26
// Author: @m0sys

#pragma once

#include <map>
#include <string>

class Encoder {
public:
    static std::string encode_dst(std::string asm_dst);
    static std::string encode_comp(std::string asm_comp);
    static std::string encode_jump(std::string asm_jump);
};

std::map<std::string, std::string> create_comp_map();
std::map<std::string, std::string> create_jump_map();
