// Wave form Fig P5.32.

module wave532_tb;
    reg A, B, C, D, E, F, enb;
    parameter stop_time = 80;

    // Setup vcd out.
    initial begin
        $dumpfile("waveform_wave532.vcd");
        $dumpvars(0, wave532_tb);
    end

    initial #stop_time $finish;

    initial fork
        enb = 0; A = 1; B = 0; C = 0; D = 0; E = 1; F = 1;
        #10 A = 0; #10 B = 1; #10 C = 1;
        #20 A = 1; #20 B = 0; #20 D = 1; #20 E = 0; 
        #30 B = 1; #30 E = 1; #30 F = 0;
        #40 enb = 1; #40 B = 0; #40 D = 0; #40 F = 1;
        #50 B = 1;
        #60 B = 0; #60 D = 1;
        #70 B = 1;
    join
endmodule
