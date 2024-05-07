#include<stdio.h>

// Global variables declaration
int nof, i, j, blocks[10][10], noBlk[10], key;

int main()
{
    // Prompt for the number of files
    printf("\nEnter the Number of Files  :  ");
    scanf("%d", &nof);

    // Loop to iterate over each file
    for (i = 1; i <= nof; i++)
    {
        // Prompt for the number of blocks for the current file
        printf("\nEnter No of Blocks of File %d  : ", i);
        scanf("%d", &noBlk[i]);
        
        // Prompt for the blocks of the current file
        printf("Enter the Blocks  :  ");
        for (j = 0; j < noBlk[i]; j++)
            scanf("%d", &blocks[i][j]);
    }

    // Prompt for the file number to search
    printf("\nEnter the File Number to Search  : ");
    scanf("%d", &key);

    // Check if the file number is valid
    if (key > nof)
        printf("\tFile Not Found !!!\n");
    else
    {
        // Print header for file details
        printf("\n  %10s   %10s   %20s   ", "File Name", "Start Block", "Occupied Blocks");
        
        // Print details of the specified file
        printf("\n  %7d   %10d               ", key, blocks[key][0]);
        
        // Print occupied blocks of the specified file
        for (i = 0; i < noBlk[key]; i++)
            printf(" %d ", blocks[key][i]);
    }
    return 0;
}



/*

        -----------------------Output - 1 --------------------

        Enter the Number of Files  :  2

        Enter No of Blocks of File 1  : 4
        Enter the Blocks  :  12 23 9 4

        Enter No of Blocks of File 2  : 5
        Enter the Blocks  :  45 65 28 20 5

        Enter the File Number to Search  : 2

           File Name   Start Block        Occupied Blocks
                2           45                45  65  28  20  5

        -----------------------Output - 2 --------------------

        Enter the Number of Files  :  2

        Enter No of Blocks of File 1  : 4
        Enter the Blocks  :  12 23 9 4

        Enter No of Blocks of File 2  : 5
        Enter the Blocks  :  45 65 28 20 5

        Enter the File Number to Search  : 6
                File Not Found !!!  


*/