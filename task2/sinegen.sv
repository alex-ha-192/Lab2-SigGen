module sinegen(
    input logic [7:0] incr, offset,
    input logic rst, en, clk,
    output logic [7:0] dout1, dout2
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
        .offset (offset),
        .dout1 (dout1),
        .dout2 (dout2)
    );

endmodule
