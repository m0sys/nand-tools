#include "Vblinky.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include <stdio.h>
#include <stdlib.h>

void tick(int tcnt, Vblinky* tb, VerilatedVcdC* tfp)
{
    tb->eval();
    if (tfp) // dump 2ns before the tick
        tfp->dump(tcnt * 10 - 2);
    tb->i_clk = 1;
    tb->eval();
    if (tfp) // tick every 10ns
        tfp->dump(tcnt * 10);
    tb->i_clk = 0;
    tb->eval();

    if (tfp) { // trailing edge dump
        tfp->dump(tcnt * 10 + 5);
        tfp->flush();
    }
}

int main(int argc, char** argv)
{
    // Setup.
    Verilated::commandArgs(argc, argv);
    Vblinky* tb = new Vblinky;
    unsigned tick_cnt = 0;

    // Gen trace.
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    tb->trace(tfp, 99);
    tfp->open("blinky_trace.vcd");

    // Test.
    int last_led = tb->o_led;

    for (int k = 0; k < (1 << 20); k++) {
        // Toggle clk.
        tick(++tick_cnt, tb, tfp);

        // Print the LEDs vals anytime it changes.
        if (last_led != tb->o_led) {
            printf("k = %7d, ", k);
            printf("led = %d\n", tb->o_led);
        }
        last_led = tb->o_led;
    }
}
