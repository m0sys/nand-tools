#!/bin/sh

cmake --build build
cd build && ctest
cd ..
