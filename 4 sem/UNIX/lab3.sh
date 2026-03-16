#!/bin/bash
read -p " Enter an operator: " op
read -p " Enter two operands " a b
case $op in
'+')res=`expr $a + $b`
echo " The result is : $res "
;;
'-')res=`expr $a - $b`
echo " The result is : $res "
;;
'/')
if [ $b -eq 0 ]
then
echo " Divide by zero error "
else
res=`expr $a / $b`
echo " The result is : $res "
fi
;;
'*')res=`expr $a \* $b`
echo " The result is : $res "
;;
'%')res=`expr $a % $b`
echo " The result is : $res "
;;
*)
echo " Invalid operator "
;;
esac
