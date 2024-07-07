
// Implement LOOK Disk Scheduling Algorithm and find the total and average head movement

#include <stdio.h>
#include <stdlib.h>

// Function to compare two integers (for qsort)
int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int main() {
    int cySize, currPos, prePos, queSize, seek = 0, i, j, ptr;
    
    // Input the number of cylinders
    printf("Enter the Number of Cylinders: ");
    scanf("%d", &cySize);

    // Input the previous head position
    printf("Enter the Previous Head Position: ");
    scanf("%d", &prePos);

    // Input the current head position
    printf("Enter the Current Position: ");
    scanf("%d", &currPos);

    // Input the queue size
    printf("Enter the Queue Size: ");
    scanf("%d", &queSize);

    int requests[queSize + 1]; // Array to store requests, plus one for current position
    printf("Enter the Requests in Order: ");
    for (i = 1; i <= queSize; i++) {
        scanf("%d", &requests[i]);
    }
    requests[0] = currPos; // Set the first element as the current position

    // Sort the requests in ascending order
    qsort(requests, queSize + 1, sizeof(int), compare);

    // Find the position in the sorted array where the current position resides
    for (i = 0; i <= queSize; i++) {
        if (requests[i] == currPos) {
            ptr = i;
            break;
        }
    }

    // Determine the direction of movement based on previous and current head positions
    int direction = (currPos > prePos) ? 1 : 0;

    if (direction) {
        // Scan towards right, then towards left
        printf("\nScanning Towards Right... Then Towards Left...\n\n");
        for (i = ptr; i <= queSize; i++) {
            printf("%d-->", requests[i]);
            seek += abs(currPos - requests[i]);
            currPos = requests[i];
        }

        
        for (i = ptr - 1; i >= 0; i--) {
            printf("%d -->", requests[i]);
            seek += abs(currPos - requests[i]);
            currPos = requests[i];
        } 
    } 
    else {
        // Scan towards left, then towards right
        printf("\nScanning Towards Left...  Then Towards Right...\n");
        for (i = ptr; i >= 0 ; i--) {
            printf("%d-->", requests[i]);
            seek += abs(currPos - requests[i]);
            currPos = requests[i];
        }

        for (i = ptr + 1; i <= queSize; i++) {
            printf("%d -->", requests[i]);
            seek += abs(currPos - requests[i]);
            currPos = requests[i];
        } 
    }

    // Output total seek time
    printf("\n  Total Seek Time    : %d", seek);
    // Output average seek time
    printf("\n  Average Seek Time  : %.2f\n", (float)seek / queSize);

    return 0;
}



/*

                            Output 1


                Enter the Number of Cylinders: 200
                Enter the Previous Head Position: 45
                Enter the Current Position: 50
                Enter the Queue Size: 7
                Enter the Requests in Order: 82 170 43 140 24 16 190

                Scanning Towards Right... Then Towards Left...

                50-->82-->140-->170-->190-->43 -->24 -->16 -->
                  Total Seek Time    : 314
                  Average Seek Time  : 44.86



                            Output 2

                Enter the Number of Cylinders: 200
                Enter the Previous Head Position: 65
                Enter the Current Position: 50
                Enter the Queue Size: 7
                Enter the Requests in Order: 82 170 43 140 24 16 190

                Scanning Towards Left...  Then Towards Right...
                50-->43-->24-->16-->82 -->140 -->170 -->190 -->
                  Total Seek Time    : 208
                  Average Seek Time  : 29.71


*/