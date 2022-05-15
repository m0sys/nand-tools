module blinky #(parameter WIDTH=27)  (
    output o_led

    ,input i_clk
    );

    reg [WIDTH-1:0] counter;

    initial counter = 0;
    always @(posedge i_clk)
        counter <= counter + 1'b1;

    assign o_led = counter[WIDTH-1];
endmodule
