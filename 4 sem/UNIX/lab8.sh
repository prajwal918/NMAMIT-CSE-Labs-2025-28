#!/bin/sh
# 8. Write a shell program that takes two file names, checks the permissions for these files.
# If they are identical, output the common permissions;
# Otherwise output each filename followed by its permission.

read -p "Enter two filenames: " f1 f2

if [ -d "$f1" -o -d "$f2" ]
then
    echo "Entered filename is a directory...."
    exit
fi

if [ -e "$f1" -a -e "$f2" ]
then
    p1=`ls -l $f1 | cut -c 2-10`
    p2=`ls -l $f2 | cut -c 2-10`
    
    if [ "$p1" = "$p2" ]
    then
        echo "$f1 and $f2 have same permissions: $p1"
    else
        echo "$f1 and $f2 have different permissions"
        echo "$f1 has permission: $p1"
        echo "$f2 has permission: $p2"
    fi
else
    echo "Invalid filenames!"
fi
