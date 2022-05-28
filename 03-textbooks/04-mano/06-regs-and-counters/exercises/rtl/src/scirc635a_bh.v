// Behaviorial desc of problem 2 reg.

module scirc635a_bh (
    // OUTPUTS
    output reg [3:0] A_o4

    // INPUTS
    ,input [3:0] I_i4
    ,input ld_i
    ,input clear_i
    ,input clk_i
    );


    always @(posedge clk_i)
        if (clear_i) A_o4 <= 4'b0000;
        else if (ld_i) A_o4 <= I_i4;
        else A_o4 <= A_o4;
endmodule
