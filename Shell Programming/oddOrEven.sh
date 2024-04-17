	
	# Program to check whether a number is even or odd

	#!/bin/sh
	echo "Enter any Number : "
	read num
	b=`expr $num % 2`
	if [ $b -eq 0 ]
	then
	echo "Even"
	else
	echo "odd"
	fi

	: '

		 Output - 1 
	-----------------------

	$ sh oddOrEven.sh
	Enter any Number :
	6
	Even

	
	 	Output - 2 
	-----------------------
	
	$ sh oddOrEven.sh
	Enter any Number :
	7
	odd


	'