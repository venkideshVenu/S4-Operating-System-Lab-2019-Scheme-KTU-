
// Implement FCFS Disk Scheduling Algorithm and find the total and average head movement


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, diff, cySize, seek = 0, queSize, headPos, queue[30];

    // Input the number of cylinders
    printf("Enter the Number of Cylinders: ");
    scanf("%d", &cySize);

    // Input the current position of the head
    printf("Enter the Current Position: ");
    scanf("%d", &queue[0]);

    // Input the size of the request queue
    printf("Enter the Queue Size: ");
    scanf("%d", &queSize);

    // Input the requests in order
    printf("Enter the Requests in Order: ");
    for (i = 1; i <= queSize; i++)
    {
        scanf("%d", &queue[i]);
    }

    // Calculate seek time
    for (i = 0; i < queSize; i++)
    {
        // Calculate the absolute difference between current and next request
        diff = abs(queue[i + 1] - queue[i]);
        // Accumulate the seek time
        seek += diff;
        // Print movement details
        printf("\nMoving From %3d to %3d with Difference %3d", queue[i], queue[i + 1], diff);
    }

    // Output total seek time
    printf("\nTotal Seek Time: %d", seek);
    // Output average seek time
    printf("\nAverage Seek Time: %d", (seek / queSize));

    return 0;
}


// 98 183 37 122 14 124 65 67


/*
Enter the Number of Cylinders : 200
Enter the Current Position : 53
Enter the Queue Size  :  8
Enter the Requests in Order : 98 183 37 122 14 124 65 67

Moving From  53 to  98 with Difference 45
Moving From  98 to 183 with Difference 85
Moving From 183 to  37 with Difference 146
Moving From  37 to 122 with Difference 85
Moving From 122 to  14 with Difference 108
Moving From  14 to 124 with Difference 110
Moving From 124 to  65 with Difference 59
Moving From  65 to  67 with Difference 2
Total Seek Time   :  640
Average Seek Time :  80



*/
