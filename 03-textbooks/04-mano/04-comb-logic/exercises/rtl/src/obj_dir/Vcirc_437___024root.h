// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vcirc_437.h for the primary calling header

#ifndef VERILATED_VCIRC_437___024ROOT_H_
#define VERILATED_VCIRC_437___024ROOT_H_  // guard

#include "verilated.h"

class Vcirc_437__Syms;
VL_MODULE(Vcirc_437___024root) {
  public:

    // DESIGN SPECIFIC STATE
    VL_OUT8(Cout,0,0);
    VL_IN8(M,0,0);
    VL_OUT8(S[4],0,0);
    VL_IN8(A[4],0,0);
    VL_IN8(B[4],0,0);

    // INTERNAL VARIABLES
    Vcirc_437__Syms* vlSymsp;  // Symbol table

    // CONSTRUCTORS
    Vcirc_437___024root(const char* name);
    ~Vcirc_437___024root();
    VL_UNCOPYABLE(Vcirc_437___024root);

    // INTERNAL METHODS
    void __Vconfigure(Vcirc_437__Syms* symsp, bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
