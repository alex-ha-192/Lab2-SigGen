// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vsigdelay.h for the primary calling header

#include "verilated.h"

#include "Vsigdelay___024root.h"

VL_INLINE_OPT void Vsigdelay___024root___sequent__TOP__0(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___sequent__TOP__0\n"); );
    // Init
    SData/*8:0*/ __Vdly__sigdelay__DOT__write_addr;
    SData/*8:0*/ __Vdlyvdim0__sigdelay__DOT__signal_ram__DOT__ram_array__v0;
    CData/*7:0*/ __Vdlyvval__sigdelay__DOT__signal_ram__DOT__ram_array__v0;
    // Body
    __Vdly__sigdelay__DOT__write_addr = vlSelf->sigdelay__DOT__write_addr;
    __Vdlyvval__sigdelay__DOT__signal_ram__DOT__ram_array__v0 
        = vlSelf->mic_signal;
    __Vdlyvdim0__sigdelay__DOT__signal_ram__DOT__ram_array__v0 
        = vlSelf->sigdelay__DOT__write_addr;
    vlSelf->delayed_signal = vlSelf->sigdelay__DOT__signal_ram__DOT__ram_array
        [vlSelf->sigdelay__DOT__read_addr];
    vlSelf->sigdelay__DOT__signal_ram__DOT__ram_array[__Vdlyvdim0__sigdelay__DOT__signal_ram__DOT__ram_array__v0] 
        = __Vdlyvval__sigdelay__DOT__signal_ram__DOT__ram_array__v0;
    __Vdly__sigdelay__DOT__write_addr = (0x1ffU & ((IData)(1U) 
                                                   + (IData)(vlSelf->sigdelay__DOT__write_addr)));
    vlSelf->sigdelay__DOT__read_addr = (0x1ffU & (((IData)(1U) 
                                                   + (IData)(vlSelf->sigdelay__DOT__write_addr)) 
                                                  - (IData)(vlSelf->offset)));
    vlSelf->sigdelay__DOT__write_addr = __Vdly__sigdelay__DOT__write_addr;
}

void Vsigdelay___024root___eval(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vsigdelay___024root___sequent__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vsigdelay___024root___eval_debug_assertions(Vsigdelay___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vsigdelay__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vsigdelay___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->wr & 0xfe00U))) {
        Verilated::overWidthError("wr");}
    if (VL_UNLIKELY((vlSelf->rd & 0xfe00U))) {
        Verilated::overWidthError("rd");}
    if (VL_UNLIKELY((vlSelf->offset & 0xfe00U))) {
        Verilated::overWidthError("offset");}
    if (VL_UNLIKELY((vlSelf->__pinNumber8 & 0xfeU))) {
        Verilated::overWidthError("__pinNumber8");}
}
#endif  // VL_DEBUG
