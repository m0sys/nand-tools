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
	rm -rf circ_437_tb
	rm -rf waveform.vcd
