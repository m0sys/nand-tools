`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/29/2021 01:08:07 PM
// Design Name: 
// Module Name: silly_func_self_smart_tb
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


module silly_func_self_smart_tb(

    );

    logic clk, reset;
    logic a, b, c, y, yexpected;
    logic [31:0] vectornum, errors;
    logic [3:0] testvectors[10000:0];

    // Init device under test (dut).
    silly_func dut(a, b, c, y);

    // Gen clock.
    always
    begin
        clk=1; #5; clk=0; #5;
    end

    // Load vectors and pulse reset.
    initial
    begin
        $readmemb("example.tv", testvectors);
        vectornum=0; errors=0;
        reset=1; #27; reset=0;
    end

    // Apply test vectors on rising edge clk.
    always @(posedge clk)
    begin
        #1; {a, b, c, yexpected} = testvectors[vectornum];
    end

    // Check result on falling edge of clk.
    always @(negedge clk)
        if (~reset) begin // skip during reset
            if (y !== yexpected) begin 
                $display("Error: inputs=%b", {a, b, c});
                $display(" outputs=%b (%b expected)", y, yexpected);
                errors=errors+1;
            end
            vectornum=vectornum+1;
            if (testvectors[vectornum] === 4'bx) begin
                $display("%d tests completed with %d errors", vectornum, errors);
                $finish;
            end
        end
endmodule
