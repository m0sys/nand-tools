`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/29/2021 07:50:56 AM
// Design Name: 
// Module Name: flopr
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


module flopr(
    input logic clk,
    input logic reset,
    input logic [3:0] d,
    output logic [3:0] q
    );

    always_ff @(posedge clk)
        if (reset) q <= 4'b0;
        else q <= d;
endmodule
