#!/usr/bin/env bash

make clean
./premake5 gmake2
bear -- make config=debug
