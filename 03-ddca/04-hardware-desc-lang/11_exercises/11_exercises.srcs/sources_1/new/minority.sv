`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/08/2021 08:10:37 AM
// Design Name: 
// Module Name: minority
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


module minority(
    input logic a5, b5, c5,
    output logic y5
    );

    assign y5 = ~a5 & ~b5 & c5 | ~a5 & b5 & ~c5 | a5 & ~b5 & ~c5 | ~a5 & ~b5 & ~c5;
endmodule
