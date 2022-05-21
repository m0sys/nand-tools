run_scirc524: iver_scirc524
	@echo
	@echo "Running scirc524_tb"
	./scirc524_tb

iver_scirc524: rtl/src/scirc524.v rtl/test/scirc524_tb.v
	@echo
	@echo "IVerlog DFF with Async Preset & Clear (scirc524) TB"
	iverilog -o scirc524_tb rtl/test/scirc524_tb.v

.PHONY: clean
clean:
	# scirc524
	rm -rf scirc524_tb
	rm -rf waveform_scirc524.vcd
