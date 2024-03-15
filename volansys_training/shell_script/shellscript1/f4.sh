#!/bin/bash
clear

echo "enter the first number"
read number1
echo "enter the second number"
read number2
(( sum = $number1 + $number2 ))
echo "$sum"
