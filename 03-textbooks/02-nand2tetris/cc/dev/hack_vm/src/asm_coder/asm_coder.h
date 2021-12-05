// Asm Coder translates VM code into Hack assembly code and writesout to file.
// Date: 2021/11/30
// Author: m0sys

#pragma once
#include <fstream>
#include <map>
#include <string>

#define __COMMENTS_ENB__ 0
#define __EOL_COMM_ENB__ 0
#define __LINE_NUM_ENB__ 0

#define WRITE_ENDL(outfile) outfile << "\n"
#if __COMMENTS_ENB__
#define WRITE_COMMENT(outfile, msg) outfile << "//  (" << __LINE__ << "): " << msg << "\n"
#else
#define WRITE_COMMENT(outfile, msg)
#endif

#if __LINE_NUM_ENB__
#define WRITE_ASM(outfile, cmd, msg) outfile << cmd << " // (" << __LINE__ << ") " << msg << "\n"
#elif __EOL_COMM_ENB__
#define WRITE_ASM(outfile, cmd, msg) outfile << cmd << " // " << msg << "\n"
#else
#define WRITE_ASM(outfile, cmd, msg) outfile << cmd << "\n"
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
    void set_file_name(std::string pname);

    void close(); // closes the output file/stream.

private:
    void write_push(const std::string& seg, int i);
    void write_pop(const std::string& seg, int i);
    std::string comp_unique_logical_label(std::string type, int c);

    // Specialized asm writers.
    static void write_push_asm(std::ostream& out);
    static void write_pop_asm(std::ostream& out);

    // Convetions:
    //  - write_store_x_y_asm will store x in y reg.
    //  - write_load_x_y_asm will load 'x' in 'y' where 'y' is in (D, A).
    static void write_store_d15(std::ostream& out);
    static void write_store_d15addr_read_d14(std::ostream& out);
    static void write_load_imm_d(std::ostream& out, int i);
    static void write_set_d2m(std::ostream& out);
    static void write_set_d2a(std::ostream& out);

    static void write_at_sp_asm(std::ostream& out);
    static void write_at_lcl_asm(std::ostream& out);
    static void write_at_arg_asm(std::ostream& out);
    static void write_at_this_asm(std::ostream& out);
    static void write_at_that_asm(std::ostream& out);

    void write_pred_asm(std::string label);
    static void write_pred_jmp_asm(std::ostream& out, std::string label);
    static void write_false_case_asm(std::ostream& out, std::string label);
    static void write_true_case_asm(std::ostream& out, std::string label);
    static void write_label_point_asm(std::ostream& out, std::string label);

    static bool is_jumpy(std::string cmd);

private:
    std::ofstream outfile;
    std::string prog_name;
    std::map<std::string, int> ret_map;

    static int count_eq;
    static int count_lt;
    static int count_gt;
};
