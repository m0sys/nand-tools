// Top module for rtl design exercise 8.7.

`include "rtl/src/ctrl807.v"
`include "rtl/src/dp807.v"
module rtl_design607 #(parameter WIDTH=8)  (
    // OUTPUTS
    output [WIDTH-1:0] RA_o
    ,output carry_o

    // INPUTS
    ,input [WIDTH-1:0]  RA_i8
    ,input [WIDTH-1:0]  RB_i8
    ,input start_i
    ,input clk_i
    ,input rst_b_i
    );

    wire load_reg, sub, conv_to_unsigned;

    ctrl807 M0 (
        // OUTPUTS
        .load_reg_o(load_reg)
        ,.sub_o(sub)
        ,.conv_to_unsigned_o(conv_to_unsigned)

        // INPUTS
        ,.start_i(start_i)
        ,.carry_i(carry_o)
        ,.clk_i(clk_i)
        ,.rst_b_i(rst_b_i)
    );

    dp807 M1 (
        // OUTPUTS
        .RA_o8(RA_o)
        ,.carry_o(carry_o)

        // INPUTS
        ,.RA_i8(RA_i8)
        ,.RB_i8(RB_i8)
        ,.load_reg_i(load_reg)
        ,.sub_i(sub)
        ,.conv_to_unsigned_i(conv_to_unsigned)
        ,.clk_i(clk_i)
        ,.rst_b_i(rst_b_i)
    );
endmodule
