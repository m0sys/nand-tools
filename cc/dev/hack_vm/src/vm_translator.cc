#include "vm_translator.h"
#include "asm_coder/asm_coder.h"
#include "parser/parser.h"
#include <filesystem>
#include <stdexcept>
#include <string>
#include <vector>

// DEBUG
#include "common/log.h"

VMTranslator::VMTranslator(std::string fname)
    : fname { fname }
{
    namespace fs = std::filesystem;
    // Check that fname exists before processing.
    if (!fs::exists(fname))
        throw std::logic_error("fname does not exist");

    if (fs::is_directory(fname)) {
        DEBUG_LOG("This is a directory!");
        for (const auto& entry : fs::directory_iterator(fname)) {
            DEBUG_LOG(entry.path());
            auto fn = entry.path().string();
            if (fn.find(".vm") != std::string::npos) {
                DEBUG_LOG(fn << " is .vm type!");
                paths.push_back(fn);
            }
        }
    } else
        paths.push_back(fname);

    // DEBUG_LOG("Found Paths: ");
    // for (const auto& f : paths)
    //     DEBUG_LOG(f);
    create_asm_name();
}

void VMTranslator::translate()
{

    // TODO: call setfile on asm_coder + distinguish between dir & file.
    create_prog_name(paths[0]);
    AsmCoder ac(asm_fname, prog_name, paths.size() > 1);
    DEBUG_LOG("asm_fname: " << asm_fname);
    bool first_file = true;
    for (const auto& fname : paths) {
        Parser p(fname);
        using CT = CommandType;

        if (!first_file) {
            create_prog_name(fname);
            ac.set_file_name(prog_name);
            LOG("new prog: " << prog_name);
            LOG("new prog fname: " << fname);
        }
        first_file = false;

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

            else if (ct == CT::C_LABEL) {
                auto label = p.arg1();

                ac.write_label(label);
            }

            else if (ct == CT::C_GOTO) {
                ac.write_goto(p.arg1());
            }

            else if (ct == CT::C_IF) {
                ac.write_if(p.arg1());
            }

            // TODO: add functions.
            // NOTE: must handle unique label generation for functions here.
            else if (ct == CT::C_FUNC) {
                ac.write_func(p.arg1(), p.arg2());
            }

            else if (ct == CT::C_RET) {
                ac.write_return();
            }

            else if (ct == CT::C_CALL) {
                LOG("CALL");
                ac.write_call(p.arg1(), p.arg2());
            }

            else if (ct == CT::UNKNOWN)
                throw std::logic_error("VMTranslator: Unknown command");

            else {
                throw std::logic_error("VMTranslator: Unsupported command");
            }

            p.advance();
        }
    }
    ac.close();
}

void VMTranslator::create_asm_name()
{
    using std::string;
    using std::to_string;

    // Parsing file name to find asm part of fname.
    auto ex_pos = fname.find(".vm");
    auto last_slash_pos = fname.rfind("/");
    if (ex_pos == string::npos && last_slash_pos == string::npos) {
        LOG("throwing: fname = " << fname);
        throw std::logic_error("File must be a .vm file or dir");
    }

    // Check for last occurance of backslash.
    string rpath = "";
    string prog_name = "";
    auto npos = fname.size();

    // Extract program name.
    if (last_slash_pos != string::npos && ex_pos != string::npos) {
        npos -= 3;
        npos -= last_slash_pos;
        prog_name = fname.substr(last_slash_pos + 1, npos - 1);
        rpath = fname.substr(0, last_slash_pos + 1);
        asm_fname = rpath + prog_name + ".asm";
    } else if (last_slash_pos == string::npos) {
        npos -= 3;
        prog_name = fname.substr(0, npos);
        asm_fname = rpath + prog_name + ".asm";
    } else {
        DEBUG_LOG("dir");
        DEBUG_LOG("fname: " << fname);
        DEBUG_LOG("fname.size(): " << fname.size());
        DEBUG_LOG("last_slash_pos: " << last_slash_pos);
        DEBUG_LOG("fname.substr(0, last_slash_pos): " << fname.substr(0, last_slash_pos));
        auto prev_last_slash_pos = fname.substr(0, last_slash_pos).rfind("/");
        DEBUG_LOG("prev_last_slash_pos: " << prev_last_slash_pos);
        npos = last_slash_pos - prev_last_slash_pos;
        DEBUG_LOG("fname.substr(prev_last_slash_pos + 1, npos - 1): " << fname.substr(prev_last_slash_pos + 1, npos - 1));
        prog_name = fname.substr(prev_last_slash_pos + 1, npos - 1);
        rpath = fname.substr(0, prev_last_slash_pos + 1);
        asm_fname = rpath + prog_name + "/" + prog_name + ".asm";
    }

    DEBUG_LOG("prog_name: " << prog_name);
    DEBUG_LOG("rpath: " << rpath);
    DEBUG_LOG("asm_fname: " << asm_fname);
}

void VMTranslator::create_prog_name(const std::string& fname)
{
    using std::string;
    using std::to_string;

    // Parsing file name to find asm part of fname.
    auto ex_pos = fname.find(".vm");
    if (ex_pos == string::npos)
        throw std::logic_error("File must be a .vm file");

    // Check for last occurance of backslash.
    auto last_slash_pos = fname.rfind("/");
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
    LOG("prog_name: " << prog_name);
}
