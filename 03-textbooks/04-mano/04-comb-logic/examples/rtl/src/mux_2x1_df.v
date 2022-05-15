// Dataflow desc of two-to-one-line mux.

module mux_2x1_df(
    // OUTPUTS
    output m_out

    // INPUTS
    ,input A
    ,input B
    ,input sel
    );

    assign m_out = (sel) ? A : B;
endmodule
