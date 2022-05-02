#!/usr/bin/env bash

cd rtl/src

verilator -Wall -cc thruwire.v
cd obj_dir
make -f Vthruwire.mk

cd ../../../

g++-11 -I /opt/homebrew/Cellar/verilator/4.220/share/verilator/include -I rtl/src/obj_dir /opt/homebrew/Cellar/verilator/4.220/share/verilator/include/verilated.cpp cc/thruwire.cc rtl/src/obj_dir/Vthruwire__ALL.a -o thruwire

