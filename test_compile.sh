#!/bin/bash

# remove install build
if [ -d build ] && [ ! -f build/Makefile ] 
then
   rm -rf build
fi

touch CMakeLists.txt
rm CMakeLists.txt

/usr/bin/env python3 <<END_PF_PY
from lib import createCmakeFile, autoGenerateBindings
autoGenerateBindings()
createCmakeFile()
END_PF_PY

if [ ! -d build ] 
then
   mkdir build
fi

cd build
cmake ..
make
