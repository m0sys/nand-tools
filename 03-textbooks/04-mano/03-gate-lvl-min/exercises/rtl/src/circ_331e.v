`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/13/2022 04:22:02 AM
// Design Name: 
// Module Name: circ_331e
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


module circ_331e(
    // OUTPUTS
    output F

    // INPUTS
    ,input A
    ,input B
    ,input C
    ,input D
    ,input E
    );
    wire w1;
    wire w2;

    nor U0(w1, A, B);
    nor U0_1(w2, C, D);
    nor U0_2(F, w1, w2, (!E));
endmodule
