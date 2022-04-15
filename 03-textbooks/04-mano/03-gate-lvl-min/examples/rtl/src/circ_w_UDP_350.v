// Verilog model: Circuit instantiation of Circuit UDP 350.
module circ_w_UDP_350(
    // OUTPUTS
    output e
    ,output f

    // INPUTS
    ,input a
    ,input b
    ,input c
    ,input d
    );

    UDP_350 (e, a, b, c);
    and (f, e, d);
endmodule
