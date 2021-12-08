#include "common/log.h"
#include "tokenizer/tokenizer.h"

int main()
{
    LOG("HELLO, WORLD");
    Tokenizer t("../../../projects/10/ExpressionLessSquare/Main.jack");
    DEBUG_LOG("HELLO, WORLD; DEBUG");
}
