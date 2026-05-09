// C Program to Illustrate Multithreading using POSIX Threads

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Function executed by Thread 1
void *thread1_function(void *arg)
{
    for (int i = 1; i <= 5; i++)
    {
        printf("Thread 1 is running: %d\n", i);
    }
    pthread_exit(NULL);
}

// Function executed by Thread 2
void *thread2_function(void *arg)
{
    for (int i = 1; i <= 5; i++)
    {
        printf("Thread 2 is running: %d\n", i);
    }
    pthread_exit(NULL);
}

int main()
{
    pthread_t t1, t2;

    // Create Thread 1
    pthread_create(&t1, NULL, thread1_function, NULL);

    // Create Thread 2
    pthread_create(&t2, NULL, thread2_function, NULL);

    // Wait for threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf("Both threads have finished execution.\n");

    return 0;
}
