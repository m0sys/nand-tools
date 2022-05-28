// Structural desc of Universial 4bit Shift Register (example 6.2 pp285).

module univ_4bit_shift_reg_struct (
    // OUTPUTS
    output reg [3:0] A_par // reg output

    // INPUTS
    ,input     [3:0] I_par // paral input
    ,input           s0
    ,input           s1
    ,input           msb_in // serial input from msb
    ,input           lsb_in // serial input from lsb
    ,input           clk_i
    ,input           rst_i
    );

    // Bus for mode ctrl.
    assign [1:0] sel = {s1, s0};

    // Init the four stages.
    stage ST0 (
        // OUTPUTS
        .Q(A_par[0])

        // INPUTS
        ,.i0(A_par[0])
        ,.i1(A_par[1])
        ,.i2(lsb_in)
        ,.i3(I_par[0])
        ,.sel(sel)
        ,.clk_i(clk_i)
        ,.rst_i(rst_i)
    );

    stage ST1 (
        // OUTPUTS
        .Q(A_par[1])

        // INPUTS
        ,.i0(A_par[1])
        ,.i1(A_par[2])
        ,.i2(A_par[0])
        ,.i3(I_par[1])
        ,.sel(sel)
        ,.clk_i(clk_i)
        ,.rst_i(rst_i)
    );

    stage ST2 (
        // OUTPUTS
        .Q(A_par[2])

        // INPUTS
        ,.i0(A_par[2])
        ,.i1(A_par[3])
        ,.i2(A_par[1])
        ,.i3(I_par[2])
        ,.sel(sel)
        ,.clk_i(clk_i)
        ,.rst_i(rst_i)
    );

    stage ST3 (
        // OUTPUTS
        .Q(A_par[3])

        // INPUTS
        ,.i0(A_par[3])
        ,.i1(msb_in)
        ,.i2(A_par[2])
        ,.i3(I_par[3])
        ,.sel(sel)
        ,.clk_i(clk_i)
        ,.rst_i(rst_i)
    );
endmodule
