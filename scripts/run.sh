#! /bin/sh

cd ..
cmake -S . -B ./build
cd build
make
ctest
./src/DesignPatterns
# remember to sudo chmod +x run.sh