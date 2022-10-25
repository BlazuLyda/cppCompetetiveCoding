#!/bin/bash

for ((i=0; i<100000; i++)); do
	echo $i
	./gen $i > in
	./sciezki < in > wout
	./brut < in > bout
	diff wout bout || break
done
