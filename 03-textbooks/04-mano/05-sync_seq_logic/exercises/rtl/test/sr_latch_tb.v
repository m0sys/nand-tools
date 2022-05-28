// Testbench for SR Latch.

`include "rtl/src/sr_latch.v"

module sr_latch_tb;
    wire t_Q, t_Q_b;
    reg t_S, t_R, t_enb;
    parameter stop_time = 100;

    sr_latch dut (
        // OUTPUTS
        .Q(t_Q)
        ,.Q_b(t_Q_b)

        // INPUTS
        ,.S(t_S)
        ,.R(t_R)
        ,.enb(t_enb)
    );

    initial #stop_time $finish;

    initial begin
        $dumpfile("waveform_sr_latch.vcd");
        $dumpvars(0, sr_latch_tb);
    end

    initial fork
        t_enb = 0; t_S = 0; t_R = 0;
        #5 t_S = 1; 
        #10 t_R = 1;
        #15 t_S = 0; #15 t_R = 0; #15 t_enb = 1; // hold
        #25 t_R = 1; // reset
        #30 t_R = 0; // hold
        #35 t_S = 1; // set 
        #40 t_S = 0; // hold
        #50 t_R = 1; // reset
        #55 t_R = 0; // hold
        #60 t_S = 1; // set
        #65 t_S = 0; // hold
        #80 t_S = 1; #80 t_R = 1; // forbidden state
    join
    
endmodule
