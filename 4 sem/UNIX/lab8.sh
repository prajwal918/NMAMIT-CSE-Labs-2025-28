#!/bin/sh
echo "Enter the two file names: "
read f1 f2
if [ -d $f1 -o -d $f2 ]
then 
echo "Entered file name is a directory...."
exit
fi
if [ -e $f1 -a -e $f2 ] #a-> logical AND
then
p1=`ls -l $f1 | cut -c 2-10`
p2=`ls -l $f2 | cut -c 2-10`
if [ "$p1" = "$p2" ]
then
echo "$f1  and $f2 have same permissions: $p1"
else
 echo "$f1  and $f2 have different permissions............" #use chmod 674 
 echo "$f1 has permission : $p1"
 echo "$f2 has permission : $p2"
fi
else
echo "Invalid file names!"
fi 
