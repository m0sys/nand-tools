// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vthru_wire.h for the primary calling header

#include "Vthru_wire.h"
#include "Vthru_wire__Syms.h"

//==========

VL_CTOR_IMP(Vthru_wire) {
    Vthru_wire__Syms* __restrict vlSymsp = __VlSymsp = new Vthru_wire__Syms(this, name());
    Vthru_wire* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vthru_wire::__Vconfigure(Vthru_wire__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vthru_wire::~Vthru_wire() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vthru_wire::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vthru_wire::eval\n"); );
    Vthru_wire__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vthru_wire* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("verilog_tutorial.srcs/sources_1/new/thru_wire.v", 23, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vthru_wire::_eval_initial_loop(Vthru_wire__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("verilog_tutorial.srcs/sources_1/new/thru_wire.v", 23, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vthru_wire::_combo__TOP__1(Vthru_wire__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vthru_wire::_combo__TOP__1\n"); );
    Vthru_wire* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->o_led = vlTOPp->i_sw;
}

void Vthru_wire::_eval(Vthru_wire__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vthru_wire::_eval\n"); );
    Vthru_wire* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vthru_wire::_eval_initial(Vthru_wire__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vthru_wire::_eval_initial\n"); );
    Vthru_wire* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vthru_wire::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vthru_wire::final\n"); );
    // Variables
    Vthru_wire__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vthru_wire* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vthru_wire::_eval_settle(Vthru_wire__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vthru_wire::_eval_settle\n"); );
    Vthru_wire* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vthru_wire::_change_request(Vthru_wire__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vthru_wire::_change_request\n"); );
    Vthru_wire* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vthru_wire::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vthru_wire::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((i_sw & 0xfeU))) {
        Verilated::overWidthError("i_sw");}
}
#endif  // VL_DEBUG

void Vthru_wire::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vthru_wire::_ctor_var_reset\n"); );
    // Body
    i_sw = VL_RAND_RESET_I(1);
    o_led = VL_RAND_RESET_I(1);
}
