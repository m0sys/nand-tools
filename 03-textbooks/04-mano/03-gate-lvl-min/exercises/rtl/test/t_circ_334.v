`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/14/2022 07:16:26 AM
// Design Name: 
// Module Name: t_circ_334
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


module t_circ_334(
    );
    // OUTPUTS
    wire Out1, Out2, Out3;
    // INPUTS
    reg A, B, C, D;

    circ_334 M1(Out1, Out2, Out3, A, B, C, D);
    initial
        begin
            A=1'b0; B=1'b0; C=1'b0; D=1'b0;
            #50 A=1'b0; B=1'b0; C=1'b0; D=1'b1;
            #50 A=1'b0; B=1'b0; C=1'b1; D=1'b0;
            #50 A=1'b0; B=1'b0; C=1'b1; D=1'b1;
            #50 A=1'b0; B=1'b1; C=1'b0; D=1'b0;
            #50 A=1'b0; B=1'b1; C=1'b0; D=1'b1;
            #50 A=1'b0; B=1'b1; C=1'b1; D=1'b0;
            #50 A=1'b0; B=1'b1; C=1'b1; D=1'b1;
            #50 A=1'b1; B=1'b0; C=1'b0; D=1'b0;
            #50 A=1'b1; B=1'b0; C=1'b0; D=1'b1;
            #50 A=1'b1; B=1'b0; C=1'b1; D=1'b0;
            #50 A=1'b1; B=1'b0; C=1'b1; D=1'b1;
            #50 A=1'b1; B=1'b1; C=1'b0; D=1'b0;
            #50 A=1'b1; B=1'b1; C=1'b0; D=1'b1;
            #50 A=1'b1; B=1'b1; C=1'b1; D=1'b0;
            #50 A=1'b1; B=1'b1; C=1'b1; D=1'b1;
        end

    initial #900 $finish;
endmodule
