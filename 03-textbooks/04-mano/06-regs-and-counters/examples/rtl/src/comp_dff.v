// Complementing D-Flip-Flop.

module comp_dff (
    // OUTPUTS
    output reg Q_o

    // INPUTS
    ,input clk_i
    ,input rst_i
    );

    always @(negedge clk_i, posedge rst_i)
        if (rst_i) Q_o <= 1'b0;
        else Q_o <= #2 ~Q_o; // intra-assignment delay
endmodule
