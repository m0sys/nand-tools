#pragma once
#include <string>

namespace prompt {

void ask_double(double& num, std::string msg);
void ask_int(int& num, std::string msg);
void ask_float(float& num, std::string msg);
}
