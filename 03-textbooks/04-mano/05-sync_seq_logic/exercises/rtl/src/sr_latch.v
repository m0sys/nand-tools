// Problem 5.34 - impl fig 5.5

module sr_latch (
    //OUTPUTS
    output Q
    ,output Q_b

    ,input S
    ,input R
    ,input enb
    );

    wire w0, w1;

    nand 
        n0 (w0, S, enb),
        n1 (w1, R, enb);

    // Feedback nand.
    nand 
        n2 (Q, w0, Q_b),
        n3 (Q_b, w1, Q);
        
endmodule
