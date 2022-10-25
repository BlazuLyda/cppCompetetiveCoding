#!/bin/bash

for((i=1; i<=10; i++))
do
	./rand $i > num
	echo $num
	
done
