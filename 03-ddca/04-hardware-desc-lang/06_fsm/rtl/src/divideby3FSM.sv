`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 09/29/2021 09:48:59 AM
// Design Name: 
// Module Name: divideby3FSM
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


module divideby3FSM(
    input logic clk,
    input logic reset,
    output logic y
    );


    typedef enum logic [1:0] { S0, S1, S2 } statetype;
    statetype [1:0] state, nextstate;

    // state reg
    always_ff @(posedge clk, posedge reset)
        if (reset) state <= S0;
        else state <= nextstate;

    // next state logic
    always_comb
        case (state)
            S0: nextstate <= S1;
            S1: nextstate <= S2;
            S2: nextstate <= S0;
            default: nextstate <= S0;
        endcase
endmodule
