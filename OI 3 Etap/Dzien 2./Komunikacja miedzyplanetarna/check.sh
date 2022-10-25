#!/bin/bash

for((i=1; i<=100000; i++))
{
	echo $i
	
	./gen $i > in
	./komunikacja1 < in > wout
	./kom2 < in > bout
	
	diff bout wout || break
}
