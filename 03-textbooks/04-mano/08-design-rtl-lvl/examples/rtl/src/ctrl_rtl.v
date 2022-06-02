// Controller for design_exmpl_rtl.

module ctrl_rtl (
    // OUTPUTS
    output reg set_E_ro
    ,output reg clr_E_ro
    ,output reg set_F_ro
    ,output reg clr_A_F_ro
    ,output reg incr_A_ro

    // INPUTS
    ,input A2_i
    ,input A3_i
    ,input start_i
    ,input clk_i
    ,input rst_b_i
    );
    
    reg [1:0] state, nxt_state;
    parameter S_idle = 2'b00, S_1 = 2'b01, S_2 = 2'b11; // state codes
    
    always @(posedge clk_i, negedge rst_b_i)
        if (rst_b_i == 0) state <= S_idle;
        else state <= nxt_state;

    // Nxt state logic determined by the ASMD chart.
    always @(state, start_i, A2_i, A3_i) begin
        nxt_state = S_idle;
        case (state)
            S_idle : if (start_i) nxt_state = S_1; else nxt_state = S_idle;
            S_1: if (A2_i & A3_i) nxt_state = S_2; else nxt_state = S_1;
            S_2: nxt_state = S_idle;
            default: nxt_state = S_idle;
        endcase
    end

    // Output logic determined by the ASMD chart.
    always @(state, start_i, A2_i) begin
        set_E_ro = 0; // default assign
        clr_E_ro = 0;
        set_F_ro = 0;
        clr_A_F_ro = 0;
        incr_A_ro = 0;
        case (state)
            S_idle: if (start_i) clr_A_F_ro = 1;
            S_1: begin incr_A_ro = 1; if (A2_i) set_E_ro = 1; else clr_E_ro = 1; end
            S_2: set_F_ro = 1;
        endcase
    end
endmodule
