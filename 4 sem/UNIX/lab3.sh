#!/bin/bash
read -p "Enter the operator: " choice
read -p "Enter 2 numbers: " n1 n2
case $choice in
'+') res=`expr $n1 + $n2`
echo "The result of addition: $res"
;;
'-') res=`expr $n1 - $n2`
echo "The result of subtraction: $res"
;;
'*') res=`expr $n1 \* $n2`
echo "The result of multiplication: $res"
;;
'/')
if [ $n2 -eq 0 ]
then
echo "Divide by zero error"
else
res=`expr $n1 / $n2`
echo "The result of division: $res"
fi
;;
'%') res=`expr $n1 % $n2`
echo "The result of modulus division: $res"
;;
*) echo "Invalid operator"
;;
esac
