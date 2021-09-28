`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/28/2021 04:28:18 PM
// Design Name: 
// Module Name: full_adder
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


module full_adder(
    input logic a, b, cin,
    output logic s, cout
    );

    // Hardware executes all assignments in parallel.
    logic p, g;
    
    assign p = a ^ b;
    assign g = a & b;
    
    assign s = p ^ cin;
    assign cout = g | (p & cin);
endmodule
