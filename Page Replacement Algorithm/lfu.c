

#include <stdio.h>

// Structure to represent a page entry
struct  pageEntry{
    int content;
    int count;
    int last_used;
} frames[50];

int main() {
    int i, j, nos, nof, refStr[50], pgflt = 0;

    printf("Enter the Length of the Reference String: ");
    scanf("%d", &nos);
    printf("Enter the Frame Size: ");
    scanf("%d", &nof);

    for (i = 0; i < nof; i++) {
        frames[i].content = -1; // Initialize frame content to -1 (empty)
        frames[i].count = 0; // Initialize count to 0
        frames[i].last_used = -1; // Initialize last used time to -1
    }

    printf("Enter the Reference String: ");
    for (i = 0; i < nos; i++)
        scanf("%d", &refStr[i]);

    printf("\n\t Ref String\t Page Number\t\t Status\n");
	printf("---------------------------------------------------------------\n");

    for (i = 0; i < nos; i++) {
        int found = 0;
        printf("\t%d\t\t", refStr[i]);

        // Check if the page is already in a frame
        for (j = 0; j < nof; j++) {
            if (frames[j].content == refStr[i]) {
                found = 1;
                frames[j].count++; // Increment the count
                frames[j].last_used = i; // Update the last used time
                break;
            }
        }

        // If page not found in frames
        if (!found) {
            pgflt++; // Increment page fault counter

            // Find the least frequently used page
            int min_count = frames[0].count;
            int min_last_used = frames[0].last_used;
            int min_index = 0;
            for (j = 1; j < nof; j++) {
                if (frames[j].count < min_count || (frames[j].count == min_count && frames[j].last_used < min_last_used)) {
                    min_count = frames[j].count;
                    min_last_used = frames[j].last_used;
                    min_index = j;
                }
            }

            // Replace the least frequently used page
            frames[min_index].content = refStr[i];
            frames[min_index].count = 1;
            frames[min_index].last_used = i;
        }

        // Output: Page in frames and page fault or hit
        for (j = 0; j < nof; j++)
            printf("%2d ", frames[j].content);
        
        if (found)
            printf("\tPage Hit\n");
        else
            printf("\tPage Fault\n");
    }

    printf("\nNumber of Page Fault: %d", pgflt);
    printf("\nNumber of Page Hits: %d\n", (nos - pgflt));

    return 0;
}


/*



Output


                Ref String      Page Number             Status
        ---------------------------------------------------------------
                4                4 -1 -1        Page Fault
                5                4  5 -1        Page Fault
                2                4  5  2        Page Fault
                1                1  5  2        Page Fault
                2                1  5  2        Page Hit
                3                1  3  2        Page Fault
                3                1  3  2        Page Hit
                5                5  3  2        Page Fault
                5                5  3  2        Page Hit
                1                5  3  1        Page Fault

        Number of Page Fault: 7
        Number of Page Hits: 3

*/
