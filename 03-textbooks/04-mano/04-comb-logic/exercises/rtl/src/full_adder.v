// Dataflow  desc of a full-adder circuit.

module full_adder(
    // OUTPUTS
    output S
    ,output Cout

    // INPUTS
    ,input x
    ,input y
    ,input Cin
    );

    assign S = x ^ y ^ Cin;
    assign Cout = x&&y || x&&Cin || y&&Cin;
endmodule
