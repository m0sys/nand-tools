// Testbench for scirc538.

`include "rtl/src/scirc658_struct.v"
`include "rtl/src/scirc658_bh.v"

module scirc658_tb;
    wire [3:0] t_A_o4;
    wire t_C_o;
    wire [3:0] t_A_o4_2;
    wire t_C_o_2;
    reg t_cnt_i;
    reg t_ld_i;
    reg [3:0] t_I_i4;
    reg t_clk_i;
    reg t_rst_i;

    parameter stop_time = 200;

    scirc658_struct dut (
        // OUTPUTS
        .A_o4(t_A_o4)
        ,.C_o(t_C_o)

        // INPUTS
        ,.cnt_i(t_cnt_i)
        ,.ld_i(t_ld_i)
        ,.I_i4(t_I_i4)
        ,.clk_i(t_clk_i)
        ,.rst_i(t_rst_i)
    );

    scirc658_bh dut2 (
        // OUTPUTS
        .A_o4(t_A_o4_2)
        ,.C_o(t_C_o_2)

        // INPUTS
        ,.cnt_i(t_cnt_i)
        ,.ld_i(t_ld_i)
        ,.I_i4(t_I_i4)
        ,.clk_i(t_clk_i)
        ,.rst_i(t_rst_i)
    );

    initial #stop_time $finish;
    
    // Setup clk + vcd out.
    initial begin
        $dumpfile("waveform_scirc658.vcd");
        $dumpvars(0, scirc658_tb);
        t_clk_i = 0; forever #5 t_clk_i = ~t_clk_i;
    end

    initial fork
        t_rst_i = 0; t_I_i4 = 4'b0000; t_ld_i = 1;
        #2 t_rst_i = 1;
        // Test counting capability.
        #6 t_cnt_i = 1; #6 t_ld_i = 0;
        #52 t_rst_i = 0; #52 t_cnt_i=0;
        #54 t_rst_i = 1; 
        // Test para ld capability.
        #56 t_I_i4 = 4'b0111; #56 t_ld_i = 1;
        #66 t_ld_i = 0; #66 t_cnt_i = 1;

        #101 t_I_i4 = 4'b1000; #101 t_cnt_i = 0; #101 t_ld_i = 1;
        #111 t_ld_i = 0; #111 t_cnt_i = 1;
    join
endmodule
