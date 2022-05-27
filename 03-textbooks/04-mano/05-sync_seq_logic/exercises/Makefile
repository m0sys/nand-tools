run_sr_latch: iver_sr_latch
	@echo
	@echo "Running sr_latch_tb"
	./sr_latch_tb

iver_sr_latch: rtl/src/sr_latch.v rtl/test/sr_latch_tb.v
	@echo
	@echo "IVerlog SR Latch TB"
	iverilog -o sr_latch_tb rtl/test/sr_latch_tb.v

run_wave532: iver_wave532
	@echo
	@echo "Running wave532_tb"
	./wave532_tb

iver_wave532: rtl/test/wave532_tb.v
	@echo
	@echo "IVerlog wave532 TB"
	iverilog -o wave532_tb rtl/test/wave532_tb.v

run_scirc529: iver_scirc529
	@echo
	@echo "Running scirc529_tb"
	./scirc529_tb

iver_scirc529: rtl/src/scirc529_bh.v  rtl/test/scirc529_tb.v
	@echo
	@echo "IVerlog scirc529 BH & STRUCT TB"
	iverilog -o scirc529_tb rtl/test/scirc529_tb.v

run_scirc528: iver_scirc528
	@echo
	@echo "Running scirc528_tb"
	./scirc528_tb

iver_scirc528: rtl/src/scirc528_bh.v rtl/src/scirc528_struc.v rtl/test/scirc528_tb.v
	@echo
	@echo "IVerlog scirc528 BH & STRUCT TB"
	iverilog -o scirc528_tb rtl/test/scirc528_tb.v

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
	rm -rf scirc528_tb
	rm -rf waveform_scirc528.vcd
	# scirc529
	rm -rf scirc529_tb
	rm -rf waveform_scirc529.vcd
	# wave532
	rm -rf wave532_tb
	rm -rf waveform_wave532.vcd
	# sr_latch
	rm -rf sr_latch_tb
	rm -rf waveform_sr_latch.vcd
