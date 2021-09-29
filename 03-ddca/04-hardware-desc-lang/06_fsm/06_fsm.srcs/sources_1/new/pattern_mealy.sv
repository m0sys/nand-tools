`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/29/2021 10:17:42 AM
// Design Name: 
// Module Name: pattern_mealy
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


module pattern_mealy(
    input logic clk,
    input logic reset,
    input logic a,
    output logic y
    );

    typedef enum logic {S0, S1} statetype;
    statetype state, nextstate;

    // state reg.
    always_ff @(posedge clk, posedge reset)
        if (reset) state <= S0;
        else       state <= nextstate;

    // next state logic.
    always_comb
        case (state)
            S0: if (a) nextstate=S0;
                else   nextstate=S1;

            S1: if (a) nextstate=S1;
                else   nextstate=S0;
            default:   nextstate=S0;
    endcase

    // output logic
    assign y = (a & state == S1);
endmodule
