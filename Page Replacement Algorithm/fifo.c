

#include <stdio.h>

int i, j, k = 0, nos, nof, refStr[30], pgflt, flag;

int main() {
    // Input: Length of the reference string and frame size
    printf("Enter the Length of the Reference String: ");
    scanf("%d", &nos);
    printf("Enter the Frame Size: ");
    scanf("%d", &nof);

    // Initialize page fault counter
    pgflt = 0;

    // Initialize frame array with -1 (empty)
    int frame[30];
    for (i = 0; i < 30; i++)
        frame[i] = -1;

    // Input: Reference string
    printf("Enter the Reference String: ");
    for (i = 0; i < nos; i++)
        scanf("%d", &refStr[i]);

    // Output: Header for the table
    printf("\n\t Ref String\t  Page Number\t\t  Status\n");
    printf("---------------------------------------------------------------\n");

    // Loop through the reference string
    for (i = 0; i < nos; i++) {
        flag = 0; // Initialize flag to 0 (page fault)
        printf("\t\t%d\t", refStr[i]); // Output: Current reference string value

        // Check if reference string value is in any frame
        for (j = 0; j < nof; j++) {
            if (frame[j] == refStr[i]) { // If found in a frame
                flag = 1; // Set flag to 1 (page hit)
                break;
            }
        }

        // If not found in any frame
        if (flag == 0) {
            frame[k] = refStr[i]; // Place reference string in a frame
            k = (k + 1) % nof; // Update the index for next insertion (circular buffer)
            pgflt++; // Increment page fault counter
        }

        // Output: Content of each frame
        for (j = 0; j < nof; j++)
            printf("%2d   ", frame[j]);

        // Output: Page hit or page fault
        if (flag == 1)
            printf("\tPage Hit\n");
        else
            printf("\tPage Fault\n");
    }

    // Output: Number of page faults and hits
    printf("\nNumber of Page Fault: %d", pgflt);
    printf("\nNumber of Hits: %d\n", (nos - pgflt));

    return 0;
}


/*

                 Output

        Enter the Length of the Reference String: 20
        Enter the Frame Size: 4
        Enter the Reference String: 1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6

                Ref String       Page Number             Status
        ---------------------------------------------------------------
                        1        1   -1   -1   -1       Page Fault
                        2        1    2   -1   -1       Page Fault
                        3        1    2    3   -1       Page Fault
                        4        1    2    3    4       Page Fault
                        2        1    2    3    4       Page Hit
                        1        1    2    3    4       Page Hit
                        5        5    2    3    4       Page Fault
                        6        5    6    3    4       Page Fault
                        2        5    6    2    4       Page Fault
                        1        5    6    2    1       Page Fault
                        2        5    6    2    1       Page Hit
                        3        3    6    2    1       Page Fault
                        7        3    7    2    1       Page Fault
                        6        3    7    6    1       Page Fault
                        3        3    7    6    1       Page Hit
                        2        3    7    6    2       Page Fault
                        1        1    7    6    2       Page Fault
                        2        1    7    6    2       Page Hit
                        3        1    3    6    2       Page Fault
                        6        1    3    6    2       Page Hit

        Number of Page Fault: 14
        Number of Hits: 6

*/