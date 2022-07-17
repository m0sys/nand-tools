#include "strpulate.h"
#include <sstream>
#include <string>
#include <vector>

template <typename Out> void split(const std::string& s, char delim, Out res);

std::vector<std::string> common::split(const std::string& s, char delim)
{
    std::vector<std::string> elems;
    ::split(s, delim, std::back_inserter(elems));
    return elems;
}

template <typename Out> void split(const std::string& s, char delim, Out res)
{
    std::istringstream iss(s);
    std::string item;
    while (std::getline(iss, item, delim)) {
        *res++ = item;
    }
}

// trim from left
std::string& common::ltrim(std::string& s, const char* t)
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

// trim from right
std::string& common::rtrim(std::string& s, const char* t)
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

// trim from left & right
std::string& common::trim(std::string& s, const char* t) { return ltrim(rtrim(s, t), t); }
