// Dataflow desc of 32bit shift left logic by 3 bits.

module circ458 (
    // OUTPUTS
    output [31:0] y_o32

    // INPUTS
    ,input [31:0] A_i32
    );

    assign y_o32[31:0] = { A_i32[28:0], 1'b0, 1'b0, 1'b0};
endmodule
