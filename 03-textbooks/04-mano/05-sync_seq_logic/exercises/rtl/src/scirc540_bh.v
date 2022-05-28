// Behavioural desc of state diagram in Prob 5.18. 

module scirc540_bh (
    // OUTPUTS
    output [1:0] y_out_o2

    // INPUTS
    ,input [1:0] x_i2
    ,input clk_i
    ,input rst_i
    );

    reg [1:0] state, nxt_state;
    parameter S0 = 2'b00, S1 = 2'b01, S2 = 2'b10, S3 = 2'b11;

    always @(posedge clk_i, negedge rst_i) begin
        if (!rst_i) state <= S0;
        else state <= nxt_state;
    end

    // Specify the state transitions.
    always @(x_i2, state) begin
        case (state)
            S0: if (x_i2 == 2'b00 || x_i2 == 2'b01) nxt_state = S0; 
                else if (x_i2 == 2'b11) nxt_state = S1;
                else  nxt_state = S3;
            S1: if (x_i2 == 2'b00 || x_i2 == 2'b01) nxt_state = S1; 
                else if (x_i2 == 2'b11) nxt_state = S2;
                else  nxt_state = S0;
            S2: if (x_i2 == 2'b00 || x_i2 == 2'b01) nxt_state = S2; 
                else if (x_i2 == 2'b11) nxt_state = S3;
                else  nxt_state = S1;
            S3: if (x_i2 == 2'b00 || x_i2 == 2'b01) nxt_state = S3; 
                else if (x_i2 == 2'b11) nxt_state = S0;
                else  nxt_state = S2;
        endcase
    end

    // Specify output conds.
    assign y_out_o2 = state;
endmodule
