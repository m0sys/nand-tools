// Gate-level desc of a full adder built using half adders.

module full_adder2(
    // OUTPUTS
    output S
    ,output C_out

    // INPUTS
    ,input x
    ,input y
    ,input C_in
    );
    wire S1, C1, C2;

    half_adder HA1 (S1, C1, x, y);
    half_adder HA2 (S, C2, S1, C_in);
    or G1 (C, C2, C1);
endmodule
