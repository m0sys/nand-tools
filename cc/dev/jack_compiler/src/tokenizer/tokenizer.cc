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

        remove_backslash_r(line);
        remove_line_comment(line);
        rtrim(line);
        lines.push_back(line);
    }

    string tokn;
    for (const auto& l : lines) {
        std::stringstream ss(l);
        while (std::getline(ss, tokn, ' ')) {
            if (is_white_space(tokn))
                continue;

            // Handle method calls. e.g. game.run();
            if (tokn.find('.') != string::npos) {
                int p_pos = tokn.find('.');
                string lhs = tokn.substr(0, p_pos);
                string rhs = tokn.substr(p_pos + 1, tokn.size() - p_pos);
                LOG("TOKEN: " << tokn);
                LOG("LHS: " << lhs);
                LOG("RHS: " << rhs);
                LOG("RHS: meth = " << rhs.substr(0, rhs.size() - 3));
                tokns.push_back(lhs);
                tokns.push_back(string(1, '.'));
                tokns.push_back(rhs.substr(0, rhs.size() - 3));
                tokns.push_back(string(1, rhs[rhs.size() - 3]));
                tokns.push_back(string(1, rhs[rhs.size() - 2]));
                tokns.push_back(string(1, rhs[rhs.size() - 1]));
                continue;
            }

            // Handle end of statement ';'.
            if (tokn.find(';') != string::npos) {
                tokns.push_back(tokn.substr(0, tokn.size() - 1));
                tokns.push_back(string(1, ';'));
                continue;
            }

            // TODO: handle function declaration param lst.
            //
            // TODO: handle if condition.

            // if (tokn.find(';') != string::npos)
            //    continue;
            tokns.push_back(tokn);
        }
        LOG(l);
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
