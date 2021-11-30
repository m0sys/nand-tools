// Asm Coder translates VM code into Hack assembly code and writesout to file.
// Date: 2021/11/30
// Author: m0sys

#pragma once
#include <fstream>
#include <string>

class AsmCoder {

public:
    AsmCoder(std::string asm_fname);
    void write_arith(std::string cmd);
    void write_push_pop(bool is_push, const std::string& seg, int i);

    void close(); // closes the output file/stream.

private:
    void write_push(const std::string& seg, int i);
    void write_pop(const std::string& seg, int i);

    static void write_push_logic(std::ostream& out);
    static void write_pop_logic(std::ostream& out);

private:
    std::ofstream outfile;
};
