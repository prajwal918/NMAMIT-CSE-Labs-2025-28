#!/bin/bash

read -p "Enter Day number: " day
case $day in
1) echo "Day is monday"
;;
2) echo "Day is Tuesday"
;;
3) echo "Day is Wednesday"
;;
4) echo "Day is Thursday"
;;
5) echo "Day is Friday"
;;
6) echo "Day is Saturday"
;;
7) echo "Day is Sunday"
;;
*) echo "Invalid day number"
;;
esac
