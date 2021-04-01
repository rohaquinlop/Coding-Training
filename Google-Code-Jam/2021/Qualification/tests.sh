#!/bin/bash
g++ $1
./a.out < in.txt > out.txt
cat out.txt

