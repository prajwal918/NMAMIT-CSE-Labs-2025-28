#!/bin/bash
if [ $# -eq 0 ]
then
echo "Enter command line arguments"
else
res=`expr $1 % $2`
if [ $res -eq 0 ]
then
echo "$1 is divisible by $2"
else
echo "$1 is not divisible by $2"
fi
fi
