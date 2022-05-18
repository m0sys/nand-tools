// Test bench stimulus for circ_442_df.

`timescale 1ns / 1ns
`include "rtl/src/circ_442_df.v"

module circ_442_df_tb;
    wire [3:0] t_ex_o4;
    reg  [3:0] t_bcd_i4;

    parameter stop_time = 150;

    circ_442_df dut (
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
        $dumpfile("waveform_circ442_df.vcd");
        $dumpvars(0, circ_442_df_tb);

        for (i=0; i < 10; i++) begin
            #10 t_bcd_i4 = cnt_l4;
            cnt_l4 = cnt_l4 + 1;
        end
    end
endmodule
