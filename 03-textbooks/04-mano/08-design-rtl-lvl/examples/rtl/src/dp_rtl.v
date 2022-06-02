// Datapath for design_exmpl_rtl.

module dp_rtl (
    // OUTPUTS
    output reg [3:0] A_ro4
    ,output reg E_ro
    ,output reg F_ro

    // INPUTS
    ,input set_E_i
    ,input clr_E_i
    ,input set_F_i
    ,input clr_A_F_i
    ,input incr_A_i
    ,input clk_i
    );

    // RTL ops directly from ASMD chart.
    always @(posedge clk_i) begin
        if (set_E_i)        E_ro<=1;
        if (clr_E_i)        E_ro<=0;
        if (set_F_i)        F_ro<=1;
        if (clr_A_F_i)      begin A_ro4 <= 0; F_ro <= 0; end
        if (incr_A_i)       A_ro4<=A_ro4+1;
    end 
endmodule
