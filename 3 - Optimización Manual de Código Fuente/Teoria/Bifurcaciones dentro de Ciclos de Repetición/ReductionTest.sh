#!/bin/bash

g++ -W -Wall -ansi -pedantic ReductionsAskWrong.c

time ./a.out $1
time ./a.out $1
time ./a.out $1
time ./a.out $1

g++ -W -Wall -ansi -pedantic ReductionsAskRight.c

time ./a.out $1
time ./a.out $1
time ./a.out $1
time ./a.out $1

g++ -W -Wall -ansi -pedantic ReductionsIfWrong.c

time ./a.out $1
time ./a.out $1
time ./a.out $1
time ./a.out $1

g++ -W -Wall -ansi -pedantic ReductionsIfRight.c

time ./a.out $1
time ./a.out $1
time ./a.out $1
time ./a.out $1

