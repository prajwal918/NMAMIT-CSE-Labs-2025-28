#!/bin/bash
read -p "Enter a string: " str
if [ -z "$str" ]
then
echo "Null String"
z=0
else
z=`expr "$str" : ".*"`
echo "string length is $z"
fi
if [ $z -ge 6 ]
then
echo "First 3 characters: "
echo `expr "$str" : '\(...\).*'`
echo "Last 3 characters: "
echo `expr "$str" : '.*\(...\)'`
else
echo "Length of the String is less than 6"
fi
