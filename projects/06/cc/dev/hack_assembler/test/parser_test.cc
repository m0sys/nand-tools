// Test file for testing Hack assembly Parser.
// TODO: fix relative path to src files.
#include "../src/parser.h"
#include <gtest/gtest.h>

/*
 * Testing Add.asm
 */

class ParserTestAddAsm : public ::testing::Test {
protected:
    void SetUp() override { parser = new Parser("../../../add/Add.asm"); }

    void TearDown() override { delete parser; }

    Parser* parser;
};

TEST_F(ParserTestAddAsm, CreatingNewParser)
{
    //
    ASSERT_EQ(parser->num_instrs(), 6) << "Parsed file is not 6 instructions";
}

/* Testing first instruction in Add.asm */

TEST_F(ParserTestAddAsm, ATypeInstrTypeL00)
{
    //
    EXPECT_EQ(parser->instr_type(), InstrType::A_TYPE);
}

TEST_F(ParserTestAddAsm, ATypeSymbolL00)
{
    //
    EXPECT_EQ(parser->symbol(), "2") << "Parsed symbol not 2: " << parser->symbol();
}

TEST_F(ParserTestAddAsm, ATypeDstL00)
{
    //
    EXPECT_ANY_THROW(parser->dst()) << "Parsed dst should throw for atype instr";
}

TEST_F(ParserTestAddAsm, ATypeCompL00)
{
    //
    EXPECT_ANY_THROW(parser->comp()) << "Parsed comp should throw for atype instr";
}

TEST_F(ParserTestAddAsm, ATypeJumpL00)
{
    //
    EXPECT_ANY_THROW(parser->jump()) << "Parsed jump should throw for atype instr";
}

/* Testing second instruction in Add.asm */

TEST_F(ParserTestAddAsm, CTypeAdvanceL01)
{
    parser->advance();
    EXPECT_EQ(parser->instr_type(), InstrType::C_TYPE);
}

TEST_F(ParserTestAddAsm, CTypeSymbolL01)
{
    parser->advance();
    EXPECT_ANY_THROW(parser->symbol()) << "Parsed symbol should throw for ctype instr";
}

TEST_F(ParserTestAddAsm, CTypeDstL01)
{
    parser->advance();
    EXPECT_EQ(parser->dst(), "D") << "Parsed dst should be D for curr ctype instr";
}

TEST_F(ParserTestAddAsm, CTypeCompL01)
{
    parser->advance();
    EXPECT_EQ(parser->comp(), "A") << "Parsed comp should be A for curr ctype instr";
}

TEST_F(ParserTestAddAsm, CTypeJumpL01)
{
    parser->advance();
    EXPECT_EQ(parser->jump(), "") << "Parsed jump should be empty for curr ctype instr";
}

/*
 * Testing Max.asm
 */

class ParserTestMaxAsm : public ::testing::Test {
protected:
    void SetUp() override { parser = new Parser("../../../max/Max.asm"); }

    void TearDown() override { delete parser; }

    Parser* parser;
};

/* Testing first instruction in Add.asm */

TEST_F(ParserTestMaxAsm, ATypeInstrTypeL00)
{
    //
    EXPECT_EQ(parser->instr_type(), InstrType::A_TYPE);
}

// TEST_F(ParserTestMaxAsm, CTypeAdvanceL01)
//{
//    parser->advance();
//    EXPECT_EQ(parser->instr_type(), InstrType::C_TYPE);
//}
