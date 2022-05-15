// Gate-level desc of two-to-four-line decoder

module decoder_2x4_gates(
    // OUTPUTS
    output[0:3] D

    // INPUTS
    ,input A
    ,input B
    ,input enb
    );

    wire A_not, B_not, enb_not;
    not
        G1 (A_not, A),
        G2 (B_not, B),
        G3 (enb_not, enb);

    nand
        G4 (D[0], A_not, B_not, enb_not),
        G5 (D[1], A_not, B, enb_not),
        G6 (D[2], A, B_not, enb_not),
        G7 (D[3], A, B, enb_not);
endmodule
