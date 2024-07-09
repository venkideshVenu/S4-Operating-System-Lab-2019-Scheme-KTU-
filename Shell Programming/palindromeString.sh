#!/bin/sh

echo -n "Enter a String : "
read a
flag=1

len=${#a}
for (( i=0 ; i<len ; i++ ))
do
    if [ "${a:i:1}" != "${a:b-i-1:1}" ]
    then
        flag=0
        break

    fi
done
if [ $flag -eq 1 ]
then
    echo "Given String is Palindrome"
else
    echo "Not a Palindrome"
fi

: '

OUTPUT 1


                Enter a String : Hello
                Not a Palindrome


OUTPUT 2

                Enter a String : malayalam
                Given String is Palindrome

'