#!/bin/bash

for ((i=1; i<=1000; i++)); do
	echo $i
	./oranzada < ./in/$i.in > wout
	diff wout ./out/$i.out | break
done
