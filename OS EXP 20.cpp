// Reader-Writer Problem using Semaphores

#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t wrt, mutex;

int readcount = 0;
int data = 10;

// Reader Function
void *reader(void *arg)
{
    int id = *(int *)arg;

    sem_wait(&mutex);
    readcount++;

    if(readcount == 1)
        sem_wait(&wrt);

    sem_post(&mutex);

    // Reading Section
    printf("Reader %d reads data = %d\n", id, data);

    sem_wait(&mutex);
    readcount--;

    if(readcount == 0)
        sem_post(&wrt);

    sem_post(&mutex);
}

// Writer Function
void *writer(void *arg)
{
    int id = *(int *)arg;

    sem_wait(&wrt);

    // Writing Section
    data = data + 5;
    printf("Writer %d writes data = %d\n", id, data);

    sem_post(&wrt);
}

int main()
{
    pthread_t r1, r2, w1;
    int id1 = 1, id2 = 2, id3 = 1;

    // Initialize Semaphores
    sem_init(&mutex, 0, 1);
    sem_init(&wrt, 0, 1);

    // Create Threads
    pthread_create(&r1, NULL, reader, &id1);
    pthread_create(&r2, NULL, reader, &id2);
    pthread_create(&w1, NULL, writer, &id3);

    // Wait for Threads
    pthread_join(r1, NULL);
    pthread_join(r2, NULL);
    pthread_join(w1, NULL);

    // Destroy Semaphores
    sem_destroy(&mutex);
    sem_destroy(&wrt);

    return 0;
}
