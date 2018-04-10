#!/bin/bash

for filas in 1000 3000 6000 ; do
    for i in {1..9} ; do
        time ./$1 1 $filas $filas
    done
done

