// 4x1 mux.

module mux4 (
    // OUTPUTS
    output reg mout

    // INPUTS
    ,input i0
    ,input i1
    ,input i2
    ,input i3
    ,input [1:0] sel
    );

    always @(sel, i0, i1, i2, i3)
        case (sel)
            2'b00: mout = i0;
            2'b01: mout = i1;
            2'b10: mout = i2;
            2'b11: mout = i3;
        endcase
endmodule
