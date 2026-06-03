#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, head, total = 0;
    int request[50];

    printf("Enter the number of requests: ");
    scanf("%d", &n);

    printf("Enter the request sequence: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &request[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("\nSeek Sequence: %d", head);

    for(i = 0; i < n; i++)
    {
        total += abs(head - request[i]);
        head = request[i];
        printf(" -> %d", head);
    }

    printf("\n\nTotal Head Movement = %d", total);
    printf("\nAverage Seek Time = %.2f\n", (float)total / n);

    return 0;
}
