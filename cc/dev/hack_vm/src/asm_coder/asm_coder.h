// Asm Coder translates VM code into Hack assembly code and writesout to file.
// Date: 2021/11/30
// Author: m0sys

#pragma once
#include <fstream>
#include <string>

#define __COMMENTS_ENB__ 0
#if __COMMENTS_ENB__
#define WRITE_COMMENT(outfile, msg) outfile << "// " << msg << "\n"
#else
#define WRITE_COMMENT(outfile, msg)
#endif

class AsmCoder {

public:
    AsmCoder(std::string asm_fname, std::string prog_name);
    void write_arith(std::string cmd);
    void write_push_pop(bool is_push, const std::string& seg, int i);

    void close(); // closes the output file/stream.

private:
    void write_push(const std::string& seg, int i);
    void write_pop(const std::string& seg, int i);

    // Asm specialized writers.
    static void write_push_logic(std::ostream& out);
    static void write_pop_logic(std::ostream& out);
    static void write_store_d15(std::ostream& out);
    static void write_store_d15addr_read_d14(std::ostream& out);
    static void write_load_imm_d(std::ostream& out, int i);

    static void write_at_sp(std::ostream& out);
    static void write_at_lcl(std::ostream& out);
    static void write_at_arg(std::ostream& out);
    static void write_at_this(std::ostream& out);
    static void write_at_that(std::ostream& out);

private:
    std::ofstream outfile;
    std::string prog_name;

    static int count_eq;
    static int count_lt;
    static int count_gt;
};
