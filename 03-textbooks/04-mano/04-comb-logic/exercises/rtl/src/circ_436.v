// Gate-lvl desc of 4bit priority encoder (Fig. 4.23).

module circ_436 (
    // OUTPUTS
    output y
    ,output x
    ,output V

    // INPUTS
    ,input [3:0] D
    );

    wire D2_b;
    wire w0;

    not (D2_b, D[2]);
    and (w0, D2_b, D[1]);

    or (x, D[3], D[2]);
    or (V, x, D[1], D[0]);

    or (y, D[3], w0);
endmodule
