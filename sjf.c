#include <stdio.h>
int main()
{
    int n;
    printf("Enter Number of process: ");
    scanf("%d",&n);
    int pid[n];
    printf("Enter Process Id's: \n");
    for (int i = 0;i<n;i++){
        scanf("%d",&pid[i]);
    }
    int at[n];
    printf("Enter arrival time of each process: \n");
    for (int i = 0;i<n;i++)
    {
        scanf("%d",&at[i]);
    }
    int bt[n];
    printf("Enter burst time of each process: \n");
    for (int i = 0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }

    
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                // Swap arrival time
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // Swap burst time
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // Swap process ID
                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
                
            }
        }
    }
    int ct[n];

    int completed = 0, currentTime = 0, shortest;
    int completedProcesses[n];
    for (int i = 0; i < n; i++) {
        completedProcesses[i] = 0;
    }

    while (completed != n) {
        shortest = -1;
        for (int i = 0; i < n; i++) {
            if (at[i] <= currentTime && !completedProcesses[i]) {
                if (shortest == -1 || bt[i] < bt[shortest]) {
                    shortest = i;
                }
            }
        }

        if (shortest != -1) {
            currentTime += bt[shortest];
            ct[shortest] = currentTime;
            completedProcesses[shortest] = 1;
            completed++;
        } else {
            currentTime++;
        }
    }
    
    int tat[n];
    for (int i = 0;i<n;i++)
    {
        tat[i] = ct[i] - at[i];
    }
    int wt[n];
    for (int i = 0;i<n;i++)
    {
        wt[i] = tat[i] - bt[i];
    }
printf("\n=====================================  The Process Table  ==============================================\n");
            printf("Process No   Arrival Time   Burst Time   Complition Time   Turnaround Time     Waiting time\n");
    for (int i = 0;i<n;i++){
            printf("%d              %d              %d          %d               %d                   %d\n",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
    }


}