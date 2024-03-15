#!/bin/bash
clear

sum=0
i=0
for i in "$@"
do
    sum=$((sum + i))
done
echo "sum = $sum"
