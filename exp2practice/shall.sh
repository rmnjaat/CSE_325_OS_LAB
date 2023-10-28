#!/bin/bash

#echo "enter a number you want table "
#read a

#for v in {1..10}
#do
#echo "$a * $v = " `expr $a \* $v`
#done


#if [ 2 -lt 1 -a 1 -lt 2 ]
#then 
#echo " or"

#else
#echo "--"
#fi


#echo "enter file name "

#read a


#for i in $@
#do
#if [ `expr $i % 2` == 0 ]
#then 
#echo "this is even"
#else
#echo "this is odd"
#fi
#done



#read a
#read b
#cp $a $b
#echo "copy sucessfull"
#word=$(wc -w  "$a")
#word=$(ls -l $a)
#echo "sucessfull"
#echo $word

#a=0
#while [ $a -ne 5 ]
#do
#echo " choose 1 2 3 4  = + - * /     choose 5 for exit"
#read a
#echo "enter number 1 "
#read b 
#echo " enter number 2 "
#read c
#case $a in 
#1)
#echo "addition of $b and $c is `expr $b + $c `";;
#
#2)
#echo "subtraction of $b - $c is `expr $b - $c`";;
#3)
#echo "mul of $b * $c `expr $b \* $c`";;
#4)
#echo "divid od $b / $c is `expr $b / $c` ";;
#*)
#break;;
#esac
#echo "sucessfull"
#done


#read a
#for((i=2;i<a;i++))
#do
#c=0
#for((j=1;j<=i;j++))
#do
#if [ `expr $i % $j` == 0 ]
#then 
#c=`expr $c + 1`
#else
#d=9
#fi
#done
#if [ $c -eq 2 ]
#then
#echo -n "$i"
#fi
#done

pwd
