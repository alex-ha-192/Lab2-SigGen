#include "Vsinegen.h"
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "vbuddy.cpp"

int main(int argc, char **argv, char **env) {
    int i;
    int clk;

    Verilated::commandArgs(argc, argv);

    Vsinegen* sinegen = new Vsinegen;
    
    Verilated::traceEverOn(true);
    VerilatedVcdC* tfp = new VerilatedVcdC;
    sinegen->trace(tfp, 99);
    tfp->open("sinegen.vcd");

    if (vbdOpen() != 1) return (-1);
    vbdHeader("L2T1: Sine");
    vbdSetMode(0);

    sinegen->clk = 1;
    sinegen->rst = 1;
    sinegen->en = 1;
    sinegen->incr = 2;
    sinegen->offset = 1;

    const int CLOCK_COUNT = 1000000;
    for (i = 0; i < CLOCK_COUNT; i++) {
        for (clk = 0; clk < 2; clk++) {
            tfp->dump(2 * i + clk);
            sinegen->clk = !sinegen->clk;
            sinegen->eval();
        }
        
        if (sinegen->en) {
            vbdPlot((int) sinegen->dout1, 0, 255);
            vbdPlot((int) sinegen->dout2, 0, 255);
        }
        vbdCycle(i + 1);

        sinegen->rst = 0;
        sinegen->en = !vbdFlag();
        sinegen->offset = vbdValue();

        if (Verilated::gotFinish() || vbdGetkey() == 'q') {
            exit(0);
        }
    }

    vbdClose();
    tfp->close();
    exit(0);
}