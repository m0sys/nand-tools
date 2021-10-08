`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/08/2021 06:45:23 AM
// Design Name: 
// Module Name: exercise3_tb
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


module exercise3_tb(

    );
    logic clk, reset;
    logic [3:0]a;
    logic y, yexpected; 
    logic [31:0] vectornum, errors;
    logic [4:0] testvectors[10000:0];

    // Init device under test (dut).
    exercise3 dut(a, y);

    // Gen clock.
    always
    begin
        clk=1; #5; clk=0; #5;
    end

    // Load vectors and pulse reset.
    initial
    begin
        $readmemb("exercise3.tv", testvectors);
        vectornum=0; errors=0;
        reset=1; #27; reset=0;
    end

    // Apply test vectors on rising edge clk.
    always @(posedge clk)
    begin
        #1; {a[3], a[2], a[1], a[0], yexpected} = testvectors[vectornum];
    end

    // Check result on falling edge of clk.
    always @(negedge clk)
        if (~reset) begin // skip during reset
            if (y !== yexpected) begin 
                $display("Error: inputs=%b", {a[3], a[2], a[1], a[0]});
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
