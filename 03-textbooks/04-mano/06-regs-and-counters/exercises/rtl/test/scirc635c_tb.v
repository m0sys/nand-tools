// Testbench for scirc635c_struct.

`include "rtl/src/scirc635c_struct.v"
`include "rtl/src/scirc635c_bh.v"

module scirc635c_tb;
    wire [3:0] t_A_o4;
    wire [3:0] t_A_o4_2;
    reg [3:0] t_I_i4;
    reg t_ld_i;
    reg t_shift_i;
    reg t_bstream_i;
    reg t_clk_i;
    reg t_rst_i;

    parameter stop_time = 200;

    scirc635c_struct dut (
        // OUTPUTS
        .A_o4(t_A_o4)

        // INPUTS
        ,.I_i4(t_I_i4)
        ,.ld_i(t_ld_i)
        ,.shift_i(t_shift_i)
        ,.bstream_i(t_bstream_i)
        ,.clk_i(t_clk_i)
        ,.rst_i(t_rst_i)
    );

    scirc635c_bh dut2 (
        // OUTPUTS
        .A_o4(t_A_o4_2)

        // INPUTS
        ,.I_i4(t_I_i4)
        ,.ld_i(t_ld_i)
        ,.shift_i(t_shift_i)
        ,.bstream_i(t_bstream_i)
        ,.clk_i(t_clk_i)
        ,.rst_i(t_rst_i)
    );

    initial #stop_time $finish;
    
    // Setup clk + vcd out.
    initial begin
        $dumpfile("waveform_scirc635c.vcd");
        $dumpvars(0, scirc635c_tb);
        t_clk_i = 0; forever #5 t_clk_i = ~t_clk_i;
    end

    initial fork
        t_rst_i = 0; t_ld_i = 0; t_shift_i = 0;
        #2 t_rst_i = 1;
        // Test para load.
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
        #102 t_rst_i = 0; #104 t_rst_i = 1;
        // Test shift with bstream capability.
        #106 t_ld_i = 1; #106 t_I_i4 = 4'b0001;
        #111 t_ld_i = 0; #111 t_shift_i = 1; #111 t_bstream_i = 1;
        #116 t_bstream_i = 0;
        #121 t_bstream_i = 1;
        #126 t_bstream_i = 0;
        #131 t_bstream_i = 1;
        #151 t_bstream_i = 0;
        #182 t_rst_i = 0; #184 t_rst_i = 1;
        #186 t_shift_i = 0; #186 t_ld_i = 1; #186 t_I_i4 = 4'b0101;
    join
endmodule
