
#include <stdio.h>

// Global variables declaration
int i, j, k, nop, nor, completed = 0;
int alloc[10][10], request[10][10], avail[10], finish[10] = {0};

int main()
{
    // Prompt for the number of processes and resources
    printf("Enter the Number of Processes :  ");
    scanf("%d", &nop);
    printf("Enter the Number of Resources  :  ");
    scanf("%d", &nor);

    // Prompt for the allocation matrix
    printf("Enter the Allocation Matrix : \n");
    for (i = 0; i < nop; i++)
        for (j = 0; j < nor; j++)
            scanf("%d", &alloc[i][j]);

    // Prompt for the request matrix
    printf("Enter the Request Matrix : \n");
    for (i = 0; i < nop; i++)
        for (j = 0; j < nor; j++)
            scanf("%d", &request[i][j]);

    // Prompt for the available matrix
    printf("Enter the Available Matrix : ");
    for (i = 0; i < nor; i++)
        scanf("%d", &avail[i]);

    // Deadlock detection algorithm
    for (k = 0; k < nop; k++) {
        for (i = 0; i < nop; i++) {

            if (finish[i] == 0) {
                int flag = 0;
                // Check if the current process can be satisfied with available resources
                for (j = 0; j < nor; j++) {
                    if (request[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }

                // If all the requested resources can be allocated, mark the process as finished
                if (flag == 0) {
                    for (j = 0; j < nor; j++)
                        avail[j] += alloc[i][j];
                    finish[i] = 1;
                    completed++;
                }
            }
        }
    }

    // Check if all processes have been completed to determine the system's state
    if (completed == nop)
        printf("No DeadLock - System is in Safe mode  :)");
    else
    {
        printf("\nThe System is in DeadLock STATE :(\n");
        printf("DeadLock Causing Process are  :  ");
        // Print the processes causing deadlock
        for (i = 0; i < nop; i++)
        {
            if (finish[i] == 0)
                printf(" P%d", i);
        }
    }
}


/*

       -----------------------Output -1--------------------

        Enter the Number of Processes :  5
        Enter the Number of Resources  :  3
        Enter the Allocation Matrix :
        0 1 0
        2 0 0
        3 0 2
        2 1 1
        0 0 2
        Enter the Request Matrix :
        0 0 0
        2 0 2
        0 0 0
        1 0 0
        0 0 2
        Enter the Available Matrix : 0 0 0
        No DeadLock - System is in Safe mode  :)
        

        --------------------Output-2-----------------------

        Enter the Number of Processes :  3
        Enter the Number of Resources  :  3
        Enter the Allocation Matrix :
        3 6 8
        4 3 3
        3 4 4
        Enter the Request Matrix :
        3 3 3
        2 0 3
        1 2 4
        Enter the Available Matrix : 1 2 0

        The System is in DeadLock STATE :(
        DeadLock Causing Process are  :   P0 P1 P2


*/