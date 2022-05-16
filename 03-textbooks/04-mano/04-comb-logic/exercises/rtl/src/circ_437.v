// Gate-lvl desc of 4bit add-sub circuit (Fig. 4.13).

`include "rtl/src/full_adder.v" 

module circ_437(
    // OUTPUTS
    output [3:0] S
    ,output      Cout

    // INPUTS
    ,input [3:0] A
    ,input [3:0] B
    ,input       M
    );

    wire w0, w1, w2, w3;
    wire C1, C2, C3;

    xor 
        x0 (w0, B[0], M),
        x1 (w1, B[1], M),
        x2 (w2, B[2], M),
        x3 (w3, B[3], M);

    full_adder
        FA0 (S[0], C1, w0, A[0], M),
        FA1 (S[1], C2, w1, A[1], C1),
        FA2 (S[2], C3, w2, A[2], C2),
        FA3 (S[3], Cout, w3, A[3], C3);

endmodule
