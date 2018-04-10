#!/bin/bash

inden -kr -o indentado$1 $1
gcc -ftest-coverage -fprofile-arcs -o exec indentado$1

for data in datos* ; do
    ./exec < $data
done

