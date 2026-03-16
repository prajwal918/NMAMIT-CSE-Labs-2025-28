#!/bin/bash

# Experiment 4: Divisibility Check
# a) Read from keyboard (interactive):
read -p "Enter the value of n and m: " n m
y=`expr $n % $m`

if [ $y -eq 0 ]
then
    echo "$n is divisible by $m"
else
    echo "$n is not divisible by $m"
fi
