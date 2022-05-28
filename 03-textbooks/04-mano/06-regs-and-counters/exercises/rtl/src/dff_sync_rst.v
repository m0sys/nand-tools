// Behaviorial desc of D-Flip-Flop.

module dff_sync_rst (
    // OUTPUTS
    output reg Q

    // INPUTS
    ,input D
    ,input clk_i
    );

    always @(posedge clk_i)
        Q <= D;
endmodule
