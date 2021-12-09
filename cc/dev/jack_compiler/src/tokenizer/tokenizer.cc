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
        // remove_line_comment(line);
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
            bool is_string_const = tokn.find('"') != string::npos;

            // clang-format off
            bool is_exception = is_meth_call ||
                                has_left_paren ||
                                has_right_paren ||
                                has_left_bra ||
                                has_right_bra ||
                                has_comma ||
                                has_semi ||
                                is_string_const;
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
    if (has_more_tokens())
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

Kwd Tokenizer::keyword() { return Kwd::N; }

char Tokenizer::symbol() { return 'c'; }

std::string Tokenizer::id() { return ""; }

int Tokenizer::int_val() { return -1; }

std::string Tokenizer::str_val() { return ""; }
