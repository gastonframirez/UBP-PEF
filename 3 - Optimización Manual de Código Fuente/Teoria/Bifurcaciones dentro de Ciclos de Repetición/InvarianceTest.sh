#!/bin/bash

g++ -W -Wall -ansi -pedantic InvariantCondWrong.c

time ./a.out $1
time ./a.out $1
time ./a.out $1
time ./a.out $1

g++ -W -Wall -ansi -pedantic InvariantCondRight.c

time ./a.out $1
time ./a.out $1
time ./a.out $1
time ./a.out $1

