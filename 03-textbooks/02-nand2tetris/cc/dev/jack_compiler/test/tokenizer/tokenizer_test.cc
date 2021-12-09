// Test file for Tokenizer.

#include "../../src/tokenizer/tokenizer.h"
#include <gtest/gtest.h>

/*
 * Testing BasicTest.vm
 */

class TokenizerTest : public ::testing::Test {
protected:
    void SetUp() override { tz = new Tokenizer("../../../projects/10/ArrayTest/Main.jack"); }

    void TearDown() override { delete tz; }

    Tokenizer* tz;
};

TEST_F(TokenizerTest, Tkn1)
{
    ASSERT_EQ(tz->token_type(), TokenType::KWD) << "Tkn type must be KWD";
    ASSERT_EQ(tz->keyword(), Kwd::CLS);
}

TEST_F(TokenizerTest, Tkn2)
{
    for (int i = 0; i < 1; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::ID) << "Tkn type must be ID";
    ASSERT_EQ(tz->id(), "Main");
}

TEST_F(TokenizerTest, Tkn3)
{
    for (int i = 0; i < 2; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::SYMB) << "Tkn type must be SYMB";
    ASSERT_EQ(tz->symbol(), '{');
}

TEST_F(TokenizerTest, Tkn4)
{
    for (int i = 0; i < 3; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::KWD) << "Tkn type must be KWD";
    ASSERT_EQ(tz->keyword(), Kwd::FUNC);
}

TEST_F(TokenizerTest, Tkn5)
{
    for (int i = 0; i < 4; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::KWD) << "Tkn type must be KWD";
    ASSERT_EQ(tz->keyword(), Kwd::VOID);
}

TEST_F(TokenizerTest, Tkn6)
{
    for (int i = 0; i < 5; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::ID) << "Tkn type must be ID";
    ASSERT_EQ(tz->id(), "main");
}

TEST_F(TokenizerTest, Tkn7)
{
    for (int i = 0; i < 6; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::SYMB) << "Tkn type must be SYMB";
    ASSERT_EQ(tz->symbol(), '(');
}

TEST_F(TokenizerTest, Tkn8)
{
    for (int i = 0; i < 7; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::SYMB) << "Tkn type must be SYMB";
    ASSERT_EQ(tz->symbol(), ')');
}

TEST_F(TokenizerTest, Tkn9)
{
    for (int i = 0; i < 8; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::SYMB) << "Tkn type must be SYMB";
    ASSERT_EQ(tz->symbol(), '{');
}

TEST_F(TokenizerTest, Tkn10)
{
    for (int i = 0; i < 9; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::KWD) << "Tkn type must be KWD";
    ASSERT_EQ(tz->keyword(), Kwd::VAR);
}

TEST_F(TokenizerTest, Tkn13)
{
    for (int i = 0; i < 12; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::SYMB) << "Tkn type must be SYMB";
    ASSERT_EQ(tz->symbol(), ';');
}

TEST_F(TokenizerTest, Tkn21)
{
    for (int i = 0; i < 20; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::SYMB) << "Tkn type must be SYMB";
    ASSERT_EQ(tz->symbol(), ',');
}

TEST_F(TokenizerTest, Tkn24)
{
    for (int i = 0; i < 23; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::KWD) << "Tkn type must be KWD";
    ASSERT_EQ(tz->keyword(), Kwd::LET);
}

TEST_F(TokenizerTest, Tkn26)
{
    for (int i = 0; i < 25; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::SYMB) << "Tkn type must be SYMB";
    ASSERT_EQ(tz->symbol(), '=');
}

TEST_F(TokenizerTest, Tkn27)
{
    for (int i = 0; i < 26; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::ID) << "Tkn type must be ID";
    ASSERT_EQ(tz->id(), "Keyboard");
}

TEST_F(TokenizerTest, Tkn28)
{
    for (int i = 0; i < 27; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::SYMB) << "Tkn type must be SYMB";
    ASSERT_EQ(tz->symbol(), '.');
}

TEST_F(TokenizerTest, Tkn29)
{
    for (int i = 0; i < 28; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::ID) << "Tkn type must be ID";
    ASSERT_EQ(tz->id(), "readInt");
}

TEST_F(TokenizerTest, Tkn30)
{
    for (int i = 0; i < 29; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::SYMB) << "Tkn type must be SYMB";
    ASSERT_EQ(tz->symbol(), '(');
}

TEST_F(TokenizerTest, Tkn31)
{
    for (int i = 0; i < 30; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::STR_CONST) << "Tkn type must be STR_CONST";
    ASSERT_EQ(tz->str_val(), "HOW MANY NUMBERS? ");
    ASSERT_EQ(tz->str_val(), "HOW MANY NUMBERS? ");
}

TEST_F(TokenizerTest, Tkn32)
{
    for (int i = 0; i < 31; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::SYMB) << "Tkn type must be SYMB";
    ASSERT_EQ(tz->symbol(), ')');
}

TEST_F(TokenizerTest, Tkn33)
{
    for (int i = 0; i < 32; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::SYMB) << "Tkn type must be SYMB";
    ASSERT_EQ(tz->symbol(), ';');
}

TEST_F(TokenizerTest, Tkn47)
{
    for (int i = 0; i < 46; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::INT_CONST) << "Tkn type must be INT_CONST";
    ASSERT_EQ(tz->int_val(), 0);
}

TEST_F(TokenizerTest, Tkn49)
{
    for (int i = 0; i < 48; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::KWD) << "Tkn type must be KWD";
    ASSERT_EQ(tz->keyword(), Kwd::WHILE);
}

TEST_F(TokenizerTest, Tkn52)
{
    for (int i = 0; i < 51; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::SYMB) << "Tkn type must be SYMB";
    ASSERT_EQ(tz->symbol(), '<');
}

TEST_F(TokenizerTest, Tkn58)
{
    for (int i = 0; i < 57; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::SYMB) << "Tkn type must be SYMB";
    ASSERT_EQ(tz->symbol(), '[');
}

TEST_F(TokenizerTest, Tkn66)
{
    for (int i = 0; i < 65; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::STR_CONST) << "Tkn type must be STR_CONST";
    ASSERT_EQ(tz->str_val(), "ENTER THE NEXT NUMBER: ");
}

TEST_F(TokenizerTest, Tkn74)
{
    for (int i = 0; i < 73; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::INT_CONST) << "Tkn type must be INT_CONST";
    ASSERT_EQ(tz->int_val(), 1);
}

TEST_F(TokenizerTest, Tkn112)
{
    for (int i = 0; i < 111; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::KWD) << "Tkn type must be KWD";
    ASSERT_EQ(tz->keyword(), Kwd::DO);
}

TEST_F(TokenizerTest, Tkn137)
{
    for (int i = 0; i < 136; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::KWD) << "Tkn type must be KWD";
    ASSERT_EQ(tz->keyword(), Kwd::RET);
}
