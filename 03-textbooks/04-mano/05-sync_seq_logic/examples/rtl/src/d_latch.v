// Example 5.1: D-Latch (pp 221)

module d_latch(
    // OUTPUTS
    output reg Q

    // INPUTS
    ,input D
    ,input enb
    );

    always @(enb, D) 
        if (enb)
            Q <= D;
endmodule
