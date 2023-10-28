#!/bin/bash

echo "Enter number 1"
read a

echo "Enter number 2"
read b

echo `expr $a + $b`
