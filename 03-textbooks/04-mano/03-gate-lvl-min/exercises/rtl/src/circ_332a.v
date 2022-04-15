`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/13/2022 04:46:40 AM
// Design Name: 
// Module Name: circ_332a
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


module circ_332a(
    // OUTPUTS
    output F

    // INPUTS
    ,input A
    ,input B
    ,input C
    ,input D
    );

    assign F = A && (C && D || B) || B && (!C);
endmodule
