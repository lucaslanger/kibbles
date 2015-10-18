#!/bin/bash 

while( true )
do
	for pair in $(ps l | awk '{print $3 " " $6 " " $2 "-" $13}' | grep $UID-sleep | awk '{print $1 "," $2}')
	do	
		pID=$(echo $pair | cut -d "," -f1,3)
		niceFactor=$(echo $pair | cut -d "," -f2,3)	
	
		if ( test $niceFactor -lt 5 )
		then
			echo "Killing: " $pID
			kill $pID
		fi 
	done
done
	
