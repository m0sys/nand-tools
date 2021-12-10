// Analyzer drives the syntax analysis of the Jack language.
// Date: 2021/12/08
// Author: m0sys

#pragma once
#include <string>
#include <vector>

class Analyzer {
public:
    Analyzer(std::string fname);

    // Generates tokens for each .jack file and stores them in individual XML files.
    void tokenize();

    // Generates program structured XML for each .jack file.
    void compile();

private:
    std::string create_ext_fname(const std::string& jack_fname, const std::string& ext, bool T = false);

private:
    std::string fname;
    std::vector<std::string> paths;
    bool tokenized = false;
};
