#include "asm_coder.h"
#include "../common/log.h"
#include <fstream>
#include <iostream>
#include <string>

AsmCoder::AsmCoder(std::string asm_fname, std::string prog_name)
    : outfile { std::ofstream(asm_fname) }
    , prog_name { prog_name }
{
}

void AsmCoder::write_arith(std::string cmd)
{
    outfile << "// " << cmd << "\n";
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
    // TODO: add jumping logic.
    /*
    else if (cmd == "eq") {
        outfile << "D=M-D\n";
        outfile << "@TRUE\n";
        outfile << "D;JEQ\n";
        outfile << "@FALSE\n";
        outfile << "0;JMP\n";

        outfile << "(TRUE)\n";
        outfile << "D=-1\n";
        outfile << "(FALSE)\n";
        outfile << "D=0\n";
    }
    */

    else
        throw std::logic_error("AsmCoder: unsupported arithmentic op");

    // Push res onto top of the stack.
    write_push_logic(outfile);

    outfile << "// [end write_arith]\n\n";
}

void AsmCoder::write_push_pop(bool is_push, const std::string& seg, int i)
{
    if (is_push)
        write_push(seg, i);
    else
        write_pop(seg, i);
    outfile << "// [end write_push_pop]\n\n";
}

void AsmCoder::close()
{
    // Add END loop.
    outfile << "(END)\n";
    outfile << "@END\n";
    outfile << "0;JMP\n";

    outfile.close();
}

// Writes seg[i] to the top of the stack.
void AsmCoder::write_push(const std::string& seg, int i)
{
    outfile << "// push " << seg << " " << i << "\n";
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

    // Push onto stack.
    write_push_logic(outfile);
}

// Writes top of the stack to seg[i].
void AsmCoder::write_pop(const std::string& seg, int i)
{
    DEBUG_LOG("Poping: seg=" << seg << ", i=" << i);

    outfile << "// pop " << seg << " " << i << "\n";
    // Pop top of the stack.
    write_pop_logic(outfile);

    // Store D register in appropriate register.

    if (seg == "pointer") {
        if (i == 0)
            outfile << "@THIS\n";
        else
            outfile << "@THAT\n";

        outfile << "M=D\n";
    }

    else if (seg == "temp") {
        outfile << "@R14\n"; // location where popped value is
        outfile << "M=D\n";

        outfile << "@5\n";
        outfile << "D=A\n";
        outfile << "@" << std::to_string(i) << "\n";
        outfile << "D=D+A\n"; // address to store popped value

        outfile << "@R15\n"; // location where address to store is
        outfile << "M=D\n";
        outfile << "@R14\n";
        outfile << "D=M\n"; // popped value is now here

        // FIXME: cannot use @M as address. M will be determined when file is loaded.
        //        that is what is stored at RAM[R15] will not become the next address.
        outfile << "@R15\n";
        outfile << "A=M\n";
        outfile << "M=D\n";
    }

    else if (seg == "static") {
        outfile << "@" << prog_name << "." << std::to_string(i) << "\n";
        outfile << "M=D\n";
    }

    else { // seg = {local|argument|this|that}
        // Load (base+i) into D register.

        // outfile << "@" << std::to_string(i) << "\n";

        outfile << "@R14\n"; // location where popped value is
        outfile << "M=D\n";
        outfile << "@" << std::to_string(i) << "\n";
        outfile << "D=A\n";

        // Figure out which register to write to.
        if (seg == "local")
            outfile << "@LCL\n";

        else if (seg == "argument")
            outfile << "@ARG\n";

        else if (seg == "this")
            outfile << "@THIS\n";

        else if (seg == "that")
            outfile << "@THAT\n";

        outfile << "D=M+D\n"; // location where to store popped value
        outfile << "@R15\n";
        outfile << "M=D\n";

        outfile << "@R14\n";
        outfile << "D=M\n";

        // FIXME: cannot use @M as address. M will be determined when file is loaded.
        //        that is what is stored at RAM[R15] will not become the next address.
        outfile << "@R15\n";
        outfile << "A=M\n";
        outfile << "M=D\n";
    }
}

void AsmCoder::write_push_logic(std::ostream& out)
{
    out << "// [start]: push_logic\n";
    out << "@SP\n";
    out << "A=M\n";
    out << "M=D\n";
    out << "@SP\n";
    out << "M=M+1\n";
    out << "// [end]: push_logic\n";
}

void AsmCoder::write_pop_logic(std::ostream& out)
{
    out << "// [start]: pop_logic\n";
    out << "@SP\n";
    out << "M=M-1\n";
    out << "A=M\n";
    out << "D=M\n";
    out << "// [end]: pop_logic\n";
}
