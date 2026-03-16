#!/bin/bash

# Experiment 4: Divisibility Check

# a) Read from keyboard (interactive):
echo "a) Read from keyboard (interactive):"
read -p "Enter the value of n and m: " n m
y=`expr $n % $m`
if [ $y -eq 0 ]
then
    echo "$n is divisible by $m"
else
    echo "$n is not divisible by $m"
fi

echo ""

# b) Supplied as command line arguments:
echo "b) Supplied as command line arguments:"
if [ $# -eq 0 ]
then
    echo "Enter valid cmd line arg"
else
    y=`expr $1 % $2`
    if [ $y -eq 0 ]
    then
        echo "$1 is divisible by $2"
    else
        echo "$1 is not divisible by $2"
    fi
fi
