// C Program to Simulate Dining Philosophers Problem
// Using POSIX Threads and Semaphores

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5   // Number of philosophers

sem_t forks[N];
pthread_t philosophers[N];

// Function for philosopher activity
void *dining(void *num)
{
    int id = *(int *)num;

    while (1)
    {
        // Thinking
        printf("Philosopher %d is Thinking\n", id);
        sleep(1);

        // Pick left fork
        sem_wait(&forks[id]);
        printf("Philosopher %d picked up Left Fork %d\n", id, id);

        // Pick right fork
        sem_wait(&forks[(id + 1) % N]);
        printf("Philosopher %d picked up Right Fork %d\n", id, (id + 1) % N);

        // Eating
        printf("Philosopher %d is Eating\n", id);
        sleep(2);

        // Put down left fork
        sem_post(&forks[id]);
        printf("Philosopher %d put down Left Fork %d\n", id, id);

        // Put down right fork
        sem_post(&forks[(id + 1) % N]);
        printf("Philosopher %d put down Right Fork %d\n", id, (id + 1) % N);

        printf("Philosopher %d finished Eating\n\n", id);
    }
}

int main()
{
    int i;
    int phil[N];

    // Initialize semaphores for forks
    for (i = 0; i < N; i++)
    {
        sem_init(&forks[i], 0, 1);
    }

    // Create philosopher threads
    for (i = 0; i < N; i++)
    {
        phil[i] = i;
        pthread_create(&philosophers[i], NULL, dining, &phil[i]);
    }

    // Join threads
    for (i = 0; i < N; i++)
    {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy semaphores
    for (i = 0; i < N; i++)
    {
        sem_destroy(&forks[i]);
    }

    return 0;
}
