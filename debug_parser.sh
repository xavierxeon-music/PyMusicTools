#!/bin/bash

for FILENAME in $@
do
   if [ -f $FILENAME ]
   then
      rm $FILENAME
   fi
done

/usr/bin/env python3 <<END_PF_PY
from lib import createCmakeFile, autoGenerateBindings
autoGenerateBindings()
createCmakeFile()
END_PF_PY
