d=1
while [ $d -ne 5 ]
do


echo " chosse 1,2,3,4   +,-,*,\ respectively and   5 for exit" 
read c

if [ $c -eq 5 ]
then
 break
fi

echo "num 1 ="
read a
echo "num 2="
read b



case $c in 
1) echo `expr $a + $b`;;
2)echo `expr $a - $b`;;
3) echo `expr $a \* $b`;;
4)echo `expr $a / $b`;;

esac
done 
