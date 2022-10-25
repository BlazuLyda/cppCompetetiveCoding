#!/bin/bash

for((i=100000; i<500000; i++))
{
	echo $i
	./gen $i > in
	./zaklecia < in > wout
	./brut < in > bout
	diff wout bout || break
}