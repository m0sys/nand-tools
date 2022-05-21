// Test bench for DFF with async preset & clear.

`include "rtl/src/scirc524.v"

module scirc524_tb;
    wire t_Q;
    reg t_D;
    reg t_clk_i;
    reg t_rst_b_i;
    reg t_prst_b_i;
    parameter stop_time = 200;

    scirc524 dut (
        // OUTPUTS
        .Q(t_Q)

        // INPUTS
        ,.D(t_D)
        ,.clk_i(t_clk_i)
        ,.rst_b_i(t_rst_b_i)
        ,.prst_b_i(t_prst_b_i)
    );

    initial #stop_time $finish;

    // Setup clk + vcd out.
    initial begin
        $dumpfile("waveform_scirc524.vcd");
        $dumpvars(0, scirc524_tb);
        t_clk_i = 0; forever #5 t_clk_i = ~t_clk_i;
    end

    initial fork 
        t_rst_b_i = 0;
        #2 t_rst_b_i = 1;
        #3 t_prst_b_i = 0;
        #5 t_prst_b_i = 1;
        #7 t_rst_b_i = 0;
        #9 t_rst_b_i = 1;
        #14 t_D = 1;
        #21 t_D = 0;
        #26 t_D = 1;
        #30 t_D = 0; 
        #37 t_prst_b_i = 0;
        #44 t_prst_b_i = 1;
        #52 t_rst_b_i = 0;
        #54 t_rst_b_i = 1;
        #44 t_D = 0;
        #49 t_prst_b_i = 0;
        #51 t_prst_b_i = 1;
        #60 t_D = 1;
        #100 t_D = 0;
    join

    // Some monitoring code for the fun of it.
    initial
        $monitor ("time = ", $time, ": Q=%b, D=%b",  t_Q, t_D);

endmodule
