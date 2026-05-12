// Worst Fit Memory Management Algorithm

#include <stdio.h>

int main()
{
    int blockSize[10], processSize[10];
    int allocation[10];
    int m, n, i, j, worstIdx;

    // Number of memory blocks
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    // Memory block sizes
    printf("Enter sizes of memory blocks:\n");
    for(i = 0; i < m; i++)
        scanf("%d", &blockSize[i]);

    // Number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Process sizes
    printf("Enter sizes of processes:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &processSize[i]);

    // Initially no allocation
    for(i = 0; i < n; i++)
        allocation[i] = -1;

    // Worst Fit Allocation
    for(i = 0; i < n; i++)
    {
        worstIdx = -1;

        for(j = 0; j < m; j++)
        {
            if(blockSize[j] >= processSize[i])
            {
                if(worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }

        // Allocate memory block
        if(worstIdx != -1)
        {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    // Display Allocation
    printf("\nProcess No\tProcess Size\tBlock No\n");

    for(i = 0; i < n; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
