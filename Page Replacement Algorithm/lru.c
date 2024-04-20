#include <stdio.h>
void main() {
	int i, j, k = 0, nos, nof, refStr[50], pgflt = 0, id = 0, min, cnt = 0, flag;
	int frame_content[50]; // Array to store frame content
	int frame_count[50]; // Array to store frame counts
	printf("Enter the Length of the Reference String: ");
	scanf("%d", &nos);
	printf("Enter the Frame Size: ");
	scanf("%d", &nof);
	for (i = 0; i < nof; i++) {
		frame_content[i] = -1; // Initialize content to -1 (empty)
		frame_count[i] = 0; // Initialize count to 0
	}
	printf("Enter the Reference String: ");
	for (i = 0; i < nos; i++)
	scanf("%d", &refStr[i]);
	printf("\n\t Ref String\t Page Number\t\t Status\n");
	printf("---------------------------------------------------------------\n");
	for (i = 0; i < nos; i++) {
		flag = 0; // Initialize flag to 0 (page fault)
		printf("\t%d\t\t", refStr[i]); // Output: Current reference string value
		// Check if reference string value is in any frame
		for (j = 0; j < nof; j++) {
			if (frame_content[j] == refStr[i]) { // If found in a frame
				frame_count[j] = cnt++; // Update the count
				flag = 1; // Set flag to 1 (page hit)
				break;
			}
		}
		// If not found in any frame
		if (j == nof) {
			// If there's still space in frames
			if (id < nof) {
				frame_content[id] = refStr[i]; // Place reference string in a frame
				frame_count[id] = cnt++; // Update the count
				id++; // Increment frame ID
			}
			// If all frames are occupied
			else {
				min = 0; // Initialize min to 0
				// Find the frame with minimum count
				for (k = 0; k < nof; k++) {
					if (frame_count[k] < frame_count[min])
					min = k;
				}
				frame_content[min] = refStr[i]; // Replace content in frame with minimum count
				frame_count[min] = cnt++; // Update the count
			}
			pgflt++; // Increment page fault counter
		}
		for (j = 0; j < nof; j++)
		printf("%2d ", frame_content[j]);
		if (flag == 1)
			printf("\t\tPage Hit\n");
		else
			printf("\t\tPage Fault\n");
	}
	printf("\nNumber of Page Fault: %d", pgflt);
	printf("\nNumber of Page Hits: %d\n", (nos - pgflt));
}


/*

                 Output

        Enter the Length of the Reference String: 20
        Enter the Frame Size: 4
        Enter the Reference String: 1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6

                Ref String      Page Number             Status
        ---------------------------------------------------------------
                1                1 -1 -1 -1             Page Fault
                2                1  2 -1 -1             Page Fault
                3                1  2  3 -1             Page Fault
                4                1  2  3  4             Page Fault
                2                1  2  3  4             Page Hit
                1                1  2  3  4             Page Hit
                5                1  2  5  4             Page Fault
                6                1  2  5  6             Page Fault
                2                1  2  5  6             Page Hit
                1                1  2  5  6             Page Hit
                2                1  2  5  6             Page Hit
                3                1  2  3  6             Page Fault
                7                1  2  3  7             Page Fault
                6                6  2  3  7             Page Fault
                3                6  2  3  7             Page Hit
                2                6  2  3  7             Page Hit
                1                6  2  3  1             Page Fault
                2                6  2  3  1             Page Hit
                3                6  2  3  1             Page Hit
                6                6  2  3  1             Page Hit

        Number of Page Fault: 10
        Number of Page Hits: 10

*/