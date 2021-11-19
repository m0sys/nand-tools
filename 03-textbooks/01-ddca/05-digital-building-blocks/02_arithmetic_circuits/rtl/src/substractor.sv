`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/09/2021 11:20:35 AM
// Design Name: 
// Module Name: substractor
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


module substractor #(parameter N = 8)(
    input logic [N-1:0] a, b,
    output logic [N-1:0] y
    );

    assign y = a - b;
endmodule
