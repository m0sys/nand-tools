#include "prompt_input.h"
#include <iostream>
#include <stdexcept>

void prompt::ask_double(double& num, std::string msg)
{
	using std::cin;

	std::cout << msg;
	cin >> num;
	if (cin.fail()) {
		throw std::logic_error("Error: not a number");
	}
}

void prompt::ask_int(int& num, std::string msg)
{
	using std::cin;

	std::cout << msg;
	cin >> num;
	if (cin.fail()) {
		throw std::logic_error("Error: not a number");
	}
}

void prompt::ask_float(float& num, std::string msg)
{
	using std::cin;

	std::cout << msg;
	cin >> num;
	if (cin.fail()) {
		throw std::logic_error("Error: not a number");
	}
}
