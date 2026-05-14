#include <stdio.h>

int main() {
    int blockSize[20], processSize[20];
    int allocation[20];
    int m, n, i, j, bestIdx;

    // Input number of memory blocks
    printf("Enter number of memory blocks: ");
    scanf("%d", &m);

    // Input block sizes
    printf("Enter sizes of memory blocks:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }

    // Input number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input process sizes
    printf("Enter sizes of processes:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    // Initialize allocation array
    for(i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    // Best Fit Allocation
    for(i = 0; i < n; i++) {
        bestIdx = -1;

        for(j = 0; j < m; j++) {
            if(blockSize[j] >= processSize[i]) {

                if(bestIdx == -1 ||
                   blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j;
                }
            }
        }

        // Allocate memory block
        if(bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    // Display result
    printf("\nProcess No\tProcess Size\tBlock No\n");

    for(i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}
