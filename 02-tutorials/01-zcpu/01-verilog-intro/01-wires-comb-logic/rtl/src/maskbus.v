`default_nettype none

module maskbus(
    // OUTPUTS
    output [8:0] o_led

    // INPUTS
    ,input [8:0]  i_sw
    );

    wire [8:0] w_intern; 

    assign w_intern = 9'h87;
    assign o_led = i_sw ^ w_intern;
endmodule
