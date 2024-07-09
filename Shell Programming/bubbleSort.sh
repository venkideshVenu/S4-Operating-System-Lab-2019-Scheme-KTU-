#!/bin/sh

# Prompt user for the number of elements
echo -n "Enter the Number of Elements : "
read n

# Prompt user to enter array elements
echo "Enter array Elements one by one : "
for ((i=0; i<n; i++))
do
    read array[i]
done

# Perform bubble sort
for ((i = 0; i < n-1; i++))
do
    for ((j = 0; j < n-i-1; j++))
    do
        if [ ${array[j]} -gt ${array[j+1]} ]
        then
            temp=${array[j]}
            array[j]=${array[j+1]}
            array[j+1]=$temp
        fi
    done
done

# Print sorted array
echo -n "Sorted Array is : "
for ((i = 0; i < n; i++))
do
    echo -n "${array[i]} "
done


: '
OUTPUT

                    Enter the Number of Elements : 5
                    Enter array Elements one by one :
                    8
                    1
                    6
                    4
                    5
                    Sorted Array is : 1 4 5 6 8
'