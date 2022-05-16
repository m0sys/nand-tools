// Test bench stimulus for circ_437.

`timescale 1ns / 1ns
`include "rtl/src/circ_437.v"

module circ_437_tb;
    wire [3:0] t_S;
    wire       t_Cout;
    reg  [3:0] t_A;
    reg  [3:0] t_B;
    reg        t_M;
    parameter stop_time = 200;

    circ_437 dut (
        // OUTPUTS
        .S(t_S)
        ,.Cout(t_Cout)

        // INPUTS
        ,.A(t_A)
        ,.B(t_B)
        ,.M(t_M)
    );

    initial # stop_time $finish;
    
    initial begin
        $dumpfile("waveform.vcd");
        $dumpvars(0, circ_437_tb);

        // Add 0 and 0 - should be 0.
        t_A = 4'b0; t_B = 4'b0; t_M = 0; 

        // Add 1 and 2 - should be 3.
        #10 t_A = 4'b0001; t_B = 4'b0001; t_M = 0;

        // Add 7 and 8 - should be 15.
        #10 t_A = 4'b0111; t_B = 4'b1000; t_M = 0;

        // 4 + 4 = 8.
        #10 t_A = 4'b0100; t_B = 4'b0100; t_M = 0;

        // 4 - 4 = 0.
        #10 t_A = 4'b0100; t_B = 4'b0100; t_M = 1;

        // 4 - 5 = -1.
        #10 t_A = 4'b0100; t_B = 4'b0101; t_M = 1;
    end

endmodule
