#pragma once
#include "Valu___024unit.h"
#include "alu_in_tx.h"
#include "alu_out_tx.h"
#include "log.h"
#include <deque>

#define LOG_FATAL(x) LOG("Fatal Error in AluScb: " << x);

class AluScb {
private:
    std::deque<AluInTx*> in_q;

public:
    // Input interface for monitor port.
    void write_in(AluInTx* tx) { in_q.push_back(tx); }

    // Output interface for monitor port.
    void write_out(AluOutTx* tx, vluint64_t& sim_time)
    {
        if (in_q.empty()) {
            LOG_FATAL("empty AluInTx queue");
            exit(1);
        }

        // Grap tx itmm from front of input queue.
        AluInTx* in;
        in = in_q.front();
        in_q.pop_front();

        switch (in->op) {
        // A valid signal should not be created at the output when nop.
        case AluInTx::nop:
            LOG_FATAL("recieved  NOP in input");
            exit(1);
            break;

        case AluInTx::add:
            if (in->a + in->b != tx->out) {
                LOG("");
                LOG("AluScb: add mismatch");
                LOG(" Expected: " << (in->a + in->b));
                LOG(" Actual: " << tx->out);
                LOG(" Simtime: " << sim_time);
            }
            break;

        case AluInTx::sub:
            if (in->a - in->b != tx->out) {
                LOG("");
                LOG("AluScb: sub mismatch");
                LOG(" Expected: " << (in->a - in->b));
                LOG(" Actual: " << tx->out);
                LOG(" Simtime: " << sim_time);
            }
            break;
        }

        delete in;
        delete tx;
    }
};
