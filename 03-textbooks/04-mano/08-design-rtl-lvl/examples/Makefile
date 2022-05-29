run_scirc658: iver_scirc658
	@echo
	@echo "Running scirc658_tb"
	./scirc658_tb

iver_scirc658: rtl/src/scirc658_struct.v rtl/src/scirc658_bh.v rtl/test/scirc658_tb.v
	@echo
	@echo "IVerlog scirc658 TB"
	iverilog -o scirc658_tb rtl/test/scirc658_tb.v

run_scirc659: iver_scirc659
	@echo
	@echo "Running scirc659_tb"
	./scirc659_tb

iver_scirc659: rtl/src/scirc659_struct.v rtl/src/scirc659_bh.v rtl/test/scirc659_tb.v
	@echo
	@echo "IVerlog scirc659 TB"
	iverilog -o scirc659_tb rtl/test/scirc659_tb.v

run_scirc635c: iver_scirc635c
	@echo
	@echo "Running scirc635c_tb"
	./scirc635c_tb

iver_scirc635c: rtl/src/scirc635c_struct.v rtl/src/scirc635c_bh.v rtl/test/scirc635c_tb.v
	@echo
	@echo "IVerlog scirc635c TB"
	iverilog -o scirc635c_tb rtl/test/scirc635c_tb.v

run_scirc635a: iver_scirc635a
	@echo
	@echo "Running scirc635a_tb"
	./scirc635a_tb

iver_scirc635a: rtl/src/scirc635a_struct.v rtl/src/scirc635a_bh.v  rtl/test/scirc635a_tb.v
	@echo
	@echo "IVerlog scirc635a TB"
	iverilog -o scirc635a_tb rtl/test/scirc635a_tb.v

.PHONY: clean
clean:
	# scirc635a
	rm -rf scirc635a_tb
	rm -rf waveform_scirc635a.vcd
	# scirc635c
	rm -rf scirc635c_tb
	rm -rf waveform_scirc635c.vcd
	# scirc659
	rm -rf scirc659_tb
	rm -rf waveform_scirc659.vcd
	# scirc658
	rm -rf scirc658_tb
	rm -rf waveform_scirc658.vcd
