`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 10/09/2021 09:21:18 AM
// Design Name: 
// Module Name: traffic_controller
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


module traffic_controller(
    input logic clk, reset,
    input logic ta, tb,
    output logic [1:0] la, lb
    );

    // state defs
    logic [3:0] state, nstate;

    parameter S0 = 4'b0001;
    parameter S1 = 4'b0010;
    parameter S2 = 4'b0100;
    parameter S3 = 4'b1000;

    always_ff @(posedge clk, posedge reset)
        if (reset) state <= S0;
        else state <= nstate;

    always_comb
        case (state)
            S0: if (ta) nstate <= S0;
                else    nstate <= S1;
            S1:         nstate <= S2;
            S2: if (tb) nstate <= S2;
                else    nstate <= S3;
            S3:         nstate <= S0;
        endcase

    assign la = { state == S2, state == S1};
    assign lb = { state == S0 || state == S1, state == S3 };

endmodule
