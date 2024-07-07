#include <stdio.h>
#include <stdlib.h>

// Global variables to store the current position, queue size, total seek time, and arrays for requests and completion status
int currPos, queSize, seek = 0, ptr, requests[30], completed[30];

// Function to find the index of the request closest to the current head position
int findRequestIndex() {
    int position = -1, minDistance = 9999;
    for (int i = 0; i < queSize; i++) {
        // If the request has not been completed
        if (!completed[i]) {
            int distance = abs(currPos - requests[i]);
            // Update the closest request
            if (distance < minDistance) {
                minDistance = distance;
                position = i;
            }
        }
    }
    return position;
}

int main() {
    // Input the current head position
    printf("Enter the Current Position: ");
    scanf("%d", &currPos);

    // Input the number of requests in the queue
    printf("Enter the Queue Size: ");
    scanf("%d", &queSize);

    // Input the requests
    printf("Enter the Requests in Order: ");
    for (int i = 0; i < queSize; i++) 
        scanf("%d", &requests[i]);

    // Initialize the completed array to indicate no requests have been completed
    for (int i = 0; i < queSize; i++)
        completed[i] = 0;

    // Print the initial head position
    printf(" Seek Sequence : %d", currPos);
    
    // Process each request
    for (int i = 0; i < queSize; i++) {
        int index = findRequestIndex();
        // Mark the request as completed
        completed[index] = 1;
        // Calculate the seek time for the current move
        seek += abs(currPos - requests[index]);
        // Move the head to the request position
        currPos = requests[index];
        // Print the current position in the seek sequence
        printf(" --> %d", currPos);
    }

    // Print the total and average seek time
    printf("\n  Total Seek Time    : %d", seek);
    printf("\n  Average Seek Time  : %.2f\n", (float)seek / queSize);

    return 0;
}

/*

                                    Output 1

                Enter the Current Position: 50
                Enter the Queue Size: 7
                Enter the Requests in Order: 82 170 43 140 24 16 190
                Seek Sequence : 50 --> 43 --> 24 --> 16 --> 82 --> 140 --> 170 --> 190
                Total Seek Time    : 208
                Average Seek Time  : 29.71

                                    Output 2

                Enter the Current Position: 100
                Enter the Queue Size: 6
                Enter the Requests in Order: 20 89 130 45 120 180
                Seek Sequence : 100 --> 89 --> 120 --> 130 --> 180 --> 45 --> 20
                Total Seek Time    : 262
                Average Seek Time  : 43.67
*/
