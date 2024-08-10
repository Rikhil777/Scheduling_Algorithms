#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    printf("Enter Number of processes: ");
    scanf("%d", &n);
    int pid[n], at[n], bt[n], remaining_bt[n], ct[n], tat[n], wt[n];
    
    printf("Enter Process IDs: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pid[i]);
    }
    
    printf("Enter arrival time of each process: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &at[i]);
    }
    
    printf("Enter burst time of each process: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        remaining_bt[i] = bt[i]; 
    }

    int completed = 0, currentTime = 0, shortest = -1;
    int minRemainingTime = INT_MAX;
    int finishTime;
    int isProcessRunning = 0;

    while (completed != n) {
       
        for (int i = 0; i < n; i++) {
            if (at[i] <= currentTime && remaining_bt[i] < minRemainingTime && remaining_bt[i] > 0) {
                shortest = i;
                minRemainingTime = remaining_bt[i];
                isProcessRunning = 1;
            }
        }

        if (isProcessRunning == 0) {
            currentTime++;
            continue;
        }

        
        remaining_bt[shortest]--;
        minRemainingTime = remaining_bt[shortest];

       
        if (remaining_bt[shortest] == 0) {
            completed++;
            isProcessRunning = 0;
            minRemainingTime = INT_MAX;
            finishTime = currentTime + 1;
            ct[shortest] = finishTime; 
        }

        currentTime++;
    }

    
    for (int i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];  
        wt[i] = tat[i] - bt[i];  
    }

    
    printf("\n=====================================  The Process Table  ==============================================\n");
    printf("Process No   Arrival Time   Burst Time   Completion Time   Turnaround Time   Waiting Time\n");
    
    for (int i = 0; i < n; i++) {
        printf("%d           %d              %d          %d                  %d               %d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    return 0;
}
