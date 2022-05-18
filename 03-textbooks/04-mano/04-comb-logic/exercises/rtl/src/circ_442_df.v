// Dateflow desc of a BCD to Excess3 converter circuit.
 
module circ_442_df (
    // OUTPUTS
    output [3:0] ex_o4

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

    assign ex_o4[3] = bcd_i4[3] 
                      | (bcd_i4[2] & bcd_i4[0]) 
                      | (bcd_i4[2] & bcd_i4[1]);

    assign ex_o4[2] = (bcd_i4[2] & ~bcd_i4[1] & ~bcd_i4[0]) 
                      | (~bcd_i4[2] & bcd_i4[0]) 
                      | (~bcd_i4[2] & bcd_i4[1]);

    assign ex_o4[1] = (~bcd_i4[1] & ~bcd_i4[0]) 
                      | (bcd_i4[1] & bcd_i4[0]);

    assign ex_o4[0] = ~bcd_i4[0];

endmodule
