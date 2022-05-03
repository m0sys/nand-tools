#!/usr/bin/env bash

cd rtl/src

verilator -Wall -cc thruwire.v
cd obj_dir
make -f Vthruwire.mk

cd ../../../

VINC="/opt/homebrew/Cellar/verilator/4.220/share/verilator/include"
g++-11 -I$VINC -I rtl/src/obj_dir $VINC/verilated.cpp cc/thruwire.cc rtl/src/obj_dir/Vthruwire__ALL.a -o thruwire

