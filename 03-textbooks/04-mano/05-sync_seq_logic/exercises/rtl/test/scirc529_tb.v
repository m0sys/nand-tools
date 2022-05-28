// Test bench for scirc529_bh.

`include "rtl/src/scirc529_bh.v"

module scirc529_tb;
    wire [1:0] t_y_out_o2;
    reg t_x_i;
    reg t_clk_i;
    reg t_rst_i;

    parameter stop_time = 100;

    scirc529_bh dut (
        // OUTPUTS
        .y_out_o2(t_y_out_o2)

        // INPUTS
        ,.x_i(t_x_i)
        ,.clk_i(t_clk_i)
        ,.rst_i(t_rst_i)
    );

    initial #stop_time $finish;

    // Setup clk + vcd out.
    initial begin
        $dumpfile("waveform_scirc529.vcd");
        $dumpvars(0, scirc529_tb);
        t_clk_i = 0; forever #5 t_clk_i = ~t_clk_i;
    end

    initial fork
        t_rst_i = 0;
        #2 t_rst_i = 1;   // S0
        #6 t_x_i = 1'b0;  // S0
        #11 t_x_i = 1'b1;  // S1
        #16 t_x_i = 1'b1; // S2
        #18 t_rst_i = 0;  // S0
        #20 t_rst_i = 1;  // S1
        #31 t_x_i = 0;    // S3
        #41 t_x_i = 1;    // S3
        #46 t_x_i = 0;    // S0
        #61 t_x_i = 1;    // move until S2
    join

endmodule
