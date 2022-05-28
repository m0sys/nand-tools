// Test bench for 4bit Ripple Counter.

`include "rtl/src/ripple_cnter_4bit.v"

module ripple_cnter_4bit_tb;
    reg t_cnt;
    reg t_rst;
    wire t_A0, t_A1, t_A2, t_A3;

    ripple_cnter_4bit dut (
        // OUTPUTS
        .A3_o(t_A3)
        ,.A2_o(t_A2)
        ,.A1_o(t_A1)
        ,.A0_o(t_A0)

        // INPUTS
        ,.cnt_i(t_cnt)
        ,.rst_i(t_rst)
    );

    always
        #5 t_cnt = ~t_cnt;
        
    initial begin
        $dumpfile("waveform_ripple_cnt.vcd");
        $dumpvars(0, ripple_cnter_4bit_tb);
        t_cnt = 1'b0;
        t_rst = 1'b1;
        #4 t_rst = 1'b0;
    end

    initial #170 $finish;
endmodule
