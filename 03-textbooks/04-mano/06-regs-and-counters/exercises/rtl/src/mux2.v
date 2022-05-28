// Behaviorial desc of 2x1 mux.

module mux2 (
    // OUTPUTS
    output reg mout

    // INPUTS
    ,input x
    ,input y
    ,input sel
    );

    always @(x, y, sel)
        if(!sel) mout = x; else mout = y;
endmodule
