// Test file for testing Hack Assembler.
#include "../src/assembler.h"
#include <fstream>
#include <gtest/gtest.h>
#include <string>

TEST(AssemblerTestAddAsm, TestMatchingResults)
{
    using std::string;
    auto a = Assembler("../../../add/Add.asm");
    a.assemble();
    std::ifstream infile(a.m_fname);
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

TEST(AssemblerTestMaxAsm, TestMatchingResults)
{
    using std::string;
    auto a = Assembler("../../../max/Max.asm");
    a.assemble();
    std::ifstream infile(a.m_fname);
    string line;

    // Testing first instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "0000000000000000") << "hack i0 not equal";

    // Testing second instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "1111110000010000") << "hack i1 not equal";

    // Testing third instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "0000000000000001") << "hack i2 not equal";

    // Testing forth instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "1111010011010000") << "hack i3 not equal";

    // Testing fifth instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "0000000000001010") << "hack i4 not equal";

    // Testing sixth instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "1110001100000001") << "hack i5 not equal";

    // Testing seventh instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "0000000000000001") << "hack i6 not equal";

    // Testing eighth instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "1111110000010000") << "hack i7 not equal";

    // Testing nineth instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "0000000000001100") << "hack i8 not equal";

    // Testing tenth instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "1110101010000111") << "hack i9 not equal";

    // Testing eleventh instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "0000000000000000") << "hack i10 not equal";

    // Testing twelvth instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "1111110000010000") << "hack i11 not equal";

    // Testing thirteenth instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "0000000000000010") << "hack i12 not equal";

    // Testing 14th instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "1110001100001000") << "hack i13 not equal";

    // Testing 15th instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "0000000000001110") << "hack i14 not equal";

    // Testing 16th instruction.
    std::getline(infile, line);
    ASSERT_EQ(line, "1110101010000111") << "hack i15 not equal";

    EXPECT_FALSE(std::getline(infile, line));
    infile.close();
}

TEST(AssemblerTestRectAsm, TestMatchingResults)
{
    using std::string;
    auto a = Assembler("../../../rect/Rect.asm");
    a.assemble();
    std::ifstream infile(a.m_fname);
    string line;

    // Testing 6th instruction.
    for (int i = 0; i < 5; i++)
        std::getline(infile, line);
    ASSERT_EQ(line, "0000000000010000") << "hack i5 not equal";

    // Testing 8th instruction.
    for (int i = 0; i < 4; i++)
        std::getline(infile, line);
    ASSERT_EQ(line, "0000000000010001") << "hack i7 not equal";

    infile.close();
}
