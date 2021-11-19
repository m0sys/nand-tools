`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/28/2021 04:15:06 PM
// Design Name: 
// Module Name: mux4
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


module mux4(
    input logic [3:0] d0, d1, d2, d3,
    input logic [1:0] s,
    output logic [3:0] y
    );

    assign y = s[1] ? (s[0] ? d3 : d2)
                    : (s[0] ? d1 : d0);
endmodule
