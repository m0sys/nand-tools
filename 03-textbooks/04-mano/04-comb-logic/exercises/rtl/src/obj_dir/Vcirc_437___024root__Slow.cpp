// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcirc_437.h for the primary calling header

#include "verilated.h"

#include "Vcirc_437__Syms.h"
#include "Vcirc_437___024root.h"

void Vcirc_437___024root___ctor_var_reset(Vcirc_437___024root* vlSelf);

Vcirc_437___024root::Vcirc_437___024root(const char* _vcname__)
    : VerilatedModule(_vcname__)
 {
    // Reset structure values
    Vcirc_437___024root___ctor_var_reset(this);
}

void Vcirc_437___024root::__Vconfigure(Vcirc_437__Syms* _vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->vlSymsp = _vlSymsp;
}

Vcirc_437___024root::~Vcirc_437___024root() {
}
