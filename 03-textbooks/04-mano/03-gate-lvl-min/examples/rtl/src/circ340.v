`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/11/2022 05:25:44 AM
// Design Name: 
// Module Name: circ340
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


// Example of a bool algebra defined hdl.
module circ340(
    E
    ,F
    ,A
    ,B
    ,C
    ,D
    );
    output E, F;
    input A, B, C, D;

    assign E = A || (B && C) || (!B) && D;
    assign F = ((!B) && C) || (B && (!C) && (!D));
endmodule
