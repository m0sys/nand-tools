// Dataflow desc of 4bit eq.

module  circ_456 (
    // OUTPUTS
    output y_o

    // INPUTS
    ,input [3:0] A_i4
    ,input [3:0] B_i4
    );

    assign y_o = ~(A_i4[3] ^ B_i4[3]) 
                 & ~(A_i4[2] ^ B_i4[2])
                 & ~(A_i4[1] ^ B_i4[1])
                 & ~(A_i4[0] ^ B_i4[0]);
endmodule
