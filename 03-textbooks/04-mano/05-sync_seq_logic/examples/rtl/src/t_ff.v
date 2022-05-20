// Example 5.3: T-Flip-Flop Built from dff (pp 222).

`include "d_ff.v" 

module t_ff (
    // OUTPUTS
    output reg Q

    // INPUTS
    ,input T
    ,input clk
    ,input rst
    );

    wire DT;
    assign DT = Q ^ T;
    d_ff tf1 (Q, DT, clk, rst);

endmodule
