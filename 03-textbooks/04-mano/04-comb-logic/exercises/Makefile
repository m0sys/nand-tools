run_circ_442_df: iver_circ_442_df
	@echo
	@echo "Running circ_442_df_tb"
	./circ_442_df_tb

iver_circ_442_df: rtl/src/circ_442_df.v rtl/test/circ_442_df_tb.v
	@echo
	@echo "IVerlog Circ442 DATAFLOW TB"
	iverilog -o circ_442_df_tb rtl/test/circ_442_df_tb.v

run_circ_442_gl: iver_circ_442_gl
	@echo
	@echo "Running circ_442_gl_tb"
	./circ_442_gl_tb

iver_circ_442_gl: rtl/src/circ_442_gl.v rtl/test/circ_442_gl_tb.v
	@echo
	@echo "IVerlog Circ442 GATE-LVL TB"
	iverilog -o circ_442_gl_tb rtl/test/circ_442_gl_tb.v

run_circ_438: iver_circ_438
	@echo
	@echo "Running circ_438_tb"
	./circ_438_tb

iver_circ_438: rtl/src/circ_438.v rtl/test/circ_438_tb.v
	@echo
	@echo "IVerlog Circ438 TB"
	iverilog -o circ_438_tb rtl/test/circ_438_tb.v

run_circ_437: iver_circ_437
	@echo
	@echo "Running circ_437_tb"
	./circ_437_tb

iver_circ_437: rtl/src/circ_437.v  rtl/src/full_adder.v rtl/test/circ_437_tb.v
	@echo
	@echo "IVerlog Circ437 TB"
	iverilog -o circ_437_tb rtl/test/circ_437_tb.v

.PHONY: clean
clean:
	# circ437
	rm -rf circ_437_tb
	rm -rf waveform_circ437.vcd
	# circ438
	rm -rf circ_438_tb
	rm -rf waveform_circ438.vcd
	# circ442
	rm -rf circ_442_gl_tb
	rm -rf waveform_circ442_gl.vcd
	rm -rf circ_442_df_tb
	rm -rf waveform_circ442_df.vcd
