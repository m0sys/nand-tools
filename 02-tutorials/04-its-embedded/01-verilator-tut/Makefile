MODULE=alu

.PHONY:sim
sim: waveform.vcd

.PHONY:verilate
verilate: .stamp.verilate

.PHONY:build
build: rtl/src/obj/Valu

.PHONY:waves
waves: waveform.vcd
		@echo
		@echo "### WAVES ###"
		gtkwave waveform.vcd

waveform.vcd: ./rtl/src/obj_dir/V$(MODULE)
	@echo
	@echo "### SIMULATING ###"
	@./rtl/src/obj_dir/V$(MODULE)


./rtl/src/V$(MODULE): .stamp.verilate
	@echo
	@echo "### BUILDING SIM ###"
	make -C rtl/src/obj_dir -f V$(MODULE).mk V$(MODULE)

.stamp.verilate: $(MODULE).sv tb_$(MODULE).cc
	@echo
	@echo "### VERILATING ###"
	verilator -Wall --trace -cc rtl/src/$(MODULE).sv --exe cc/tb_$(MODULE).cc
	@touch .stamp.verilate

.PHONY:lint
lint: $(MODULE).sv

