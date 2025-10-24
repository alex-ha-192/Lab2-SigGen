module sinegen(
    input logic [7:0] incr,
    input logic rst, en, clk,
    output logic [7:0] dout
);

    logic [7:0] addr;

    counter sinegen_counter (
        .incr (incr),
        .rst (rst),
        .en (en),
        .clk (clk),
        .count (addr)
    );

    rom sinegen_rom (
        .clk (clk),
        .addr (addr),
        .dout (dout)
    );

endmodule
