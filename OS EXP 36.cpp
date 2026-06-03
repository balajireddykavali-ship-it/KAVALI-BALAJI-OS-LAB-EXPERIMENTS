#include <stdio.h>

int main()
{
    int n, i, j, blocks[20][20], nob[20];
    char fname[20][20];

    printf("Enter number of files: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nEnter file name: ");
        scanf("%s", fname[i]);

        printf("Enter number of blocks: ");
        scanf("%d", &nob[i]);

        printf("Enter block numbers: ");
        for(j = 0; j < nob[i]; j++)
        {
            scanf("%d", &blocks[i][j]);
        }
    }

    printf("\n\nLinked File Allocation\n");
    printf("---------------------------------\n");

    for(i = 0; i < n; i++)
    {
        printf("\nFile: %s\n", fname[i]);
        printf("Blocks: ");

        for(j = 0; j < nob[i]; j++)
        {
            if(j == nob[i] - 1)
                printf("%d -> NULL", blocks[i][j]);
            else
                printf("%d -> ", blocks[i][j]);
        }
        printf("\n");
    }

    return 0;
}
