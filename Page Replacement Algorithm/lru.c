#include <stdio.h>

void main() {
	int i, j, nos, nof, refStr[50], pgflt = 0, id = 0, min, found;
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
		
		found = 0; // Initialize found to 0 (page fault)
		printf("\t%d\t\t", refStr[i]); // Output: Current reference string value

		// Check if reference string value is in any frame
		for (j = 0; j < nof; j++) {
			if (frame_content[j] == refStr[i]) { // If found in a frame
				frame_count[j] = i; // Update the count
				found = 1; // Set found to 1 (page hit)
				break;
			}
		}

		// If not found in any frame
		if (!found) {

			// If there's still space in frames
			if (id < nof) {
				frame_content[id] = refStr[i]; // Place reference string in a frame
				frame_count[id] = i; // Update the count
				id++; // Increment frame ID
			}

			// If all frames are occupied
			else {
				min = 0; // Initialize min to 0
				// Find the frame with minimum count
				for (j = 0; j < nof; j++) {
					if (frame_count[j] < frame_count[min])
					min = j;
				}
				frame_content[min] = refStr[i]; // Replace content in frame with minimum count
				frame_count[min] = i; // Update the count
			}
			pgflt++; // Increment page fault counter
		}

		for (j = 0; j < nof; j++)
			printf("%2d ", frame_content[j]);

		if (found)
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



OUTPUT 2


		Enter the Length of the Reference String: 20
		Enter the Frame Size: 3
		Enter the Reference String: 7 0 1 2 0 3 0 4 2 3 0 3 2 1 2 0 1 7 0 1

		         Ref String      Page Number             Status
		---------------------------------------------------------------
		        7                7 -1 -1                Page Fault
		        0                7  0 -1                Page Fault
		        1                7  0  1                Page Fault
		        2                2  0  1                Page Fault
		        0                2  0  1                Page Hit
		        3                2  0  3                Page Fault
		        0                2  0  3                Page Hit
		        4                4  0  3                Page Fault
		        2                4  0  2                Page Fault
		        3                4  3  2                Page Fault
		        0                0  3  2                Page Fault
		        3                0  3  2                Page Hit
		        2                0  3  2                Page Hit
		        1                1  3  2                Page Fault
		        2                1  3  2                Page Hit
		        0                1  0  2                Page Fault
		        1                1  0  2                Page Hit
		        7                1  0  7                Page Fault
		        0                1  0  7                Page Hit
		        1                1  0  7                Page Hit

		Number of Page Fault: 12
		Number of Page Hits: 8



OUTPUT 3

		Enter the Length of the Reference String: 20
		Enter the Frame Size: 3
		Enter the Reference String: 1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6

		         Ref String      Page Number             Status
		---------------------------------------------------------------
		        1                1 -1 -1                Page Fault
		        2                1  2 -1                Page Fault
		        3                1  2  3                Page Fault
		        4                4  2  3                Page Fault
		        2                4  2  3                Page Hit
		        1                4  2  1                Page Fault
		        5                5  2  1                Page Fault
		        6                5  6  1                Page Fault
		        2                5  6  2                Page Fault
		        1                1  6  2                Page Fault
		        2                1  6  2                Page Hit
		        3                1  3  2                Page Fault
		        7                7  3  2                Page Fault
		        6                7  3  6                Page Fault
		        3                7  3  6                Page Hit
		        2                2  3  6                Page Fault
		        1                2  3  1                Page Fault
		        2                2  3  1                Page Hit
		        3                2  3  1                Page Hit
		        6                2  3  6                Page Fault

		Number of Page Fault: 15
		Number of Page Hits: 5
*/