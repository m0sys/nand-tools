module ripple_counter(
    input CLK,
    input CLR,
    output [3:0] Q // MSB = 3, LSB = 0
);

always @(posedge CLK, posedge CLR)
begin
    if (CLR)
        Q <= 0;
    else if (CLK)
        Q <= Q + 1;
end

endmodule
