`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/28/2021 02:34:10 PM
// Design Name: 
// Module Name: silly_func_testbench
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


module silly_func_testbench(

    );
    logic aa, bb, cc;
    logic out1;
    silly_func U1(aa, bb, cc, out1);
    initial begin
        aa=0;
        bb=0;
        cc=0;
        #100;
        aa=1;
        #100;
        cc=1;
        #100;
        bb=1;
        #100;
    end
endmodule
