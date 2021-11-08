`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/29/2021 06:13:50 AM
// Design Name: 
// Module Name: example
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

// BE SINGLE-MINDED.

module example(
    input logic a, b, c,
    output logic y
    );

    logic ab, bb, cb, n1, n2, n3;

    assign #1 { ab, bb, cb } = ~{ a, b, c };
    assign #2 n1 = ab & bb & cb;
    assign #2 n2 = a & bb & cb;
    assign #2 n3 = a & bb & c;
    assign #4 y = n1 | n2 | n3;
endmodule
