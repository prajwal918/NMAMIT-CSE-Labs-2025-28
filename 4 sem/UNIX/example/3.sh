#!/bin/bash

read -p "Enter two operands: " m n
read -p "Enter an operator: " op

case $op in
'+') res=`expr $m + $n`
     echo $res
     ;;
'-') res=`expr $m - $n`
     echo $res
     ;;
'*') res=`expr $m \* $n`
     echo $res
     ;;
'/') res=`expr $m / $n`
     echo $res
     ;;
'%') res=`expr $m % $n`
     echo $res
     ;;
*)   echo "Illegal operator"
     ;;
esac