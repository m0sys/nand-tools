// Structural desc of Problem 2 reg.

`include "rtl/src/dff_sync_rst.v"
`include "rtl/src/mux2.v"

module scirc635a_struct (
    // OUTPUTS
    output [3:0] A_o4

    // INPUTS
    ,input [3:0] I_i4
    ,input ld_i
    ,input clear_i
    ,input clk_i
    );

    wire clear_b, d0, d1, d2, d3, m0, m1, m2, m3; 

    mux2 
        M0 (m0, A_o4[0], I_i4[0], ld_i),
        M1 (m1, A_o4[1], I_i4[1], ld_i),
        M2 (m2, A_o4[2], I_i4[2], ld_i),
        M3 (m3, A_o4[3], I_i4[3], ld_i);

    and 
        D0 (d0, clear_b, m0),
        D1 (d1, clear_b, m1),
        D2 (d2, clear_b, m2),
        D3 (d3, clear_b, m3);

    dff_sync_rst 
        F0 (A_o4[0], d0, clk_i),
        F1 (A_o4[1], d1, clk_i),
        F2 (A_o4[2], d2, clk_i),
        F3 (A_o4[3], d3, clk_i);

    assign clear_b = ~clear_i;
endmodule
