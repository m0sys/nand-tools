// Structural desc of state diagram in Fig. 5.17.

`include "rtl/src/dff.v"

module scirc528_struc (
    // OUTPUTS
    output y_out

    // INPUTS
    ,input [1:0] x_i
    ,input clk_i
    ,input rst_i
    );

    wire w0, w1;
    assign w0 = x_i[1] ^ x_i[0];

    assign w1 = y_out ^ w0;

    dff D1 (
        // OUTPUTS
        .Q(y_out)

        // INPUTS
        ,.clk(clk_i)
        ,.rst(rst_i)
        ,.D(w1)
    );
endmodule
