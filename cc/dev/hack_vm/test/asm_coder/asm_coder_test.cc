// Test file for testing AsmCoder.

#include "../../src/asm_coder/asm_coder.h"
#include "../../src/parser/parser.h"
#include <fstream>
#include <gtest/gtest.h>
#include <string>

void assert_push_logic(std::ifstream& in);
void assert_pop_logic(std::ifstream& in);

/*
 * Testing BasicTest.vm
 */

class AsmCoderTestBasicTestVM : public ::testing::Test {
protected:
    void SetUp() override
    {
        vm_fname = "../../../projects/07/MemoryAccess/BasicTest/BasicTest.vm";
        asm_fname = "../../../projects/07/MemoryAccess/BasicTest/BasicTest.asm";
        parser = new Parser(vm_fname);
        asm_coder = new AsmCoder(asm_fname);
    }

    void TearDown() override { delete parser; }

    Parser* parser;
    AsmCoder* asm_coder;
    std::string vm_fname;
    std::string asm_fname;
};

TEST_F(AsmCoderTestBasicTestVM, Code1)
{
    using std::string;

    // push constant 10
    auto arg1 = parser->arg1();
    auto arg2 = parser->arg2();
    asm_coder->write_push_pop(true, arg1, arg2);
    asm_coder->close();

    std::ifstream infile(asm_fname);
    string line;

    // line 0
    std::getline(infile, line);
    ASSERT_EQ(line, "@10") << "line not matching";

    // line 1
    std::getline(infile, line);
    ASSERT_EQ(line, "D=A") << "line not matching";

    assert_push_logic(infile);
    infile.close();
}

TEST_F(AsmCoderTestBasicTestVM, Code2)
{
    using std::string;

    // pop local 0
    for (int i = 0; i < 1; i++)
        parser->advance();
    auto arg1 = parser->arg1();
    auto arg2 = parser->arg2();
    asm_coder->write_push_pop(false, arg1, arg2);
    asm_coder->close();

    std::ifstream infile(asm_fname);
    string line;

    assert_pop_logic(infile);

    // line 0
    std::getline(infile, line);
    ASSERT_EQ(line, "@LCL") << "line not matching";

    // line 1
    std::getline(infile, line);
    ASSERT_EQ(line, "A=M+0") << "line not matching";

    // line 2
    std::getline(infile, line);
    ASSERT_EQ(line, "M=D") << "line not matching";

    infile.close();
}

TEST_F(AsmCoderTestBasicTestVM, Code5)
{
    using std::string;

    // pop argument 2
    for (int i = 0; i < 4; i++)
        parser->advance();
    auto arg1 = parser->arg1();
    auto arg2 = parser->arg2();
    asm_coder->write_push_pop(false, arg1, arg2);
    asm_coder->close();

    std::ifstream infile(asm_fname);
    string line;

    assert_pop_logic(infile);

    // line 0
    std::getline(infile, line);
    ASSERT_EQ(line, "@ARG") << "line not matching";

    // line 1
    std::getline(infile, line);
    ASSERT_EQ(line, "A=M+2") << "line not matching";

    // line 2
    std::getline(infile, line);
    ASSERT_EQ(line, "M=D") << "line not matching";

    infile.close();
}

TEST_F(AsmCoderTestBasicTestVM, Code8)
{
    using std::string;

    // pop this 6
    for (int i = 0; i < 7; i++)
        parser->advance();
    auto arg1 = parser->arg1();
    auto arg2 = parser->arg2();
    asm_coder->write_push_pop(false, arg1, arg2);
    asm_coder->close();

    std::ifstream infile(asm_fname);
    string line;

    assert_pop_logic(infile);

    // line 0
    std::getline(infile, line);
    ASSERT_EQ(line, "@THIS") << "line not matching";

    // line 1
    std::getline(infile, line);
    ASSERT_EQ(line, "A=M+6") << "line not matching";

    // line 2
    std::getline(infile, line);
    ASSERT_EQ(line, "M=D") << "line not matching";

    infile.close();
}

TEST_F(AsmCoderTestBasicTestVM, Code11)
{
    using std::string;

    // pop that 5
    for (int i = 0; i < 10; i++)
        parser->advance();
    auto arg1 = parser->arg1();
    auto arg2 = parser->arg2();
    asm_coder->write_push_pop(false, arg1, arg2);
    asm_coder->close();

    std::ifstream infile(asm_fname);
    string line;

    assert_pop_logic(infile);

    // line 0
    std::getline(infile, line);
    ASSERT_EQ(line, "@THAT") << "line not matching";

    // line 1
    std::getline(infile, line);
    ASSERT_EQ(line, "A=M+5") << "line not matching";

    // line 2
    std::getline(infile, line);
    ASSERT_EQ(line, "M=D") << "line not matching";

    infile.close();
}

TEST_F(AsmCoderTestBasicTestVM, Code14)
{
    using std::string;

    // pop temp 6
    for (int i = 0; i < 13; i++)
        parser->advance();
    auto arg1 = parser->arg1();
    auto arg2 = parser->arg2();
    asm_coder->write_push_pop(false, arg1, arg2);
    asm_coder->close();

    std::ifstream infile(asm_fname);
    string line;

    assert_pop_logic(infile);

    // line 0
    std::getline(infile, line);
    ASSERT_EQ(line, "@5") << "line not matching";

    // line 1
    std::getline(infile, line);
    ASSERT_EQ(line, "D=A") << "line not matching";

    // line 2
    std::getline(infile, line);
    ASSERT_EQ(line, "@6") << "line not matching";

    // line 3
    std::getline(infile, line);
    ASSERT_EQ(line, "A=D+A") << "line not matching";

    // line 4
    std::getline(infile, line);
    ASSERT_EQ(line, "M=D") << "line not matching";

    infile.close();
}

TEST_F(AsmCoderTestBasicTestVM, Code15)
{
    using std::string;

    // push local 0
    for (int i = 0; i < 14; i++)
        parser->advance();
    auto arg1 = parser->arg1();
    auto arg2 = parser->arg2();
    asm_coder->write_push_pop(true, arg1, arg2);
    asm_coder->close();

    std::ifstream infile(asm_fname);
    string line;

    // line 0
    std::getline(infile, line);
    ASSERT_EQ(line, "@LCL") << "line not matching";

    // line 1
    std::getline(infile, line);
    ASSERT_EQ(line, "A=M+0") << "line not matching";

    // line 2
    std::getline(infile, line);
    ASSERT_EQ(line, "D=M") << "line not matching";

    assert_push_logic(infile);
    infile.close();
}

TEST_F(AsmCoderTestBasicTestVM, Code16)
{
    using std::string;

    // push this 5
    for (int i = 0; i < 15; i++)
        parser->advance();
    auto arg1 = parser->arg1();
    auto arg2 = parser->arg2();
    asm_coder->write_push_pop(true, arg1, arg2);
    asm_coder->close();

    std::ifstream infile(asm_fname);
    string line;

    // line 0
    std::getline(infile, line);
    ASSERT_EQ(line, "@THAT") << "line not matching";

    // line 1
    std::getline(infile, line);
    ASSERT_EQ(line, "A=M+5") << "line not matching";

    // line 2
    std::getline(infile, line);
    ASSERT_EQ(line, "D=M") << "line not matching";

    assert_push_logic(infile);
    infile.close();
}

TEST_F(AsmCoderTestBasicTestVM, Code18)
{
    using std::string;

    // push argument 1
    for (int i = 0; i < 17; i++)
        parser->advance();
    auto arg1 = parser->arg1();
    auto arg2 = parser->arg2();
    asm_coder->write_push_pop(true, arg1, arg2);
    asm_coder->close();

    std::ifstream infile(asm_fname);
    string line;

    // line 0
    std::getline(infile, line);
    ASSERT_EQ(line, "@ARG") << "line not matching";

    // line 1
    std::getline(infile, line);
    ASSERT_EQ(line, "A=M+1") << "line not matching";

    // line 2
    std::getline(infile, line);
    ASSERT_EQ(line, "D=M") << "line not matching";

    assert_push_logic(infile);
    infile.close();
}

TEST_F(AsmCoderTestBasicTestVM, Code20)
{
    using std::string;

    // push this 6
    for (int i = 0; i < 19; i++)
        parser->advance();
    auto arg1 = parser->arg1();
    auto arg2 = parser->arg2();
    asm_coder->write_push_pop(true, arg1, arg2);
    asm_coder->close();

    std::ifstream infile(asm_fname);
    string line;

    // line 0
    std::getline(infile, line);
    ASSERT_EQ(line, "@THIS") << "line not matching";

    // line 1
    std::getline(infile, line);
    ASSERT_EQ(line, "A=M+6") << "line not matching";

    // line 2
    std::getline(infile, line);
    ASSERT_EQ(line, "D=M") << "line not matching";

    assert_push_logic(infile);
    infile.close();
}

TEST_F(AsmCoderTestBasicTestVM, Code24)
{
    using std::string;

    // push temp 6
    for (int i = 0; i < 23; i++)
        parser->advance();
    auto arg1 = parser->arg1();
    auto arg2 = parser->arg2();
    asm_coder->write_push_pop(true, arg1, arg2);
    asm_coder->close();

    std::ifstream infile(asm_fname);
    string line;

    // line 0
    std::getline(infile, line);
    ASSERT_EQ(line, "@5") << "line not matching";

    // line 1
    std::getline(infile, line);
    ASSERT_EQ(line, "D=A") << "line not matching";

    // line 2
    std::getline(infile, line);
    ASSERT_EQ(line, "@6") << "line not matching";

    // line 3
    std::getline(infile, line);
    ASSERT_EQ(line, "A=D+A") << "line not matching";

    // line 4
    std::getline(infile, line);
    ASSERT_EQ(line, "D=M") << "line not matching";

    assert_push_logic(infile);
    infile.close();
}

void assert_push_logic(std::ifstream& in)
{
    std::string line;

    // line 1
    std::getline(in, line);
    ASSERT_EQ(line, "@SP") << "line not matching";

    // line 2
    std::getline(in, line);
    ASSERT_EQ(line, "A=M") << "line not matching";

    // line 3
    std::getline(in, line);
    ASSERT_EQ(line, "M=D") << "line not matching";

    // line 4
    std::getline(in, line);
    ASSERT_EQ(line, "@SP") << "line not matching";

    // line 5
    std::getline(in, line);
    ASSERT_EQ(line, "M=M+1") << "line not matching";
}

void assert_pop_logic(std::ifstream& in)
{
    std::string line;

    // line 1
    std::getline(in, line);
    ASSERT_EQ(line, "@SP") << "line not matching";

    // line 2
    std::getline(in, line);
    ASSERT_EQ(line, "M=M-1") << "line not matching";

    // line 3
    std::getline(in, line);
    ASSERT_EQ(line, "A=M") << "line not matching";

    // line 4
    std::getline(in, line);
    ASSERT_EQ(line, "D=M") << "line not matching";
}
