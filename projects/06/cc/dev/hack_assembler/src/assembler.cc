#include "assembler.h"
#include "encoder.h"
#include "parser.h"
#include <bitset>
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
}

void Assembler::assemble()
{
    using std::cout;
    using std::string;

    std::ofstream outfile(m_fname);

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
            cout << "TO decode: " << dst << comp << jmp << "\n";

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
            string out = std::bitset<16>(std::stoi(p.symbol())).to_string();
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

void Assembler::first_pass() { }
void Assembler::second_pass() { }

std::string Assembler::dec_to_bin(std::string dec) { return "hello"; }
