
# Print Even Elements in a given array 

#!/bin/sh

# Read the array size
echo -n "Enter the number of Elements: "
read n

# Read the array elements
echo "Enter the Array Elements : "
for (( i=0; i<$n; i++ ))
do
    read array[i]
done

# Print the even numbers
echo -n "Even numbers in the array are : "
for (( i=0; i<$n; i++ ))
do
    if [ $((${array[i]} % 2)) -eq 0 ]
    then
        echo -n "${array[i]} "
    fi
done


: '
OUTPUT

                Enter the number of Elements: 8
                Enter the Array Elements :
                7
                4
                9
                2
                5
                3
                6
                1
                Even numbers in the array are : 4 2 6

'