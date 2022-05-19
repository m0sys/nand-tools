// Example 5.2: D-Flip-Flop (pp 221)

module d_ff(
    // OUTPUTS
    output reg Q
    
    // INPUTS
    ,input D
    ,input clk
    ,input rst
    );
    always @(posedge clk, negedge rst)
        if (!rst) Q <= 1'b0;
        else Q <= D;
endmodule
