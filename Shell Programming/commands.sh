
: '
	Menu driven program to display 
		1) current working directory
		2) Today date
		3) List of Users login
'

#!/bin/sh
echo "   1 - Current Working directory"
echo "   2 - Today's Data"
echo "   3 - List of Users"
echo "   4 - Exit "
while [ 1 -eq 1 ]
do
	
	echo "Choose Option :"
	read c
	case $c in
	1)pwd;;
	2)date;;
	3)who;;
	4)exit;;

	*)echo "Invalid Input";;
	esac
done



: '
			Output
--------------------------------
		$ sh commands.sh
	1 - Current Working directory
	2 - Today Data
	3 - List of Users
	4 - Exit
	Choose Option :
	1
	/d/Projects/S4 OS Lab/Shell Programming
	Choose Option :
	2
	Wed, Apr 17, 2024  6:49:17 PM
	Choose Option :
	3
	Choose Option :
	4
'