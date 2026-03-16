#!/bin/bash

read -p " Enter the year " year
x=`expr $year % 400`
y=`expr $year % 4`
z=`expr $year % 100`
if [ $x -eq 0 ] || ([ $y -eq 0 ] && [ $z -ne 0 ])
then
echo " $year is a leap year"
else
echo " $year is not leap year"
fi
