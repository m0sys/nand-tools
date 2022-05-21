run_scirc528: iver_scirc528
	@echo
	@echo "Running scirc528_bh_tb"
	./scirc528_bh_tb

iver_scirc528: rtl/src/scirc528_bh.v rtl/test/scirc528_bh_tb.v
	@echo
	@echo "IVerlog scirc528 BH TB"
	iverilog -o scirc528_bh_tb rtl/test/scirc528_bh_tb.v

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
	# scirc528
	rm -rf scirc528_bh_tb
	rm -rf waveform_scirc528_bh.vcd
