



#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>

#define N 5
#define LEFT (i+4)%5
#define RIGHT (i)%5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

int state[N];
pthread_t t[N];
sem_t s[N];
sem_t mutex;

void think(int n) {
    printf("The Philosopher %d is thinking \n", n);
    sleep(1);
}

void eat(int n) {
    printf("Philosopher %d is eating\n", n);
    sleep(1);
    printf("Philosopher %d finished eating\n", n);
}

void take_fork(int i) {
    sem_wait(&mutex); // Acquire mutex to access shared data
    state[i] = HUNGRY; // Set philosopher's state to hungry
    if(state[i] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING) {
        // If philosopher is hungry and neighbors are not eating, allow philosopher to eat
        state[i] = EATING; // Set philosopher's state to eating
        sem_wait(&s[LEFT]); // Wait for left fork
        sem_wait(&s[RIGHT]); // Wait for right fork
    }
    sem_post(&mutex); // Release mutex
}

void putforks(int i) {
    state[i] = THINKING; // Set philosopher's state to thinking
    sem_post(&s[LEFT]); // Release left fork
    sem_post(&s[RIGHT]); // Release right fork
}

void *philo(int n) {
    while(1) {
        think(n); // Philosopher thinks
        take_fork(n); // Philosopher tries to take forks
        if(state[n] == EATING) { // If philosopher is eating
            eat(n); // Philosopher eats
            putforks(n); // Philosopher puts down forks
        }
    }
}

int main() {
    int i;

    // Initialize semaphores
    for(i = 0; i < N; i++)
        sem_init(&s[i], 0, 1); // Each fork semaphore initialized to 1
    sem_init(&mutex, 0, 1); // Mutex semaphore initialized to 1

    // Create philosopher threads
    for(i = 0; i < N; i++)
        pthread_create(&t[i], NULL, (void *)philo, (void *)i);

    while(1); // Keep the main thread running

    return 0;
}



/*
            Output


        The Philosopher 0 is thinking
        The Philosopher 1 is thinking
        The Philosopher 4 is thinking
        The Philosopher 3 is thinking
        The Philosopher 2 is thinking
        Philosopher 2 is eating
        Philosopher 4 is eating
        Philosopher 4 finished eating
        Philosopher 2 finished eating
        The Philosopher 4 is thinking
        The Philosopher 2 is thinking
        Philosopher 1 is eating
        Philosopher 1 finished eating
        The Philosopher 1 is thinking
        Philosopher 0 is eating
        Philosopher 3 is eating
        Philosopher 3 finished eating
        Philosopher 0 finished eating
        Philosopher 2 is eating
        The Philosopher 3 is thinking
        The Philosopher 0 is thinking
        Philosopher 4 is eating
        Philosopher 4 finished eating
        Philosopher 2 finished eating
        The Philosopher 4 is thinking
        The Philosopher 2 is thinking
        Philosopher 1 is eating
        Philosopher 1 finished eating
        Philosopher 0 is eating
        The Philosopher 4 is thinking
        Philosopher 3 is eating
        The Philosopher 1 is thinking
        Philosopher 3 finished eating
        Philosopher 0 finished eating
        Philosopher 2 is eating
        The Philosopher 1 is thinking
        The Philosopher 3 is thinking
        The Philosopher 0 is thinking
        Philosopher 4 is eating
        Philosopher 4 finished eating
        The Philosopher 0 is thinking
        The Philosopher 3 is thinking
        Philosopher 2 finished eating
        The Philosopher 4 is thinking
        The Philosopher 2 is thinking
        Philosopher 1 is eating
        Philosopher 1 finished eating
        The Philosopher 2 is thinking
        Philosopher 4 is eating
        The Philosopher 1 is thinking
        Philosopher 4 finished eating
        Philosopher 3 is eating
        Philosopher 0 is eating
        The Philosopher 1 is thinking
        The Philosopher 4 is thinking
        Philosopher 3 finished eating
        Philosopher 0 finished eating
        The Philosopher 3 is thinking
        Philosopher 2 is eating
        The Philosopher 0 is thinking
        Philosopher 4 is eating

    //  it will continue...... and ouput may vary on each excecution

*/