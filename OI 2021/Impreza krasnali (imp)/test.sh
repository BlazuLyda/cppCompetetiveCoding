#!/bin/bash
i=1

while read -r line; do
	echo $i
	words=( $line )
	input=${words[0]}
	bout=${words[1]}
	
	if [ $input == "res:" ]; then
		echo "Good"
		break
	fi
	
	wout=$(echo $input$'\n' | ./imprezaTest)
	
	if [ $wout != $bout ]; then
		break
	fi
	
	i=$((i+1))
done < "./out8"