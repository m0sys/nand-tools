run_scirc635a: iver_scirc635a
	@echo
	@echo "Running scirc635a_tb"
	./scirc635a_struct_tb

iver_scirc635a: rtl/src/scirc635a_struct.v  rtl/test/scirc635a_struct_tb.v
	@echo
	@echo "IVerlog scirc635a_struct TB"
	iverilog -o scirc635a_struct_tb rtl/test/scirc635a_struct_tb.v

.PHONY: clean
clean:
	# scirc635a
	rm -rf scirc635a_struct_tb
	rm -rf waveform_scirc635a_struct.vcd
