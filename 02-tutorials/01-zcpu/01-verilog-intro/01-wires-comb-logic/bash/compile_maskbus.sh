#!/usr/bin/env bash

cd rtl/src

verilator -Wall -cc maskbus.v
cd obj_dir
make -f Vmaskbus.mk

cd ../../../

g++-11 -I /opt/homebrew/Cellar/verilator/4.220/share/verilator/include -I rtl/src/obj_dir /opt/homebrew/Cellar/verilator/4.220/share/verilator/include/verilated.cpp cc/maskbus.cc rtl/src/obj_dir/Vmaskbus__ALL.a -o maskbus

