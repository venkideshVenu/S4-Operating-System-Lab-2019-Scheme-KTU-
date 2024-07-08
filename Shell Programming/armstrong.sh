

#!/bin/sh

echo "Enter a Number : "
read num
copy=$num
check=0

while [ $num -ne 0 ]
do
    digit=`expr $num % 10`
    check=`expr $check + $digit \* $digit \* $digit`
    num=`expr $num / 10`
done

if [ $check -eq $copy ]
then
    echo "Number is Armstrong"
else
    echo "Number is not Armstrong"
fi




: '

OUTPUT 1 

			Enter a Number :
			153
			Number is Armstrong


OUTPUT 2

			Enter a Number :
			245
			Number is not Armstrong


'