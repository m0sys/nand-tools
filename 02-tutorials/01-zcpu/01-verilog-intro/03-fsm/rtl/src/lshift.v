module lshift(
    output var [7:0] o_led
    ,input i_clk
    ,input i_input
    );

    always @(posedge i_clk)
        o_led <= { o_led[6:0], i_input };
endmodule
