`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/29/2021 06:19:40 AM
// Design Name: 
// Module Name: example_tb
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


module example_tb(

    );

    logic aa, bb, cc;
    logic out1;

    example U1(aa, bb, cc, out1);
    initial begin
        // conf #1
        aa=0;
        bb=0;
        cc=0;
        #10;
        // conf #2
        cc=1;
        #10;
        // conf #3
        cc=0;
        bb=1;
        #10;
        // conf #4
        cc=1;
        #10;
        // conf #5
        cc=0;
        bb=0;
        aa=1;
        #10;
        // conf #6
        cc=1;
        #10;
        // conf #7
        bb=1;
        cc=0;
        #10;
        // conf #8
        cc=1;
        #10;
    end
endmodule
