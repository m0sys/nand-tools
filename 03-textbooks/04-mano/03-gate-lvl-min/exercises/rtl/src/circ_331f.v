`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/13/2022 04:28:35 AM
// Design Name: 
// Module Name: circ_331f
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


module circ_331f(
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
    
    nor (w1, (!A), B);
    nor (w2, A, (!B));
    nor (w3, w1, w2);

    nor (w4, C, (!D));
    nor (F, w3, w4);
endmodule
