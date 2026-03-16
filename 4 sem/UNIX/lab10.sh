#!/bin/bash

# Experiment 10: Nested Directory Creation
if [ $# -eq 0 ]
then
    echo "no arguments"
else
    w=`pwd`
    for dir in "$@"
    do
        path=`echo "$dir" | tr '/' ' '`
        for folder in $path
        do
            if [ -d "$folder" ]
            then
                echo "directory $folder already exists"
            else
                mkdir "$folder"
                echo "directory $folder created"
            fi
            cd "$folder"
        done
        cd "$w"
    done
fi
