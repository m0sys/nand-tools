// Test file for testing Hack machine code Encoder.
#include "../src/encoder.h"
#include "../src/parser.h"
#include <gtest/gtest.h>

/*
 * Testing Add.asm
 */

class EncoderTestAddAsm : public ::testing::Test {
protected:
    void SetUp() override { parser = new Parser("../../../add/Add.asm"); }

    void TearDown() override { delete parser; }

    Parser* parser;
};

TEST_F(EncoderTestAddAsm, TestParserNumInstrs)
{
    //
    ASSERT_EQ(parser->num_instrs(), 6) << "Parsed file is not 6 instructions";
}

TEST_F(EncoderTestAddAsm, CTypeEncodeDstL01)
{
    // Testing second instruction in Add.asm
    parser->advance();
    auto dst = parser->dst();
    auto enc_dst = Encoder::encode_dst(dst);
    EXPECT_EQ(enc_dst.size(), 3);
    EXPECT_EQ(enc_dst, "010");

    // Testing forth instruction in Add.asm
    parser->advance();
    parser->advance();
    auto dst2 = parser->dst();
    auto enc_dst2 = Encoder::encode_dst(dst2);
    EXPECT_EQ(enc_dst2.size(), 3);
    EXPECT_EQ(enc_dst2, "010");

    // Testing sixth instruction in Add.asm
    parser->advance();
    parser->advance();
    auto dst3 = parser->dst();
    auto enc_dst3 = Encoder::encode_dst(dst3);
    EXPECT_EQ(enc_dst3.size(), 3);
    EXPECT_EQ(enc_dst3, "001");

    // TODO: add null dst test case.
}
