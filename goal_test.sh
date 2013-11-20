#!/bin/bash

for i in $( ls tests/goal )
do
    echo $i :
    ./scc tests/goal/$i tests/goal/out_files/$i.s
done
