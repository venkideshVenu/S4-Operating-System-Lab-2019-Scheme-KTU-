
//  Implementation of the Memory Allocation Methods for fixed partition*
//        a) First Fit b) Worst Fit c) Best Fit

#include <stdio.h>

int nop, nob, i, j;

// Structure to represent memory block
struct memory
{
    int num;    // Block number
    int status; // Status of the block (0 for free, 1 for allocated)
    int size;   // Size of the block
    int alBk;   // Allocated block number
    int remSize; // Remaining size of the block after allocation
} pro[10], block[10], temp;

// Function to sort the memory blocks based on different criteria
void sort(int T)
{
    for (i = 0; i < nob; i++)
    {
        for (j = 0; j < nob - i - 1; j++)
        {
            if ((T == 1 && block[j].size > block[j + 1].size) ||
                (T == 2 && block[j].size < block[j + 1].size) ||
                (T == 3 && block[j].num > block[j + 1].num))
            {
                temp = block[j];
                block[j] = block[j + 1];
                block[j + 1] = temp;
            }
        }
        block[i].status = 0; // Reset status after sorting
    }
}

// Function to implement first fit memory allocation
void first_fit()
{
    for (i = 0; i < nop; i++)
    {
        pro[i].status = 0; // Reset process status
        for (j = 0; j < nob; j++)
        {
            if ((pro[i].size <= block[j].size) && (block[j].status == 0))
            {
                pro[i].alBk = block[j].num; // Allocate block to process
                block[j].remSize = block[j].size - pro[i].size; // Calculate remaining size of block
                pro[i].status = block[j].status = 1; // Update status of process and block
                break;
            }
        }
    }
}

// Function to implement best fit memory allocation
void best_fit()
{
    sort(1); // Sort blocks by size
    first_fit(); // Perform first fit allocation
    sort(3); // Sort blocks back to original order
}

// Function to implement worst fit memory allocation
void worst_fit()
{
    sort(2); // Sort blocks by size in descending order
    first_fit(); // Perform first fit allocation
    sort(3); // Sort blocks back to original order
}

// Function to display allocation details
void display()
{
    printf("\n%10s %10s %10s %10s %10s \n", "Process", "Size", "Block", "B.Size", "RemSize");
    for (i = 0; i < nop; i++)
    {
        int id = pro[i].alBk;
        if ((id > 0) && (pro[i].status == 1))
            printf("\n      P%d %10d         B%d %10d %10d", pro[i].num, pro[i].size, id, block[id - 1].size, block[id - 1].remSize);
        else
            printf("\n      P%d %10d         --         --        --", pro[i].num, pro[i].size);
    }
}

int main()
{
    printf("Enter the No of Process and No of Block sizes : ");
    scanf("%d  %d", &nop, &nob);

    printf("Enter the Process Size in the Order : ");
    for (i = 0; i < nop; i++)
    {
        scanf("%d", &pro[i].size);
        pro[i].num = (i + 1);
        pro[i].status = 0;
    }
    printf("Enter the Block Size in the Order : ");
    for (i = 0; i < nob; i++)
    {
        scanf("%d", &block[i].size);
        block[i].num = (i + 1);
        block[i].status = 0;
    }

    // Perform first fit allocation and display results
    first_fit();
    printf("\n\n-----------------------First Fit------------------------\n");
    display();

    // Perform best fit allocation and display results
    best_fit();
    printf("\n\n-----------------------Best Fit------------------------\n");
    display();

    // Perform worst fit allocation and display results
    worst_fit();
    printf("\n\n-----------------------Worst Fit------------------------\n");
    display();

    return 0;
}


/*
        Output

    Enter the No of Process and No of Block sizes : 4 6
    Enter the Process Size in the Order : 357 210 468 491
    Enter the Block Size in the Order : 200 400 600 500 300 250


    -----------------------First Fit------------------------

    Process       Size      Block     B.Size    RemSize

        P1        357         B2        400         43
        P2        210         B3        600        390
        P3        468         B4        500         32
        P4        491         --         --        --

    -----------------------Best Fit------------------------

    Process       Size      Block     B.Size    RemSize

        P1        357         B2        400         43
        P2        210         B6        250         40
        P3        468         B4        500         32
        P4        491         B3        600        109

    -----------------------Worst Fit------------------------

    Process       Size      Block     B.Size    RemSize

        P1        357         B3        600        243
        P2        210         B4        500        290
        P3        468         --         --        --
        P4        491         --         --        --


*/