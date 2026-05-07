#include <stdio.h>

int main() {
    int n, tq, i;
    int bt[10], rt[10], wt[10], tat[10];
    int total_wt = 0, total_tat = 0;
    int time = 0, remain;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    remain = n;

    printf("Enter Burst Time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("P%d: ", i + 1);
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    while(remain != 0) {
        for(i = 0; i < n; i++) {
            if(rt[i] > 0) {
                if(rt[i] <= tq) {
                    time += rt[i];
                    rt[i] = 0;
                    remain--;

                    tat[i] = time;
                    wt[i] = tat[i] - bt[i];

                    total_wt += wt[i];
                    total_tat += tat[i];
                }
                else {
                    rt[i] -= tq;
                    time += tq;
                }
            }
        }
    }

    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\n",
               i + 1, bt[i], wt[i], tat[i]);
    }

    printf("\nAverage Waiting Time = %.2f",
           (float)total_wt / n);

    printf("\nAverage Turnaround Time = %.2f\n",
           (float)total_tat / n);

    return 0;
}
