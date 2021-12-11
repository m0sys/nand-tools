#include "tokenizer.h"
#include "../common/log.h"
#include "../common/strpulate.h"

#include <algorithm>
#include <bits/stdc++.h>
#include <filesystem>
#include <fstream>
#include <stdio.h>
#include <string>
#include <vector>

Tokenizer::Tokenizer(std::string jack_file)
{
    LOG(jack_file);
    // Check that fname exists before processing.
    if (!std::filesystem::exists(jack_file))
        throw std::logic_error("Tokenizer: jack_file does not exist");

    using std::string;

    std::ifstream infile(jack_file);
    string line;
    std::vector<string> lines;

    while (std::getline(infile, line)) {
        if (is_comment(line) || is_white_space(line))
            continue;

        // remove_backslash_r(line);
        remove_line_comment(line);
        line = common::trim(line);
        lines.push_back(line);
    }

    string tokn;
    for (const auto& l : lines) {
        DEBUG_LOG(l);
        std::stringstream ss(l);

        while (std::getline(ss, tokn, ' ')) {
            if (is_white_space(tokn))
                continue;

            bool is_meth_call = tokn.find('.') != string::npos;
            bool has_left_paren = tokn.find('(') != string::npos;
            bool has_right_paren = tokn.find(')') != string::npos;
            bool has_left_bra = tokn.find('[') != string::npos;
            bool has_right_bra = tokn.find(']') != string::npos;
            bool has_comma = tokn.find(',') != string::npos;
            bool has_semi = tokn.find(';') != string::npos;

            // clang-format off
            bool is_exception = is_meth_call ||
                                has_left_paren ||
                                has_right_paren ||
                                has_left_bra ||
                                has_right_bra ||
                                has_comma ||
                                has_semi;
            // clang-format on

            if (is_exception) {
                string rest = tokn;

                // Handle method call.
                if (is_meth_call) {
                    int p_pos = rest.find('.');
                    string lhs = rest.substr(0, p_pos);
                    string rhs = rest.substr(p_pos + 1, rest.size() - p_pos);
                    tokns.push_back(lhs);
                    tokns.push_back(string(1, '.'));
                    rest = rhs;
                }

                // Handle left paren.
                has_left_paren = rest.find('(') != string::npos;
                if (has_left_paren) {
                    int p_pos = rest.find('(');
                    string lhs = rest.substr(0, p_pos);
                    string rhs = rest.substr(p_pos + 1, rest.size() - p_pos);
                    if (lhs.size() != 0)
                        tokns.push_back(lhs);
                    tokns.push_back(string(1, '('));
                    rest = rhs;
                }

                // Handle string.
                // is_string_const = rest.find('"') != string::npos;
                // if (is_string_const) {
                //    string quote = "";

                //    // Handle case where str is a single word string.
                //    if (rest.rfind('"') != 0 && rest.rfind('"') != string::npos) {
                //        int p_pos = rest.rfind('"');
                //        string lhs = rest.substr(0, p_pos + 1);
                //        string rhs = rest.substr(p_pos + 2, rest.size() - (p_pos + 1));
                //        if (lhs.size() != 0)
                //            tokns.push_back(lhs);
                //        rest = rhs;
                //    } else {
                //        bool quote_not_ended = true;
                //        while (quote_not_ended) {
                //            quote += rest + " ";
                //            std::getline(ss, rest);
                //            if (rest.rfind())
                //        }
                //    }
                //}

                // Handle comma.
                has_comma = rest.find(',') != string::npos;
                if (has_comma) {
                    int p_pos = rest.find(',');
                    string lhs = rest.substr(0, p_pos);
                    string rhs = rest.substr(p_pos + 1, rest.size() - p_pos);
                    if (lhs.size() != 0)
                        tokns.push_back(lhs);
                    tokns.push_back(string(1, ','));
                    rest = rhs;
                }

                // Handle right paren.
                has_right_paren = rest.find(')') != string::npos;
                if (has_right_paren) {
                    int p_pos = rest.find(')');
                    string lhs = rest.substr(0, p_pos);
                    string rhs = rest.substr(p_pos + 1, rest.size() - p_pos);
                    if (lhs.size() != 0)
                        tokns.push_back(lhs);
                    tokns.push_back(string(1, ')'));
                    rest = rhs;
                }

                // Handle left bra.
                has_left_bra = rest.find('[') != string::npos;
                if (has_left_bra) {
                    int p_pos = rest.find('[');
                    string lhs = rest.substr(0, p_pos);
                    string rhs = rest.substr(p_pos + 1, rest.size() - p_pos);
                    if (lhs.size() != 0)
                        tokns.push_back(lhs);
                    tokns.push_back(string(1, '['));
                    rest = rhs;
                }

                // Handle right paren.
                has_right_bra = rest.find(']') != string::npos;
                if (has_right_bra) {
                    int p_pos = rest.find(']');
                    string lhs = rest.substr(0, p_pos);
                    string rhs = rest.substr(p_pos + 1, rest.size() - p_pos);
                    if (lhs.size() != 0)
                        tokns.push_back(lhs);
                    tokns.push_back(string(1, ']'));
                    rest = rhs;
                }

                // Handle semicolon.
                has_semi = rest.find(';') != string::npos;
                if (has_semi) {
                    int p_pos = rest.find(';');
                    string lhs = rest.substr(0, p_pos);
                    string rhs = rest.substr(p_pos + 1, rest.size() - p_pos);
                    if (lhs.size() != 0)
                        tokns.push_back(lhs);
                    tokns.push_back(string(1, ';'));
                    rest = rhs;
                }
                if (rest.size() != 0 && !is_white_space(rest))
                    tokns.push_back(rest);

                continue;
            }

            tokns.push_back(tokn);
        }
    }

    // for (const auto& t : tokns)
    //    LOG("tkn(" << t.size() << "): " << t);

    curr_token_idx = 0;
    infile.close();
}

bool Tokenizer::is_comment(const std::string& line)
{
    // clang-format off
    return line.substr(0, 2) == "//"  || 
           line.substr(0, 2) == "/*"  || 
           line.substr(0, 3) == "/**" ||
           line.substr(0,2)  == "*/";
    // clang-format on
}

bool Tokenizer::is_white_space(const std::string& line)
{
    //
    return std::all_of(line.begin(), line.end(), isspace);
}

void Tokenizer::remove_backslash_r(std::string& line) { line.erase(line.size() - 1); }

void Tokenizer::remove_line_comment(std::string& line)
{
    auto pos = line.find("//");
    if (pos != std::string::npos) {
        line.erase(pos);
    }
}

bool Tokenizer::has_more_tokens()
{
    //
    return curr_token_idx < tokns.size();
}

void Tokenizer::advance()
{
    // Handle skipping over string segments. - kinda hacky at this point.
    if (token_type() == TokenType::STR_CONST)
        advance_str_const();

    else if (has_more_tokens())
        curr_token_idx++;
    else
        throw std::out_of_range("Tokenizer: current token is the last token");
}

TokenType Tokenizer::token_type()
{
    using std::string;
    auto curtk = curr_token();
    if (found_kwd(curtk))
        return TokenType::KWD;

    if (found_symb(curtk))
        return TokenType::SYMB;

    if (curtk[0] == '"')
        return TokenType::STR_CONST;

    if (is_num(curtk)) {
        if (std::stoi(curtk) < 0 || std::stoi(curtk) > 32767)
            throw std::overflow_error("Tokenizer: cannot process numbers out of [0...32767]");
        return TokenType::INT_CONST;
    }

    return TokenType::ID;
}

std::string Tokenizer::curr_token() { return tokns[curr_token_idx]; }

bool Tokenizer::found_kwd(std::string kwd)
{
    //
    return std::find(KWDS.begin(), KWDS.end(), kwd) != KWDS.end();
}

bool Tokenizer::found_symb(std::string symb)
{

    //
    return std::find(SYMBS.begin(), SYMBS.end(), symb) != SYMBS.end();
}

bool Tokenizer::is_num(std::string s)
{
    //
    return !s.empty() && std::all_of(s.begin(), s.end(), ::isdigit);
}

Kwd Tokenizer::keyword()
{
    if (token_type() != TokenType::KWD)
        throw std::logic_error("Tokenizer: can only extract keyword from KWD types");

    auto curtk = curr_token();
    if (curtk == "class")
        return Kwd::CLS;

    if (curtk == "constructor")
        return Kwd::CONSTR;

    if (curtk == "function")
        return Kwd::FUNC;

    if (curtk == "method")
        return Kwd::METH;

    if (curtk == "field")
        return Kwd::FIELD;

    if (curtk == "static")
        return Kwd::STATIC;

    if (curtk == "var")
        return Kwd::VAR;

    if (curtk == "int")
        return Kwd::INT;

    if (curtk == "char")
        return Kwd::CHAR;

    if (curtk == "boolean")
        return Kwd::BOOL;

    if (curtk == "void")
        return Kwd::VOID;

    if (curtk == "true")
        return Kwd::T;

    if (curtk == "false")
        return Kwd::F;

    if (curtk == "null")
        return Kwd::N;

    if (curtk == "this")
        return Kwd::THIS;

    if (curtk == "let")
        return Kwd::LET;

    if (curtk == "do")
        return Kwd::DO;

    if (curtk == "if")
        return Kwd::IF;

    if (curtk == "else")
        return Kwd::ELSE;

    if (curtk == "while")
        return Kwd::WHILE;

    if (curtk == "return")
        return Kwd::RET;

    throw std::logic_error("Tokenizer: unsupported keyword!");
}

char Tokenizer::symbol()
{
    if (token_type() != TokenType::SYMB)
        throw std::logic_error("Tokenizer: can only extract symbol from SYMB types");
    return curr_token()[0];
}

std::string Tokenizer::id()
{
    if (token_type() != TokenType::ID)
        throw std::logic_error("Tokenizer: can only extract id from ID types");
    return curr_token();
}

int Tokenizer::int_val()
{
    if (token_type() != TokenType::INT_CONST)
        throw std::logic_error("Tokenizer: can only extract int from INT_CONST types");

    return std::stoi(curr_token());
}

std::string Tokenizer::str_val()
{
    using std::string;

    if (token_type() != TokenType::STR_CONST)
        throw std::logic_error("Tokenizer: can only extract str from STR_CONST types");

    auto curtk = curr_token();
    // Remove '/"'
    curtk = curtk.substr(1, curtk.size());
    string quote = "";

    // Handle case where str is a single word string.
    if (curtk.rfind('"') != 0 && curtk.rfind('"') != string::npos)
        return curtk;

    unsigned counter = 0;
    do {
        quote += curtk + " ";
        curr_token_idx++;
        counter++;
        curtk = curr_token();
    } while (curtk.rfind('"') == string::npos);

    quote += curtk;
    // Remove '/"'
    quote = quote.substr(0, quote.size() - 1);
    curr_token_idx -= counter;

    return quote;
}
void Tokenizer::advance_str_const()
{
    using std::string;

    auto curtk = curr_token();

    // Handle case where str is a single word string.
    if (curtk.rfind('"') != 0 && curtk.rfind('"') != string::npos) {
        curr_token_idx++;
        return;
    }

    do {
        curr_token_idx++;
        curtk = curr_token();
    } while (curtk.rfind('"') == string::npos);
    curr_token_idx++;
}

std::string Tokenizer::__debug_current_token__() { return curr_token(); }
