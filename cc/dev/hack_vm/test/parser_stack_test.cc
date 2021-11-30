// Test file for testing VM Parser.

#include "../src/parser.h"
#include <gtest/gtest.h>

/*
 * Testing StackTest.vm
 */

class ParserTestStackTestVM : public ::testing::Test {
protected:
    void SetUp() override { parser = new Parser("../../../projects/07/StackArithmetic/StackTest/StackTest.vm"); }

    void TearDown() override { delete parser; }

    Parser* parser;
};

TEST_F(ParserTestStackTestVM, ParserNumberOfCmds)
{
    //
    ASSERT_EQ(parser->num_cmds(), 38) << "Parsed file is not 24 cmds long";
}

TEST_F(ParserTestStackTestVM, ParserCmd1)
{
    for (int i = 0; i < 0; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 17) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd2)
{
    for (int i = 0; i < 1; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 17) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd3)
{
    for (int i = 0; i < 2; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_ARITH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "eq") << "Parsed arg1 does not match";
    ASSERT_ANY_THROW(parser->arg2()) << "Parsed arg2 must throw";
}

TEST_F(ParserTestStackTestVM, ParserCmd4)
{
    for (int i = 0; i < 3; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 17) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd5)
{
    for (int i = 0; i < 4; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 16) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd6)
{
    for (int i = 0; i < 5; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_ARITH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "eq") << "Parsed arg1 does not match";
    ASSERT_ANY_THROW(parser->arg2()) << "Parsed arg2 must throw";
}

TEST_F(ParserTestStackTestVM, ParserCmd7)
{
    for (int i = 0; i < 6; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 16) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd8)
{
    for (int i = 0; i < 7; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 17) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd9)
{
    for (int i = 0; i < 8; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_ARITH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "eq") << "Parsed arg1 does not match";
    ASSERT_ANY_THROW(parser->arg2()) << "Parsed arg2 must throw";
}

TEST_F(ParserTestStackTestVM, ParserCmd10)
{
    for (int i = 0; i < 9; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 892) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd11)
{
    for (int i = 0; i < 10; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 891) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd12)
{
    for (int i = 0; i < 11; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_ARITH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "lt") << "Parsed arg1 does not match";
    ASSERT_ANY_THROW(parser->arg2()) << "Parsed arg2 must throw";
}

TEST_F(ParserTestStackTestVM, ParserCmd13)
{
    for (int i = 0; i < 12; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 891) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd14)
{
    for (int i = 0; i < 13; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 892) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd15)
{
    for (int i = 0; i < 14; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_ARITH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "lt") << "Parsed arg1 does not match";
    ASSERT_ANY_THROW(parser->arg2()) << "Parsed arg2 must throw";
}

TEST_F(ParserTestStackTestVM, ParserCmd16)
{
    for (int i = 0; i < 15; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 891) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd17)
{
    for (int i = 0; i < 16; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 891) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd18)
{
    for (int i = 0; i < 17; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_ARITH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "lt") << "Parsed arg1 does not match";
    ASSERT_ANY_THROW(parser->arg2()) << "Parsed arg2 must throw";
}

TEST_F(ParserTestStackTestVM, ParserCmd19)
{
    for (int i = 0; i < 18; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 32767) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd20)
{
    for (int i = 0; i < 19; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 32766) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd21)
{
    for (int i = 0; i < 20; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_ARITH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "gt") << "Parsed arg1 does not match";
    ASSERT_ANY_THROW(parser->arg2()) << "Parsed arg2 must throw";
}

TEST_F(ParserTestStackTestVM, ParserCmd22)
{
    for (int i = 0; i < 21; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 32766) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd23)
{
    for (int i = 0; i < 22; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 32767) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd24)
{
    for (int i = 0; i < 23; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_ARITH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "gt") << "Parsed arg1 does not match";
    ASSERT_ANY_THROW(parser->arg2()) << "Parsed arg2 must throw";
}

TEST_F(ParserTestStackTestVM, ParserCmd25)
{
    for (int i = 0; i < 24; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 32766) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd26)
{
    for (int i = 0; i < 25; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 32766) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd27)
{
    for (int i = 0; i < 26; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_ARITH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "gt") << "Parsed arg1 does not match";
    ASSERT_ANY_THROW(parser->arg2()) << "Parsed arg2 must throw";
}

TEST_F(ParserTestStackTestVM, ParserCmd28)
{
    for (int i = 0; i < 27; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 57) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd29)
{
    for (int i = 0; i < 28; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 31) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd30)
{
    for (int i = 0; i < 29; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 53) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd31)
{
    for (int i = 0; i < 30; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_ARITH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "add") << "Parsed arg1 does not match";
    ASSERT_ANY_THROW(parser->arg2()) << "Parsed arg2 must throw";
}

TEST_F(ParserTestStackTestVM, ParserCmd32)
{
    for (int i = 0; i < 31; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 112) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd33)
{
    for (int i = 0; i < 32; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_ARITH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "sub") << "Parsed arg1 does not match";
    ASSERT_ANY_THROW(parser->arg2()) << "Parsed arg2 must throw";
}

TEST_F(ParserTestStackTestVM, ParserCmd34)
{
    for (int i = 0; i < 33; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_ARITH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "neg") << "Parsed arg1 does not match";
    ASSERT_ANY_THROW(parser->arg2()) << "Parsed arg2 must throw";
}

TEST_F(ParserTestStackTestVM, ParserCmd35)
{
    for (int i = 0; i < 34; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_ARITH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "and") << "Parsed arg1 does not match";
    ASSERT_ANY_THROW(parser->arg2()) << "Parsed arg2 must throw";
}

TEST_F(ParserTestStackTestVM, ParserCmd36)
{
    for (int i = 0; i < 35; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 82) << "Parsed arg2 does not match";
}

TEST_F(ParserTestStackTestVM, ParserCmd37)
{
    for (int i = 0; i < 36; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_ARITH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "or") << "Parsed arg1 does not match";
    ASSERT_ANY_THROW(parser->arg2()) << "Parsed arg2 must throw";
}

TEST_F(ParserTestStackTestVM, ParserCmd38)
{
    for (int i = 0; i < 37; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_ARITH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "not") << "Parsed arg1 does not match";
    ASSERT_ANY_THROW(parser->arg2()) << "Parsed arg2 must throw";

    ASSERT_FALSE(parser->has_more_lines()) << "Parser must not have any more lines";
    ASSERT_ANY_THROW(parser->advance()) << "Parser must have reached the end of cmds";
}
