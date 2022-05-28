// Behavioral desc of D-Flip-Flop.

module dff (
    // OUTPUTS
    output reg Q

    // INPUTS
    ,input D
    ,input clk_i
    ,input rst_i
    );

    always @(posedge clk_i, negedge rst_i)
        if (!rst_i) Q <= 1'b0; else Q <= D;
endmodule
