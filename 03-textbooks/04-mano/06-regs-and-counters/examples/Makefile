run_ripple_cnt: iver_ripple_cnt
	@echo
	@echo "Running ripple_cnter_4bit_tb"
	./ripple_cnter_4bit_tb

iver_ripple_cnt: rtl/src/ripple_cnter_4bit.v  rtl/test/ripple_cnter_4bit_tb.v
	@echo
	@echo "IVerlog ripple_cnter_4bit TB"
	iverilog -o ripple_cnter_4bit_tb rtl/test/ripple_cnter_4bit_tb.v

.PHONY: clean
clean:
	# ripple_cnt
	rm -rf ripple_cnter_4bit_tb
	rm -rf waveform_ripple_cnt.vcd
