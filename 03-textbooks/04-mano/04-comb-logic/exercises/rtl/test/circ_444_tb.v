// Test bench stimulus for circ_444.

`timescale 1ns / 1ns
`include "rtl/src/circ_444.v"

module circ_444_tb;
    wire [7:0] t_y_o8;
    reg  [7:0] t_A_i8;
    reg  [7:0] t_B_i8;
    reg  [2:0] t_sel_i3;
    parameter stop_time  = 300;

    circ_444 dut(
        // OUTPUTS
        .y_o8(t_y_o8)

        // INPUTS
        ,.A_i8(t_A_i8)
        ,.B_i8(t_B_i8)
        ,.sel_i3(t_sel_i3)
    );

    initial # stop_time $finish;

    // Register to cnt sel, A, B.
    reg [2:0] cnt_sel_l3 = 3'b0;
    reg [7:0] cnt_A_l8 = 7'b0;
    reg [7:0] cnt_B_l8 = 7'b0;
    integer i, j, k;
    parameter MAX_SEL = 8;
    parameter MAX_8BIT = 5; 

    initial begin
        $dumpfile("waveform_circ444.vcd");
        $dumpvars(0, circ_444_tb);

        // TODO: have to reverse so that sel is most inner.

        for (i = 0; i < MAX_8BIT; i++) begin 
            for (j = 0; j < MAX_8BIT; j++) begin
                for (k = 0; k < MAX_SEL; k++) begin
                    #4 t_A_i8 = cnt_A_l8; t_B_i8 = cnt_B_l8; t_sel_i3 = cnt_sel_l3;
                    cnt_sel_l3 = cnt_sel_l3 + 1;
                end
                cnt_A_l8 = cnt_A_l8 + 1;
            end
            cnt_B_l8 = cnt_B_l8 + 1;
        end
    end
endmodule
