#!/bin/bash 

for processID in $(ps l | awk '{print $3 " " $2 "-" $13}' | grep $UID-less | awk '{print $1}')
do
	echo "Killing the following processId: " $processID
	kill $processID
done
