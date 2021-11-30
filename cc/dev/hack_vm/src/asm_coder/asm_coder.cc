#include "asm_coder.h"
#include <fstream>
#include <iostream>
#include <string>

AsmCoder::AsmCoder(std::string asm_fname)
    : outfile { std::ofstream(asm_fname) }
{
}

void AsmCoder::write_arith(std::string cmd)
{
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

    if (cmd == "add")
        outfile << "D=M+D\n";
    else if (cmd == "sub")
        outfile << "D=M-D\n";
    else if (cmd == "and")
        outfile << "D=M&D\n";
    else if (cmd == "or")
        outfile << "D=M|D\n";
    else
        throw std::logic_error("AsmCoder: unsupported arithmentic op");

    // Push res onto top of the stack.
    write_push_logic(outfile);
}

void AsmCoder::write_push_pop(bool is_push, const std::string& seg, int i)
{
    if (is_push)
        write_push(seg, i);
    else
        write_pop(seg, i);
}

void AsmCoder::close() { outfile.close(); }

// Writes seg[i] to the top of the stack.
void AsmCoder::write_push(const std::string& seg, int i)
{
    // Figure out where the data comes from.
    if (seg == "local")
        outfile << "@LCL\n";

    else if (seg == "argument")
        outfile << "@ARG\n";

    else if (seg == "this")
        outfile << "@THIS\n";

    else if (seg == "that")
        outfile << "@THAT\n";

    // Load D register with appropriate value.

    if (seg == "constant") {
        // Load constant i into D register.
        outfile << "@" << std::to_string(i) << "\n";
        outfile << "D=A\n";
    }

    else if (seg == "pointer") {
        if (i == 0)
            outfile << "@THIS\n";
        else
            outfile << "@THAT\n";

        outfile << "D=M\n";
    }

    else if (seg == "temp") {
        outfile << "@5\n";
        outfile << "D=A\n";
        outfile << "@" << std::to_string(i) << "\n";
        outfile << "A=D+A\n";
        outfile << "D=M\n";
    }

    else { // seg = {local|argument|this|that}
        // Load (base+i) into D register.
        outfile << "A=M+" << std::to_string(i) << "\n";
        outfile << "D=M\n";
    }

    // Push onto stack.
    write_push_logic(outfile);
}

// Writes top of the stack to seg[i].
void AsmCoder::write_pop(const std::string& seg, int i)
{
    std::cout << "Poping: seg=" << seg << ", i=" << i << "\n";

    // Pop top of the stack.
    write_pop_logic(outfile);

    // Figure out which register to write to.
    if (seg == "local")
        outfile << "@LCL\n";

    else if (seg == "argument")
        outfile << "@ARG\n";

    else if (seg == "this")
        outfile << "@THIS\n";

    else if (seg == "that")
        outfile << "@THAT\n";

    // Store D register in appropriate register.

    if (seg == "pointer") {
        if (i == 0)
            outfile << "@THIS\n";
        else
            outfile << "@THAT\n";

        outfile << "M=D\n";
    }

    else if (seg == "temp") {
        outfile << "@5\n";
        outfile << "D=A\n";
        outfile << "@" << std::to_string(i) << "\n";
        outfile << "A=D+A\n";
        outfile << "M=D\n";
    }

    else { // seg = {local|argument|this|that}
        // Load (base+i) into D register.
        outfile << "A=M+" << std::to_string(i) << "\n";
        outfile << "M=D\n";
    }
}

void AsmCoder::write_push_logic(std::ostream& out)
{
    out << "@SP\n";
    out << "A=M\n";
    out << "M=D\n";
    out << "@SP\n";
    out << "M=M+1\n";
}

void AsmCoder::write_pop_logic(std::ostream& out)
{
    out << "@SP\n";
    out << "M=M-1\n";
    out << "A=M\n";
    out << "D=M\n";
}
