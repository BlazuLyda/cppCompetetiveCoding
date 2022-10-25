#!/bin/bash

for ((i=0; i<=999; i++)); do
	echo $i
	
	./impreza < ./tests2/in/imp$i.in > wout
	diff wout ./tests2/out/imp$i.out | break
done
