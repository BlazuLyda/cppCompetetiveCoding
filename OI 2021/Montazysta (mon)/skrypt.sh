#!/bin/bash
for i in {0..4999}
do
	echo $i

    ./mon < ./mon-duze/in/mon${i}.in > wout

    ./spr ./mon-duze/in/mon${i}.in wout ./mon-duze/out/mon${i}.out

done

