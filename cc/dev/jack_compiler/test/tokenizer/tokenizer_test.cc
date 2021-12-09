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
    //
    ASSERT_EQ(tz->token_type(), TokenType::KWD) << "Tkn type must be KWD";
}

TEST_F(TokenizerTest, Tkn2)
{
    //
    for (int i = 0; i < 1; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::ID) << "Tkn type must be ID";
}

TEST_F(TokenizerTest, Tkn3)
{
    //
    for (int i = 0; i < 2; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::SYMB) << "Tkn type must be SYMB";
}

TEST_F(TokenizerTest, Tkn4)
{
    //
    for (int i = 0; i < 3; i++)
        tz->advance();
    ASSERT_EQ(tz->token_type(), TokenType::KWD) << "Tkn type must be KWD";
}
