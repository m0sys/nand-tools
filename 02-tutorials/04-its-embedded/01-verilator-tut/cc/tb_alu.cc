#include "Valu.h"
#include "Valu___024unit.h"
#include "alu_in_drv.h"
#include "alu_in_mon.h"
#include "alu_in_tx.h"
#include "alu_out_mon.h"
#include "alu_scb.h"
#include "log.h"
#include <cstdlib>
#include <iostream>
#include <stdlib.h>
#include <verilated.h>
#include <verilated_vcd_c.h>

#define MAX_SIM_TIME 300
#define VERIF_START_TIME 7
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

    AluInTx* tx;
    AluInDrv* drv = new AluInDrv(dut);
    AluScb* scb = new AluScb();
    AluInMon* in_mon = new AluInMon(dut, scb);
    AluOutMon* out_mon = new AluOutMon(dut, scb);
    while (sim_time < MAX_SIM_TIME) {
        dut_rst(dut, sim_time);
        dut->clk ^= 1;
        dut->eval();

        if (dut->clk == 1) {
            if (sim_time >= VERIF_START_TIME) {
                tx = rnd_alu_in_tx();
                drv->drive(tx);
                in_mon->monitor();
                out_mon->monitor(sim_time);
            }
        }
        m_trace->dump(sim_time);
        sim_time++;
    }

    m_trace->close();
    delete dut;
    delete out_mon;
    delete in_mon;
    delete scb;
    delete drv;
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
