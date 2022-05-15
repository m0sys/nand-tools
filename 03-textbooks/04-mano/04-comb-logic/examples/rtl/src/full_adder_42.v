// Gate-level desc of a full adder.

module full_adder(
    // OUTPUTS
    output S
    ,output C_out

    // INPUTS
    ,input x
    ,input y
    ,input C_in
    );
    wire p1, p2, p3;

    xor (S, x, y, C_in);
    and
        G0 (p1, x, y),
        G1 (p2, x, C_in),
        G2 (p3, y, C_in);
    or (C_out, p1, p2, p3);
endmodule
