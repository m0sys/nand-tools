// Behaviorial desc of 4bit binary counter with para ld.

module scirc658_bh (
    // OUTPUTS
    output reg [3:0] A_o4
    ,output C_o

    // INPUTS
    ,input cnt_i
    ,input  ld_i
    ,input [3:0] I_i4
    ,input rst_i
    ,input clk_i
    );

    always @(posedge clk_i, negedge rst_i)
        if (!rst_i) A_o4 <= 4'b0000;
        else if (ld_i) A_o4 <= I_i4;
        else if (cnt_i) A_o4 <= A_o4 + 1;
        else A_o4 <= A_o4; // redundant

    assign C_o = &A_o4;
endmodule
