#include "Vmaskbus.h"
#include "verilated.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);

    // Init design.
    Vmaskbus* tb = new Vmaskbus;

    // Run design thru 20 timesteps.
    for (int k = 0; k < 20; k++) {
        // Set the switch input to bot 9 bits of counter.
        tb->i_sw = k & 0x1ff;
        tb->eval();

        // Print out results.
        printf("k = %2d, ", k);
        printf("sw = %3x, ", tb->i_sw);
        printf("led = %3x\n", tb->o_led);
    }
}
