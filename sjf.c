#include <stdio.h>

int main(){
    int n, i, j, bt[100], wt[100], tat[100], twt = 0, ttat = 0, temp;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        printf("Enter the burst time for P%d: ", i);
        scanf("%d", &bt[i]);
    }

    // Sort burst times for SJF
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(bt[j] > bt[j + 1]){
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time
    wt[0] = 0;  // First process has no waiting time
    for(i = 1; i < n; i++){
        wt[i] = wt[i - 1] + bt[i - 1];
    }

    for(i = 0; i < n; i++){
        tat[i] = wt[i] + bt[i];
    }

    // Totals
    for(i = 0; i < n; i++){
        ttat += tat[i];
        twt += wt[i];
    }

    // Output
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++){
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i, bt[i], wt[i], tat[i]);
    }

    // Averages
    float avg_wt = (float)twt / n;
    float avg_tat = (float)ttat / n;

    printf("\nTotal Waiting Time: %d", twt);
    printf("\nTotal Turnaround Time: %d", ttat);
    printf("\nAverage Waiting Time: %.2f", avg_wt);
    printf("\nAverage Turnaround Time: %.2f\n", avg_tat);

    return 0;
}
