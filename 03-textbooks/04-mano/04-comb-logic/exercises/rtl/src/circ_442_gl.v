// Gate-lvl desc of a BCD to Excess3 converter circuit.

module circ_442_gl (
    // OUTPUTS
    output [3:0] ex_o4

    // INPUTS
    ,input [3:0] bcd_i4
    );
    // --EX3--
    // A|B|C|D
    // 3|2|1|0
    //
    // --BCD--
    // w|x|y|z
    // 3|2|1|0

    wire al1_l, al2_l, bl1_l, bl2_l, bl3_l, cl1_l, cl2_l;

    // STAGE 1:

    // Compute required literals (prods) for A output.
    and
        a0 (al1_l, bcd_i4[2], bcd_i4[0]),
        a1 (al2_l, bcd_i4[2], bcd_i4[1]);

    // Compute required literals (prods) for B output.
    and
        b0 (bl1_l, bcd_i4[2], ~bcd_i4[1], ~bcd_i4[0]),
        b1 (bl2_l, ~bcd_i4[2], bcd_i4[0]),
        b2 (bl3_l, ~bcd_i4[2], bcd_i4[1]);

    // Compute required literals (prods) for C output.
    and
        c0 (cl1_l, ~bcd_i4[1], ~bcd_i4[0]),
        c1 (cl2_l, bcd_i4[1], bcd_i4[0]);


    // STAGE 2:

    // Compute required sum of prods for A, B, C, D outputs.
    or 
        aout (ex_o4[3], bcd_i4[3], al1_l, al2_l),
        bout (ex_o4[2], bl1_l, bl2_l, bl3_l),
        cout (ex_o4[1], cl1_l, cl2_l);

    assign ex_o4[0] = ~bcd_i4[0];

endmodule
