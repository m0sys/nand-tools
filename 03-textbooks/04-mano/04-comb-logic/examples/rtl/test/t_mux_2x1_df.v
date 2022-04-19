// Test bench with stimulus for mux_2x1_df.

module t_mux_2x1_df;
    wire t_mux_out;
    reg t_A, t_B;
    reg t_sel;
    parameter stop_time = 50;

    mux_2x1_df M1 (t_mux_out, t_A, t_B, t_sel);

    initial # stop_time $finish;

    initial begin // stimulus gen
        t_sel = 1; t_A = 0; t_B = 1;
        #10 t_A = 1; t_B = 0;
        #10 t_sel = 0;
        #10 t_A = 0; t_B = 1;
    end

    initial begin // response monitor
        $monitor ("time =", $time, "sel = %b A = %b B = %b OUT = %b", t_sel, t_A, t_B, t_mux_out);
    end
endmodule
