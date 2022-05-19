// Test bench stimulus for circ_456.

`timescale 1ns / 1ns
`include "rtl/src/circ_456.v"

module circ_456_tb;
    wire t_y_o;
    reg [3:0] t_A_i4;
    reg [3:0] t_B_i4;
    parameter stop_time = 100;

    circ_456 dut (
        // OUTPUTS
        .y_o(t_y_o)

        // INPUTS
        ,.A_i4(t_A_i4)
        ,.B_i4(t_B_i4)
    );

    initial # stop_time $finish;

    initial begin
        $dumpfile("waveform_circ456.vcd");
        $dumpvars(0, circ_456_tb);

        // When both zero - should be 1.
        t_A_i4 = 4'b0; t_B_i4 = 4'b0;

        // When both 15 - should be 1.
        #10 t_A_i4 = 4'hF; t_B_i4 = 4'hF;

        // When A is 1 and B is 2 - should be 0.
        #10 t_A_i4 = 4'b0001; t_B_i4 = 4'b0010;

        // When A is 2 and B is 2 - should be 1.
        #10 t_A_i4 = 4'b0010; t_B_i4 = 4'b0010;

        // When A is 2 and B is 3 - should be 0.
        #10 t_A_i4 = 4'b0010; t_B_i4 = 4'b0011;
    end



endmodule
