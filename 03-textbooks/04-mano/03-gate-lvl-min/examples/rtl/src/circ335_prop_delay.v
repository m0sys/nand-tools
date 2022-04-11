`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/11/2022 04:58:09 AM
// Design Name: 
// Module Name: circ335_prop_delay
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


module circ335_prop_delay(
    A
    ,B
    ,C
    ,D
    ,E
    );

    output D, E;
    input A, B, C;
    wire w1;

    and #(30) G1(w1, A, B); // opt gate instance name
    not #(10) G2(E, C);
    or #(20) G3(D, w1, E);
endmodule
