// Behaviorial desc of 4bit Johnson counter.

module scirc659_bh (
    // OUTPUTS
    output reg [3:0] A_o4

    // INPUTS
    ,input clk_i
    ,input rst_i
    );

    always @(posedge clk_i, negedge rst_i)
        if (!rst_i) A_o4 <= 4'b0000;
        else A_o4 <= {~A_o4[0], A_o4[3:1]};
endmodule
