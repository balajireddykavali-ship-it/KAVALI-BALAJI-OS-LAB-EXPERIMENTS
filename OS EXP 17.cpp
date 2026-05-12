// C Program to Simulate Banker's Algorithm (Deadlock Avoidance)

#include <stdio.h>

int main() {
    int n, m, i, j, k;

    // n = number of processes
    // m = number of resources
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resource types: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m];
    int avail[m];

    printf("\nEnter Allocation Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter Maximum Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter Available Resources:\n");
    for(i = 0; i < m; i++) {
        scanf("%d", &avail[i]);
    }

    // Calculate Need Matrix
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("\nNeed Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    int finish[n], safeSeq[n];
    for(i = 0; i < n; i++) {
        finish[i] = 0;
    }

    int work[m];
    for(i = 0; i < m; i++) {
        work[i] = avail[i];
    }

    int count = 0;

    while(count < n) {
        int found = 0;

        for(i = 0; i < n; i++) {

            if(finish[i] == 0) {

                for(j = 0; j < m; j++) {
                    if(need[i][j] > work[j]) {
                        break;
                    }
                }

                if(j == m) {

                    for(k = 0; k < m; k++) {
                        work[k] += alloc[i][k];
                    }

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0) {
            break;
        }
    }

    // Check system state
    if(count == n) {
        printf("\nSystem is in SAFE state.\n");
        printf("Safe Sequence: ");

        for(i = 0; i < n; i++) {
            printf("P%d ", safeSeq[i]);
        }
        printf("\n");
    }
    else {
        printf("\nSystem is NOT in safe state (Deadlock may occur).\n");
    }

    return 0;
}
