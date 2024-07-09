
# Print Even Elements in a given array 

#!/bin/sh

# Read the array size
echo "Enter the number of elements in the array: "
read n

# Read the array elements
echo "Enter the array elements: "
for (( i=0; i<$n; i++ ))
do
    read array[i]
done

# Print the even numbers
echo "Even numbers in the array are: "
for (( i=0; i<$n; i++ ))
do
    if [ $((${array[i]} % 2)) -eq 0 ]
    then
        echo ${array[i]}
    fi
done