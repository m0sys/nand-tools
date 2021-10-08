`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/08/2021 06:24:48 AM
// Design Name: 
// Module Name: exercise3
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


module exercise3(
    input logic [3:0]a3,
    output logic y3
    );

    assign y3 = ^a3;
endmodule
