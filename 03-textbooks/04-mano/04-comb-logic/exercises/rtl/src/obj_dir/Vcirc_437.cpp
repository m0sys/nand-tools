// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vcirc_437.h"
#include "Vcirc_437__Syms.h"

//============================================================
// Constructors

Vcirc_437::Vcirc_437(VerilatedContext* _vcontextp__, const char* _vcname__)
    : vlSymsp{new Vcirc_437__Syms(_vcontextp__, _vcname__, this)}
    , Cout{vlSymsp->TOP.Cout}
    , M{vlSymsp->TOP.M}
    , S{vlSymsp->TOP.S}
    , A{vlSymsp->TOP.A}
    , B{vlSymsp->TOP.B}
    , rootp{&(vlSymsp->TOP)}
{
}

Vcirc_437::Vcirc_437(const char* _vcname__)
    : Vcirc_437(nullptr, _vcname__)
{
}

//============================================================
// Destructor

Vcirc_437::~Vcirc_437() {
    delete vlSymsp;
}

//============================================================
// Evaluation loop

void Vcirc_437___024root___eval_initial(Vcirc_437___024root* vlSelf);
void Vcirc_437___024root___eval_settle(Vcirc_437___024root* vlSelf);
void Vcirc_437___024root___eval(Vcirc_437___024root* vlSelf);
#ifdef VL_DEBUG
void Vcirc_437___024root___eval_debug_assertions(Vcirc_437___024root* vlSelf);
#endif  // VL_DEBUG
void Vcirc_437___024root___final(Vcirc_437___024root* vlSelf);

static void _eval_initial_loop(Vcirc_437__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    Vcirc_437___024root___eval_initial(&(vlSymsp->TOP));
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial loop\n"););
        Vcirc_437___024root___eval_settle(&(vlSymsp->TOP));
        Vcirc_437___024root___eval(&(vlSymsp->TOP));
    } while (0);
}

void Vcirc_437::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vcirc_437::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vcirc_437___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        Vcirc_437___024root___eval(&(vlSymsp->TOP));
    } while (0);
    // Evaluate cleanup
}

//============================================================
// Utilities

VerilatedContext* Vcirc_437::contextp() const {
    return vlSymsp->_vm_contextp__;
}

const char* Vcirc_437::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vcirc_437::final() {
    Vcirc_437___024root___final(&(vlSymsp->TOP));
}
