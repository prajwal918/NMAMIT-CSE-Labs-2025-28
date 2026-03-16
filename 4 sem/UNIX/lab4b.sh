#!/bin/bash

# Experiment 4: Divisibility Check
# b) Supplied as command line arguments:
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
