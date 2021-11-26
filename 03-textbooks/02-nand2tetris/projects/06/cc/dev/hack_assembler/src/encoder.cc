#include "encoder.h"

std::string Encoder::encode_dst(std::string asm_dst)
{
    //
    std::string res = "000";
    if (asm_dst.find('M') != std::string::npos)
        res.at(2) = '1';

    if (asm_dst.find('D') != std::string::npos)
        res.at(1) = '1';

    if (asm_dst.find('A') != std::string::npos)
        res.at(0) = '1';

    return res;
}

std::string Encoder::encode_comp(std::string asm_comp)
{
    //
    return "todo";
}

std::string Encoder::encode_jump(std::string asm_jump)
{
    //
    return "todo";
}
