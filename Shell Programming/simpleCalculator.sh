
# Program to implement simple calculator

#!/bin/sh
echo "      1 - Addition "
echo "      2 - Subtraction "
echo "      3 - Multiplication"
echo "      4 - Division "
echo "      5 - Modulus "
echo "      6 - Exit"
while [ 1 -eq 1 ]
do
	echo " Enter Option : "
	read c
	echo " Enter Two Numbers :"
	read a b
	
	case $c in
	1)echo " $a + $b = `expr $a + $b`";;
	2)echo " $a - $b = `expr $a - $b`";;
	3)echo " $a * $b = `expr $a \* $b`";;
	4)echo " $a / $b = `expr $a / $b`";;
	5)echo " $a % $b = `expr $a % $b`";;
	6)exit;;
	*)echo "    Invalid Input !!!";;
	esac
done


: '

		 Output 
	-----------------------

	$ sh simpleCalculator.sh
      1 - Addition
      2 - Subtraction
      3 - Multiplication
      4 - Division
      5 - Modulus
      6 - Exit
 Enter Option :
1
 Enter Two Numbers :
6 5
 6 + 5 = 11
 Enter Option :
2
 Enter Two Numbers :
8 2
 8 - 2 = 6
 Enter Option :
3
 Enter Two Numbers :
4 3
 4 * 3 = 12
 Enter Option :
4
 Enter Two Numbers :
12 6
 12 / 6 = 2
 Enter Option :
5
 Enter Two Numbers :
50 5
 50 % 5 = 0
 Enter Option :
6
 Enter Two Numbers :
1


	'