`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/13/2022 05:08:59 AM
// Design Name: 
// Module Name: circ_332e
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


module circ_332e(
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

    assign F = ~(~(A || B) ||  ~(C || D) || (!E));
    // sln
    // assign F = (A ~| B) ~| (C ~| D) ~| (!E);
endmodule
