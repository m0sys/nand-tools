// Behavioral desc of Binary 4bit Counter with parallel load (example 6.3 pp 288).

module bin_4bit_cnt_para_ld (
    // OUTPUTS
    output reg [3:0] A_cnt_o4 // Data output
    ,output C_o

    // INPUTS
    ,input [3:0] data_i4
    ,input cnt_i              // active high to count
    ,input ld_i               // active high load
    ,input clk_i
    ,input rst_i              // active low rst
    );

    assign C_o = cnt_i && (~ld_i) && (A_cnt_o4 == 4'b1111);

    always @(posedge clk_i, negedge rst_i)
        if (!rst_i) A_cnt_o4 <= 4'b0000;
        else if (ld_i) A_cnt_o4 <= data_i4;
        else if (cnt_i) A_cnt_o4 <= A_cnt_o4 + 1'b1;
        else A_cnt_o4 <= A_cnt_o4;
endmodule
