#!/bin/sh

read n
q=`expr $n % 2`


if [ $q -eq 0 ]
then
echo " $n is even number"
else
echo " $n is odd number"
fi




