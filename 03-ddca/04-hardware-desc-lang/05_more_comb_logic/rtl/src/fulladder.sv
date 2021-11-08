`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/29/2021 08:28:13 AM
// Design Name: 
// Module Name: fulladder
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


module fulladder(
    input logic a, b, cin,
    output logic s, cout
    );

    logic p, g;
    
    always_comb
    begin
        p = a ^ b;
        g = a & b;
        s = p ^ cin;
        cout = g | (p & cin);
    end
endmodule
