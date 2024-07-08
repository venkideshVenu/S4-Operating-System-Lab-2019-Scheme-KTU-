#include <stdio.h>
#include <stdlib.h>

// Global variables
int nos, nof, refStr[50], pgflt = 0, frames[5], id = 0;

// Function to find the position of the page to replace
int findPosition(int start) {
    int index = -1;    // Variable to store the index of the page to be replaced
    int farthest = start;  // Variable to store the farthest distance a page is used in the future

    for (int i = 0; i < nof; i++) {
        int j;
        for (j = start; j < nos; j++) {
            if (frames[i] == refStr[j]) {  // Check if the page in frame is in future references
                if (j > farthest) {   // Update the farthest if current page has greater distance
                    farthest = j;
                    index = i;
                }
                break;
            }
        }
        if (j == nos) {
            return i; // If the page is not found in future references, replace this page
        }
    }

    return (index == -1) ? 0 : index; // If all frames are found in the future references, return the farthest one
}

int main() {
    // Input the length of the reference string
    printf("Enter the Length of the Reference String: ");
    scanf("%d", &nos);

    // Input the frame size
    printf("Enter the Frame Size: ");
    scanf("%d", &nof);

    // Input the reference string
    printf("Enter the Reference String: ");
    for (int i = 0; i < nos; i++)
        scanf("%d", &refStr[i]);

    // Initialize frames to -1 (indicating empty)
    for (int i = 0; i < nof; i++)
        frames[i] = -1;

    printf("\n\tRef String\tPage Frames\t\tStatus\n");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < nos; i++) {
        int found = 0; // Variable to check if the page is found in frames
        printf("\n\t%d\t\t", refStr[i]);

        // Check if the page is already in a frame
        for (int j = 0; j < nof; j++) {
            if (frames[j] == refStr[i]) {
                found = 1;
                break;
            }
        }

        // If page not found in frames
        if (!found) {
            pgflt++; // Increment page fault counter

            // If there is space in frames, add the page directly
            if (id < nof) {
                frames[id] = refStr[i]; // Place reference string in a frame
                id++; // Increment frame ID
            } else {
                // Otherwise, find the page to replace
                int index = findPosition(i + 1);
                frames[index] = refStr[i];
            }
        }

        // Output: Page in frames and page fault or hit
        for (int j = 0; j < nof; j++)
            printf("%2d ", frames[j]);

        if (found)
            printf("\tPage Hit");
        else
            printf("\tPage Fault");
    }

    // Print the total number of page faults and page hits
    printf("\nNumber of Page Faults : %d", pgflt);
    printf("\nNumber of Page Hits   : %d\n", (nos - pgflt));

    return 0;
}


/*

OUTPUT  1


                Enter the Length of the Reference String: 20
                Enter the Frame Size: 3
                Enter the Reference String: 1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6

                        Ref String      Page Frames             Status
                ---------------------------------------------------------------

                        1                1 -1 -1        Page Fault
                        2                1  2 -1        Page Fault
                        3                1  2  3        Page Fault
                        4                1  2  4        Page Fault
                        2                1  2  4        Page Hit
                        1                1  2  4        Page Hit
                        5                1  2  5        Page Fault
                        6                1  2  6        Page Fault
                        2                1  2  6        Page Hit
                        1                1  2  6        Page Hit
                        2                1  2  6        Page Hit
                        3                3  2  6        Page Fault
                        7                3  7  6        Page Fault
                        6                3  7  6        Page Hit
                        3                3  7  6        Page Hit
                        2                3  2  6        Page Fault
                        1                3  2  1        Page Fault
                        2                3  2  1        Page Hit
                        3                3  2  1        Page Hit
                        6                6  2  1        Page Fault
                Number of Page Faults : 11
                Number of Page Hits   : 9



OUTPUT 2

                Enter the Length of the Reference String: 20
                Enter the Frame Size: 3
                Enter the Reference String: 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

                        Ref String      Page Frames             Status
                ---------------------------------------------------------------

                        7                7 -1 -1        Page Fault
                        0                7  0 -1        Page Fault
                        1                7  0  1        Page Fault
                        2                2  0  1        Page Fault
                        0                2  0  1        Page Hit
                        3                2  0  3        Page Fault
                        0                2  0  3        Page Hit
                        4                2  4  3        Page Fault
                        2                2  4  3        Page Hit
                        3                2  4  3        Page Hit
                        0                2  0  3        Page Fault
                        3                2  0  3        Page Hit
                        2                2  0  3        Page Hit
                        1                2  0  1        Page Fault
                        2                2  0  1        Page Hit
                        0                2  0  1        Page Hit
                        1                2  0  1        Page Hit
                        7                7  0  1        Page Fault
                        0                7  0  1        Page Hit
                        1                7  0  1        Page Hit
                Number of Page Faults : 9
                Number of Page Hits   : 11

*/