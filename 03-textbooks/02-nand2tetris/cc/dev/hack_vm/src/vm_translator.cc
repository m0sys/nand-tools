#include "vm_translator.h"
#include "asm_coder/asm_coder.h"
#include "parser/parser.h"
#include <filesystem>
#include <stdexcept>
#include <string>

// DEBUG
#include "common/log.h"

VMTranslator::VMTranslator(std::string fname)
    : fname { fname }
{
    // Check that fname exists before processing.
    if (!std::filesystem::exists(fname))
        throw std::logic_error("fname does not exist");

    create_prog_name();
}

void VMTranslator::translate()
{

    Parser p(fname);
    AsmCoder ac(asm_fname);
    using CT = CommandType;

    while (p.has_more_lines()) {
        auto ct = p.command_type();
        if (ct == CT::C_POP) {
            DEBUG_LOG("VM -> Command Type: C_POP");
            ac.write_push_pop(false, p.arg1(), p.arg2());
        }

        else if (ct == CT::C_PUSH) {
            DEBUG_LOG("VM -> Command Type: C_PUSH");
            ac.write_push_pop(true, p.arg1(), p.arg2());
        }

        else if (ct == CT::C_ARITH) {
            DEBUG_LOG("VM -> Command Type: C_ARITH");
            ac.write_arith(p.arg1());
        }

        p.advance();
    }

    // TODO: add end of prog asm.

    ac.close();
}

void VMTranslator::create_prog_name()
{
    using std::string;
    using std::to_string;

    // Parsing file name to find asm part of fname.
    auto ex_pos = fname.find(".vm");
    if (ex_pos == string::npos)
        throw std::logic_error("File must be a .vm file");

    // Check for last occurance of backslash.
    auto last_slash_pos = fname.rfind("/");
    string prog_name;
    string rpath = "";
    auto npos = fname.size() - 3;

    // Extract program name.
    if (last_slash_pos != string::npos) {
        npos -= last_slash_pos;
        prog_name = fname.substr(last_slash_pos + 1, npos - 1);
        rpath = fname.substr(0, last_slash_pos + 1);
    } else {
        prog_name = fname.substr(0, npos);
    }

    // Create prog_name.asm file where asm code will later be written in.
    asm_fname = rpath + prog_name + ".asm";
}
