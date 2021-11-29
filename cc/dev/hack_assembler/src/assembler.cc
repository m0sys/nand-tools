#include "assembler.h"
#include "encoder.h"
#include "parser.h"
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

// I will build hardware for my code to live in. To exist. To Be. - m0sys (2021/11/27)

Assembler::Assembler(std::string fname)
    : fname(fname)
{
    // Check that fname exists before processing.
    if (!std::filesystem::exists(fname))
        throw std::logic_error("fname does not exist");

    create_prog_name();
    create_init_st();
}
void Assembler::create_prog_name()
{
    using std::string;
    using std::to_string;

    // Parsing file name to find asm part of fname.
    auto ex_pos = fname.find(".asm");
    if (ex_pos == string::npos)
        throw std::logic_error("File must be an .asm file");

    // Check for last occurance of backslash.
    auto last_slash_pos = fname.rfind("/");
    string prog_name;
    string rpath = "";
    auto npos = fname.size() - 4;

    // Extract program name.
    if (last_slash_pos != string::npos) {
        npos -= last_slash_pos;
        prog_name = fname.substr(last_slash_pos + 1, npos - 1);
        rpath = fname.substr(0, last_slash_pos + 1);
    } else {
        prog_name = fname.substr(0, npos);
    }

    // Create prog_name.hack file where machine code will later be written in.
    m_fname = rpath + prog_name + ".hack";
}

void Assembler::create_init_st()
{
    using std::to_string;

    // Create init symbols.
    // Add R values.
    for (int i = 0; i < 16; i++) {
        auto symb = "R" + to_string(i);
        st[symb] = to_string(i);
    }

    // Add Keywords.
    st["SP"] = to_string(0);
    st["LCL"] = to_string(1);
    st["ARG"] = to_string(2);
    st["THIS"] = to_string(3);
    st["THAT"] = to_string(4);
    st["SCREEN"] = to_string(16384);
    st["KBD"] = to_string(24576);
    st["LOOP"] = to_string(4);
    st["STOP"] = to_string(18);
}

bool Assembler::is_num(std::string str)
{
    //
    return std::all_of(str.begin(), str.end(), isdigit);
}

void Assembler::assemble()
{
    first_pass();
    second_pass();
}

// Generate numbers for label symbols.
void Assembler::first_pass()
{
    using std::to_string;
    Parser p(fname);
    for (int i = 0; p.has_more_lines(); i++) {
        if (p.instr_type() == InstrType::L_TYPE) {
            i--;
            st[p.symbol()] = to_string(i + 1);
        }
        p.advance();
    }
}

// Translates into machine code while also handling variables.
void Assembler::second_pass()
{

    using std::cout;
    using std::string;
    std::ofstream outfile(m_fname);

    // Translation step.
    Parser p(fname);
    using e = Encoder;

    while (p.has_more_lines()) {
        if (p.instr_type() == InstrType::C_TYPE) {
            // C_TYPE instruction.
            auto b_dst = e::encode_dst(p.dst());
            auto b_comp = e::encode_comp(p.comp());
            auto b_jump = e::encode_jump(p.jump());
            outfile << "111" << b_comp << b_dst << b_jump << "\n";

        } else if (p.instr_type() == InstrType::A_TYPE) {
            // A_TYPE instruction.
            auto symb = p.symbol();
            int addr;
            string out;

            if (is_num(symb))
                addr = std::stoi(symb);

            else {
                // Handles variables case.
                if (st.find(symb) == st.end()) {
                    st[symb] = std::to_string(curr_var_idx);
                    curr_var_idx++;
                }

                addr = std::stoi(st[symb]);
            }

            out = dec_to_bin(addr);
            outfile << out << "\n";
        }

        p.advance();
    }

    outfile.close();
}

std::string Assembler::dec_to_bin(int dec) { return std::bitset<16>(dec).to_string(); }
