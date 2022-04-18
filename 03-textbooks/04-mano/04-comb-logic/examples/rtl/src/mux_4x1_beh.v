// Behavioral desc of a four-to-one line mux.

module mux_4x1_beh(
    // OUTPUTS
    output reg m_out

    // INPUTS
    ,input in_0, in_1, in_2, in_3
    ,input [1:0] sel
    );

    always @(in_0, in_1, in_2, in_3, sel)
        case (sel)
            2'b00: m_out = in_0;
            2'b01: m_out = in_1;
            2'b10: m_out = in_2;
            2'b11: m_out = in_3;
        endcase
endmodule
