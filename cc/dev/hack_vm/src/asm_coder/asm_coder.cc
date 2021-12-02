#include "asm_coder.h"
#include "../common/log.h"
#include <fstream>
#include <iostream>
#include <string>

int AsmCoder::count_eq = 0;
int AsmCoder::count_lt = 0;
int AsmCoder::count_gt = 0;

AsmCoder::AsmCoder(std::string asm_fname, std::string prog_name)
    : outfile { std::ofstream(asm_fname) }
    , prog_name { prog_name }
{
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
        else
            throw std::logic_error("AsmCoder: unsupported arithmentic op");
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
    write_continue_label(out, label);
}

void AsmCoder::write_true_case(std::ostream& out, std::string label)
{
    out << "(" << label << ")\n";
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

void AsmCoder::write_continue_label(std::ostream& out, std::string label)
{
    //
    out << "(" << label << ".CONTINUE)\n";
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
    outfile << "(" << label << ")\n";
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

void AsmCoder::close()
{
    // Add END loop.
    outfile << "(END)\n";
    outfile << "@END\n";
    outfile << "0;JMP\n";

    outfile.close();
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
