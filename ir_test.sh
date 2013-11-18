#!/bin/bash

for i in $( ls tests/ir )
do
    echo $i :
    ./parser tests/ir/$i $i.ir
done
