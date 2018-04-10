#!/bin/bash

for i in *.c ; do
    echo Probando $i
    gcc -W -Wall -ansi -pedantic $i
    time ./a.out $1
    time ./a.out $1
    time ./a.out $1
done
