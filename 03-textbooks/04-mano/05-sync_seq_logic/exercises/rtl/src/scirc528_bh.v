// Behavioural desc of state diagram in Fig. 5.17.

module scirc528_bh (
    // OUTPUTS
    output y_out

    // INPUTS
    ,input [1:0] x_i 
    ,input clk_i
    ,input rst_i
    );

    reg state, nxt_state;
    parameter S0 = 1'b0, S1 = 1'b1;

    always @(posedge clk_i, negedge rst_i)
        if (!rst_i) state <= S0;
        else state <= nxt_state;

    // Specify the state transitions.
    always @(x_i, state)
        case (state)
            S0: if (x_i == 2'b01 || x_i == 2'b10) nxt_state = S1; else nxt_state = S0;
            S1: if (x_i == 2'b01 || x_i == 2'b10) nxt_state = S0; else nxt_state = S1;
        endcase 

    // Specify output conds.
    assign y_out = state;
endmodule
