#!/bin/bash
#
# Autor: Maximiliano A. Eschoyez
# Programacion Eficiente - UBP 2007
#
# Mon Aug  6 22:42:14 ART 2007
#

if [ -e $1.f95 ]; then

  nivelOptimizacion="O O0 O1 O2 O3 O4 O5 Os"

  for ol in $nivelOptimizacion ; do
    printf "Compilando con optimizacion -%s\n" $ol
    gfortran -W -Wall -pedantic -$ol -o $1 $1.f95 && ./$1
    echo
  done

else
  printf "Utilizar:\n\t%s NombreArchivo\n" $0
fi


