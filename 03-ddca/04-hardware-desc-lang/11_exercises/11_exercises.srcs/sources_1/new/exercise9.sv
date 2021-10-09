`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/09/2021 08:02:12 AM
// Design Name: 
// Module Name: exercise9
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


module exercise9(
    input logic a9, b9, c9,
    output logic y9
    );

    //     10x  | x00  |  011
    // y = a~b | ~b~c | ~abc 
    mux8 fmux(.s({a9, b9, c9}), .d0(1), .d1(1), .d2(0), .d3(0), .d4(1), .d5(0), .d6(0), .d7(1), .y(y9));
endmodule
