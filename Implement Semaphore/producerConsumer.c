

//  C program to simulate producer-consumer problem using semaphores.


#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

// Declare semaphores and buffer
sem_t mutex;
sem_t empty;
sem_t full;
int buffer[8];

// Producer function
void producer(int *p) {
    int a[10], i = 0, n = *(int *)p;
    while (i <= 5) {
        sem_wait(&empty); // Wait for empty slots in buffer
        sem_wait(&mutex); // Wait for mutex to access buffer
        a[i] = 3;
        printf("Producer %d Produced Item %d\n", n, i);
        sleep(1);
        i++;
        buffer[i] = a[i];
        sem_post(&mutex); // Release mutex
        sem_post(&full); // Signal that buffer is full
    }
}

// Consumer function
void consumer(void *p) {
    int b[10], i = 0, n = *(int *)p;
    while (i <= 5) {
        sem_wait(&full); // Wait for buffer to be full
        sem_wait(&mutex); // Wait for mutex to access buffer
        printf("Consumer %d Consumes Item %d\n", n, i);
        sleep(1);
        b[i] = buffer[i];
        i++;
        sem_post(&mutex); // Release mutex
        sem_post(&empty); // Signal that buffer has empty slots
    }
}

int main() {

    int n;

    pthread_t p[5]; // Array of producer threads
    pthread_t c[5]; // Array of consumer threads


    // Initialize semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&empty, 0, 5);
    sem_init(&full, 0, 0);

    // Create producer and consumer threads
    for (n = 0; n < 5; n++) {
        pthread_create(&p[n], 0, (void *)producer, (void *)&n);
        pthread_create(&c[n], 0, (void *)consumer, (void *)&n);
    }

    // Keep the main thread running
    while (1);

    return 0;
}


/*
            Output


    Producer 2 Produced Item 0
    Producer 2 Produced Item 0
    Producer 2 Produced Item 0
    Producer 5 Produced Item 0
    Producer 5 Produced Item 0
    Consumer 2 Consumes Item 0
    Consumer 2 Consumes Item 0
    Consumer 5 Consumes Item 0
    Consumer 5 Consumes Item 0
    Consumer 5 Consumes Item 0
    Producer 2 Produced Item 1
    Producer 2 Produced Item 1
    Producer 2 Produced Item 1
    Producer 5 Produced Item 1

    //  it will continue...... and ouput may vary on each excecution

*/