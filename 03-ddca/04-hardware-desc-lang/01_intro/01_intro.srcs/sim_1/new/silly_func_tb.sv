`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/29/2021 12:36:04 PM
// Design Name: 
// Module Name: silly_func_tb
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


module silly_func_tb(
    );

    logic a, b, c, y;

    // Init device under test (dut).
    silly_func dut(a, b, c, y);

    // Apply inputs one at a time.
    initial begin
        a=0; b=0; c=0; #10;
        c=1;           #10;
        b=1; c=0;      #10;
        c=1;           #10;
        a=1; b=0; c=0; #10;
        c=1;           #10;
        b=1; c=0;      #10;
        c=1;           #10;
    end
endmodule
