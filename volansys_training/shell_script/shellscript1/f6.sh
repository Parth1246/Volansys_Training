#!/bin/bash
clear

for file in *.txt
do
    mv "$file" "${file%.txt}.text"
done
