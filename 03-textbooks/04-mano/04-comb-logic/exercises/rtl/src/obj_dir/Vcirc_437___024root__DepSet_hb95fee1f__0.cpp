// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vcirc_437.h for the primary calling header

#include "verilated.h"

#include "Vcirc_437___024root.h"

VL_INLINE_OPT void Vcirc_437___024root___combo__TOP__0(Vcirc_437___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcirc_437__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcirc_437___024root___combo__TOP__0\n"); );
    // Init
    CData/*0:0*/ circ_437__DOT__w0;
    CData/*0:0*/ circ_437__DOT__w1;
    CData/*0:0*/ circ_437__DOT__w2;
    CData/*0:0*/ circ_437__DOT__w3;
    CData/*0:0*/ circ_437__DOT__C1;
    CData/*0:0*/ circ_437__DOT__C2;
    CData/*0:0*/ circ_437__DOT__C3;
    // Body
    circ_437__DOT__w3 = (vlSelf->B[3U] ^ (IData)(vlSelf->M));
    circ_437__DOT__w2 = (vlSelf->B[2U] ^ (IData)(vlSelf->M));
    circ_437__DOT__w1 = (vlSelf->B[1U] ^ (IData)(vlSelf->M));
    circ_437__DOT__w0 = (vlSelf->B[0U] ^ (IData)(vlSelf->M));
    vlSelf->S[0U] = (((IData)(circ_437__DOT__w0) ^ 
                      vlSelf->A[0U]) ^ (IData)(vlSelf->M));
    circ_437__DOT__C1 = (((IData)(circ_437__DOT__w0) 
                          & (vlSelf->A[0U] | (IData)(vlSelf->M))) 
                         | (vlSelf->A[0U] & (IData)(vlSelf->M)));
    vlSelf->S[1U] = (((IData)(circ_437__DOT__w1) ^ 
                      vlSelf->A[1U]) ^ (IData)(circ_437__DOT__C1));
    circ_437__DOT__C2 = (((IData)(circ_437__DOT__w1) 
                          & (vlSelf->A[1U] | (IData)(circ_437__DOT__C1))) 
                         | (vlSelf->A[1U] & (IData)(circ_437__DOT__C1)));
    vlSelf->S[2U] = (((IData)(circ_437__DOT__w2) ^ 
                      vlSelf->A[2U]) ^ (IData)(circ_437__DOT__C2));
    circ_437__DOT__C3 = (((IData)(circ_437__DOT__w2) 
                          & (vlSelf->A[2U] | (IData)(circ_437__DOT__C2))) 
                         | (vlSelf->A[2U] & (IData)(circ_437__DOT__C2)));
    vlSelf->Cout = (((IData)(circ_437__DOT__w3) & (
                                                   vlSelf->A
                                                   [3U] 
                                                   | (IData)(circ_437__DOT__C3))) 
                    | (vlSelf->A[3U] & (IData)(circ_437__DOT__C3)));
    vlSelf->S[3U] = (((IData)(circ_437__DOT__w3) ^ 
                      vlSelf->A[3U]) ^ (IData)(circ_437__DOT__C3));
}

void Vcirc_437___024root___eval(Vcirc_437___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcirc_437__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcirc_437___024root___eval\n"); );
    // Body
    Vcirc_437___024root___combo__TOP__0(vlSelf);
}

#ifdef VL_DEBUG
void Vcirc_437___024root___eval_debug_assertions(Vcirc_437___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vcirc_437__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vcirc_437___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->M & 0xfeU))) {
        Verilated::overWidthError("M");}
}
#endif  // VL_DEBUG
