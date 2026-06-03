// Sequential File Allocation Simulation

#include <stdio.h>

int main()
{
    int n, i, recordNo;

    printf("Enter number of records: ");
    scanf("%d", &n);

    int records[n];

    printf("Enter record values:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &records[i]);
    }

    printf("\nSequential Allocation of Records:\n");
    for(i = 0; i < n; i++)
    {
        printf("Record %d -> %d\n", i + 1, records[i]);
    }

    printf("\nEnter record number to access: ");
    scanf("%d", &recordNo);

    if(recordNo < 1 || recordNo > n)
    {
        printf("Invalid record number.\n");
        return 0;
    }

    printf("\nAccessing Record %d:\n", recordNo);
    printf("Records read sequentially:\n");

    for(i = 0; i < recordNo; i++)
    {
        printf("Reading Record %d : %d\n", i + 1, records[i]);
    }

    printf("\nRequested Record Data = %d\n", records[recordNo - 1]);

    return 0;
}
