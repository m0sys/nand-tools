#include "parser/parser.h"
#include <iostream>
#include <regex>
#include <stdexcept>
#include <string>

#define LOG(x) std::cout << x << "\n"

void regex_playground();

int main(int argc, char* argv[])
{
    if (argc < 1)
        throw std::logic_error("must provide fname as arg");

    LOG("Hello, VM translator!");

    regex_playground();
    Parser("../../../projects/07/MemoryAccess/BasicTest/BasicTest.vm");
    LOG("Done VM translation");
}

void regex_playground()
{
    using std::cout;
    using std::string;

    auto const rgx = std::regex("(add|sub|neg|eq|gt|lt|and|or|not)");

    string s1 = "add";
    string s2 = "sub";
    string s3 = "lt";

    cout << s1 << ": " << std::regex_match(s1.begin(), s1.end(), rgx) << "\n";
    cout << s2 << ": " << std::regex_match(s2.begin(), s2.end(), rgx) << "\n";
    cout << s3 << ": " << std::regex_match(s3.begin(), s3.end(), rgx) << "\n";
}
