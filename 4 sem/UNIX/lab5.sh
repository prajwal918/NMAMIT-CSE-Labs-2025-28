#!/bin/bash
echo "Shell script name: $0"
if [ $# -eq 0 ]
then
echo "Invalid command line arguments"
exit
fi
echo "No of arguments: $# "
num=1
for i in $@
do
echo "Arg $num is $i"
num=`expr $num + 1`
done
echo "The input argument list is: $@"
num=$#
echo "Arguments in reverse order: "
for arg in $@
do
reverse="$arg $reverse"
echo "Arg $num is $arg"
num=`expr $num - 1`
done
echo "Reversed list is: $reverse"
