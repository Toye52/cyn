#!/bin/bash

mkdir -p build
cd build

cmake ../Factory
make

./Myproject
