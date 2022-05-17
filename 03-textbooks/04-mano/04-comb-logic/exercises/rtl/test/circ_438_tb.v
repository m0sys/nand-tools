// Test bench stimulus for circ_438.

`timescale 1ns / 1ns
`include "rtl/src/circ_438.v"

module circ_438_tb;
    wire [3:0] t_mout;
    reg        t_enb;
    reg        t_sel;
    reg [3:0]  t_A;
    reg [3:0]  t_B;
    parameter stop_time = 100;

    circ_438 dut (
        // OUTPUTS
        .mout(t_mout)

        // INPUTS
        ,.enb(t_enb)
        ,.sel(t_sel)
        ,.A(t_A)
        ,.B(t_B)
    );

    initial # stop_time $finish;

    initial begin
        $dumpfile("waveform_circ438.vcd");
        $dumpvars(0, circ_438_tb);

        // Asserted enable should givv 0000 regardless of other inputs.
        t_enb = 1; t_sel = 0; t_A = 4'b0001; t_B = 4'b0010;

        #10 t_enb = 1; t_sel = 1; t_A = 4'b0001; t_B = 4'b0010;

        // Should select A. 
        #10 t_enb = 0; t_sel = 0; t_A = 4'b0001; t_B = 4'b0010;

        // Should select B. 
        #10 t_enb = 0; t_sel = 1; t_A = 4'b0001; t_B = 4'b0010;

    end

    initial begin
        $monitor ("time =", $time, ": A=%b, B=%b, enb=%b, sel=%b, mout=%b", t_A, t_B, t_enb, t_sel, t_mout);
    end

endmodule
