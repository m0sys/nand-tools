// Example 5.5: Mealy machine zero detector (pp 224).

module zero_detector (
    // OUTPUTS
    output reg y_out

    // INPUTS
    ,input x_in
    ,input clk
    ,input rst
    );

    reg [1:0] state, next_state;
    parameter S0=2'b00, S1=2'b01, S2=2'b10, S3=2'b11;

    always @(posedge  clk, negedge rst)
        if (rst == 0) state <= S0;
        else state <= next_state;

    // Specify state transitions.
    always @(state, x_in)
        case (state)
            S0: if (x_in) next_state = S1; else next_state = S0;
            S1: if (x_in) next_state = S3; else next_state = S0;
            S2: if (~x_in)next_state = S0; else next_state = S2;
            S3: if (x_in) next_state = S2; else next_state = S0;
        endcase

    // Specify the output conds.
    // NOTE: can combine with prev always block since they have the same sen_lst
    always @(state, x_in)
        case (state)
            // Since the output is a function of both state  and input it is a
            // mealy machine.
            S0: y_out = 0;
            S1, S2, S3: y_out = ~x_in;
        endcase
endmodule
