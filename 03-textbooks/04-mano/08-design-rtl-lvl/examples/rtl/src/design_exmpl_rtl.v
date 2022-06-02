// RTL desc of design example (see Fig. 8.11).

// Top level module.
module design_exmpl_rtl (
    // OUTPUTS
    output [3:0] A_o4
    ,output E_o
    ,output F_o

    // INPUTS
    ,input start_i
    ,input clk_i
    ,input rst_b_i
    );

    wire set_E, clr_E, set_F, clr_A_F, incr_A;

    ctrl_rtl M0 (
        // OUTPUTS
        .set_E_ro(set_E)
        ,.clr_E_ro(clr_E)
        ,.set_F_ro(set_F)
        ,.clr_A_F_ro(clr_A_F)
        ,.incr_A_ro(incr_A)

        // INPUTS
        ,.A2_i(A_o4[2])
        ,.A3_i(A_o4[3])
        ,.start_i(start_i)
        ,.clk_i(clk_i)
        ,.rst_b_i(rst_b_i)
    );

    dp_rtl M1 (
        // OUTPUTS
        .A_ro4(A_o4)
        ,.E_ro(E_o)
        ,.F_ro(F_o)

        // INPUTS
        ,.set_E_i(set_E)
        ,.clr_E_i(clr_E)
        ,.set_F_i(set_F)
        ,.clr_A_F_i(clr_A_F)
        ,.incr_A_i(incr_A)
        ,.clk_i(clk_i)
    );
endmodule
