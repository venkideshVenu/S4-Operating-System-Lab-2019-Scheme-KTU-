#!/bin/sh

# Prompt user for the number of elements
echo -n "Enter the Number of Elements: "
read n

# Prompt user to enter array elements
echo "Enter array elements one by one: "
for ((i=0; i<n; i++))
do
    read array[i]
done

# Prompt user to enter the key to search
read -p "Enter the Key to Search: " key

# Initialize flag to 0
flag=0

# Search for the key in the array
for (( i = 0; i < n; i++ ))
do
    if [ $key -eq ${array[i]} ]
    then
        flag=1
        break
    fi
done

# Check if the key was found and print the result
if [ $flag -eq 1 ]
then
    echo "Search Element Found At Index $i"
else
    echo "Search Element Not Found"
fi



: '
OUTPUT 1

                    Enter the Number of Elements: 5
                    Enter array elements one by one:
                    1
                    4
                    6
                    8
                    3
                    Enter the Key to Search: 8
                    Search Element Found At Index 3

OUTPUT 2

                    Enter the Number of Elements: 5
                    Enter array elements one by one:
                    9
                    8
                    4
                    6
                    5
                    Enter the Key to Search: 3
                    Search Element Not Found

'