#!/bin/bash

for i in $( ls tests/goal )
do
    echo $i :
    ./scc -N -s tests/goal/$i tests/goal/out_files/${i}.s
    ./scc -O -s tests/goal/$i tests/goal/out_files/${i}_o.s
done
