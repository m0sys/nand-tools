// Tokenizer takes Jack Code and generates tokens that represent the code.
// Date: 2021/12/08
// Author: m0sys

#pragma once
#include <string>
#include <vector>

enum class TokenType {
    KWD,
    SYMB,
    ID,
    INT_CONST,
    STR_CONST,
};

enum class Kwd {
    CLS,
    METH,
    FUNC,
    CONSTR,
    INT,
    BOOL,
    CHAR,
    VOID,
    VAR,
    STATIC,
    FIELD,
    LET,
    DO,
    IF,
    ELSE,
    WHILE,
    RET,
    T,
    F,
    N,
    THIS,
};

class Tokenizer {
public:
    // Opens fname.jack file and prepares for tokenizining the file.
    Tokenizer(std::string jack_file);

    // Checks to see if there are more tokens left in `tokens`.
    bool has_more_tokens();

    // Moves to next token.
    void advance();

    // Returns the current token's type.
    TokenType token_type();

    // Returns the current token's keyword type if token is of type KWD.
    Kwd keyword();

    // Returns the current token's symbol if token is of type SYMB.
    char symbol();

    // Returns the current token's id if token is of type ID.
    std::string id();

    // Returns the current token's integer value if token is of type INT_CONST.
    int int_val();

    // Returns the current token's string value if token is of type STR_CONST.
    std::string str_val();

private:
    unsigned curr_token_idx = 0;
    std::vector<std::string> tokns;
};
