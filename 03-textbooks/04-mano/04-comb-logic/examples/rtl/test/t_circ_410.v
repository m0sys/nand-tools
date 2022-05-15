module t_circ_410
    reg [2:0] D;
    wire F1, F2;

    circ_410 M1 (F1, F2, D[2], D[1], D[0]);

    initial
    begin
        D = 3'b000;
        repeat(7) #10 D = D 1 1'b1;
    end

    initial
        $monitor("ABC = %b F1 = %b F2 = %b", D, F1, F2);
endmodule
