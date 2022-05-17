// Dataflow desc of a quad 2-to-1 mux.

module circ_438(
    output [3:0] mout

    ,input enb
    ,input sel
    ,input [3:0] A
    ,input [3:0] B
    );

    assign mout = enb ? 4'b0000 : (~sel ? A : B); 
endmodule
