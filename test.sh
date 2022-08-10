#!/bin/bash

# remove install build
if [ -d build ] && [ ! -f build/Makefile ] 
then
   rm -rf build
fi

rm CMakeLists.txt

/usr/bin/env python3 <<END_PF_PY
from lib import createCmakeFile
createCmakeFile()
END_PF_PY

mkdir build
cd build

cmake ..
make