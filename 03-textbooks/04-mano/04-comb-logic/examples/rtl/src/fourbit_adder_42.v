// Gate-level desc of a four-bit ripple carry adder.

module ripple_carry_4bit_adder(
    // OUTPUTS
    output[3:0] Sum
    ,output C4

    // INPUTS
    ,input[3:0] A
    ,input[3:0] B
    ,input C0
    );
    wire C1, C2, C3;

    full_adder2 
        FA1 (Sum[0], C1, A[0], B[0], C0),
        FA2 (Sum[1], C2, A[1], B[1], C1),
        FA3 (Sum[2], C3, A[2], B[2], C2),
        FA4 (Sum[3], C4, A[3], B[3], C3);
endmodule
