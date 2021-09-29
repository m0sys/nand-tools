`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/29/2021 12:44:55 PM
// Design Name: 
// Module Name: silly_func_self_tb
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


module silly_func_self_tb(
    );

    logic a, b, c, y;

    // Init device under test (dut).
    silly_func dut(a, b, c, y);

    // Apply inputs one at a time.
    initial begin
        a=0; b=0; c=0; #10;
        assert (y === 1) else $error("000 failed.");
        c=1;           #10;
        assert (y === 0) else $error("001 failed.");
        b=1; c=0;      #10;
        assert (y === 0) else $error("010 failed.");
        c=1;           #10;
        assert (y === 0) else $error("011 failed.");
        a=1; b=0; c=0; #10;
        assert (y === 1) else $error("100 failed.");
        c=1;           #10;
        assert (y === 1) else $error("101 failed.");
        b=1; c=0;      #10;
        assert (y === 0) else $error("110 failed.");
        c=1;           #10;
        assert (y === 0) else $error("111 failed.");
    end
endmodule
