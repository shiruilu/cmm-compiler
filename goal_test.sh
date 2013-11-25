#!/bin/bash

for i in $( ls -l tests/goal | grep ^- | awk '{print $9}' )
do
    echo $i :
    ./scc tests/goal/$i -N -s tests/goal/out_files/${i}.s
    ./scc tests/goal/$i -O -s tests/goal/out_files/${i}_o.s
done
