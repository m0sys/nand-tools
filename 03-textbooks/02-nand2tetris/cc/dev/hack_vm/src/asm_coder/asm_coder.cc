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
    if (is_multi) {
        DEBUG_LOG("IS MULTI");
        WRITE_COMMENT(outfile, "[init_prog_name: " << prog_name << "]");
        WRITE_COMMENT(outfile, "[start_bootstrap_code]");
        // SP = 256
        WRITE_COMMENT(outfile, "[SP = 256]");
        write_load_imm_d(outfile, 256);
        write_at_sp_asm(outfile);
        WRITE_ASM(outfile, "M=D", "");
        // call Sys.init
        write_call("Sys.init", 0);
        WRITE_COMMENT(outfile, "[end_boostrap_code]\n\n");
    }
}

void AsmCoder::write_arith(std::string cmd)
{
    WRITE_ENDL(outfile);
    WRITE_COMMENT(outfile, cmd);

    if (is_jumpy(cmd)) {
        if (cmd == "eq") {
            WRITE_COMMENT(outfile, "[eq_start]");

            auto eq_label = comp_unique_logical_label(".EQ", count_eq);
            write_pred_asm(eq_label);
            count_eq++;

            WRITE_COMMENT(outfile, "[eq_end]");

        } else if (cmd == "lt") {
            WRITE_COMMENT(outfile, "[lt_start]");

            auto lt_label = comp_unique_logical_label(".LT", count_lt);
            write_pred_asm(lt_label);
            count_lt++;

            WRITE_COMMENT(outfile, "[lt_end]");

        } else {
            WRITE_COMMENT(outfile, "[gt_start]");

            auto gt_label = comp_unique_logical_label(".GT", count_gt);
            write_pred_asm(gt_label);
            count_gt++;

            WRITE_COMMENT(outfile, "[gt_end]");
        }

    } else {

        // Get first arg off the stack.
        WRITE_COMMENT(outfile, "Getting first arg off the stack (y)");
        write_pop_asm(outfile);

        // Deal with unary ops first.
        if (cmd == "neg")
            WRITE_ASM(outfile, "D=-D", "negative unary op");
        else if (cmd == "not")
            WRITE_ASM(outfile, "D=!D", "negation unary op");
        if (cmd == "neg" || cmd == "not") {
            // Push res onto top of the stack.
            write_push_asm(outfile);
            return;
        }

        // Save first arg into R13 register.
        WRITE_ASM(outfile, "@R13", "save first arg here (y)");
        WRITE_ASM(outfile, "M=D", "");

        // Get second arg off the stack.
        WRITE_COMMENT(outfile, "Getting second arg off the stack (x)");
        write_pop_asm(outfile);

        // Do operation.
        WRITE_ASM(outfile, "@R13", "");

        // NOTE: M = arg1 (y) , D = arg2 (x).
        if (cmd == "add")
            WRITE_ASM(outfile, "D=D+M", "add op");
        else if (cmd == "sub")
            WRITE_ASM(outfile, "D=D-M", "sub op");
        else if (cmd == "and")
            WRITE_ASM(outfile, "D=D&M", "and op");
        else if (cmd == "or")
            WRITE_ASM(outfile, "D=D|M", "or op");
        else {
            throw std::logic_error("AsmCoder: unsupported arithmentic op");
        }
    }

    // Push res onto top of the stack.
    WRITE_COMMENT(outfile, "Pushing arith res onto top of the stack");
    write_push_asm(outfile);

    WRITE_COMMENT(outfile, "[end_write_arith]\n");
}

bool AsmCoder::is_jumpy(std::string cmd)
{
    //
    return cmd == "eq" || cmd == "lt" || cmd == "gt";
}

std::string AsmCoder::comp_unique_logical_label(std::string type, int c)
{
    //
    return prog_name + type + std::to_string(c);
}
void AsmCoder::write_pred_asm(std::string label)
{
    write_arith("sub");
    write_pop_asm(outfile);
    write_pred_jmp_asm(outfile, label);
}
void AsmCoder::write_pred_jmp_asm(std::ostream& out, std::string label)
{
    WRITE_ASM(out, "@" << label, "");
    if (label.find("EQ") != std::string::npos)
        WRITE_ASM(out, "D;JEQ", "");
    else if (label.find("LT") != std::string::npos)
        WRITE_ASM(out, "D;JLT", "");
    else if (label.find("GT") != std::string::npos)
        WRITE_ASM(out, "D;JGT", "");
    write_false_case_asm(out, label);
    write_true_case_asm(out, label);
    write_label_point_asm(out, label + ".CONTINUE");
}

void AsmCoder::write_false_case_asm(std::ostream& out, std::string label)
{
    WRITE_ASM(out, "D=0", "");
    WRITE_ASM(out, "@" << label << ".CONTINUE", "");
    WRITE_ASM(out, "0;JMP", "");
}

void AsmCoder::write_true_case_asm(std::ostream& out, std::string label)
{
    write_label_point_asm(out, label);
    WRITE_ASM(out, "D=-1", "");
    WRITE_ASM(out, "@" << label << ".CONTINUE", "");
    WRITE_ASM(out, "0;JMP", "");
}

void AsmCoder::write_label_point_asm(std::ostream& out, std::string label)
{
    //
    WRITE_ASM(out, "(" << label << ")", "");
}

void AsmCoder::write_push_pop(bool is_push, const std::string& seg, int i)
{
    WRITE_ENDL(outfile);

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

    // Figure out type of push.
    if (seg == "constant") {
        // Load constant i into D register.
        write_load_imm_d(outfile, i);
    }

    else if (seg == "pointer") {
        if (i == 0)
            write_at_this_asm(outfile);
        else
            write_at_that_asm(outfile);

        WRITE_ASM(outfile, "D=M", "");
    }

    else if (seg == "temp") {
        WRITE_ASM(outfile, "@R5", "");
        WRITE_ASM(outfile, "D=A", "");
        WRITE_ASM(outfile, "@" << std::to_string(i), "");
        WRITE_ASM(outfile, "A=D+A", "");
        WRITE_ASM(outfile, "D=M", "");
    }

    else if (seg == "static") {
        WRITE_ASM(outfile, "@" << prog_name << "." << std::to_string(i), "");
        WRITE_ASM(outfile, "D=M", "");
    }

    else { // seg = {local|argument|this|that}

        if (seg == "local")
            write_at_lcl_asm(outfile);

        else if (seg == "argument")
            write_at_arg_asm(outfile);

        else if (seg == "this")
            write_at_this_asm(outfile);

        else if (seg == "that")
            write_at_that_asm(outfile);

        // Load (base+i) into D register.
        WRITE_ASM(outfile, "D=M", "");
        WRITE_ASM(outfile, "@" << std::to_string(i), "");
        WRITE_ASM(outfile, "A=D+A", "");
        WRITE_ASM(outfile, "D=M", "");
    }

    write_push_asm(outfile);
}

// Writes top of the stack to seg[i].
void AsmCoder::write_pop(const std::string& seg, int i)
{
    WRITE_COMMENT(outfile, "pop " << seg << " " << i);

    // Pop top of the stack.
    WRITE_COMMENT(outfile, "Popping top of the stack into reg D");
    write_pop_asm(outfile);

    // Store D register in appropriate register.
    WRITE_COMMENT(outfile, "Storing val in D in appropriate register");
    if (seg == "pointer") {
        if (i == 0)
            write_at_this_asm(outfile);
        else
            write_at_that_asm(outfile);
        WRITE_ASM(outfile, "M=D", "");
    }

    else if (seg == "temp") {
        WRITE_ASM(outfile, "@R14", "location where popped value is stored");
        WRITE_ASM(outfile, "M=D", "");

        WRITE_ASM(outfile, "@R5", "");
        WRITE_ASM(outfile, "D=A", "");
        WRITE_ASM(outfile, "@" << std::to_string(i), "");
        WRITE_ASM(outfile, "D=D+A", "address to store popped val");

        write_store_d15addr_read_d14(outfile); // REMOVED

        // Store D.
        write_store_d15(outfile); // REMOVED
    }

    else if (seg == "static") {
        WRITE_ASM(outfile, "@" << prog_name << "." << std::to_string(i), "");
        WRITE_ASM(outfile, "M=D", "");
    }

    else { // seg = {local|argument|this|that}
        // Store D into register (base+i).
        WRITE_ASM(outfile, "@R14", "location where popped value is stored");
        WRITE_ASM(outfile, "M=D", "");
        write_load_imm_d(outfile, i);

        // Figure out which register to write to.
        if (seg == "local")
            write_at_lcl_asm(outfile);

        else if (seg == "argument")
            write_at_arg_asm(outfile);

        else if (seg == "this")
            write_at_this_asm(outfile);

        else if (seg == "that")
            write_at_that_asm(outfile);

        WRITE_ASM(outfile, "D=M+D", "location where popped val will be stored");

        write_store_d15addr_read_d14(outfile);

        // Store D.
        write_store_d15(outfile);
    }
}

void AsmCoder::write_label(std::string label)
{
    WRITE_ENDL(outfile);
    WRITE_COMMENT(outfile, "label " << label);
    write_label_point_asm(outfile, label);
}

void AsmCoder::write_goto(std::string label)
{
    WRITE_ENDL(outfile);
    WRITE_COMMENT(outfile, "goto");
    WRITE_ASM(outfile, "@" << label, "");
    WRITE_ASM(outfile, "0;JMP", "");
}

void AsmCoder::write_if(std::string label)
{
    WRITE_ENDL(outfile);
    WRITE_COMMENT(outfile, "if-goto " << label);
    // If stack top value is not zero goto label.
    write_pop_asm(outfile);
    WRITE_ASM(outfile, "@" << label, "");
    WRITE_ASM(outfile, "D;JNE", "");
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
    WRITE_ENDL(outfile);
    WRITE_COMMENT(outfile, prog_name << ".vm: function " << func_name << " " << n_vars);

    // Initialize local variables.
    write_label_point_asm(outfile, func_name);
    for (int i = 0; i < n_vars; i++) { // repeat nVars times
        // push 0
        WRITE_COMMENT(outfile, "Intializing local " << i << " to 0");
        WRITE_ASM(outfile, "D=0", "");
        write_push_asm(outfile);
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
    WRITE_ENDL(outfile);
    WRITE_COMMENT(outfile, "call " << func_name << " " << n_args);

    // Generate return label (returnAddress).
    std::string point_of_ret = func_name + "$ret";
    int i = 0;
    if (ret_map.contains(point_of_ret))
        i = ret_map[point_of_ret];

    // Save caller's frame (state) in stack before proceeding.

    // Push ret_addr onto stack.
    WRITE_COMMENT(outfile, "push returnAddress");
    WRITE_ASM(outfile, "@" << point_of_ret << std::to_string(i), "");
    write_set_d2a(outfile);
    write_push_asm(outfile);

    // Push lcl|arg|this|that onto stack.
    WRITE_COMMENT(outfile, "push LCL");
    write_at_lcl_asm(outfile);
    write_set_d2m(outfile);
    write_push_asm(outfile);

    WRITE_COMMENT(outfile, "push ARG");
    write_at_arg_asm(outfile);
    write_set_d2m(outfile);
    write_push_asm(outfile);

    WRITE_COMMENT(outfile, "push THIS");
    write_at_this_asm(outfile);
    write_set_d2m(outfile);
    write_push_asm(outfile);

    WRITE_COMMENT(outfile, "push THAT");
    write_at_that_asm(outfile);
    write_set_d2m(outfile);
    write_push_asm(outfile);

    // Reposiiton ARG and LCL
    WRITE_COMMENT(outfile, "ARG = SP - 5 - nArgs");
    write_at_sp_asm(outfile);
    write_set_d2m(outfile);
    write_at_arg_asm(outfile);
    // ARG = SP
    WRITE_ASM(outfile, "M=D", "");
    write_load_imm_d(outfile, 5);
    write_at_arg_asm(outfile);
    // ARG = SP - 5
    WRITE_ASM(outfile, "M=M-D", "");
    write_load_imm_d(outfile, n_args);
    write_at_arg_asm(outfile);
    // ARG = SP - 5 - nArgs
    WRITE_ASM(outfile, "M=M-D", "now ARG = SP - 5 - nArgs");

    WRITE_COMMENT(outfile, "LCL = SP");
    write_at_sp_asm(outfile);
    write_set_d2m(outfile);
    write_at_lcl_asm(outfile);
    // LCL = SP
    WRITE_ASM(outfile, "M=D", "now LCL = SP");

    // Goto func_name
    WRITE_COMMENT(outfile, "goto f");
    WRITE_ASM(outfile, "@" << func_name, "");
    WRITE_ASM(outfile, "0;JMP", "");

    // Jump to location where calle code is.
    WRITE_COMMENT(outfile, "(returnAddress)");
    write_label_point_asm(outfile, point_of_ret + std::to_string(i));
    ret_map[point_of_ret] = i + 1;

    WRITE_COMMENT(outfile, "[end_call]: " << func_name);
}

void AsmCoder::write_set_d2a(std::ostream& out) { WRITE_ASM(out, "D=A", ""); }
void AsmCoder::write_set_d2m(std::ostream& out) { WRITE_ASM(out, "D=M", ""); }

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

    WRITE_ENDL(outfile);
    WRITE_COMMENT(outfile, "[start_return]");

    // Put return value in temp reg (frame).
    // frame = LCL
    WRITE_COMMENT(outfile, "frame = LCL");
    write_at_lcl_asm(outfile);
    write_set_d2m(outfile);
    WRITE_ASM(outfile, "@R13", "FRAME");
    WRITE_ASM(outfile, "M=D", "");

    // retAddr = *(frame-5)
    WRITE_COMMENT(outfile, "retAddr = *(frame-5)");
    write_load_imm_d(outfile, 5);
    WRITE_ASM(outfile, "@R13", "");
    WRITE_ASM(outfile, "D=M-D", "");
    WRITE_ASM(outfile, "A=D", "");
    write_set_d2m(outfile);
    WRITE_ASM(outfile, "@R14", "RET_ADDR");
    WRITE_ASM(outfile, "M=D", "");

    // Reposition return val & sp for caller.
    // *ARG = pop()
    WRITE_COMMENT(outfile, "*ARG = pop()");
    write_at_arg_asm(outfile);
    write_set_d2m(outfile);
    WRITE_ASM(outfile, "@R15", "storing ARG in R15");
    WRITE_ASM(outfile, "M=D", "");
    write_pop_asm(outfile);
    WRITE_ASM(outfile, "@R15", "RET_VAL");
    WRITE_ASM(outfile, "A=M", "A=*ARG");
    WRITE_ASM(outfile, "M=D", "");

    // SP = ARG+1
    WRITE_COMMENT(outfile, "SP = ARG+1");
    write_at_arg_asm(outfile);
    write_set_d2m(outfile);
    WRITE_ASM(outfile, "D=D+1", "");
    write_at_sp_asm(outfile);
    WRITE_ASM(outfile, "M=D", "");

    // Restore caller's fram (state) from stack before returning to return_addr.

    // THAT = *(frame-1)
    WRITE_COMMENT(outfile, "THAT = *(frame-1)");
    WRITE_ASM(outfile, "@R13", "must still contain FRAME");
    WRITE_ASM(outfile, "D=M-1", "");
    WRITE_ASM(outfile, "A=D", "");
    write_set_d2m(outfile);
    write_at_that_asm(outfile);
    WRITE_ASM(outfile, "M=D", "");

    // THIS = *(frame-2)
    WRITE_COMMENT(outfile, "THIS = *(frame-2)");
    write_load_imm_d(outfile, 2); // l:176
    WRITE_ASM(outfile, "@R13", "must still contain FRAME");
    WRITE_ASM(outfile, "D=M-D", "");
    WRITE_ASM(outfile, "A=D", "");
    write_set_d2m(outfile);
    write_at_this_asm(outfile);
    WRITE_ASM(outfile, "M=D", "");

    // ARG = *(frame-3)
    WRITE_COMMENT(outfile, "ARG = *(frame-3)");
    write_load_imm_d(outfile, 3); // l:184
    WRITE_ASM(outfile, "@R13", "must still contain FRAME");
    WRITE_ASM(outfile, "D=M-D", "");
    WRITE_ASM(outfile, "A=D", "");
    write_set_d2m(outfile);
    write_at_arg_asm(outfile);
    WRITE_ASM(outfile, "M=D", "");

    // LCL = *(frame-4)
    WRITE_COMMENT(outfile, "LCL = *(frame-4)");
    write_load_imm_d(outfile, 4); // l:192
    WRITE_ASM(outfile, "@R13", "must still contain FRAME");
    WRITE_ASM(outfile, "D=M-D", "");
    WRITE_ASM(outfile, "A=D", "");
    write_set_d2m(outfile);
    write_at_lcl_asm(outfile);
    WRITE_ASM(outfile, "M=D", "");

    // Goto return_addr.
    WRITE_COMMENT(outfile, "goto retAddr");
    WRITE_ASM(outfile, "@R14", "must still contain RET_ADDR");
    write_set_d2m(outfile);
    WRITE_ASM(outfile, "A=D", "");
    WRITE_ASM(outfile, "0;JMP", "");

    WRITE_COMMENT(outfile, "[end_return]");
}

void AsmCoder::close()
{
    // Add END loop.
    WRITE_ASM(outfile, "(END)", "...closing file...");
    WRITE_ASM(outfile, "@END", "");
    WRITE_ASM(outfile, "0;JMP", "");

    outfile.close();
}

void AsmCoder::set_file_name(std::string pname)
{
    WRITE_COMMENT(outfile, "");
    WRITE_COMMENT(outfile, "");
    WRITE_COMMENT(outfile, "[new_prog_name: " << pname << "]\n\n");
    prog_name = pname;
}

void AsmCoder::write_at_sp_asm(std::ostream& out) { WRITE_ASM(out, "@SP", ""); }
void AsmCoder::write_at_lcl_asm(std::ostream& out) { WRITE_ASM(out, "@LCL", ""); }

void AsmCoder::write_at_arg_asm(std::ostream& out) { WRITE_ASM(out, "@ARG", ""); }
void AsmCoder::write_at_this_asm(std::ostream& out) { WRITE_ASM(out, "@THIS", ""); }
void AsmCoder::write_at_that_asm(std::ostream& out) { WRITE_ASM(out, "@THAT", ""); }

void AsmCoder::write_load_imm_d(std::ostream& out, int i)
{
    WRITE_ASM(out, "@" << std::to_string(i), "");
    WRITE_ASM(out, "D=A", "");
}

void AsmCoder::write_store_d15addr_read_d14(std::ostream& out)
{
    WRITE_ASM(out, "@R15", "storing D in R15");
    WRITE_ASM(out, "M=D", "");
    WRITE_ASM(out, "@R14", "loading R14 into D");
    WRITE_ASM(out, "D=M", "");
}

void AsmCoder::write_store_d15(std::ostream& out)
{
    WRITE_ASM(out, "@R15", "storing D in RAM[R15]");
    WRITE_ASM(out, "A=M", "");
    WRITE_ASM(out, "M=D", "");
}

void AsmCoder::write_push_asm(std::ostream& out)
{
    WRITE_COMMENT(out, "[start_push_logic]");
    write_at_sp_asm(out);
    WRITE_ASM(out, "A=M", "");
    WRITE_ASM(out, "M=D", "");
    write_at_sp_asm(out);
    WRITE_ASM(out, "M=M+1", "");
    WRITE_COMMENT(out, "[end_push_logic]");
}

void AsmCoder::write_pop_asm(std::ostream& out)
{
    WRITE_COMMENT(out, "[start_pop_logic]");
    write_at_sp_asm(out);
    WRITE_ASM(out, "M=M-1", "");
    WRITE_ASM(out, "A=M", "");
    WRITE_ASM(out, "D=M", "");
    WRITE_COMMENT(out, "[end_pop_logic]");
}
