#!/bin/bash

for i in $( ls -l tests/syntax | grep ^- | awk '{print $9}' )
do
    echo $i :
    ./scc tests/syntax/$i -N -i tests/syntax/out_files/${i}.syn
done