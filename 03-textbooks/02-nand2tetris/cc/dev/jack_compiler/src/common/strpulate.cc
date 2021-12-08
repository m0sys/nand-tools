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
