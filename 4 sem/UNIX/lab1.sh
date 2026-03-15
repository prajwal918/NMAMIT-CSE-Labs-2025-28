#!/bin/bash

read -p "Enter the numbers: " a b c

if [ $a -gt $b ] && [ $a -gt $c ]
then
echo "the largest number is $a"
elif [ $b -gt $c ] && [ $b -gt $a ]
then
echo "The largest number is $b"
else
echo "The largest number is $c"
fi
if [ $a -lt $b ] && [ $a -lt $c ]
then
echo "the smallest number is $a"
elif [ $b -lt $c ] && [ $b -lt $a ]
then
echo "The smallest number is $b"
else
echo "The smallest number is $c"
fi
