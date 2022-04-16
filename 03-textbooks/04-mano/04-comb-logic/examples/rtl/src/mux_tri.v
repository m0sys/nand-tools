// Mux with three-state output.

module mux_tri(
    // OUTPUTS
    output tri m_out

    // INPUTS
    ,input A
    ,input B
    ,input sel
    );

    bufif1 (m_out, A, sel);
    bufif0 (m_out, B, sel);
endmodule
