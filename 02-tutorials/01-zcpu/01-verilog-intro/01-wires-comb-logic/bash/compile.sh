#!/usr/bin/env bash
g++-11 -I /opt/homebrew/Cellar/verilator/4.220/share/verilator/include -I rtl/src/obj_dir /opt/homebrew/Cellar/verilator/4.220/share/verilator/include/verilated.cpp cc/thruwire.cc rtl/src/obj_dir/Vthruwire__ALL.a -o thruwire

