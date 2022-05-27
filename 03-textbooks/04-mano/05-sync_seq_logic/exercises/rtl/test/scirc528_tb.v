// Test bench for  scirc528_bh & scirc528_struc.

`include "rtl/src/scirc528_bh.v"
`include "rtl/src/scirc528_struc.v"

module scirc528_tb;
    wire t_y_out, t_y_out_2;
    reg [1:0] t_x_i;
    reg t_clk_i;
    reg t_rst_i;
    parameter stop_time = 100; 

    scirc528_bh dut (
        // OUTPUTS
        .y_out(t_y_out)

        // INPUTS
        ,.x_i(t_x_i)
        ,.clk_i(t_clk_i)
        ,.rst_i(t_rst_i)
    );

    scirc528_struc dut2 (
        // OUTPUTS
        .y_out(t_y_out_2)

        // INPUTS
        ,.x_i(t_x_i)
        ,.clk_i(t_clk_i)
        ,.rst_i(t_rst_i)
    );


    initial #stop_time $finish;

    // Setup clk + vcd out.
    initial begin
        $dumpfile("waveform_scirc528.vcd");
        $dumpvars(0, scirc528_tb);
        t_clk_i = 0; forever #5 t_clk_i = ~t_clk_i;
    end

    initial fork
        t_rst_i = 0;
        #2 t_rst_i = 1;
        #4 t_x_i = 2'b00;
        #11 t_x_i = 2'b011;
        #16 t_x_i = 2'b01;
        #21 t_rst_i = 0;
        #23 t_rst_i = 1;
        #26 t_x_i = 2'b10;
        #36 t_x_i = 2'b00;
        #46 t_x_i = 2'b011;
        #56 t_x_i = 2'b01;
        #76 t_x_i = 2'b10;
    join

endmodule
