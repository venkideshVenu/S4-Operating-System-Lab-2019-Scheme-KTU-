#include <stdio.h>
#include <stdlib.h> 

// Global variables declaration
int nof, i, j, noBlk[10], key;

// Struct definition for a linked list node
struct table
{
    int blkNo;
    struct table *link;
};

// Global pointers to linked list heads
struct table *file[10], *head, *tail, *new, *temp;

int main()
{
    // Prompt for the number of files
    printf("\nEnter the Number of Files : ");
    scanf("%d", &nof);

    // Loop to iterate over each file
    for (i = 1; i <= nof; i++)
    {
        // Prompt for the number of blocks for the current file
        printf("\nEnter No of Blocks of File %d : ", i);
        scanf("%d", &noBlk[i]);

        // Prompt for the blocks of the current file
        printf("Enter the Blocks of File : ");

        // Initialize head and tail pointers for the current file's linked list
        tail = head = NULL;

        // Loop to iterate over each block of the current file
        for (j = 0; j < noBlk[i]; j++)
        {
            // Allocate memory for a new node
            new = malloc(sizeof(struct table)); 

            // Read block number from input
            scanf("%d", &new->blkNo);

            // Set link of new node to NULL
            new->link = NULL;

            // If the linked list is empty, set head and tail to the new node
            if (head == NULL)
            {
                head = new;
                tail = new;
            }
            else // If the linked list is not empty, append the new node to the end
            {
                tail->link = new;
                tail = new;
            }
        }

        // Store the head of the linked list in the file array
        file[i] = head; 
    }

    // Prompt for the file number to search
    printf("\nEnter the File Number to Search : ");
    scanf("%d", &key);

    // Check if the file number is valid
    if (key > nof || key < 1) 
        printf("\tFile Not Found !!!\n");
    else
    {
        // Print header for file details
        printf("\n%10s    %10s    %10s    %20s   ", "File Name", "No of Blocks", "Start Block", "Occupied Blocks");
        
        // Print details of the specified file
        printf("\n%7d    %10d    %10d \t\t", key, noBlk[key], file[key]->blkNo);
        
        // Print occupied blocks of the specified file
        temp = file[key];
        while (temp != NULL)
        {
            printf(" %d -> ", temp->blkNo);
            temp = temp->link;
        }
    }

    // Free allocated memory ( Optional )
    for (i = 1; i <= nof; i++)
    {
        struct table *current = file[i];
        while (current != NULL)
        {
            struct table *next = current->link;
            free(current);
            current = next;
        }
    }

    return 0;
}


/*

       --------------------------------------Output -1----------------------------------

        Enter the Number of Files : 3

        Enter No of Blocks of File 1 : 2
        Enter the Blocks of File : 10 14

        Enter No of Blocks of File 2 : 4
        Enter the Blocks of File : 66 55 44 33

        Enter No of Blocks of File 3 : 2
        Enter the Blocks of File : 68 90

        Enter the File Number to Search : 2

         File Name    No of Blocks    Start Block         Occupied Blocks
              2             4            66              66 ->  55 ->  44 ->  33 ->
        

        ---------------------------------------Output-2---------------------------------

        Enter the Number of Files : 3

        Enter No of Blocks of File 1 : 2
        Enter the Blocks of File : 10 14

        Enter No of Blocks of File 2 : 4
        Enter the Blocks of File : 66 55 44 33

        Enter No of Blocks of File 3 : 2
        Enter the Blocks of File : 68 90

        Enter the File Number to Search : 4
                File Not Found !!!

*/