

#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    int id;
    void *sm;
    char buf[100];

    // Create or access a shared memory segment
    id = shmget((key_t)1222, 1024, 0666);
    if (id == -1) {
        perror("shmget");
        exit(1);
    }
    printf("Key of Shared Memory is %d\n", id);

    // Attach the shared memory segment
    sm = shmat(id, NULL, 0);
    if (sm == (void *)-1) {
        perror("shmat");
        exit(1);
    }
    printf("Process attached at %p\n", sm);

    // Read data from shared memory
    printf("Data read from Memory:\n%s\n", (char *)sm);

    // Copy data from shared memory to buffer
    strcpy(buf, sm);

    // Extract integers from the buffer
    int a = buf[0] - '0';
    int b = buf[2] - '0';

    // Calculate and print the sum
    printf("The Sum is %d\n", a + b);

    return 0;
}


/*
        Output
    
    Key of Shared Memory is : 2
    Process Attached is : 0x7f2cc0f9c000
    Data Read from Memeory : 8 5
    Sum is : 13


*/