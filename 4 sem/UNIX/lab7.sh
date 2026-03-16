#!/bin/bash

# Experiment 7: Substring Extraction and Character Search
read -p "Enter a String: " str
if [ -z "$str" ]
then
    echo "Null String"
else
    z=`expr "$str" : '.*'`
    echo "String length is $z"
    if [ $z -ge 3 ]
    then
        echo "Substring is:"
        echo `expr "$str" : '.*\(...\)'`
        echo "Another Substring is:"
        echo `expr "$str" : '..\(....\).*'`
        
        read -p "Enter the character to be searched: " ch
        res=`expr "$str" : "[^$ch]*$ch"`
        if [ $res -ne 0 ]
        then
            echo "Position of character $ch in a string is $res"
        else
            echo "Character $ch does not exist in the string"
        fi
    else
        echo "String length is less than 3"
    fi
fi
