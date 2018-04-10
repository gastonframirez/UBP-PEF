#!/bin/bash

g++ -W -Wall -ansi -pedantic IndexDependentCondWrong.c

time ./a.out $1
time ./a.out $1
time ./a.out $1
time ./a.out $1

g++ -W -Wall -ansi -pedantic IndexDependentCondRight.c

time ./a.out $1
time ./a.out $1
time ./a.out $1
time ./a.out $1

