// Classical Process Synchronization Problem - Producer Consumer using Semaphores

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

int buffer[SIZE];
int in = 0, out = 0;
int mutex = 1;
int full = 0;
int empty = SIZE;

void wait_sem(int *s)
{
    (*s)--;
}

void signal_sem(int *s)
{
    (*s)++;
}

void produce(int item)
{
    wait_sem(&empty);
    wait_sem(&mutex);

    buffer[in] = item;
    printf("Produced: %d\n", item);
    in = (in + 1) % SIZE;

    signal_sem(&mutex);
    signal_sem(&full);
}

void consume()
{
    int item;

    wait_sem(&full);
    wait_sem(&mutex);

    item = buffer[out];
    printf("Consumed: %d\n", item);
    out = (out + 1) % SIZE;

    signal_sem(&mutex);
    signal_sem(&empty);
}

int main()
{
    int choice, item;

    while (1)
    {
        printf("\n1. Produce\n");
        printf("2. Consume\n");
        printf("3. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                if (empty == 0)
                {
                    printf("Buffer is Full!\n");
                }
                else
                {
                    printf("Enter item: ");
                    scanf("%d", &item);
                    produce(item);
                }
                break;

            case 2:
                if (full == 0)
                {
                    printf("Buffer is Empty!\n");
                }
                else
                {
                    consume();
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid Choice!\n");
        }
    }

    return 0;
}
