// Test bench for design example.


`include "rtl/src/design_exmpl_rtl.v"

`timescale 1ns/ 1ps

module design_exmpl_rtl_tb;
    reg t_start_i, t_clk_i, t_rst_b_i;
    wire  [3:0] t_A_o4;
    wire t_E_o, t_F_o;

    design_exmpl_rtl M0 (
        .A_o4(t_A_o4)
        ,.E_o(t_E_o)
        ,.F_o(t_F_o)

        ,.start_i(t_start_i)
        ,.clk_i(t_clk_i)
        ,.rst_b_i(t_rst_b_i)
    );

    initial #500 $finish;
    initial begin
        t_rst_b_i = 0;
        t_start_i = 0;
        t_clk_i = 0;
        #5 t_rst_b_i = 1; t_start_i =1;
        repeat (32)
        begin
            #5 t_clk_i = ~t_clk_i;
        end
    end

    initial
        $monitor("A = %b E = %b F = %b time = %0d", t_A_o4, t_E_o, t_F_o, $time);
endmodule
