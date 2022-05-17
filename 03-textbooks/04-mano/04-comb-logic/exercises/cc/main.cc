#include "Vcirc_437.h"
#include "testbench.h"
#include "verilated.h"

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);

    TESTBENCH<Vcirc_437>* tb = new TESTBENCH<Vcirc_437>();

    // Tick the clk until we are done.
    while (!tb->done()) {
        tb->tick();
    }
    exit(EXIT_SUCCESS);
}
