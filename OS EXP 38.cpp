#include <stdio.h>
#include <stdlib.h>

void sort(int arr[], int n)
{
    int i, j, temp;
    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int req[100], n, head, disk_size;
    int i, total = 0, pos;
    char dir;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter request queue: ");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter disk size: ");
    scanf("%d", &disk_size);

    printf("Enter direction (L/R): ");
    scanf(" %c", &dir);

    sort(req, n);

    for(i = 0; i < n; i++)
    {
        if(req[i] >= head)
        {
            pos = i;
            break;
        }
    }

    printf("\nSeek Sequence: %d ", head);

    if(dir == 'R' || dir == 'r')
    {
        for(i = pos; i < n; i++)
        {
            total += abs(head - req[i]);
            head = req[i];
            printf("-> %d ", head);
        }

        total += abs(head - (disk_size - 1));
        head = disk_size - 1;

        for(i = pos - 1; i >= 0; i--)
        {
            total += abs(head - req[i]);
            head = req[i];
            printf("-> %d ", head);
        }
    }
    else
    {
        for(i = pos - 1; i >= 0; i--)
        {
            total += abs(head - req[i]);
            head = req[i];
            printf("-> %d ", head);
        }

        total += abs(head - 0);
        head = 0;

        for(i = pos; i < n; i++)
        {
            total += abs(head - req[i]);
            head = req[i];
            printf("-> %d ", head);
        }
    }

    printf("\n\nTotal Head Movement = %d\n", total);

    return 0;
}
