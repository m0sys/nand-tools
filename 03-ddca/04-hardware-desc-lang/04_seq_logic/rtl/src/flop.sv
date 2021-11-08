`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/29/2021 07:32:21 AM
// Design Name: 
// Module Name: flop
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


module flop(
    input logic clk,
    input logic [3:0] d,
    output logic [3:0] q
    );

    always_ff @(posedge clk)
        q <= d;
endmodule
