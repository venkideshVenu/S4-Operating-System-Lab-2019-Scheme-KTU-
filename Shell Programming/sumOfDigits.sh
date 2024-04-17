
#  Program to find the sum of digits in a number

#!/bin/sh
echo "Enter any Number : "
read num
sum=0
while [ $num -ne 0 ]
do
	digit=`expr $num % 10`
	num=`expr $num / 10`
	sum=`expr $sum + $digit`
done 
echo " Sum is $sum"





: '
		Output
	-----------------------
	$ sh sumOfDigits.sh
	Enter any Number :
	246
	Sum is 12

'