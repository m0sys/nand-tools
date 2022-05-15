#include "Valu.h"
#include "Valu___024unit.h"
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <verilated.h>
#include <verilated_vcd_c.h>

#define LOG(x) std::cout << x << "\n"

#define MAX_SIM_TIME 300
vluint64_t sim_time = 0;
vluint64_t posedge_cnt = 0;

// Decls
void dut_rst(Valu* dut, vluint64_t& sim_time);
void check_out_valid(Valu* dut, vluint64_t& sim_time);
void set_rnd_out_valid(Valu* dut, vluint64_t& sim_time);

int main(int argc, char** argv, char** env)
{
    srand(time(NULL));

    Verilated::commandArgs(argc, argv);

    Valu* dut = new Valu;
    Verilated::traceEverOn(true);
    VerilatedVcdC* m_trace = new VerilatedVcdC;
    dut->trace(m_trace, 5);
    m_trace->open("waveform.vcd");

    while (sim_time < MAX_SIM_TIME) {
        dut_rst(dut, sim_time);

        dut->clk ^= 1;
        dut->eval();

        if (dut->clk == 1) {
            posedge_cnt++;
            switch (posedge_cnt) {
            case 10:
                dut->in_valid = 1;
                ;
                dut->a_in = 5;
                dut->b_in = 3;
                dut->op_in = Valu___024unit::operation_t::add;
                break;

            case 12:
                if (dut->out != 8)
                    LOG("Addition failed @ " << sim_time);
                break;

            case 20:
                dut->in_valid = 1;
                ;
                dut->a_in = 5;
                dut->b_in = 3;
                dut->op_in = Valu___024unit::operation_t::sub;
                break;

            case 22:
                if (dut->out != 2)
                    LOG("Substration failed @ " << sim_time);
                break;
            }
            check_out_valid(dut, sim_time);
        }
        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    exit(EXIT_SUCCESS);
}

void dut_rst(Valu* dut, vluint64_t& sim_time)
{
    dut->rst = 0;
    if (sim_time > 1 && sim_time < 5) {
        dut->rst = 1;
        dut->a_in = 0;
        dut->b_in = 0;
        dut->op_in = 0;
        dut->in_valid = 0;
    }
}

#define VERIF_START_TIME 7
void check_out_valid(Valu* dut, vluint64_t& sim_time)
{
    static unsigned char in_valid = 0;      // in_valid from cur cycle
    static unsigned char in_valid_d = 0;    // delayed in_valid
    static unsigned char out_valid_exp = 0; // expected out_valid val

    if (sim_time >= VERIF_START_TIME) {
        out_valid_exp = in_valid_d;
        in_valid_d = in_valid;
        in_valid = dut->in_valid;

        if (out_valid_exp != dut->out_valid) {
            LOG("ERROR: out_valid mismatch, exp: " << (int)(out_valid_exp) << " recv: " << (int)(dut->out_valid) << " simtime: " << sim_time);
        }
    }
}

void set_rnd_out_valid(Valu* dut, vluint64_t& sim_time)
{
    if (sim_time >= VERIF_START_TIME)
        dut->in_valid = rand() % 2; // gen values 0 and 1
}
