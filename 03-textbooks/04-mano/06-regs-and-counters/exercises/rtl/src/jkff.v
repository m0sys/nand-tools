// Behaviorial desc of JK-Flip-Flop.

module jkff (
    // OUTPUTS
    output reg Q
    
    // INPUTS
    ,input J
    ,input K
    ,input clk_i
    ,input rst_i
    );

    always @(posedge clk_i, negedge rst_i)
        if (!rst_i) Q <= 1'b0;    // async rst
        else if (~J&~K) Q <= Q;   // hold
        else if (J&~K) Q <= 1'b1; // set
        else if (~J&K) Q <= 1'b0; // rst
        else Q <= ~Q;             // toggle
endmodule
