`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/28/2021 03:51:26 PM
// Design Name: 
// Module Name: and8
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

// HOW DOES ONE BUILD A MICROPROCESSOR.


module and8(
    input logic [7:0] a,
    output logic y
    );

    assign y = &a;
endmodule
