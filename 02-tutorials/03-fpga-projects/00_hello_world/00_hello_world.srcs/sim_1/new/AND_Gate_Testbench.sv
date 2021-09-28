`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/28/2021 12:56:52 PM
// Design Name: 
// Module Name: AND_Gate_Testbench
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


module AND_Gate_Testbench(

    );
    logic aa, bb;
    logic out1;
    AND_Gate U1(aa, bb, out1);
    initial begin
        aa=0;
        bb=0;
        #100;
        bb=1;
        #100;
        aa=1;
        bb=0;
        #100;
        bb=1;
        #100;
    end
endmodule


