

#include <stdio.h>

int i, j, k = 0, nos, nof, refStr[30], pgflt, found,frame[5];

int main() {
    // Input: Length of the reference string and frame size
    printf("Enter the Length of the Reference String: ");
    scanf("%d", &nos);
    printf("Enter the Frame Size: ");
    scanf("%d", &nof);

    // Initialize page fault counter
    pgflt = 0;

    // Initialize frame array with -1 (empty)
    for (i = 0; i < nof; i++)
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
        found = 0; // Initialize found to 0 (page fault)
        printf("\t\t%d\t", refStr[i]); // Output: Current reference string value

        // Check if reference string value is in any frame
        for (j = 0; j < nof; j++) {
            if (frame[j] == refStr[i]) { // If found in a frame
                found = 1; // Set found to 1 (page hit)
                break;
            }
        }

        // If not found in any frame
        if (!found) {
            frame[k] = refStr[i]; // Place reference string in a frame
            k = (k + 1) % nof; // Update the index for next insertion (circular buffer)
            pgflt++; // Increment page fault counter
        }

        // Output: Content of each frame
        for (j = 0; j < nof; j++)
            printf("%2d   ", frame[j]);

        // Output: Page hit or page fault
        if (found)
            printf("\tPage Hit\n");
        else
            printf("\tPage Fault\n");
    }

    // Output: Number of page faults and hits
    printf("\nNumber of Page Fault : %d", pgflt);
    printf("\nNumber of Hits       : %d\n", (nos - pgflt));

    return 0;
}


/*


OUTPUT 1

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

            Number of Page Fault : 14
            Number of Hits       : 6



OUTPUT 2

            Enter the Length of the Reference String: 20
            Enter the Frame Size: 3
            Enter the Reference String: 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

                     Ref String       Page Number             Status
            ---------------------------------------------------------------
                            7        7   -1   -1    Page Fault
                            0        7    0   -1    Page Fault
                            1        7    0    1    Page Fault
                            2        2    0    1    Page Fault
                            0        2    0    1    Page Hit
                            3        2    3    1    Page Fault
                            0        2    3    0    Page Fault
                            4        4    3    0    Page Fault
                            2        4    2    0    Page Fault
                            3        4    2    3    Page Fault
                            0        0    2    3    Page Fault
                            3        0    2    3    Page Hit
                            2        0    2    3    Page Hit
                            1        0    1    3    Page Fault
                            2        0    1    2    Page Fault
                            0        0    1    2    Page Hit
                            1        0    1    2    Page Hit
                            7        7    1    2    Page Fault
                            0        7    0    2    Page Fault
                            1        7    0    1    Page Fault

            Number of Page Fault : 15
            Number of Hits       : 5


OUTPUT 3


            D:\Studies\MITS\Sem 4\Exam Practice>a
            Enter the Length of the Reference String: 20
            Enter the Frame Size: 4
            Enter the Reference String: 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

                     Ref String       Page Number             Status
            ---------------------------------------------------------------
                            7        7   -1   -1   -1       Page Fault
                            0        7    0   -1   -1       Page Fault
                            1        7    0    1   -1       Page Fault
                            2        7    0    1    2       Page Fault
                            0        7    0    1    2       Page Hit
                            3        3    0    1    2       Page Fault
                            0        3    0    1    2       Page Hit
                            4        3    4    1    2       Page Fault
                            2        3    4    1    2       Page Hit
                            3        3    4    1    2       Page Hit
                            0        3    4    0    2       Page Fault
                            3        3    4    0    2       Page Hit
                            2        3    4    0    2       Page Hit
                            1        3    4    0    1       Page Fault
                            2        2    4    0    1       Page Fault
                            0        2    4    0    1       Page Hit
                            1        2    4    0    1       Page Hit
                            7        2    7    0    1       Page Fault
                            0        2    7    0    1       Page Hit
                            1        2    7    0    1       Page Hit

            Number of Page Fault : 10
            Number of Hits       : 10



*/