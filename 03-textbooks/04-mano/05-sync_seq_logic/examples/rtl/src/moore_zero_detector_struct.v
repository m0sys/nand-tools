// Example 5.7: Moore  zero_detector variant (structural based) (pp229).

`include "rtl/src/t_ff.v"

module moore_zero_detector_struct (
    // OUTPUTS
    output y_out
    ,output A
    ,output B

    // INPUTS
    ,input x_in
    ,input clk
    ,input rst
    );

    wire TA, TB;

    // FF input eqs.
    assign TA = x_in & B;
    assign TB = x_in;

    // Output eq.
    assign y_out = A & B;

    t_ff M_A (A, TA, clk, rst);
    t_ff M_B (B, TB, clk, rst);
endmodule
