#!/bin/sh

mkdir build
cd build
cmake ..
cp compile_commands.json ../
make -j 10
