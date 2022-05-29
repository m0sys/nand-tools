// Structural desc of 4bit binary counter with para ld.

`include "rtl/src/jkff.v"

module scirc658_struct (
    // OUTPUTS
    output [3:0] A_o4
    ,output C_o

    // INPUTS
    ,input cnt_i
    ,input  ld_i
    ,input [3:0] I_i4
    ,input rst_i
    ,input clk_i
    );

    wire to_cnt, j0, k0, j1, k1, j2, k2, j3, k3;
    wire j0_ld, k0_ld, j1_ld, k1_ld, j2_ld, k2_ld, j3_ld, k3_ld;
    wire tinc1, tinc2, tinc3;

    // Check if to count.
    and (to_cnt, cnt_i, ~ld_i);

    // Load/cnt mux.
    and 
        JL0 (j0_ld, I_i4[0], ld_i),
        JL1 (j1_ld, I_i4[1], ld_i),
        JL2 (j2_ld, I_i4[2], ld_i),
        JL3 (j3_ld, I_i4[3], ld_i);

    and 
        KL0 (k0_ld, ~I_i4[0], ld_i),
        KL1 (k1_ld, ~I_i4[1], ld_i),
        KL2 (k2_ld, ~I_i4[2], ld_i),
        KL3 (k3_ld, ~I_i4[3], ld_i);

    or 
        JO0 (j0, j0_ld, to_cnt),
        JO1 (j1, j1_ld, tinc1),
        JO2 (j2, j2_ld, tinc2),
        JO3 (j3, j3_ld, tinc3),

        KO0 (k0, k0_ld, to_cnt),
        KO1 (k1, k1_ld, tinc1),
        KO2 (k2, k2_ld, tinc2),
        KO3 (k3, k3_ld, tinc3);

    // Check if count so inc.
    and 
        T1 (tinc1, to_cnt, A_o4[0]),
        T2 (tinc2, to_cnt, A_o4[0], A_o4[1]),
        T3 (tinc3, to_cnt, A_o4[0], A_o4[1], A_o4[2]);

    // Setup jks.
    jkff 
        F0 (A_o4[0], j0, k0, clk_i, rst_i),
        F1 (A_o4[1], j1, k1, clk_i, rst_i),
        F2 (A_o4[2], j2, k2, clk_i, rst_i),
        F3 (A_o4[3], j3, k3, clk_i, rst_i);

    // Compute  C_o.
    and (C_o, to_cnt, &A_o4);
endmodule
