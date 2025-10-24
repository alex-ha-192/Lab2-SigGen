module counter #(
    parameter ADDRESS_WIDTH = 8
) (
    input logic [ADDRESS_WIDTH-1:0] incr,
    input logic rst, en, clk,
    output logic [ADDRESS_WIDTH-1:0] count
);

    always_ff @(posedge clk)
        if (rst) count <= 0;
        else if (en) count <= count + incr;
        else count <= count;
endmodule
