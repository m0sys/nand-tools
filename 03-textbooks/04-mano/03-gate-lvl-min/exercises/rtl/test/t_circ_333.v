`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 04/14/2022 06:50:41 AM
// Design Name: 
// Module Name: t_circ_333
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


module t_circ_333(
    );
    // OUTPUTS
    wire F;
    // INPUTS
    reg x, y;

    circ_333 M1(F, x, y);
    initial
        begin
            x=1'b0; y=1'b0;
            #100 y=1'b1;
        end

    initial #200 $finish;
endmodule
