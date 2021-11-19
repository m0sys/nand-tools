`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/29/2021 10:01:52 AM
// Design Name: 
// Module Name: pattern_moore
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


module pattern_moore(
    input logic clk,
    input logic reset,
    input logic a,
    output logic y
    );

    typedef enum logic [1:0] {S0, S1, S2} statetype;
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

            S1: if (a) nextstate=S2;
                else   nextstate=S1;

            S2: if (a) nextstate=S0;
                else   nextstate=S1;
            default:   nextstate=S0;
    endcase
endmodule
