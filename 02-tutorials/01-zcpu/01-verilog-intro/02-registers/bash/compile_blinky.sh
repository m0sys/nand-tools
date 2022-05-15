#!/usr/bin/env bash

cd rtl/src
verilator -Wall --trace -GWIDTH=12 -cc blinky.v
cd obj_dir
make -f Vblinky.mk

cd ../../../

VINC="/opt/homebrew/Cellar/verilator/4.220/share/verilator/include"

g++-11 -I$VINC -I rtl/src/obj_dir $VINC/verilated.cpp $VINC/verilated_vcd_c.cpp cc/blinky.cc rtl/src/obj_dir/Vblinky__ALL.a -o blinky
