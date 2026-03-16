#!/bin/bash

# Experiment 9: Renaming Files to Uppercase
if [ $# -eq 0 ]
then
    echo "Invalid arguments!!!"
    exit
fi

for file in "$@"
do
    if [ -f "$file" ]
    then
        ufile=`echo "$file" | tr '[a-z]' '[A-Z]'`
        if [ -f "$ufile" ]
        then
            echo "$ufile already exists"
        else
            mv "$file" "$ufile"
            echo "$file renamed to $ufile"
        fi
    else
        echo "$file does not exist"
    fi
done
