`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/29/2021 05:55:38 AM
// Design Name: 
// Module Name: tristate
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


module tristate(
    input logic [3:0] a,
    input logic       en,
    output tri [3:0] y
    );

    assign y = en ? a : 4'bz;
endmodule
