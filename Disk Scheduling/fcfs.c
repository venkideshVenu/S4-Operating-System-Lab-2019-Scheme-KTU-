
// Implement FCFS Disk Scheduling Algorithm and find the total and average head movement


#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, diff, cySize, seek = 0, queSize, request[30];

    // Input the number of cylinders
    printf("Enter the Number of Cylinders: ");
    scanf("%d", &cySize);

    // Input the current position of the head
    printf("Enter the Current Position: ");
    scanf("%d", &request[0]);

    // Input the size of the request queue
    printf("Enter the Queue Size: ");
    scanf("%d", &queSize);

    // Input the requests in order
    printf("Enter the Requests in Order: ");
    for (i = 1; i <= queSize; i++)
        scanf("%d", &request[i]);

    printf("\n           Head Movement           Seek Distance ");
    printf("\n     ---------------------------------------------------\n");

    // Calculate seek time
    for (i = 0; i < queSize; i++)
    {
        // Calculate the absolute difference between current and next request
        diff = abs(request[i + 1] - request[i]);
        // Accumulate the seek time
        seek += diff;
        // Print movement details
        printf("\n\t   %3d to %3d  \t\t\t%3d", request[i], request[i + 1], diff);
    }

    // Output total seek time
    printf("\n\n  Total Seek Time    : %d", seek);
    // Output average seek time
    printf("\n  Average Seek Time  : %.2f", (float)(seek/queSize));

    return 0;
}


/*                                  OUTUPUT 1


                Enter the Number of Cylinders: 200
                Enter the Current Position: 53
                Enter the Queue Size: 8
                Enter the Requests in Order: 98 183 37 122 14 124 65 67

                           Head Movement           Seek Distance
                     ---------------------------------------------------

                            53 to  98                    45
                            98 to 183                    85
                           183 to  37                   146
                            37 to 122                    85
                           122 to  14                   108
                            14 to 124                   110
                           124 to  65                    59
                            65 to  67                     2

                  Total Seek Time    : 640
                  Average Seek Time  : 80.00



                                    OUTPUT 2


                Enter the Number of Cylinders: 200
                Enter the Current Position: 100
                Enter the Queue Size: 6
                Enter the Requests in Order: 20 89 130 45 120 180

                           Head Movement           Seek Distance
                     ---------------------------------------------------

                           100 to  20                    80
                            20 to  89                    69
                            89 to 130                    41
                           130 to  45                    85
                            45 to 120                    75
                           120 to 180                    60

                  Total Seek Time    : 410
                  Average Seek Time  : 68.00


*/
