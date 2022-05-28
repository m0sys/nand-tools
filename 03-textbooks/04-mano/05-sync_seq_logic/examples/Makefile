run_zero_detector: iver_zero_detector
	@echo
	@echo "Running zero_detector_tb"
	./zero_detector_tb

iver_zero_detector: rtl/src/zero_detector.v rtl/test/zero_detector_tb.v
	@echo
	@echo "IVerlog Zero Detector TB"
	iverilog -o zero_detector_tb rtl/test/zero_detector_tb.v

.PHONY: clean
clean:
	# circ437
	rm -rf zero_detector_tb
	rm -rf waveform_zero_detector.vcd
