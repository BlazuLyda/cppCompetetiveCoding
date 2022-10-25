#!/bin/bash

for i in {0..4999}
do
  echo $i
  
  ./mon < ./mon-duze/in/mon$i.in > wout
  read -r firstline < ./mon-duze/out/mon$i.out > bout 
  
  diff wout bout | break
done
