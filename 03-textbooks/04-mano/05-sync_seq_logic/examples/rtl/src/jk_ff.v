// Example 5.3: T-Flip-Flop Built from dff (pp 223).

`include "d_ff.v"

module jk_ff (
    // OUTPUTS
    output reg Q

    // INPUTS
    ,input J
    ,input K
    ,input clk
    ,input rst
    );
    wire JK;
    assign JK = (J&~Q) | (~K&Q);
    d_ff jkf1 (Q, JK, clk, rst);

endmodule
