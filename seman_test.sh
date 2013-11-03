#!/bin/bash

for i in $( ls tests/seman )
do
    echo $i :
    ./parser tests/seman/$i
done