`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/09/2021 08:28:38 AM
// Design Name: 
// Module Name: fsm1
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


module fsm1(
    input logic clk, reset,
    input logic taken, back,
    output logic pred_taken
    );

    logic[4:0] state, next_state;
    
    parameter S0 = 5'b00001;
    parameter S1 = 5'b00010;
    parameter S2 = 5'b00100;
    parameter S3 = 5'b01000;
    parameter S4 = 5'b10000;

    always_ff @(posedge clk, posedge reset)
        if (reset) state <= S2;
        else state <= next_state;

    always_comb
        case (state)
            S0: if (taken) next_state=S1;
                else       next_state=S0;
            S1: if (taken) next_state=S2;
                else       next_state=S0;
            S2: if (taken) next_state=S3;
                else       next_state=S1;
            S3: if (taken) next_state=S4;
                else       next_state=S2;
            S4: if (taken) next_state=S4;
                else       next_state=S3;
            default:       next_state=S2;
    endcase

    assign pred_taken = (state == S4) |
                        (state == S3) |
                        (state == S2 && back);
endmodule
