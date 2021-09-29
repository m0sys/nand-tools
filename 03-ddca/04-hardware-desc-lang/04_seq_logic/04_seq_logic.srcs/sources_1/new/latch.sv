`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/29/2021 08:09:29 AM
// Design Name: 
// Module Name: latch
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

// THE MORE YOU DO IT - THE MORE LIGHT THERE WILL BE! (2021/9/29)


module latch(
    input logic  clk,
    input logic [3:0] d,
    output logic [3:0] q
    );

    always_latch
        if (clk) q <= d;
endmodule
