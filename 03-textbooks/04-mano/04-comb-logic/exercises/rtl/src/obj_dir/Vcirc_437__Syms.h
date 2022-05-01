// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VCIRC_437__SYMS_H_
#define VERILATED_VCIRC_437__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vcirc_437.h"

// INCLUDE MODULE CLASSES
#include "Vcirc_437___024root.h"

// SYMS CLASS (contains all model state)
class Vcirc_437__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vcirc_437* const __Vm_modelp;
    bool __Vm_didInit = false;

    // MODULE INSTANCE STATE
    Vcirc_437___024root            TOP;

    // CONSTRUCTORS
    Vcirc_437__Syms(VerilatedContext* contextp, const char* namep, Vcirc_437* modelp);
    ~Vcirc_437__Syms();

    // METHODS
    const char* name() { return TOP.name(); }
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
