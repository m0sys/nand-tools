// Dataflow description of two-to-four-line decoder.


module decoder_2x4_df(
    // OUTPUTS
    output [0:3] D

    // INPUTS
    ,input A
    ,input B
    ,input enb
    );
    assign D[0] = !((!A) && (!B) && (!enb)),
           D[1] = !((!A) && B && (!enb)),
           D[2] = !(A && (!B) && (!enb)),
           D[3] = !(A && B && (!enb));
endmodule
