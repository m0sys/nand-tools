#include "asm_coder.h"
#include <fstream>
#include <string>

AsmCoder::AsmCoder(std::string asm_fname)
    : outfile { std::ofstream(asm_fname) }
{
}

void AsmCoder::write_arith(std::string cmd) { }
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
    outfile << "@SP\n";
    outfile << "A=M\n";
    outfile << "M=D\n";
    outfile << "@SP\n";
    outfile << "M=M+1\n";
}

// Writes top of the stack to seg[i].
void AsmCoder::write_pop(const std::string& seg, int i)
{

    // Pop top of the stack.
    outfile << "@SP\n";
    outfile << "A=M\n";
    outfile << "M=M-1\n";
    outfile << "A=M\n";
    outfile << "D=M\n";

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
