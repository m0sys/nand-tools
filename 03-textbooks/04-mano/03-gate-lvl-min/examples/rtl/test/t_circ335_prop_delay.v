`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/11/2022 05:00:07 AM
// Design Name: 
// Module Name: t_circ335_prop_delay
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


module t_circ335_prop_delay(
    );
    // OUTPUTS
    wire D, E;
    // INPUTS
    reg A, B, C;

    circ335_prop_delay M1(A, B, C, D, E); // instance name req
    initial
        begin
            A = 1'b0; B = 1'b0; C=1'b0;
            #100 A = 1'b1; B = 1'b1; C = 1'b1;
        end

    initial #200 $finish;
endmodule
