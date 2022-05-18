// Behaviour desc of a BCD to Excess3 converter circuit.
 
module circ_442_bh (
    // OUTPUTS
    output reg [3:0] ex_o4

    // INPUTS
    ,input [3:0] bcd_i4
    );
    // --EX3--
    // A|B|C|D
    // 3|2|1|0
    //
    //
    // --BCD--
    // w|x|y|z
    // 3|2|1|0

    // reg [3:0] plus3_l4 = 4'b0011;
    always @(bcd_i4) begin
        ex_o4 = bcd_i4 + 3;
    end

endmodule
