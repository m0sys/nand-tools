// Test file for testing Hack Assembler.
#include "../src/assembler.h"
#include <fstream>
#include <gtest/gtest.h>
#include <string>

class AssemblerTestAddAsm : public ::testing::Test {
protected:
    void SetUp() override
    {
        assembler = new Assembler("../../../add/Add.asm");
        assembler->assemble();
    }
    void TearDown() override { delete assembler; }

    Assembler* assembler;
};

TEST_F(AssemblerTestAddAsm, TestMatchingResults)
{
    using std::string;
    std::ifstream infile(assembler->m_fname);
    string line;

    // Testing first instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "0000000000000010") << "hack i0 not equal";

    // Testing second instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "1110110000010000") << "hack i1 not equal";

    // Testing third instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "0000000000000011") << "hack i2 not equal";

    // Testing forth instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "1110000010010000") << "hack i3 not equal";

    // Testing fifth instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "0000000000000000") << "hack i4 not equal";

    // Testing sixth instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "1110001100001000") << "hack i3 not equal";

    EXPECT_FALSE(std::getline(infile, line));
    infile.close();
}
