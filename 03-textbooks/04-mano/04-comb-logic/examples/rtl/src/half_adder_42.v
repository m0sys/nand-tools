// Gate-level desc of a half adder.

module half_adder(
    // OUTPUTS
    output S
    ,output C

    // INPUTS
    ,input x
    ,input y
    );

    xor (S, x, y);
    and (C, x, y);
endmodule
