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

    // Sorting Arrival Time
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
    //completion time
    ct[0] = at[0] + bt[0]; //first process
    for (int i = 1;i<n;i++) 
    {
        if (at[i] > ct[i-1]){
            ct[i] = at[i] + bt[i];
        }
        else {
            ct[i] = ct[i - 1] + bt[i];
        }
    }
    int tat[n];
    for (int i = 0;i<n;i++) 
    {
        tat[i] = ct[i] - at[i];
    }
    int wt[n];
    for (int i = 0;i < n;i++)
    {
        wt[i] = tat[i] - bt[i];
    }
    
printf("\n=====================================  The Process Table  ==============================================\n");
            printf("Process No   Arrival Time   Burst Time   Complition Time   Turaround Time   Waiting Time\n");
    for (int i = 0;i<n;i++){
            printf("%d              %d              %d            %d                 %d              %d",pid[i],at[i],bt[i],ct[i],tat[i],wt[i]);
            printf("\n");
    }

}
