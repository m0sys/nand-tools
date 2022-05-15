// Transational Unit for ALU INPUTS.
#pragma once
#include "Valu___024unit.h"
#include <cstdlib>

class AluInTx {
public:
    uint32_t a;
    uint32_t b;
    enum Op {
        add = Valu___024unit::operation_t::add,
        sub = Valu___024unit::operation_t::sub,
        nop = Valu___024unit::operation_t::nop,
    } op;
};

AluInTx* rnd_alu_in_tx()
{
    // 20% chance of gen a tx.
    if (rand() % 5 == 0) {
        AluInTx* tx = new AluInTx();
        tx->op = AluInTx::Op(rand() % 3);
        tx->a = rand() % 11 + 10; // gen a in range 10-20
        tx->b = rand() % 6;       // gen a in range 0-5
        return tx;
    } else
        return nullptr;
}
