#include "parser.h"
#include "../common/strpulate.h"
#include <algorithm>
#include <fstream>
#include <regex>

// TODO: debug libs - to remove
#include "../common/log.h"
#include <filesystem>
#include <iostream>

Parser::Parser(std::string fname)
{
	using std::cout;

	std::ifstream infile(fname);
	std::string line;

	// Check that fname exists before processing.
	if (!std::filesystem::exists(fname))
		throw std::logic_error("Parser: fname does not exist");

	while (std::getline(infile, line)) {
		if (is_comment(line) || is_white_space(line))
			continue;

		remove_backslash_r(line);
		remove_line_comment(line);
		cmds.push_back(line);
	}

	curr_cmd_idx = 0;
	infile.close();
}

bool Parser::is_comment(std::string line) { return line.substr(0, 2) == "//"; }

bool Parser::is_white_space(std::string line)
{
	//
	return std::all_of(line.begin(), line.end(), isspace);
}

void Parser::remove_backslash_r(std::string& line) { line.erase(line.size() - 1); }

void Parser::remove_line_comment(std::string& line)
{
	auto pos = line.find("//");
	if (pos != std::string::npos) {
		line.erase(pos);
	}
}

void Parser::advance()
{
	if (has_more_lines())
		curr_cmd_idx++;
	else
		throw std::out_of_range("Parser: Current index is at last instruction");
}

bool Parser::has_more_lines()
{
	//
	DEBUG_LOG("current_cmd_idx: " << curr_cmd_idx);
	return curr_cmd_idx < cmds.size();
}

CommandType Parser::command_type()
{
	using std::string;
	auto ccmd = curr_cmd();

	DEBUG_LOG("current command: " << curr_cmd());

	// Check for push command.
	auto push_pos = ccmd.find("push");
	if (push_pos != string::npos)
		return CT::C_PUSH;

	// Check for pop command.
	auto pop_pos = ccmd.find("pop");
	if (pop_pos != string::npos)
		return CT::C_POP;

	auto const rgx_arith = std::regex("(add|sub|neg|eq|gt|lt|and|or|not)");
	if (std::regex_match(ccmd.begin(), ccmd.end(), rgx_arith))
		return CT::C_ARITH;

	// Check for label command.
	auto label_pos = ccmd.find("label");
	if (label_pos != string::npos)
		return CT::C_LABEL;

	// Check for if-goto command.
	auto ifgoto_pos = ccmd.find("if-goto");
	if (ifgoto_pos != string::npos)
		return CT::C_IF;

	// Check for goto command.
	auto goto_pos = ccmd.find("goto");
	if (goto_pos != string::npos)
		return CT::C_GOTO;

	// Check for function command.
	auto func_pos = ccmd.find("function");
	if (func_pos != string::npos)
		return CT::C_FUNC;

	// Check for call command.
	auto call_pos = ccmd.find("call");
	if (call_pos != string::npos)
		return CT::C_CALL;

	// Check for ret command.
	auto ret_pos = ccmd.find("ret");
	if (ret_pos != string::npos)
		return CT::C_RET;

	return CT::UNKNOWN;
}

const std::string& Parser::curr_cmd() { return cmds[curr_cmd_idx]; }

std::string Parser::arg1()
{
	using std::string;
	auto ccmd = curr_cmd();
	auto splits = common::split(ccmd, ' ');
	if (is_push_type() || is_pop_type()) {
		return splits[1];
	};

	if (is_arith_type())
		return ccmd;

	if (is_label_type() || is_goto_type() || is_ifgoto_type())
		return splits[1];

	if (is_func_type() || is_call_type())
		return splits[1];

	if (is_ret_type())
		throw std::logic_error("Parser: ret type does not have arg1");

	return "";
}

bool Parser::is_push_type() { return command_type() == CT::C_PUSH; }
bool Parser::is_pop_type() { return command_type() == CT::C_POP; }
bool Parser::is_arith_type() { return command_type() == CT::C_ARITH; }
bool Parser::is_label_type() { return command_type() == CT::C_LABEL; }
bool Parser::is_goto_type() { return command_type() == CT::C_GOTO; }
bool Parser::is_ifgoto_type() { return command_type() == CT::C_IF; }
bool Parser::is_func_type() { return command_type() == CT::C_FUNC; }
bool Parser::is_call_type() { return command_type() == CT::C_CALL; }
bool Parser::is_ret_type() { return command_type() == CT::C_RET; }

int Parser::arg2()
{
	auto ccmd = curr_cmd();
	auto splits = common::split(ccmd, ' ');

	if (is_push_type() || is_pop_type())
		return std::stoi(splits[2]);

	else if (is_func_type() || is_call_type())
		return std::stoi(splits[2]);
	else
		throw std::logic_error("arg2 can only be called for push|pop|call|func cmds");
	return -1;
}

int Parser::num_cmds() { return cmds.size(); }
