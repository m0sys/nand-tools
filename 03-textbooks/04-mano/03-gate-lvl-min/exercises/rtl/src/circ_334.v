`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/14/2022 07:05:19 AM
// Design Name: 
// Module Name: circ_334
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


module circ_334(
    // OUTPUTS
    output Out1
    ,output Out2
    ,output Out3

    // INPUTS
    ,input A
    ,input B
    ,input C
    ,input D
    );

    assign Out1 = (A || (!B)) && (!C) && (C || D);
    assign Out2 = ((!C) && D || B && C && D || C && (!D)) && ((!A) || B);
    assign Out3 = (A && B || C) && D || (!B) && C;
endmodule
