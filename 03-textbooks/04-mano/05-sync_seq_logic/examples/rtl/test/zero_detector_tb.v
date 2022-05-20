// Test bench for zero_detector.

`include "rtl/src/zero_detector.v"

module zero_detector_tb (
    );

    wire t_y_out;
    reg t_x_in, t_clk, t_rst;

    zero_detector dut (
        // OUTPUTS
        .y_out(t_y_out)

        // INPUTS
        ,.x_in(t_x_in)
        ,.clk(t_clk)
        ,.rst(t_rst)
    );

    initial #200 $finish;

    initial begin
        $dumpfile("waveform_zero_detector.vcd");
        $dumpvars(0, zero_detector_tb);
        t_clk = 0; forever #5 t_clk = ~t_clk; 
    end

    // Runs statements in parallel.
    initial fork
        t_rst = 0;
        #2 t_rst = 1;
        #87 t_rst = 0;
        #89 t_rst = 1;
        #10 t_x_in = 1;
        #30 t_x_in = 0;
        #40 t_x_in = 1;
        #50 t_x_in = 0;
        #52 t_x_in = 1;
        #54 t_x_in = 0;
        #70 t_x_in = 1;
        #80 t_x_in = 1;
        #70 t_x_in = 0;
        #90 t_x_in = 1;
        #100 t_x_in = 0;
        #120 t_x_in = 1;
        #160 t_x_in = 0;
        #170 t_x_in = 1;
    join
endmodule
