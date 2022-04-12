`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/12/2022 05:06:11 AM
// Design Name: 
// Module Name: circ_331a
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module circ_331a(
    // OUTPUTS
    output F

    // INPUTS
    ,input A
    ,input B
    ,input C
    ,input D
    );

    wire w1;
    wire w1_2;
    wire w1_3;
    wire w2;

    and U0(w1, C, D);

    assign C_inv = (!C);
    and U0_2(w2, B, C_inv);

    or U1(w1_2, w1, B);

    and U0_3(w1_3, w1_2, A);

    or U1_2(F, w1_3, w2);
endmodule
