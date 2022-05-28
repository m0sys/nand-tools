// Behaviorial desc of 4x1 mux.

module mux4 (
    // OUTPUTS
    output reg mout

    ,input w
    ,input x
    ,input y
    ,input z
    ,input [1:0] sel
    );

    always @(w, x, y, z, sel)
        case (sel)
            2'b00: mout = w;
            2'b01: mout = x;
            2'b10: mout = y;
            2'b11: mout = z;
        endcase
endmodule
