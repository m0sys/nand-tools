// Behavioural desc of state diagram in Prob 5.19.

module scirc541_bh (
    // OUTPUTS
    output y_out

    // INPUTS
    ,input x_i
    ,input clk_i
    ,input rst_i
    );

    reg [2:0] state, nxt_state;
    parameter S0 = 3'b000, S1 = 3'b001, S2 = 3'b010, S3 = 3'b011, S4 = 3'b100;

    always @(posedge clk_i, negedge rst_i) begin
        if (!rst_i) state <= S0;
        else state <= nxt_state;
    end

    // Specify the state transitions.
    always @(x_i, state) begin
        case (state)
            S0: if (x_i == 1'b0) nxt_state = S3; else  nxt_state = S4;
            S1: if (x_i == 1'b0) nxt_state = S0; else  nxt_state = S4;
            S2: if (x_i == 1'b0) nxt_state = S2; else  nxt_state = S0;
            S3: if (x_i == 1'b0) nxt_state = S1; else  nxt_state = S2;
            S4: if (x_i == 1'b0) nxt_state = S2; else  nxt_state = S3;
            default: nxt_state  = S0;
        endcase
    end

    assign y_out = (~state[2]&~state[0]&x_i) | (~state[2]&state[1]&x_i);
endmodule
