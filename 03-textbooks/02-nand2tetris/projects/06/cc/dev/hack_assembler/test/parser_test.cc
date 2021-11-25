// TODO: fix relative path to src files.
#include "../src/parser.h"
#include <gtest/gtest.h>

class ParserTest : public ::testing::Test {
protected:
    void SetUp() override { parser = new Parser("../../../add/Add.asm"); }

    void TearDown() override { delete parser; }

    Parser* parser;
};

TEST_F(ParserTest, CreatingNewParser)
{
    //
    EXPECT_EQ(parser->num_instrs(), 6) << "Parsed file is not 6 instructions";
}
