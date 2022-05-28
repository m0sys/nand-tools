// Behavioural desc of state diagram in Fig. 5.19.

module scirc529_bh (
    // OUTPUTS
    output [1:0] y_out_o2

    // INPUTS
    ,input x_i
    ,input clk_i
    ,input rst_i
    );

    reg [1:0] state, nxt_state;
    parameter S0 = 2'b00, S1 = 2'b01, S2 = 2'b10, S3 = 2'b11;

    always @(posedge clk_i, negedge rst_i)
        if (!rst_i) state <= S0;
        else state <= nxt_state;

    // Specify the state transitions.
    always @(x_i, state)
        case (state)
            S0: if (x_i == 1'b0) nxt_state = S0; else nxt_state = S1;
            S1: if (x_i == 1'b0) nxt_state = S3; else nxt_state = S2;
            S2: if (x_i == 1'b0) nxt_state = S3; else nxt_state = S2;
            S3: if (x_i == 1'b0) nxt_state = S0; else nxt_state = S3;
        endcase

    // Specify output conds.
    assign y_out_o2 = state;
        
endmodule
