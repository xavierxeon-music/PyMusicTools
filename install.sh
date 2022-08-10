#!/bin/bash

# remove test build
if [ -d build ] && [ -f build/Makefile ] 
then
   rm -rf build
fi

/usr/bin/env python3 -m pip install --user .
