

#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    int id;
    void *sm; // Pointer to shared memory

    char buf[100]; // Buffer for input data

    // Create a shared memory segment
    id = shmget((key_t)1222, 1024, 0666 | IPC_CREAT);

    // Print the key of the shared memory segment
    printf("Key of Shared Memory is: %d\n", id);

    // Attach the shared memory segment to the process
    sm = shmat(id, NULL, 0);

    // Print the address where the shared memory is attached
    printf("Process Attached is: %p\n", sm);

    // Prompt user to enter data to be written to shared memory
    printf("Enter the Data to be Written:\n");

    // Read input data from standard input
    read(0, buf, 100);

    // Copy the input data to the shared memory
    strcpy(sm, buf);

    // Print the data written to shared memory
    printf("Written Data is: %s\n", (char*)sm);

    return 0;
}




/*
        Output
    
    Key of Shared Memory is : 2
    Process Attached is : 0x7f1780c25000
    Enter the Data to be Writter : 8 5
    Written Data is : 8  5

*/
