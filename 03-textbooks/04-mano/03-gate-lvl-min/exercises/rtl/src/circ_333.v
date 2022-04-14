`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/14/2022 05:09:17 AM
// Design Name: 
// Module Name: circ_333
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


module circ_333(
    // OUTPUTS
    output F

    // INPUTS
    ,input x
    ,input y
    );
    wire xprime, yprime, w3, w4;

    not #(3) (xprime, x);
    not #(3) (yprime, y);

    and #(6) (w3, x, yprime);
    and #(6) (w4, xprime, y);

    or #(8) (F, w3, w4);
endmodule
