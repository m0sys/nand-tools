// Asm Coder translates VM code into Hack assembly code and writesout to file.
// Date: 2021/11/30
// Author: m0sys

#pragma once
#include <fstream>
#include <map>
#include <string>

#define __COMMENTS_ENB__ 1
#if __COMMENTS_ENB__
#define __FILENAME__ (strrchr(__FILE__, '/') ? strrchr(__FILE__, '/') + 1 : __FILE__)
#define WRITE_COMMENT(outfile, msg) outfile << "// " << __FILENAME__ << " (" << __LINE__ << "): " << msg << "\n"
#else
#define WRITE_COMMENT(outfile, msg)
#endif

class AsmCoder {

public:
    AsmCoder(std::string asm_fname, std::string prog_name, bool is_multi);
    void write_arith(std::string cmd);
    void write_push_pop(bool is_push, const std::string& seg, int i);
    void write_label(std::string label);
    void write_goto(std::string label);
    void write_if(std::string label);
    void write_func(std::string func_name, int n_vars);
    void write_call(std::string func_name, int n_args);
    void write_return();
    void set_file_name(std::string prog_name);

    void close(); // closes the output file/stream.

private:
    void write_push(const std::string& seg, int i);
    void write_pop(const std::string& seg, int i);
    std::string comp_unique_logical_label(std::string type, int c);

    // Specialized asm writers.
    static void write_push_logic(std::ostream& out);
    static void write_pop_logic(std::ostream& out);
    static void write_store_d15(std::ostream& out);
    static void write_store_d15addr_read_d14(std::ostream& out);
    static void write_load_imm_d(std::ostream& out, int i);
    static void write_set_d2m(std::ostream& out);
    static void write_set_d2a(std::ostream& out);

    static void write_at_sp(std::ostream& out);
    static void write_at_lcl(std::ostream& out);
    static void write_at_arg(std::ostream& out);
    static void write_at_this(std::ostream& out);
    static void write_at_that(std::ostream& out);

    void write_logical_logic(std::string label);
    static void write_logical_jmp_logic(std::ostream& out, std::string label);
    static void write_true_case(std::ostream& out, std::string label);
    static void write_false_case(std::ostream& out, std::string label);
    static void write_label_point(std::ostream& out, std::string label);

private:
    std::ofstream outfile;
    std::string prog_name;
    std::map<std::string, int> ret_map;

    static int count_eq;
    static int count_lt;
    static int count_gt;
};
