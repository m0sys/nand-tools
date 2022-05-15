module strobe(
    output o_led

    ,input i_clk
    );

    reg [26:0] counter;
    always @(posedge i_clk)
        counter <= counter + 1'b1;

    assign o_led = &counter[26:24];
endmodule
