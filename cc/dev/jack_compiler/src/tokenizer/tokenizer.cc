#include "tokenizer.h"
#include "../common/log.h"

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
        // rtrim(line);
        lines.push_back(line);
    }

    string tokn;
    for (const auto& l : lines) {
        LOG(l);
        std::stringstream ss(l);
        while (std::getline(ss, tokn, ' ')) {
            if (is_white_space(tokn))
                continue;

            bool is_meth_call = tokn.find('.') != string::npos;
            bool has_left_paren = tokn.find('(') != string::npos;
            bool has_right_paren = tokn.find(')') != string::npos;
            bool has_comma = tokn.find(',') != string::npos;
            bool has_semi = tokn.find(';') != string::npos;
            bool is_exception = is_meth_call || has_left_paren || has_right_paren || has_comma || has_semi;

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
                if (rest.size() != 0)
                    tokns.push_back(rest);

                continue;
            }

            tokns.push_back(tokn);
        }
    }

    for (const auto& t : tokns)
        LOG(t);

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
void Tokenizer::rtrim(std::string& s)
{
    s.erase(std::find_if(s.rbegin(), s.rend(), [](unsigned char ch) { return !std::isspace(ch); }).base(), s.end());
}

bool Tokenizer::has_more_tokens() { return false; }

void Tokenizer::advance() { }

TokenType Tokenizer::token_type() { return TokenType::INT_CONST; }

Kwd Tokenizer::keyword() { return Kwd::N; }

char Tokenizer::symbol() { return 'c'; }

std::string Tokenizer::id() { return ""; }

int Tokenizer::int_val() { return -1; }

std::string Tokenizer::str_val() { return ""; }
