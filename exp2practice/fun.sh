#!/bin/sh

#defining function

Hello(){
	read eg
	echo "Hello,$eg  $1 $2 $eg"
	return 10
}

#Invoking
Hello Raman 18

#capturing returned value
ret=$?
echo "Returned value is $ret"
