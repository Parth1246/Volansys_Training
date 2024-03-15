#! /bin/bash

sum=0
i=0
val=$#
echo $#

echo $@

echo $1

for i in "$@"
do
              sum=$(( sum + i ))
done


echo "sum = $sum"

