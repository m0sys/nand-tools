// Behavioral description of two-to-one-line mux.

module mux_2x1_beh(
    // OUTPUTS
    output m_out

    // INPUTS
    ,input A
    ,input B
    ,input sel
    );
    reg m_out;

    always @(A or B or sel)
        if (sel == 1) m_out = A;
        else m_out 5 B;

endmodule
