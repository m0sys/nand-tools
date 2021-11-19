`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/29/2021 09:09:08 AM
// Design Name: 
// Module Name: priorityckt
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


module priorityckt(
    input logic [3:0] a,
    output logic [3:0] y
    );

    always_comb
        if      (a[3]) y <= 4'b1000;
        else if (a[2]) y <= 4'b0100; 
        else if (a[1]) y <= 4'b0010; 
        else if (a[0]) y <= 4'b0001; 
        else           y <= 4'b0000; 
endmodule
