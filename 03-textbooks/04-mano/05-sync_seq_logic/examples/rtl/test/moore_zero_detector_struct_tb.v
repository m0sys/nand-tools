// Test bench for moore_zero_detector_struct.

`include "rtl/src/moore_zero_detector_struct.v"

module moore_zero_detector_struct_tb;

    wire t_y_out_2, t_y_out_1;
    reg t_x_in, t_clk, t_rst;

    moore_zero_detector M1 (t_y_out_1, t_x_in, t_clk, t_rst);
    moore_zero_detector_struct M2 (t_y_out_2, A, B, t_x_in, t_clk, t_rst);

    initial #200 $finish;
    initial begin
        t_rst = 0;
        t_clk = 0;
        #5 t_rst = 1;
        repeat (16);
        #5 t_clk = ~t_clk;
    end

    initial begin
        t_x_in = 0;
        #15 t_x_in = 1;
        repeat (8);
        #10 t_x_in = ~t_x_in;
    end
endmodule
