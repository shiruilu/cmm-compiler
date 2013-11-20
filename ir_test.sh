#!/bin/bash

for i in $( ls tests/ir )
do
    echo $i :
    ./parser tests/ir/$i tests/ir/out_files/$i.ir
done
