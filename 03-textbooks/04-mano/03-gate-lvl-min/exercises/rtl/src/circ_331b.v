`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/13/2022 04:09:35 AM
// Design Name: 
// Module Name: circ_331b
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


module circ_331b(
    // OUTPUTS
    output F
    // INPUTS
    ,input A
    ,input B
    ,input C
    ,input D
    );
    wire w1;
    wire w2;
    wire w3;
    wire w4;

    nand U0(w1, C, D);
    or U1(w2, (!w1), (!B));
    nand U0_2(w3, w2, A);

    nand U0_3(w4, B, (!C));
    or U1_2(F, (!w3), (!w4));
endmodule
