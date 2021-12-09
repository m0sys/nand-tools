#include "common/log.h"
#include "tokenizer/tokenizer.h"

int main()
{
    LOG("HELLO, WORLD");
    Tokenizer t("../../../projects/10/ExpressionLessSquare/Square.jack");
    DEBUG_LOG("HELLO, WORLD; DEBUG");
}
