#!/bin/bash

for i in $( ls tests/ir )
do
    echo $i :
    ./scc tests/ir/$i -N -i tests/ir/out_files/${i}.ir
    ./scc tests/ir/$i -O -i tests/ir/out_files/${i}_o.ir
done
