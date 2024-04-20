
//  . Implement the banker’s algorithm for deadlock avoidance. 

#include <stdio.h>
#include <stdlib.h>

int i,j,k,nop,nor,pid,ch,choice;
int alloc[10][10],maxClm[10][10],MaxAvl[10],need[10][10],work[10]={0}, avail[10],request[10];

// Function to check if the system is in a safe state
int safety(int arr[10])
{	
	printf("\n\nThe Sequence is : ");
	int finish[10]={0},target=0;
    for (k = 0; k < 5; k++) {
        for (i = 0; i < nop; i++) {
            if (finish[i] == 0) {
                int flag = 0;
                // Check if need of the process is less than or equal to available resources
                for (j = 0; j < nor; j++) {
                    if (need[i][j] > arr[j]){
                        flag = 1;
                        break;
                    }
                }
                // If need is less than available resources, allocate resources and mark process as finished
                if (flag == 0) {
                    printf(" P%d  ",i);
                    for (j = 0; j < nor; j++)
                        arr[j] += alloc[i][j];
                    finish[i] = 1;
                    target++;
                }
            }
        }
    }
    // If all processes are finished, return 1 indicating safe state
    if (target == nop)
        return 1;
    else
        printf("\nThe System is in UNSAFE STATE :(\n");
}

// Function to handle resource request
void requestfn() { 
	printf("Enter Process ID  : ");		// Reading Process ID
	scanf("%d",&pid);
	printf("Enter Resource Vector : ");		// Reading Resource Vector
	for (j = 0; j < nor; j++)
        scanf("%d", &request[j]);
    // Check if the request exceeds the maximum claim of the process
    for (i = 0; i < nor; i++){
    	if (request[i] > need[pid][i]) {		
            printf("Process P%d Exceeded Maximum claim !!!\n",pid);
            exit(0);
        }
    }
    // Check if the request can be fulfilled with the available resources
    for (i = 0; i < nor; i++){
    	if (request[i] > avail[i]) {
            printf("Process P%d is Waiting for availailing Resource !!!\n",pid);
            exit(0);
        }
    }
    // Allocate resources to the process
    for (i = 0; i < nor; i++) {
        avail[i] -= request[i];
        alloc[pid][i] += request[i];
        need[pid][i] -= request[i];
    }
    // Check if the system remains in safe state after allocation
    ch = safety(avail);
    if (ch == 1)
        printf("\nSystem is in SAFE STATE and Resources are Allocated\n");
}

void main()
{
	printf("Enter the Number of Processes :  ");
	scanf("%d",&nop);
	printf("Enter the Number of Resorces  :  ");
	scanf("%d",&nor);
	printf("Enter the Max Available Matrix : ");
	for( i=0 ; i<nor ; i++ )
		scanf("%d",&MaxAvl[i]);
	
	printf("Enter the Allocation Matrix : \n");
	for( i=0 ; i < nop ; i++ )
		for ( j=0 ; j< nor ; j++ )
			scanf("%d",&alloc[i][j]);
			
	printf("Enter the Maximum Claim Matrix : \n");
	for( i=0 ; i < nop ; i++ )
		for ( j=0 ; j< nor ; j++ )
			scanf("%d",&maxClm[i][j]);
	// Calculate the need matrix
	for( i=0 ; i < nop ; i++ )
		for ( j=0 ; j< nor ; j++ )
			need[i][j] = maxClm[i][j] - alloc[i][j];
	// Calculate the work and available matrices
	for( j=0 ; j<nor ; j++ ){
		for( i=0 ; i<nop ; i++ )
			work[j] += alloc[i][j];
		work[j] = MaxAvl[j] - work[j];
	}	
	for ( i=0 ; i<nor ; i++ )
		avail[i] = work[i];

	printf("\nProcess    Allocation      Max       Need ");		// Printing Table
	for ( i=0 ; i<nop ; i++ ){	
		printf("\n   P%d      ",i);
		for( j=0 ; j<nor ; j++ )
			printf("  %d",alloc[i][j] );
		printf("   ");
		for( j=0 ; j<nor ; j++ )
			printf("  %d",maxClm[i][j] );
		printf("  ");
		for( j=0 ; j<nor ; j++ )
			printf("  %d",need[i][j] );
	}

	ch = safety(work);
	if ( ch == 1 )
	{
		printf("\n\nThe System is in SAFE STATE !!!\n");
		printf(" Resource Request needed ? ( Yes=1 ? No=0 )  : ");
		scanf("%d",&choice);
		if(choice)
		{
			requestfn();
			printf("\nProcess    Allocation      Max       Need ");		// Printing Table

	        for ( i=0 ; i<nop ; i++ ){	
                printf("\n   P%d      ",i);
                for( j=0 ; j<nor ; j++ )
                    printf("  %d",alloc[i][j] );
                printf("   ");
                for( j=0 ; j<nor ; j++ )
                    printf("  %d",maxClm[i][j] );
                printf("  ");
                for( j=0 ; j<nor ; j++ )
                    printf("  %d",need[i][j] );
	    }
		}
	}
}


/*

            Output

    Enter the Number of Processes :  5
    Enter the Number of Resorces  :  3
    Enter the Max Available Matrix : 10 5 7
    Enter the Allocation Matrix :
    0 1 0
    2 0 0
    3 0 2
    2 1 1
    0 0 2
    Enter the Maximum Claim Matrix :
    7 5 3
    3 2 2
    9 0 2
    2 2 2
    4 3 3

    Process    Allocation      Max       Need
    P0        0  1  0     7  5  3    7  4  3
    P1        2  0  0     3  2  2    1  2  2
    P2        3  0  2     9  0  2    6  0  0
    P3        2  1  1     2  2  2    0  1  1
    P4        0  0  2     4  3  3    4  3  1

    The Sequence is :  P1   P3   P4   P0   P2

    The System is in SAFE STATE !!!
    Resource Request needed ? ( Yes=1 ? No=0 )  : 1
    Enter Process ID  : 0
    Enter Resource Vector : 0 2 0


    The Sequence is :  P3   P1   P2   P0   P4
    System is in SAFE STATE and Resources are Allocated

    Process    Allocation      Max       Need
    P0        0  3  0     7  5  3    7  2  3
    P1        2  0  0     3  2  2    1  2  2
    P2        3  0  2     9  0  2    6  0  0
    P3        2  1  1     2  2  2    0  1  1
    P4        0  0  2     4  3  3    4  3  1


*/