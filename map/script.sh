#!/bin/bash
c=1
b=1
echo -n "0" > tmp.map
while [ $b -le $1 ]
do
    echo -n " 0" >> tmp.map
    (( b++ ))
done
echo " 0" >> tmp.map
while [ $c -le $2 ]
do
    b=1
    echo -n "0" >> tmp.map
    while [ $b -le $1 ]
    do
	echo -n " 1" >> tmp.map
	(( b++ ))
    done
    echo " 0" >> tmp.map
    (( c++ ))
done
b=1
echo -n "0" >> tmp.map
while [ $b -le $1 ]
do
    echo -n " 0" >> tmp.map
    (( b++ ))
done
echo " 0" >> tmp.map
