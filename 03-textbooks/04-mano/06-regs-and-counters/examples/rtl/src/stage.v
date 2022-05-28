// One stage shift reg.

module stage (
    // OUTPUTS
    output Q

    // INPUTS
    ,input  i0 // circulation bit sel
    ,input i1 // rshift serial input
    ,input i2 // lshift serial input
    ,input i3 // paral input
    ,input [1:0] sel // stage mode ctrl bus
    ,input clk_i
    ,input rst_i
    );

    wire  mout;

    mux4  M0 (
        // OUTPUTS
        .mout(mout)

        // INPUTS
        ,.i0(i0)
        ,.i1(i1)
        ,.i2(i2)
        ,.i3(i3)
        ,.sel(sel)
    );

    dff M1 (
        // OUTPUTS
        .Q(Q)

        // INPUTS
        ,.D(mout)
        ,.clk_i(clk_i)
        ,.rst_i(rst_i)
    );
endmodule
