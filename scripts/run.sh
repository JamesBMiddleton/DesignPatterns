#! /bin/sh

cmake -S . -B ./out/build
cd out/build
make
ctest --output-on-failure
./src/DesignPatterns
# remember to sudo chmod +x run.sh
