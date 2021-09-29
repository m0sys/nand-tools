`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/29/2021 09:16:25 AM
// Design Name: 
// Module Name: priority_casez
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


module priority_casez(
    input logic [3:0] a,
    output logic [3:0] y
    );

    always_comb
        casez(a)
        4'b1???: y <= 4'b1000;
        4'b01??: y <= 4'b0100; 
        4'b001?: y <= 4'b0010; 
        4'b0001: y <= 4'b0001; 
        default: y <= 4'b0000; 
    endcase
endmodule
