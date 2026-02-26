#!/bin/bash
read -p "Enter three numbers: " n1 n2 n3
if [ $n1 -gt $n2 ] && [ $n1 -gt $n3 ]
then
echo "$n1 is greatest"
elif [ $n2 -gt $n1 ] && [ $n2 -gt $n3 ]
then
echo "$n2 is greatest"
else
echo "$n3 is greatest"
fi
if [ $n1 -lt $n2 ] && [ $n1 -lt $n3 ]
then
echo "$n1 is smallest"
elif [ $n2 -lt $n1 ] && [ $n2 -lt $n3 ]
then
echo "$n2 is smallest"
else
echo "$n3 is smallest"
fi
