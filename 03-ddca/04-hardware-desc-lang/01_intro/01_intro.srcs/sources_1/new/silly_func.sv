`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/28/2021 08:55:09 AM
// Design Name: 
// Module Name: silly_func
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


module silly_func(
    input logic a, b, c,
    output logic y
    );

    assign y = ~a & ~b & ~c |
                a & ~b & ~c |
                a & ~b & c;
endmodule
