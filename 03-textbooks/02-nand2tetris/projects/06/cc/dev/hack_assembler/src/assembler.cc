#include "assembler.h"
#include "encoder.h"
#include "parser.h"
#include <algorithm>
#include <bitset>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

// I will build hardware for my code to live in. To exist. To Be. - m0sys (2021/11/27)

Assembler::Assembler(std::string fname)
    : fname(fname)
{

    using std::cout;
    using std::string;
    using std::to_string;

    // TODO: might want to first check that fname exists before processing.

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
        cout << "Found Backslash!\n";
        npos -= last_slash_pos;
        prog_name = fname.substr(last_slash_pos + 1, npos - 1);
        rpath = fname.substr(0, last_slash_pos + 1);
    } else {
        cout << "Found No Backslash!\n";
        prog_name = fname.substr(0, npos);
    }

    cout << "Prog Name: " << prog_name << "\n";
    cout << "Relative Path: " << rpath << "\n";

    // Create prog_name.hack file where machine code will later be written in.
    m_fname = rpath + prog_name + ".hack";
    cout << "\nMachine fname: " << m_fname << "\n";
    cout << "Original fname: " << fname << "\n";

    // Create init symbols.

    // Add R values.
    for (int i = 0; i < 16; i++) {
        auto symb = "R" + std::to_string(i);
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
    using std::cout;
    using std::string;
    std::ofstream outfile(m_fname);

    first_pass();

    // Translation step.
    int counter = 0;
    Parser p(fname);
    using e = Encoder;
    while (p.has_more_lines()) {
        if (p.instr_type() == InstrType::C_TYPE) {
            // C_TYPE instruction.
            cout << "C_TYPE Found\n";
            auto dst = p.dst();
            auto comp = p.comp();
            auto jmp = p.jump();
            cout << "TO decode: dst = " << dst << "; comp = " << comp << "; jmp = " << jmp << "\n";

            auto b_dst = e::encode_dst(p.dst());
            cout << "b_dst: " << b_dst << "\n";
            auto b_comp = e::encode_comp(p.comp());
            cout << "b_comp: " << b_comp << "\n";
            auto b_jump = e::encode_jump(p.jump());
            cout << "b_jump: " << b_jump << "\n";
            cout << "Decoded: " << b_dst << b_comp << b_jump << "\n";
            outfile << "111" << b_comp << b_dst << b_jump << "\n";
        } else if (p.instr_type() == InstrType::A_TYPE) {
            // A_TYPE instruction.
            cout << "A_TYPE Found\n";
            auto symb = p.symbol();
            cout << "Symb: " << symb << "\n";
            string out;
            if (is_num(symb))
                out = std::bitset<16>(std::stoi(symb)).to_string();
            else
                // TODO: check for existance.
                out = std::bitset<16>(std::stoi(st[symb])).to_string();

            outfile << out << "\n";
        } else {
            // L_TYPE instruction.
            cout << "L_TYPE Found\n";
        }
        // TODO: make some catches.
        cout << "Advancing\n";
        p.advance();
        cout << "Advanced\n";
        cout << "Counter: " << counter << "\n\n";
        counter++;
    }

    outfile.close();
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

// Generate numbers for variable symbols.
void Assembler::second_pass() { }

std::string Assembler::dec_to_bin(std::string dec) { return "hello"; }
