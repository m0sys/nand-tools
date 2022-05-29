// Structural desc of a 4bit Johnson counter.

`include "rtl/src/dff.v"
module scirc659_struct (
    // OUTPUTS
    output [3:0] A_o4

    // INPUTS
    ,input clk_i
    ,input rst_i
    );

    dff 
        F0 (A_o4[0], A_o4[1], clk_i, rst_i),
        F1 (A_o4[1], A_o4[2], clk_i, rst_i),
        F2 (A_o4[2], A_o4[3], clk_i, rst_i),
        F3 (A_o4[3], ~A_o4[0], clk_i, rst_i);
endmodule
