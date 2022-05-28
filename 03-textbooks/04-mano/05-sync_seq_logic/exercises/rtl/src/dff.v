// D Flip Flop.

module dff (
    // OUTPUTS
    output reg Q

    // INPUTS
    ,input clk
    ,input rst
    ,input D
    );

    always @(posedge clk, negedge rst)
        if (!rst) Q <= 1'b0;
        else Q <= D;
endmodule
