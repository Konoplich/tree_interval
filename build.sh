#!/bin/bash
rm ./ok
gcc main.c -o ok -L. -ltreeint -Wl,-rpath,. -I. -g
