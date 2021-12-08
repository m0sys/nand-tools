// Analyzer drives the syntax analysis of the Jack language.
// Date: 2021/12/08
// Author: m0sys

#pragma once
#include <string>
#include <vector>

class Analyzer {
public:
    Analyzer(std::string fname);
    void tokenize();
    void compile();

private:
    std::string fname;
    std::vector<std::string> paths;
    bool tokenized = false;
};
