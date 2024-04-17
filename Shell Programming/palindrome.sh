

# Program to check whether a number is palindrome or not

#!/bin/sh
echo "Enter any Number : "
read num
temp=$num
rev=0
while [ $num -ne 0 ]
do
	digit=`expr $num % 10`
	rev=`expr $rev \* 10 + $digit`
	num=`expr $num / 10`
done 
if [ $temp -eq $rev ]
then
echo "Palindrome"
else
echo "Not Palindrome"
fi


: '

		 Output - 1 
	-----------------------

	$ sh paliindrome.sh
	Enter any Number :
	451
	Not Palindrome
	
	 	Output - 2 
	-----------------------
	
	$ sh palindrome.sh
	Enter any Number :
	565
	Palindrome


	'