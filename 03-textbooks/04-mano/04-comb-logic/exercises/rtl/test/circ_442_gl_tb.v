// Test bench stimulus for circ_442_gl.

`timescale 1ns / 1ns
`include "rtl/src/circ_442_gl.v"

module circ_442_gl_tb;
    wire [3:0] t_ex_o4;
    reg  [3:0] t_bcd_i4;

    parameter stop_time = 150;

    circ_442_gl dut (
        // OUTPUTS
        .ex_o4(t_ex_o4)

        // INPUTS
        ,.bcd_i4(t_bcd_i4)
    );

    initial # stop_time $finish;

    // Register to cnt from 4bit 0 to 9.
    reg [3:0] cnt_l4 = 4'b0000;
    integer i;

    initial begin
        $dumpfile("waveform_circ442_gl.vcd");
        $dumpvars(0, circ_442_gl_tb);

        for (i=0; i < 10; i++) begin
            #10 t_bcd_i4 = cnt_l4;
            cnt_l4 = cnt_l4 + 1;
        end
        // // Check 0000 bcd - should be 0011
        // t_bcd_i4 = 4'b0000;

        // // Check 0001 bcd - should be 0100
        // #10 t_bcd_i4 = 4'b0001;

        // // Check 0010 bcd - should be 0101
        // #10 t_bcd_i4 = 4'b0010;

        // // Check 0011 bcd - should be 0110
        // #10 t_bcd_i4 = 4'b0011;

    end
endmodule
