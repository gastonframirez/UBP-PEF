#!/bin/bash
#
# Autor: Maximiliano A. Eschoyez
# Programacion Eficiente - UBP 2007
#
# Mon Aug  6 22:42:14 ART 2007
#

if [ -e $1.cc ]; then

  nivelOptimizacion="O O0 O1 O2 O3 Os"
  optimizacionMatematica="float-store fast-math no-math-errno unsafe-math-optimizations finite-math-only no-trapping-math rounding-math signaling-nans"

  for ol in $nivelOptimizacion ; do
    printf "Compilando con optimizacion -%s\n" $ol
    g++ -W -Wall -ansi -pedantic -$ol -o $1 $1.cc && ./$1
    echo
  done

  for om in $optimizacionMatematica ; do
    printf "Compilando con optimizacion %s\n" $om
    g++ -W -Wall -ansi -pedantic -f$om -o $1 $1.cc && ./$1
    echo
  done

else
  printf "Utilizar:\n\t%s NombreArchivo\n" $0
fi


