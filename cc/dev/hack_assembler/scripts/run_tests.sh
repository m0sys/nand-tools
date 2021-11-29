#!/bin/sh

cmake --build build
##cd build
##ctest
##cd ..
./build/hack_assembler_test
