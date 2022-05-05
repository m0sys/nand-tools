#!/usr/bin/env bash
rm -rf rtl/src/obj_dir
cd rtl/src


verilator -Wall --trace  -cc alu.sv --exe ../../cc/tb_alu.cc

make -C obj_dir -f Valu.mk Valu

cd ../../../
