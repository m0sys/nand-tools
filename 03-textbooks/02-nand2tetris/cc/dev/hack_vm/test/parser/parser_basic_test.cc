// Test file for testing VM Parser.

#include "../../src/parser/parser.h"
#include <gtest/gtest.h>

/*
 * Testing BasicTest.vm
 */

class ParserTestBasicTestVM : public ::testing::Test {
protected:
    void SetUp() override { parser = new Parser("../../../projects/07/MemoryAccess/BasicTest/BasicTest.vm"); }

    void TearDown() override { delete parser; }

    Parser* parser;
};

TEST_F(ParserTestBasicTestVM, ParserNumberOfCmds)
{
    //
    ASSERT_EQ(parser->num_cmds(), 25) << "Parsed file is not 24 cmds long";
}

TEST_F(ParserTestBasicTestVM, ParserCmd1)
{
    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 must be constant";
    ASSERT_EQ(parser->arg2(), 10) << "Parsed arg2 must be 10";
}

TEST_F(ParserTestBasicTestVM, ParserCmd2)
{
    parser->advance();
    ASSERT_EQ(parser->command_type(), CommandType::C_POP) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "local") << "Parsed arg1 must be local";
    ASSERT_EQ(parser->arg2(), 0) << "Parsed arg2 must be 0";
}

TEST_F(ParserTestBasicTestVM, ParserCmd3)
{
    for (int i = 0; i < 2; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 21) << "Parsed arg2 does not match";
}

TEST_F(ParserTestBasicTestVM, ParserCmd4)
{
    for (int i = 0; i < 3; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 22) << "Parsed arg2 does not match";
}

TEST_F(ParserTestBasicTestVM, ParserCmd5)
{
    for (int i = 0; i < 4; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_POP) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "argument") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 2) << "Parsed arg2 does not match";
}

TEST_F(ParserTestBasicTestVM, ParserCmd6)
{
    for (int i = 0; i < 5; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_POP) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "argument") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 1) << "Parsed arg2 does not match";
}

TEST_F(ParserTestBasicTestVM, ParserCmd7)
{
    for (int i = 0; i < 6; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 36) << "Parsed arg2 does not match";
}

TEST_F(ParserTestBasicTestVM, ParserCmd8)
{
    for (int i = 0; i < 7; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_POP) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "this") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 6) << "Parsed arg2 does not match";
}

TEST_F(ParserTestBasicTestVM, ParserCmd9)
{
    for (int i = 0; i < 8; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 42) << "Parsed arg2 does not match";
}

TEST_F(ParserTestBasicTestVM, ParserCmd10)
{
    for (int i = 0; i < 9; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 45) << "Parsed arg2 does not match";
}

TEST_F(ParserTestBasicTestVM, ParserCmd11)
{
    for (int i = 0; i < 10; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_POP) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "that") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 5) << "Parsed arg2 does not match";
}

TEST_F(ParserTestBasicTestVM, ParserCmd12)
{
    for (int i = 0; i < 11; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_POP) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "that") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 2) << "Parsed arg2 does not match";
}

TEST_F(ParserTestBasicTestVM, ParserCmd13)
{
    for (int i = 0; i < 12; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "constant") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 510) << "Parsed arg2 does not match";
}

TEST_F(ParserTestBasicTestVM, ParserCmd14)
{
    for (int i = 0; i < 13; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_POP) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "temp") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 6) << "Parsed arg2 does not match";
}

TEST_F(ParserTestBasicTestVM, ParserCmd15)
{
    for (int i = 0; i < 14; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "local") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 0) << "Parsed arg2 does not match";
}

TEST_F(ParserTestBasicTestVM, ParserCmd16)
{
    for (int i = 0; i < 15; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "that") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 5) << "Parsed arg2 does not match";
}

TEST_F(ParserTestBasicTestVM, ParserCmd17)
{
    for (int i = 0; i < 16; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_ARITH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "add") << "Parsed arg1 does not match";
    ASSERT_ANY_THROW(parser->arg2()) << "Parsed arg2 must throw";
}

TEST_F(ParserTestBasicTestVM, ParserCmd18)
{
    for (int i = 0; i < 17; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "argument") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 1) << "Parsed arg2 does not match";
}

TEST_F(ParserTestBasicTestVM, ParserCmd19)
{
    for (int i = 0; i < 18; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_ARITH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "sub") << "Parsed arg1 does not match";
    ASSERT_ANY_THROW(parser->arg2()) << "Parsed arg2 must throw";
}

TEST_F(ParserTestBasicTestVM, ParserCmd20)
{
    for (int i = 0; i < 19; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "this") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 6) << "Parsed arg2 does not match";
}

TEST_F(ParserTestBasicTestVM, ParserCmd21)
{
    for (int i = 0; i < 20; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "this") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 6) << "Parsed arg2 does not match";
}

TEST_F(ParserTestBasicTestVM, ParserCmd22)
{
    for (int i = 0; i < 21; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_ARITH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "add") << "Parsed arg1 does not match";
    ASSERT_ANY_THROW(parser->arg2()) << "Parsed arg2 must throw";
}

TEST_F(ParserTestBasicTestVM, ParserCmd23)
{
    for (int i = 0; i < 22; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_ARITH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "sub") << "Parsed arg1 does not match";
    ASSERT_ANY_THROW(parser->arg2()) << "Parsed arg2 must throw";
}

TEST_F(ParserTestBasicTestVM, ParserCmd24)
{
    for (int i = 0; i < 23; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_PUSH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "temp") << "Parsed arg1 does not match";
    ASSERT_EQ(parser->arg2(), 6) << "Parsed arg2 does not match";
}

TEST_F(ParserTestBasicTestVM, ParserCmd25)
{
    for (int i = 0; i < 24; i++)
        parser->advance();

    ASSERT_EQ(parser->command_type(), CommandType::C_ARITH) << "CT does not match";
    ASSERT_EQ(parser->arg1(), "add") << "Parsed arg1 does not match";
    ASSERT_ANY_THROW(parser->arg2()) << "Parsed arg2 must throw";

    ASSERT_FALSE(parser->has_more_lines()) << "Parser must not have any more lines";
    ASSERT_ANY_THROW(parser->advance()) << "Parser must have reached the end of cmds";
}
