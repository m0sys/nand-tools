// Dataflow desc of a four-bit comp.

module mag_cmp(
    // OUTPUTS
    output       A_lt_B
    ,output      A_eq_B
    ,output      A_gt_B

    // INPUTS
    ,input [3:0] A
    ,input [3:0] B
    );
    assign A_lt_B = (A < B);
    assign A_gt_B = (A > B);
    assign A_eq_B = (A == B);
endmodule
