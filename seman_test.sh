#!/bin/bash

for i in $( ls -l tests/seman | grep ^- | awk '{print $9}' )
do
    echo $i :
    ./scc tests/seman/$i -N -i tests/seman/out_files/${i}.sem
done