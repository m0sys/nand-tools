#!/bin/sh

cmake --build build
./build/jack_compiler_test

##printf "Boostrap code\n"
##./build/hack_vm ../../../projects/08/FunctionCalls/StaticsTest/
##./build/hack_vm ../../../projects/08/FunctionCalls/FibonacciElement/
##./build/hack_vm ../../../projects/08/FunctionCalls/NestedCall/


##printf "Non-Boostrap code\n"
##./build/hack_vm ../../../projects/08/FunctionCalls/SimpleFunction/SimpleFunction.vm
##./build/hack_vm ../../../projects/08/ProgramFlow/BasicLoop/BasicLoop.vm
##./build/hack_vm ../../../projects/08/ProgramFlow/FibonacciSeries/FibonacciSeries.vm

##printf "Done with Asm Generation!\n\n"
