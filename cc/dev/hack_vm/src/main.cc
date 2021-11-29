#include <iostream>

#include <stdexcept>

#define LOG(x) std::cout << x << "\n"

int main(int argc, char* argv[])
{
    if (argc < 1)
        throw std::logic_error("must provide fname as arg");

    LOG("Hello, VM translator!");
    LOG("Done VM translation");
}
