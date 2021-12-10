#include "analyzer/analyzer.h"
#include "common/log.h"

int main(int argc, char* argv[])
{
    if (argc < 1)
        throw std::logic_error("must provide fname as arg");

    LOG("Hello, JACK Compiler!");

    Analyzer a(argv[1]);
    a.compile();

    LOG("Done JACK Compilation");
}
