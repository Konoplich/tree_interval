#!/bin/bash
F=knowhow.c
I=./test_interface/interface/test_public/public/test_protected/protected/test_private/private/test_knowhow/knowhow
rm ./libtreeint.so
gcc -shared -o libtreeint.so -fPIC ${F} -I${I} -g
cp libtreeint.so ..
cp libtreeint.h ..
