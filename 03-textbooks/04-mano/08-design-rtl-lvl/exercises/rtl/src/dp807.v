// Datapath for design 807.

module dp807 (
    // OUTPUTS
    output reg [7:0] RA_o8
    ,output carry_o

    // INPUTS
    ,input [7:0] RA_i8
    ,input [7:0] RB_i8
    ,input load_reg_i
    ,input sub_i
    ,input conv_to_unsigned_i
    ,input clk_i
    ,input rst_b_i
    );

    reg [7:0] RB;

    always @(posedge clk_i, negedge rst_b_i) begin
        if(rst_b_i == 0) RA_o8 <= 0;
        if (load_reg_i) begin RA_o8 <= RA_i8; RB <= RB_i8; end
        if (sub_i)  RA_o8 <= RA_o8 + ~RB + 1;
        if (conv_to_unsigned_i) RA_o8 <= ~RA_o8 + 1;
    end
    assign carry_o = RA_o8[7];
endmodule
