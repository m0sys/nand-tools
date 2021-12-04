#include "asm_coder.h"
#include "../common/log.h"
#include <fstream>
#include <iostream>
#include <string>

int AsmCoder::count_eq = 0;
int AsmCoder::count_lt = 0;
int AsmCoder::count_gt = 0;

AsmCoder::AsmCoder(std::string asm_fname, std::string prog_name, bool is_multi)
    : outfile { std::ofstream(asm_fname) }
    , prog_name { prog_name }
{
    // TODO: implement bootstraping code.
    // TODO: enable boostraping only when multifile.
    if (is_multi) {
        LOG("IS MULTI");
        WRITE_COMMENT(outfile, "[start_boostrap_code]");
        // SP = 256
        write_load_imm_d(outfile, 256);
        write_at_sp(outfile);
        outfile << "M=D\n";
        // call Sys.init
        write_call("Sys.init", 0);
        WRITE_COMMENT(outfile, "[end_boostrap_code]\n\n");

        WRITE_COMMENT(outfile, "[init_prog_name: " << prog_name << "]");
    }
}

void AsmCoder::write_arith(std::string cmd)
{
    WRITE_COMMENT(outfile, cmd);

    bool is_jumpy = false;
    if (cmd == "eq" || cmd == "lt" || cmd == "gt")
        is_jumpy = true;

    if (is_jumpy) {
        if (cmd == "eq") {
            WRITE_COMMENT(outfile, "eq_start");

            auto eq_label = comp_unique_logical_label(".EQ", count_eq);
            write_logical_logic(eq_label);
            count_eq++;

            WRITE_COMMENT(outfile, "eq_end");
        } else if (cmd == "lt") {
            WRITE_COMMENT(outfile, "lt_start");

            auto lt_label = comp_unique_logical_label(".LT", count_lt);
            write_logical_logic(lt_label);
            count_lt++;

            WRITE_COMMENT(outfile, "lt_end");

        } else {
            WRITE_COMMENT(outfile, "gt_start");

            auto gt_label = comp_unique_logical_label(".GT", count_gt);
            write_logical_logic(gt_label);
            count_gt++;

            WRITE_COMMENT(outfile, "gt_end");
        }

    } else {

        // Get first arg off the stack.
        write_pop_logic(outfile);

        // Deal with unary ops first.
        if (cmd == "neg")
            outfile << "D=-D\n";
        else if (cmd == "not")
            outfile << "D=!D\n";

        if (cmd == "neg" || cmd == "not") {
            // Push res onto top of the stack.
            write_push_logic(outfile);
            return;
        }

        // Save first arg into R13 register.
        outfile << "@R13\n";
        outfile << "M=D\n";

        // Get second arg off the stack.
        write_pop_logic(outfile);

        // Do operation.
        outfile << "@R13\n";

        // NOTE: M = arg1 (y) , D = arg2 (x).
        if (cmd == "add")
            outfile << "D=D+M\n";
        else if (cmd == "sub")
            outfile << "D=D-M\n";
        else if (cmd == "and")
            outfile << "D=D&M\n";
        else if (cmd == "or")
            outfile << "D=D|M\n";
        else {
            LOG(cmd);
            LOG(cmd.size());
            throw std::logic_error("AsmCoder: unsupported arithmentic op");
        }
    }

    // Push res onto top of the stack.
    write_push_logic(outfile);

    WRITE_COMMENT(outfile, "[end_write_arith]\n");
}

std::string AsmCoder::comp_unique_logical_label(std::string type, int c)
{
    //
    return prog_name + type + std::to_string(c);
}
void AsmCoder::write_logical_logic(std::string label)
{
    write_arith("sub");
    write_pop_logic(outfile);
    write_logical_jmp_logic(outfile, label);
}
void AsmCoder::write_logical_jmp_logic(std::ostream& out, std::string label)
{
    out << "@" << label << "\n";
    if (label.find("EQ") != std::string::npos)
        out << "D;JEQ\n";
    else if (label.find("LT") != std::string::npos)
        out << "D;JLT\n";
    else if (label.find("GT") != std::string::npos)
        out << "D;JGT\n";
    write_false_case(out, label);
    write_true_case(out, label);
    write_label_point(out, label + ".CONTINUE");
}

void AsmCoder::write_true_case(std::ostream& out, std::string label)
{
    write_label_point(out, label);
    out << "D=-1\n";
    out << "@" << label << ".CONTINUE\n";
    out << "0;JMP\n";
}

void AsmCoder::write_false_case(std::ostream& out, std::string label)
{
    out << "D=0\n";
    out << "@" << label << ".CONTINUE\n";
    out << "0;JMP\n";
}

void AsmCoder::write_label_point(std::ostream& out, std::string label)
{
    //
    out << "(" << label << ")\n";
}

void AsmCoder::write_push_pop(bool is_push, const std::string& seg, int i)
{
    if (is_push)
        write_push(seg, i);
    else
        write_pop(seg, i);

    WRITE_COMMENT(outfile, "[end_write_push_pop]\n");
}

// Writes seg[i] to the top of the stack.
void AsmCoder::write_push(const std::string& seg, int i)
{
    WRITE_COMMENT(outfile, "push " << seg << " " << i);

    // Figure out where the data comes from.
    if (seg == "local")
        write_at_lcl(outfile);

    else if (seg == "argument")
        write_at_arg(outfile);

    else if (seg == "this")
        write_at_this(outfile);

    else if (seg == "that")
        write_at_that(outfile);

    if (seg == "constant") {
        // Load constant i into D register.
        write_load_imm_d(outfile, i);
    }

    else if (seg == "pointer") {
        if (i == 0)
            write_at_this(outfile);
        else
            write_at_that(outfile);

        outfile << "D=M\n";
    }

    else if (seg == "temp") {
        outfile << "@5\n";
        outfile << "D=A\n";
        outfile << "@" << std::to_string(i) << "\n";
        outfile << "A=D+A\n";
        outfile << "D=M\n";
    }

    else if (seg == "static") {
        outfile << "@" << prog_name << "." << std::to_string(i) << "\n";
        outfile << "D=M\n";
    }

    else { // seg = {local|argument|this|that}
        // Load (base+i) into D register.
        outfile << "D=M\n";
        outfile << "@" << std::to_string(i) << "\n";
        outfile << "A=D+A\n";
        outfile << "D=M\n";
    }

    write_push_logic(outfile);
}

// Writes top of the stack to seg[i].
void AsmCoder::write_pop(const std::string& seg, int i)
{
    DEBUG_LOG("Poping: seg=" << seg << ", i=" << i);

    WRITE_COMMENT(outfile, "pop " << seg << " " << i);

    // Pop top of the stack.
    write_pop_logic(outfile);

    // Store D register in appropriate register.

    if (seg == "pointer") {
        if (i == 0)
            write_at_this(outfile);
        else
            write_at_that(outfile);

        outfile << "M=D\n";
    }

    else if (seg == "temp") {
        outfile << "@R14\n"; // location where popped value is
        outfile << "M=D\n";

        outfile << "@5\n";
        outfile << "D=A\n";
        outfile << "@" << std::to_string(i) << "\n";
        outfile << "D=D+A\n"; // address to store popped value

        write_store_d15addr_read_d14(outfile);

        // Store D.
        write_store_d15(outfile);
    }

    else if (seg == "static") {
        outfile << "@" << prog_name << "." << std::to_string(i) << "\n";
        outfile << "M=D\n";
    }

    else { // seg = {local|argument|this|that}
        // Store D into register (base+i).
        outfile << "@R14\n"; // location where popped value is
        outfile << "M=D\n";
        write_load_imm_d(outfile, i);

        // Figure out which register to write to.
        if (seg == "local")
            write_at_lcl(outfile);

        else if (seg == "argument")
            write_at_arg(outfile);

        else if (seg == "this")
            write_at_this(outfile);

        else if (seg == "that")
            write_at_that(outfile);

        outfile << "D=M+D\n"; // location where to store popped value

        write_store_d15addr_read_d14(outfile);

        // Store D.
        write_store_d15(outfile);
    }
}

void AsmCoder::write_label(std::string label)
{
    //
    write_label_point(outfile, label);
}

void AsmCoder::write_goto(std::string label)
{
    outfile << "@" << label << "\n";
    outfile << "0;JMP\n";
}

void AsmCoder::write_if(std::string label)
{
    // If stack top value is not zero goto label.
    write_pop_logic(outfile);
    outfile << "@" << label << "\n";
    outfile << "D;JNE\n";
}

/*
 * Generates code to init local vars of callee to 0.
 *
 * Args:
 *  - func_name: unique directory level function name.
 *  - n_vars: number of local variables to initialized to 0.
 */
void AsmCoder::write_func(std::string func_name, int n_vars)
{
    WRITE_COMMENT(outfile, prog_name << ".vm: [start_func]: " << func_name);
    // std::string ufunc_name = prog_name + "." + func_name;

    // Initialize local variables.
    write_label_point(outfile, func_name);
    for (int i = 0; i < n_vars; i++) {
        write_push("constant", 0);
        write_pop("local", i);
    }

    WRITE_COMMENT(outfile, prog_name << ".vm: [end_func]: " << func_name);
}

/*
 * Generates code to saves caller's frame on the stack and jumps to exec callee.
 *
 * Args:
 *  - func_name: unique directory level function name.
 *  - n_args: number of arguments pushed to seg_arg prior to this call.
 */
void AsmCoder::write_call(std::string func_name, int n_args)
{
    WRITE_COMMENT(outfile, "[start_call]: " << func_name);
    std::string point_of_ret = func_name + "$ret";
    int i = 0;
    if (ret_map.contains(point_of_ret))
        i = ret_map[point_of_ret];

    // Save caller's frame (state) in stack before proceeding.

    // Push ret_addr onto stack.
    outfile << "@" << point_of_ret << std::to_string(i) << "\n";
    write_set_d2a(outfile);
    write_push_logic(outfile);

    // Push lcl|arg|this|that onto stack.
    write_at_lcl(outfile);
    write_set_d2m(outfile);
    write_push_logic(outfile);

    write_at_arg(outfile);
    write_set_d2m(outfile);
    write_push_logic(outfile);

    write_at_this(outfile);
    write_set_d2m(outfile);
    write_push_logic(outfile);

    write_at_that(outfile);
    write_set_d2m(outfile);
    write_push_logic(outfile);

    // Set ARG = SP - 5 - nArgs
    write_at_sp(outfile);
    write_set_d2m(outfile);
    write_at_arg(outfile);
    // ARG = SP
    outfile << "M=D\n";
    write_load_imm_d(outfile, 5);
    write_at_arg(outfile);
    // ARG = SP - 5
    outfile << "M=M-D\n";
    write_load_imm_d(outfile, n_args);
    write_at_arg(outfile);
    // ARG = SP -5 - nArgs
    outfile << "M=M-D\n";

    // Set LCL = SP
    write_at_sp(outfile);
    write_set_d2m(outfile);
    write_at_lcl(outfile);
    // LCL = SP
    outfile << "M=D\n";

    // Goto func_name
    outfile << "@" << func_name << "\n";
    outfile << "0;JMP\n";

    // Jump to location where calle code is.
    write_label_point(outfile, point_of_ret + std::to_string(i));
    ret_map[point_of_ret] = i + 1;
    WRITE_COMMENT(outfile, "[end_call]: " << func_name);
}

void AsmCoder::write_set_d2a(std::ostream& out) { out << "D=A\n"; }
void AsmCoder::write_set_d2m(std::ostream& out) { out << "D=M\n"; }

/*
 * Generates code to copy ret value to top of caller's working stack,
 * reinstate the segment pointers of the caller (sp|lcl|arg|this|that),
 * and jump to exec command at return_addr onward.
 */
void AsmCoder::write_return()
{
    // NOTE: "*" is C/C++ dereferencing syntax.
    //       So `frame = LCL` means set frame to address LCL while
    //       `frame = *LCL` would mean set frame to whatever value LCL
    //       points to.
    //       Hence retAddr = *(frame - 5) means set retAddr to whatever
    //       value the address (frame - 5) points to - that is,
    //       retAddr = RAM[frame-5].

    WRITE_COMMENT(outfile, "[start_return]");

    // Put return value in temp reg (frame).
    write_at_lcl(outfile);
    write_set_d2m(outfile);
    // FIXME: why is FRAME = 279?
    outfile << "@R13\n"; // FRAME
    // frame = LCL
    outfile << "M=D\n";

    // retAddr = *(frame-5)
    write_load_imm_d(outfile, 5);
    outfile << "@R13\n";
    outfile << "D=M-D\n";
    // FIXME: RET_ADDR should be 273 not 274.
    outfile << "@R14\n"; // RET_ADDR
    outfile << "M=D\n";  // l:158

    // Reposition return val & sp for caller.
    // *ARG = pop()
    // DONE: With some magic RAM[310] = 1196 (return_value)
    write_at_arg(outfile);  // l:163 RAM[2] = 310
    write_set_d2m(outfile); // D = 310
    outfile << "@R15\n";
    outfile << "M=D\n";       // R15 = 310
    write_pop_logic(outfile); // D = return_value
    outfile << "@R15\n";
    outfile << "A=M\n";
    outfile << "M=D\n"; // l:164 // RAM[R15] = D = 1196

    // SP = ARG+1
    write_at_arg(outfile);
    write_set_d2m(outfile);
    outfile << "D=D+1\n"; // l:167
    write_at_sp(outfile);
    outfile << "M=D\n";
    // write_set_d2m(outfile);

    // Restore caller's fram (state) from stack before returning to return_addr.

    // THAT = *(frame-1)
    outfile << "@R13\n"; // l:170
    outfile << "D=M-1\n";
    outfile << "A=D\n";
    write_set_d2m(outfile);
    write_at_that(outfile);
    outfile << "M=D\n";
    // write_set_d2m(outfile);

    // THIS = *(frame-2)
    write_load_imm_d(outfile, 2); // l:176
    outfile << "@R13\n";
    outfile << "D=M-D\n";
    outfile << "A=D\n";
    write_set_d2m(outfile);
    write_at_this(outfile);
    outfile << "M=D\n";
    // write_set_d2m(outfile);

    // ARG = *(frame-3)
    write_load_imm_d(outfile, 3); // l:184
    outfile << "@R13\n";
    outfile << "D=M-D\n";
    outfile << "A=D\n";
    write_set_d2m(outfile);
    write_at_arg(outfile);
    outfile << "M=D\n";
    // write_set_d2m(outfile);

    // LCL = *(frame-4)
    write_load_imm_d(outfile, 4); // l:192
    outfile << "@R13\n";
    outfile << "D=M-D\n";
    outfile << "A=D\n";
    write_set_d2m(outfile);
    write_at_lcl(outfile);
    outfile << "M=D\n";
    // write_set_d2m(outfile);

    // Goto return_addr.
    outfile << "@R14\n";
    write_set_d2m(outfile);
    // FIXME: I want to goto RAM[RAM[R14]] (D should be 273; therefore A = 273)
    outfile << "A=D\n";
    outfile << "D=M\n";
    outfile << "A=D\n";
    outfile << "0;JMP\n";

    WRITE_COMMENT(outfile, "[end_return]");
}

void AsmCoder::close()
{
    // Add END loop.
    outfile << "(END)\n";
    outfile << "@END\n";
    outfile << "0;JMP\n";

    outfile.close();
}

void AsmCoder::set_file_name(std::string prog_name)
{
    WRITE_COMMENT(outfile, "");
    WRITE_COMMENT(outfile, "");
    WRITE_COMMENT(outfile, "[new_prog_name: " << prog_name << "]\n\n");
    prog_name = prog_name;
}

void AsmCoder::write_at_sp(std::ostream& out) { out << "@SP\n"; }
void AsmCoder::write_at_lcl(std::ostream& out) { out << "@LCL\n"; }

void AsmCoder::write_at_arg(std::ostream& out) { out << "@ARG\n"; }
void AsmCoder::write_at_this(std::ostream& out) { out << "@THIS\n"; }
void AsmCoder::write_at_that(std::ostream& out) { out << "@THAT\n"; }

void AsmCoder::write_load_imm_d(std::ostream& out, int i)
{
    out << "@" << std::to_string(i) << "\n";
    out << "D=A\n";
}

void AsmCoder::write_store_d15addr_read_d14(std::ostream& out)
{
    out << "@R15\n";
    out << "M=D\n";
    out << "@R14\n";
    out << "D=M\n";
}

void AsmCoder::write_store_d15(std::ostream& out)
{
    out << "@R15\n";
    out << "A=M\n";
    out << "M=D\n";
}

void AsmCoder::write_push_logic(std::ostream& out)
{
    WRITE_COMMENT(out, "[start_push_logic]");
    write_at_sp(out);
    out << "A=M\n";
    out << "M=D\n";
    write_at_sp(out);
    out << "M=M+1\n";
    WRITE_COMMENT(out, "[end_push_logic]");
}

void AsmCoder::write_pop_logic(std::ostream& out)
{
    WRITE_COMMENT(out, "[start_pop_logic]");
    write_at_sp(out);
    out << "M=M-1\n";
    out << "A=M\n";
    out << "D=M\n";
    WRITE_COMMENT(out, "[end_pop_logic]");
}
