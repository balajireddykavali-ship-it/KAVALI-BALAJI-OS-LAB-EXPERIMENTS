// C Program to Implement Various Memory Allocation Strategies
// First Fit, Best Fit, and Worst Fit

#include <stdio.h>

void firstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocation[10];
    
    for(int i = 0; i < processes; i++)
        allocation[i] = -1;

    for(int i = 0; i < processes; i++)
    {
        for(int j = 0; j < blocks; j++)
        {
            if(blockSize[j] >= processSize[i])
            {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nFIRST FIT Allocation\n");
    printf("Process No\tProcess Size\tBlock No\n");

    for(int i = 0; i < processes; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void bestFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocation[10];

    for(int i = 0; i < processes; i++)
        allocation[i] = -1;

    for(int i = 0; i < processes; i++)
    {
        int bestIdx = -1;

        for(int j = 0; j < blocks; j++)
        {
            if(blockSize[j] >= processSize[i])
            {
                if(bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }

        if(bestIdx != -1)
        {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("\nBEST FIT Allocation\n");
    printf("Process No\tProcess Size\tBlock No\n");

    for(int i = 0; i < processes; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

void worstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocation[10];

    for(int i = 0; i < processes; i++)
        allocation[i] = -1;

    for(int i = 0; i < processes; i++)
    {
        int worstIdx = -1;

        for(int j = 0; j < blocks; j++)
        {
            if(blockSize[j] >= processSize[i])
            {
                if(worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }

        if(worstIdx != -1)
        {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    printf("\nWORST FIT Allocation\n");
    printf("Process No\tProcess Size\tBlock No\n");

    for(int i = 0; i < processes; i++)
    {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main()
{
    int blockSize1[] = {100, 500, 200, 300, 600};
    int blockSize2[] = {100, 500, 200, 300, 600};
    int blockSize3[] = {100, 500, 200, 300, 600};

    int processSize[] = {212, 417, 112, 426};

    int blocks = 5;
    int processes = 4;

    firstFit(blockSize1, blocks, processSize, processes);

    bestFit(blockSize2, blocks, processSize, processes);

    worstFit(blockSize3, blocks, processSize, processes);

    return 0;
}
