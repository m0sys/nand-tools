#include "Vthruwire.h"
#include "verilated.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    Verilated::commandArgs(argc, argv);

    // Init design.
    Vthruwire* tb = new Vthruwire;

    // Run design thru 20 timesteps.
    for (int k = 0; k < 20; k++) {
        // Set the switch input to LSB of our step.
        tb->i_sw = k & 1;
        tb->eval();

        // Print out results.
        printf("k = %2d, ", k);
        printf("sw = %d, ", tb->i_sw);
        printf("led = %d\n", tb->o_led);
    }
}
