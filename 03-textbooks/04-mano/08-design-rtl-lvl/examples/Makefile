run_design_exmpl_rtl: iver_design_exmpl_rtl
	@echo
	@echo "Running design_exmpl_rtl_tb"
	./design_exmpl_rtl_tb

iver_design_exmpl_rtl: rtl/src/design_exmpl_rtl.v rtl/src/ctrl_rtl.v rtl/src/dp_rtl.v rtl/test/design_exmpl_rtl_tb.v
	@echo
	@echo "IVerlog design_exmpl_rtl TB"
	iverilog -o design_exmpl_rtl_tb rtl/test/design_exmpl_rtl_tb.v


.PHONY: clean
clean:
	# design_exmpl_rtl
	rm -rf design_exmpl_rtl_tb
