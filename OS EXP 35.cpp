// Indexed File Allocation Simulation

#include <stdio.h>

int main()
{
    int n, i, blockNo;

    printf("Enter number of file blocks: ");
    scanf("%d", &n);

    int indexBlock[n];

    printf("Enter block numbers:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &indexBlock[i]);
    }

    printf("\nIndex Block Entries:\n");
    printf("File Block\tDisk Block\n");
    for(i = 0; i < n; i++)
    {
        printf("%d\t\t%d\n", i, indexBlock[i]);
    }

    printf("\nEnter file block number to access: ");
    scanf("%d", &blockNo);

    if(blockNo < 0 || blockNo >= n)
    {
        printf("Invalid file block number.\n");
        return 0;
    }

    printf("\nFile Block %d is stored at Disk Block %d\n",
           blockNo, indexBlock[blockNo]);

    return 0;
}
