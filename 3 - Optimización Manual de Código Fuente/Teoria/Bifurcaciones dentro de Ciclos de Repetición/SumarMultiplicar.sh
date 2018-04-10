#!/bin/bash

g++ -W -Wall -ansi -pedantic SumaMultiplica.c

time ./a.out $1
time ./a.out $1
time ./a.out $1
time ./a.out $1

g++ -W -Wall -ansi -pedantic SumaMultiplicaMacro.c

time ./a.out $1
time ./a.out $1
time ./a.out $1
time ./a.out $1

g++ -W -Wall -ansi -pedantic SumaMultiplicaFuncion.c

time ./a.out $1
time ./a.out $1
time ./a.out $1
time ./a.out $1


