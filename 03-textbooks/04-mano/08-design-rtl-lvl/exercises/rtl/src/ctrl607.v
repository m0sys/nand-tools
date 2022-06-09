// Controller module for design 607.

module ctrl607 (
    // OUTPUTS
    output reg load_reg_o
    ,output reg sub_o
    ,output reg conv_to_unsigned_o

    // INPUTS
    ,input start_i
    ,input carry_i
    ,input clk_i
    ,input rst_b_i
    );

    reg [1:0] state, nxt_state;
    parameter S_idle = 2'b00, S_1 = 2'b01, S_2 = 2'b10, S_3 = 2'b11; 

    // Set state transition.
    always @(posedge clk_i, negedge rst_b_i)
        if (rst_b_i == 0) state <= S_idle; 
        else state <= nxt_state;

    // Nxt state transition determined by ASMD chart.
    always @(state, start_i, carry_i) begin
        nxt_state = S_idle;
        case (state)
            S_idle: if (start_i) nxt_state = S_1; else nxt_state = S_idle;
            S_1: nxt_state = S_2;
            S_2: if (carry_i) nxt_state = S_3; else nxt_state = S_idle;
            S_3: nxt_state = S_idle;
        endcase
    end

    // Output control logic determined by ASMD chart.
    always @(state, start_i) begin
        // Default assign to avoid latches.
        load_reg_o = 0;
        sub_o = 0;
        conv_to_unsigned_o = 0;

        case (state)
            S_idle: if (start_i) load_reg_o = 1;
            S_2: sub_o  = 1;
            S_3: conv_to_unsigned_o = 1;
        endcase
    end 

endmodule
