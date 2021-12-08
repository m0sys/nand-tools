#include "analyzer.h"
#include <filesystem>
#include <stdexcept>

Analyzer::Analyzer(std::string fname)
    : fname { fname }
{
    namespace fs = std::filesystem;
    // Check that fname exists before processing.
    if (!fs::exists(fname))
        throw std::logic_error("fname does not exist");
}

void Analyzer::tokenize() { }
void Analyzer::compile() { }
