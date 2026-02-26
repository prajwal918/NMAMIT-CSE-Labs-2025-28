#!/bin/bash
read -p "Enter the year: " y
res1=`expr $y % 400`
res2=`expr $y % 4`
res3=`expr $y % 100`
if [ $res1 -eq 0 ] || ([ $res2 -eq 0 ] && [ $res3 -ne 0 ])
then
echo "$y is a leap year"
else
echo "$y is not a leap year"
fi
