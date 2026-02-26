#!/bin/bash
read -p "Enter 2 numbers: " m n
res=`expr $m % $n`
if [ $res -eq 0 ]
then
echo "$m is divisible by $n"
else
echo "$m is not divisible by $n"
fi
