#!/bin/bash

for((i=1; i<=100; i++))
do
	echo $i
	
	./gen $i > in
	
	./brut < in > bout
	./wzor < in > wout
	
	diff bout wout || break
done
