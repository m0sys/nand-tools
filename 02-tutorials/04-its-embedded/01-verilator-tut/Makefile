MODULE=alu

.PHONY:sim
sim: waveform.vcd

.PHONY:verilate
verilate: .stamp.verilate

.PHONY:build
build: obj_dir/Valu

.PHONY:waves
waves: waveform.vcd
		@echo
		@echo "### WAVES ###"
		gtkwave waveform.vcd

waveform.vcd: ./obj_dir/V$(MODULE)
	@echo
	@echo "### SIMULATING ###"
	@./obj_dir/V$(MODULE) +verilator+rand+reset+2


./obj_dir/V$(MODULE): .stamp.verilate
	@echo
	@echo "### BUILDING SIM ###"
	make -C obj_dir -f V$(MODULE).mk V$(MODULE)

.stamp.verilate: rtl/src/$(MODULE).sv cc/tb_$(MODULE).cc
	@echo
	@echo "### VERILATING ###"
	verilator -Wall --trace --x-assign unique --x-initial unique -cc rtl/src/$(MODULE).sv --exe cc/tb_$(MODULE).cc
	@touch .stamp.verilate

.PHONY:lint
lint: rtl/src/$(MODULE).sv
	verilator --lint-only rtl/src/$(MODULE).sv

.PHONY:clean
clean:
	rm -rf .stamp.*;
	rm -rf obj_dir
	rm -rf waveform.vcd


