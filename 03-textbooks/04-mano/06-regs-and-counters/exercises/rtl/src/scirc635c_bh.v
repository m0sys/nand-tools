// Behaviorial desc of problem 6 reg.

module scirc635c_bh (
    // OUTPUTS
    output reg [3:0] A_o4

    // INPUTS
    ,input [3:0] I_i4
    ,input ld_i
    ,input shift_i
    ,input bstream_i
    ,input clk_i
    ,input rst_i
    );

    always @(posedge clk_i, negedge rst_i)
        if (!rst_i) A_o4 <= 4'b0000;
        else if (shift_i) A_o4 <= {A_o4[2:0], bstream_i}; // lshift
        else if(ld_i) A_o4 <= I_i4;
        else A_o4 <= A_o4; // redundant case
endmodule
