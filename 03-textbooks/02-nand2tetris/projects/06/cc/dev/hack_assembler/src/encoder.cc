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

    // TODO: replace with hashmap.
    auto cm = create_comp_map();
    return cm.at(asm_comp);
}

std::string Encoder::encode_jump(std::string asm_jump)
{
    //
    return "todo";
}

std::map<std::string, std::string> create_comp_map()
{
    return std::map<std::string, std::string> {
        { "0", "0101010" },
        { "1", "0111111" },
        { "-1", "0111010" },
        { "D", "0001100" },
        { "A", "0110000" },
        { "!D", "0001101" },
        { "!A", "0110001" },
        { "-D", "0001111" },
        { "-A", "0110011" },
        { "D+1", "0011111" },
        { "A+1", "0110111" },
        { "D-1", "0001110" },
        { "A-1", "0110010" },
        { "D+A", "0000010" },
        { "D-A", "0010011" },
        { "A-D", "0000111" },
        { "D&A", "0000000" },
        { "D|A", "0010101" },

        { "M", "1110000" },
        { "!M", "1110001" },
        { "-M", "1110011" },
        { "M+1", "1110111" },
        { "M-1", "1110010" },
        { "D+M", "1000010" },
        { "D-M", "1010011" },
        { "M-D", "1000111" },
        { "D&M", "1000000" },
        { "D|M", "1010101" },
    };
}
