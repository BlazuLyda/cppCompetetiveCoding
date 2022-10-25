#!/bin/bash

for ((i=1; i<=200; i++)); do
	echo $i
	
	./pandemia < ./b_tests/in/$i.in > wout
	diff wout ./b_tests/out/$i.out | break
done
