`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/09/2021 09:07:00 AM
// Design Name: 
// Module Name: jkflop
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


module jkflop(
    input logic clk, j, k,
    output logic q
    );

    always_ff @(posedge clk)
        if (j == k && k == 1)
            q <= ~q;
        else if (j == 1)
            q <= 1;
        else if (k == 1)
            q <= 0;

endmodule
