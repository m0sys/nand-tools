// Monitor ALU OUTPUT.
#pragma once
#include "Valu.h"
#include "Valu___024unit.h"
#include "alu_scb.h"

class AluOutMon {
private:
    Valu* dut;
    AluScb* scb;

public:
    AluOutMon(Valu* dut, AluScb* scb)
        : dut { dut }
        , scb { scb }
    {
    }

    void monitor(vluint64_t& sim_time)
    {
        if (dut->out_valid == 1) {
            AluOutTx* tx = new AluOutTx();
            tx->out = dut->out;

            scb->write_out(tx, sim_time);
        }
    }
};
