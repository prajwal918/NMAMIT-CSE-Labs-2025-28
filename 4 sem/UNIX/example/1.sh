#!/bin/bash

read -p "Enter three numbers: " x y z

if [ $x -gt $y ] && [ $x -gt $z ]
then
echo "$x is greater"
elif [ $y -gt $x ] && [ $y -gt $z ]
then
echo "$y is greater"
else
echo "$z is greater"
fi

if [ $x -lt $y ] && [ $x -lt $z ]
then
echo "$x is smaller"
elif [ $y -lt $x ] && [ $y -lt $z ]
then
echo "$y is smaller"
else
echo "$z is smaller"
fi