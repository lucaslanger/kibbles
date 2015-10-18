#!/bin/bash 
if [[ $1 = *[!\ ]* ]]
then
	images=$(find $1 -printf "%TY-%Tm-%Td %TT %p\n" 2> /dev/null | grep .jpg | sort -n | awk '{print $3}')


	resultingImage=$(echo $1 | tr '/' '_')
	convert -append $images $resultingImage.jpg 2> /dev/null || echo "Couldn't find any images in that directory!"
else
	echo "You forget to enter an input directory!"
fi




