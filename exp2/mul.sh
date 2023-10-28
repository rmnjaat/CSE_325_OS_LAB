#!bin/bash/
echo "enter a number "
read a

for val in {1..10}
do
echo "$a * $val =" `expr $a \* $val` 
done

