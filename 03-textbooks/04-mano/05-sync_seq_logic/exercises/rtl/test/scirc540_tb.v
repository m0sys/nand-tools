// Testbench for scirc540_bh.

`include "rtl/src/scirc540_bh.v"

module scirc540_tb;
    wire [1:0]  t_y_out_o2;
    reg [1:0] t_x_i2;
    reg t_clk_i;
    reg t_rst_i;

    parameter stop_time = 100; 

    scirc540_bh dut (
        // OUTPUTS
        .y_out_o2(t_y_out_o2)

        // INPUTS
        ,.x_i2(t_x_i2)
        ,.clk_i(t_clk_i)
        ,.rst_i(t_rst_i)
    );

    initial #stop_time $finish;

    // Setup clk + vcd out.
    initial begin
        $dumpfile("waveform_scirc540.vcd");
        $dumpvars(0, scirc540_tb);
        t_clk_i = 0; forever #5 t_clk_i = ~t_clk_i;
    end

    initial fork
        t_rst_i = 0;
        #2 t_rst_i = 1;      // S0
        #6 t_x_i2 = 2'b00;   // S0
        #11 t_x_i2 = 2'b01;  // S0
        #16 t_x_i2 = 2'b11;  // S1
        #21 t_rst_i = 0;     // S0
        #23 t_rst_i = 1; #23 t_x_i2 = 2'b00;    
        #31 t_x_i2 = 2'b10;  // go backwards
        #61 t_x_i2 = 2'b00; #61 t_rst_i = 0;
        #63 t_rst_i = 1; 
        #66 t_x_i2 = 2'b11; // go forwards
    join
endmodule
