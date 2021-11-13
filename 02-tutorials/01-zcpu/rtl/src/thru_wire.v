`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company:
// Engineer:
//
// Create Date: 09/17/2021 07:56:55 AM
// Design Name:
// Module Name: thru_wire
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


module thru_wire(
    i_sw, o_led
    );

    input wire i_sw;
    output wire o_led;

    assign o_led = i_sw;
endmodule
