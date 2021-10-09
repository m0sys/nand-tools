`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/08/2021 11:32:10 AM
// Design Name: 
// Module Name: sevenseg_tb
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


module sevenseg_tb(
    );
    logic clk, reset;
    logic [3:0]a;
    logic [1:0]select = 2'b00;
    logic [6:0] y, yexp; 
    logic [3:0] digits;
    logic [31:0] vectornum, errors;
    logic [10:0] testvectors[10000:0];


    // Init device under test (dut).
    sevenseg dut(a, select,  digits, y);

    // Gen clock.
    always
    begin
        clk=1; #5; clk=0; #5;
    end

    // Load vectors and pulse reset.
    initial
    begin
        $readmemb("sevenseg.tv", testvectors);
        vectornum=0; errors=0;
        reset=1; #27; reset=0;
    end

    // Apply test vectors on rising edge clk.
    always @(posedge clk)
    begin
        #1; {a, yexp} = testvectors[vectornum];
    end

    // Check result on falling edge of clk.
    always @(negedge clk)
        if (~reset) begin // skip during reset
            if (y !== yexp) begin 
                $display("Error: testvector used = %b", testvectors[vectornum]);
                $display("Error: inputs = %b", a);
                $display(" outputs = %b (%b expected)", y, yexp);
                errors=errors+1;
            end
            vectornum=vectornum+1;
            if (testvectors[vectornum] === 11'bx) 
            begin
                $display("%d tests completed with %d errors", vectornum, errors);
                $finish;
            end
        end
endmodule
