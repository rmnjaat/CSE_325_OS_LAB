#!bin/bash
echo "enter a number "
read a
for((i=2;i<a;i++))
do
c=0
for((j=1;j<=i;j++))
do
if [ `expr $i % $j` == 0 ]
then 
c=`expr $c + 1`
else
d=9
fi
done
if [ $c -eq 2 ]
then
echo -n " $i "
fi
done
