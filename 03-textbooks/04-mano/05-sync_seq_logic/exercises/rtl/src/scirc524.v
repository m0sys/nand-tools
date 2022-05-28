// DFF with async preset & clear.

module scirc524 (
    output reg Q
    ,input D
    ,input clk_i
    ,input rst_b_i
    ,input prst_b_i
    );

    always @(posedge clk_i, negedge rst_b_i, negedge prst_b_i) 
        if (!rst_b_i) Q <= 1'b0;
        else if (!prst_b_i) Q <= 1'b1; 
        else Q <= D;
endmodule
