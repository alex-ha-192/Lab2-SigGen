module sigdelay #(
    parameter ADDRESS_WIDTH = 9,
              DATA_WIDTH = 8

) (
    input logic clk, // clk
    input logic rst, // rst
    input logic [ADDRESS_WIDTH-1:0] wr, // wr address
    input logic [ADDRESS_WIDTH-1:0] rd, // rd address
    input logic [ADDRESS_WIDTH-1:0] offset, // offset
    input logic [DATA_WIDTH-1:0] mic_signal, // mic_signal

    output logic [DATA_WIDTH-1:0] delayed_signal, // OUT delayed_signal
);

logic [ADDRESS_WIDTH-1:0] read_addr, write_addr;

initial begin
    read_addr = rd;
    write_addr = rd - offset;
end

// MIC_SIGNAL GETS WRITTEN INTO RAM
// DELAYED_SIGNAL GETS READ FROM RAM

ram signal_ram (
    // IN
    .clk (clk),
    .read_addr (read_addr),
    .write_addr (write_addr),
    .data_in (mic_signal),
    // OUT
    .data_out (delayed_signal)
);

always_ff @(posedge clk)
    begin
        write_addr <= write_addr + 1;
        read_addr <= (write_addr + 1) - offset;
    end

endmodule
