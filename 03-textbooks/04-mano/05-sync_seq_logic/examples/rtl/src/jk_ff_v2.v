// Example 5.4: JK-Flip-Flop Built from dff (pp 223).

module jk_ff2 (
    // OUTPUTS
    output reg Q
    ,output Q_b

    // INPUTS
    ,input j
    ,input k
    ,input clk
    );

    assign Q_b = ~Q;
    always @(posedge clk) 
        case ({ j, k })
            2'b00: Q <= Q;
            2'b01: Q <= 1'b0;
            2'b10: Q <= 1'b1;
            2'b11: Q <= !Q;
        endcase
endmodule
