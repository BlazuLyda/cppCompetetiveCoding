#!/bin/bash

for((i=0;i<1000;i++))
do
	echo $i
	./gen $i > in
	./trasa < in > wout
	./brut < in > bout
	diff wout bout || break
done