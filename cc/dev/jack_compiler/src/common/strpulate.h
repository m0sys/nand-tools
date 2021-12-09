// String manipulation functions.
// Date: 2021/11/29
// Author: m0sys

#pragma once
#include <string>
#include <vector>

namespace common {
std::vector<std::string> split(const std::string& s, char delim);
std::string& ltrim(std::string& s, const char* t = " \t\n\r\f\v");
std::string& rtrim(std::string& s, const char* t = " \t\n\r\f\v");
std::string& trim(std::string& s, const char* t = " \t\n\r\f\v");
}
