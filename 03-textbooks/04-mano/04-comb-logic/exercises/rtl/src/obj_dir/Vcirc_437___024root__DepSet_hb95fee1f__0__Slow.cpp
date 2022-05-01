// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcirc_437.h for the primary calling header

#include "verilated.h"

#include "Vcirc_437___024root.h"

VL_ATTR_COLD void Vcirc_437___024root___eval_initial(Vcirc_437___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcirc_437__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcirc_437___024root___eval_initial\n"); );
}

void Vcirc_437___024root___combo__TOP__0(Vcirc_437___024root* vlSelf);

VL_ATTR_COLD void Vcirc_437___024root___eval_settle(Vcirc_437___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcirc_437__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcirc_437___024root___eval_settle\n"); );
    // Body
    Vcirc_437___024root___combo__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vcirc_437___024root___final(Vcirc_437___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcirc_437__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcirc_437___024root___final\n"); );
}

VL_ATTR_COLD void Vcirc_437___024root___ctor_var_reset(Vcirc_437___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcirc_437__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcirc_437___024root___ctor_var_reset\n"); );
    // Body
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        vlSelf->S[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->Cout = VL_RAND_RESET_I(1);
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        vlSelf->A[__Vi0] = VL_RAND_RESET_I(1);
    }
    for (int __Vi0=0; __Vi0<4; ++__Vi0) {
        vlSelf->B[__Vi0] = VL_RAND_RESET_I(1);
    }
    vlSelf->M = VL_RAND_RESET_I(1);
}
