#pragma once
#include "Valu.h"
#include "alu_in_tx.h"
#include "alu_scb.h"

class AluInMon {
private:
    Valu* dut;
    AluScb* scb;

public:
    AluInMon(Valu* dut, AluScb* scb)
        : dut { dut }
        , scb { scb }
    {
    }

    void monitor()
    {
        if (dut->in_valid == 1) {
            AluInTx* tx = new AluInTx();
            tx->op = AluInTx::Op(dut->op_in);
            tx->a = dut->a_in;
            tx->b = dut->b_in;

            scb->write_in(tx);
        }
    }
};
