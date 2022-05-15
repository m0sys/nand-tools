// ALU IN Driver.
#pragma once
#include "Valu.h"
#include "alu_in_tx.h"

class AluInDrv {
private:
    Valu* dut;

public:
    AluInDrv(Valu* dut)
        : dut { dut }
    {
    }

    void drive(AluInTx* tx)
    {
        // Always start with in_valid set to 0, and later set to 1.
        dut->in_valid = 0;

        // Don't drive anything if tx is null.
        if (tx != nullptr) {
            if (tx->op != AluInTx::nop) {
                dut->in_valid = 1;
                dut->op_in = tx->op;
                dut->a_in = tx->a;
                dut->b_in = tx->b;
            }

            delete tx;
        }
    }
};
