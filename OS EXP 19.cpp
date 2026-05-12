// Process Synchronization using Mutex Locks

#include <stdio.h>
#include <pthread.h>

int shared = 0;              // Shared Resource
pthread_mutex_t lock;        // Mutex Lock

// Function for Thread 1
void *increment(void *arg)
{
    for(int i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&lock);

        shared++;
        printf("Thread 1: Shared Value = %d\n", shared);

        pthread_mutex_unlock(&lock);
    }
}

// Function for Thread 2
void *decrement(void *arg)
{
    for(int i = 0; i < 5; i++)
    {
        pthread_mutex_lock(&lock);

        shared--;
        printf("Thread 2: Shared Value = %d\n", shared);

        pthread_mutex_unlock(&lock);
    }
}

int main()
{
    pthread_t t1, t2;

    // Initialize Mutex
    pthread_mutex_init(&lock, NULL);

    // Create Threads
    pthread_create(&t1, NULL, increment, NULL);
    pthread_create(&t2, NULL, decrement, NULL);

    // Wait for Threads
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    // Destroy Mutex
    pthread_mutex_destroy(&lock);

    return 0;
}
