// Testbench for scirc635a_struct.

`include "rtl/src/scirc635a_struct.v"
`include "rtl/src/scirc635a_bh.v"

module scirc635a_tb;
    wire [3:0] t_A_o4;
    wire [3:0] t_A_o4_2;
    reg [3:0] t_I_i4;
    reg t_ld_i;
    reg t_clear_i;
    reg t_clk_i;

    parameter stop_time = 150;

    scirc635a_struct dut (
        // OUTPUTS
        .A_o4(t_A_o4)

        // INPUTS
        ,.I_i4(t_I_i4)
        ,.ld_i(t_ld_i)
        ,.clear_i(t_clear_i)
        ,.clk_i(t_clk_i)
    );

    scirc635a_bh dut2 (
        // OUTPUTS
        .A_o4(t_A_o4_2)

        // INPUTS
        ,.I_i4(t_I_i4)
        ,.ld_i(t_ld_i)
        ,.clear_i(t_clear_i)
        ,.clk_i(t_clk_i)
    );

    initial #stop_time $finish;
    
    // Setup clk + vcd out.
    initial begin
        $dumpfile("waveform_scirc635a.vcd");
        $dumpvars(0, scirc635a_tb);
        t_clk_i = 0; forever #5 t_clk_i = ~t_clk_i;
    end

    initial fork
        t_clear_i = 1; t_ld_i = 0;
        #6 t_clear_i = 0;
        #11 t_I_i4 = 4'b1111; #11 t_ld_i = 1;
        #16 t_I_i4 = 4'b1110;
        #21 t_I_i4 = 4'b1101;
        #26 t_I_i4 = 4'b1100;
        #31 t_I_i4 = 4'b1011;
        #36 t_I_i4 = 4'b1010;
        #41 t_I_i4 = 4'b1001;
        #46 t_I_i4 = 4'b1000;
        #51 t_I_i4 = 4'b0111;
        #56 t_I_i4 = 4'b0110;
        #61 t_I_i4 = 4'b0101;
        #66 t_I_i4 = 4'b0100;
        #71 t_I_i4 = 4'b0011;
        #76 t_I_i4 = 4'b0010;
        #81 t_I_i4 = 4'b0001;
        #86 t_I_i4 = 4'b0000;
        #91 t_I_i4 = 4'b1010;
        #96 t_ld_i = 0;
        #121 t_clear_i = 1; #126 t_clear_i = 0;
    join
endmodule
