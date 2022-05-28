// Behavioral desc of 4bit Ripple Counter (example 6.4 pp289).

`include "rtl/src/comp_dff.v"

module ripple_cnter_4bit (
    // OUTPUTS
    output A3_o
    ,output A2_o
    ,output A1_o
    ,output A0_o

    // INPUTS
    ,input cnt_i
    ,input rst_i
    );

    // Init comp dffs.
    comp_dff F0 (
        // OUTPUTS
        .Q_o(A0_o)

        // INPUTS
        ,.clk_i(cnt_i)
        ,.rst_i(rst_i)
    );

    comp_dff F1 (
        // OUTPUTS
        .Q_o(A1_o)

        // INPUTS
        ,.clk_i(A0_o)
        ,.rst_i(rst_i)
    );

    comp_dff F2 (
        // OUTPUTS
        .Q_o(A2_o)

        // INPUTS
        ,.clk_i(A1_o)
        ,.rst_i(rst_i)
    );

    comp_dff F3 (
        // OUTPUTS
        .Q_o(A3_o)

        // INPUTS
        ,.clk_i(A2_o)
        ,.rst_i(rst_i)
    );
endmodule
