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

TEST_F(EncoderTestAddAsm, CTypeEncodeDst)
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

TEST_F(EncoderTestAddAsm, CTypeEncodeComp)
{
    // Testing second instruction in Add.asm
    parser->advance();
    auto comp = parser->comp();
    auto enc_comp = Encoder::encode_comp(comp);
    EXPECT_EQ(enc_comp.size(), 7);
    EXPECT_EQ(enc_comp, "0110000");

    // Testing forth instruction in Add.asm
    parser->advance();
    parser->advance();
    auto comp2 = parser->comp();
    auto enc_comp2 = Encoder::encode_comp(comp2);
    EXPECT_EQ(enc_comp2.size(), 7);
    EXPECT_EQ(enc_comp2, "0000010");

    // Testing sixth instruction in Add.asm
    parser->advance();
    parser->advance();
    auto comp3 = parser->comp();
    auto enc_comp3 = Encoder::encode_comp(comp3);
    EXPECT_EQ(enc_comp3.size(), 7);
    EXPECT_EQ(enc_comp3, "0001100");

    // TODO: add null dst test case.
}

TEST(EncoderTestFullSet, AllComps)
{
    auto c0 = Encoder::encode_comp("0");
    EXPECT_EQ(c0.size(), 7);
    EXPECT_EQ(c0, "0101010");

    auto c1 = Encoder::encode_comp("1");
    EXPECT_EQ(c1.size(), 7);
    EXPECT_EQ(c1, "0111111");

    auto c2 = Encoder::encode_comp("-1");
    EXPECT_EQ(c2.size(), 7);
    EXPECT_EQ(c2, "0111010");

    auto c3 = Encoder::encode_comp("D");
    EXPECT_EQ(c3.size(), 7);
    EXPECT_EQ(c3, "0001100");

    auto c4 = Encoder::encode_comp("A");
    EXPECT_EQ(c4.size(), 7);
    EXPECT_EQ(c4, "0110000");

    auto c5 = Encoder::encode_comp("M");
    EXPECT_EQ(c5.size(), 7);
    EXPECT_EQ(c5, "1110000");

    auto c6 = Encoder::encode_comp("!D");
    EXPECT_EQ(c6.size(), 7);
    EXPECT_EQ(c6, "0001101");

    auto c7 = Encoder::encode_comp("!A");
    EXPECT_EQ(c7.size(), 7);
    EXPECT_EQ(c7, "0110001");

    auto c8 = Encoder::encode_comp("!M");
    EXPECT_EQ(c8.size(), 7);
    EXPECT_EQ(c8, "1110001");

    auto c9 = Encoder::encode_comp("-D");
    EXPECT_EQ(c9.size(), 7);
    EXPECT_EQ(c9, "0001111");

    auto c10 = Encoder::encode_comp("-A");
    EXPECT_EQ(c10.size(), 7);
    EXPECT_EQ(c10, "0110011");

    auto c11 = Encoder::encode_comp("-M");
    EXPECT_EQ(c11.size(), 7);
    EXPECT_EQ(c11, "1110011");

    auto c12 = Encoder::encode_comp("D+1");
    EXPECT_EQ(c12.size(), 7);
    EXPECT_EQ(c12, "0011111");

    auto c13 = Encoder::encode_comp("A+1");
    EXPECT_EQ(c13.size(), 7);
    EXPECT_EQ(c13, "0110111");

    auto c14 = Encoder::encode_comp("M+1");
    EXPECT_EQ(c14.size(), 7);
    EXPECT_EQ(c14, "1110111");

    auto c15 = Encoder::encode_comp("D-1");
    EXPECT_EQ(c15.size(), 7);
    EXPECT_EQ(c15, "0001110");

    auto c16 = Encoder::encode_comp("A-1");
    EXPECT_EQ(c16.size(), 7);
    EXPECT_EQ(c16, "0110010");

    auto c17 = Encoder::encode_comp("M-1");
    EXPECT_EQ(c17.size(), 7);
    EXPECT_EQ(c17, "1110010");

    auto c18 = Encoder::encode_comp("D+A");
    EXPECT_EQ(c18.size(), 7);
    EXPECT_EQ(c18, "0000010");

    auto c19 = Encoder::encode_comp("D+M");
    EXPECT_EQ(c19.size(), 7);
    EXPECT_EQ(c19, "1000010");

    auto c20 = Encoder::encode_comp("D-A");
    EXPECT_EQ(c20.size(), 7);
    EXPECT_EQ(c20, "0010011");

    auto c21 = Encoder::encode_comp("D-M");
    EXPECT_EQ(c21.size(), 7);
    EXPECT_EQ(c21, "1010011");

    auto c22 = Encoder::encode_comp("A-D");
    EXPECT_EQ(c22.size(), 7);
    EXPECT_EQ(c22, "0000111");

    auto c23 = Encoder::encode_comp("M-D");
    EXPECT_EQ(c23.size(), 7);
    EXPECT_EQ(c23, "1000111");

    auto c24 = Encoder::encode_comp("D&A");
    EXPECT_EQ(c24.size(), 7);
    EXPECT_EQ(c24, "0000000");

    auto c25 = Encoder::encode_comp("D&M");
    EXPECT_EQ(c25.size(), 7);
    EXPECT_EQ(c25, "1000000");

    auto c26 = Encoder::encode_comp("D|A");
    EXPECT_EQ(c26.size(), 7);
    EXPECT_EQ(c26, "0010101");

    auto c27 = Encoder::encode_comp("D|M");
    EXPECT_EQ(c27.size(), 7);
    EXPECT_EQ(c27, "1010101");

    EXPECT_ANY_THROW(Encoder::encode_comp(""));
}

TEST(EncoderTestFullSet, AllJumps)
{
    auto j0 = Encoder::encode_jump("null");
    EXPECT_EQ(j0.size(), 3);
    EXPECT_EQ(j0, "000");

    auto j1 = Encoder::encode_jump("JGT");
    EXPECT_EQ(j1.size(), 3);
    EXPECT_EQ(j1, "001");

    auto j2 = Encoder::encode_jump("JEQ");
    EXPECT_EQ(j2.size(), 3);
    EXPECT_EQ(j2, "010");

    auto j3 = Encoder::encode_jump("JGE");
    EXPECT_EQ(j3.size(), 3);
    EXPECT_EQ(j3, "011");

    auto j4 = Encoder::encode_jump("JLT");
    EXPECT_EQ(j4.size(), 3);
    EXPECT_EQ(j4, "100");

    auto j5 = Encoder::encode_jump("JNE");
    EXPECT_EQ(j5.size(), 3);
    EXPECT_EQ(j5, "101");

    auto j6 = Encoder::encode_jump("JLE");
    EXPECT_EQ(j6.size(), 3);
    EXPECT_EQ(j6, "110");

    auto j7 = Encoder::encode_jump("JMP");
    EXPECT_EQ(j7.size(), 3);
    EXPECT_EQ(j7, "111");
}
