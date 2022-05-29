// Testbench for scirc539.

`include "rtl/src/scirc659_struct.v"
`include "rtl/src/scirc659_bh.v"

module scirc659_tb;
    wire [3:0] t_A_o4;
    wire [3:0] t_A_o4_2;
    reg [3:0] t_I_i4;
    reg t_clk_i;
    reg t_rst_i;

    parameter stop_time = 200;

    scirc659_struct dut (
        // OUTPUTS
        .A_o4(t_A_o4)

        // INPUTS
        ,.clk_i(t_clk_i)
        ,.rst_i(t_rst_i)
    );

    scirc659_bh dut2 (
        // OUTPUTS
        .A_o4(t_A_o4_2)

        // INPUTS
        ,.clk_i(t_clk_i)
        ,.rst_i(t_rst_i)
    );


    initial #stop_time $finish;
    
    // Setup clk + vcd out.
    initial begin
        $dumpfile("waveform_scirc659.vcd");
        $dumpvars(0, scirc659_tb);
        t_clk_i = 0; forever #5 t_clk_i = ~t_clk_i;
    end

    initial fork
        t_rst_i = 0;
        #2 t_rst_i = 1;
    join
endmodule
