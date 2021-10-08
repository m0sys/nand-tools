`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/28/2021 12:49:28 PM
// Design Name: 
// Module Name: AND_Gate
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


module AND_Gate(
    input A,
    input B,
    input C,
    output logic outAND
    );

    assign outAND = A & B & C;
endmodule
