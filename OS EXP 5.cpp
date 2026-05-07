#include <stdio.h>

struct Process
{
    int pid;
    int burstTime;
    int priority;
    int waitingTime;
    int turnaroundTime;
};

int main()
{
    int n, i, j;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];

    // Input process details
    for(i = 0; i < n; i++)
    {
        printf("\nEnter Burst Time and Priority for Process P%d: ", i + 1);
        p[i].pid = i + 1;
        scanf("%d %d", &p[i].burstTime, &p[i].priority);
    }

    // Sorting based on priority (Higher priority first)
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(p[i].priority < p[j].priority)
            {
                struct Process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // Calculate Waiting Time
    p[0].waitingTime = 0;

    for(i = 1; i < n; i++)
    {
        p[i].waitingTime = p[i - 1].waitingTime + p[i - 1].burstTime;
    }

    // Calculate Turnaround Time
    for(i = 0; i < n; i++)
    {
        p[i].turnaroundTime = p[i].waitingTime + p[i].burstTime;
    }

    // Display Results
    printf("\nPID\tBurst Time\tPriority\tWaiting Time\tTurnaround Time\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
               p[i].pid,
               p[i].burstTime,
               p[i].priority,
               p[i].waitingTime,
               p[i].turnaroundTime);
    }

    return 0;
}
