// Structural desc of Problem 6 reg.

module scirc635c_struct (
    // OUTPUTS
    output [3:0] A_o4

    // INPUTS
    ,input [3:0] I_i4
    ,input ld_i
    ,input shift_i
    ,input bstream_i
    ,input clk_i
    ,input rst_i
    );

    wire d0, d1, d2, d3;

    mux4
        M0 (d0, A_o4[0], bstream_i, I_i4[0], bstream_i, {ld_i, shift_i}),
        M1 (d1, A_o4[1], A_o4[0], I_i4[1], A_o4[0], {ld_i, shift_i}),
        M2 (d2, A_o4[2], A_o4[1], I_i4[2], A_o4[1], {ld_i, shift_i}),
        M3 (d3, A_o4[3], A_o4[2], I_i4[3], A_o4[2], {ld_i, shift_i});

    dff
        F0 (A_o4[0], d0, clk_i, rst_i),
        F1 (A_o4[1], d1, clk_i, rst_i),
        F2 (A_o4[2], d2, clk_i, rst_i),
        F3 (A_o4[3], d3, clk_i, rst_i);
endmodule
