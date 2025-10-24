module ram #(
    parameter   ADDRESS_WIDTH = 9,
                DATA_WIDTH = 8
) (
    input logic clk,
    input logic [ADDRESS_WIDTH-1:0] read_addr, write_addr,
    input logic [DATA_WIDTH-1:0] data_in,
    output logic [DATA_WIDTH-1:0] data_out
);

logic [DATA_WIDTH-1:0] ram_array [2**ADDRESS_WIDTH-1:0];

always_ff @(posedge clk)
    begin
        // Synchronous output
        ram_array[write_addr] <= data_in;
        data_out <= ram_array[read_addr];
    end

endmodule
