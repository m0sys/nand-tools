`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/10/2022 06:30:34 AM
// Design Name: 
// Module Name: circ335
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


module circ335(
    A
    ,B
    ,C
    ,D
    ,E
    );
    output D, E;
    input A, B, C;
    wire w1;

    and G1(w1, A, B); // opt gate instance name
    not G2(E, C);
    or G3(D, w1, E);
endmodule
