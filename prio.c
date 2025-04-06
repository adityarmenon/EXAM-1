#include <stdio.h>

int main() {
    int n, pid[100], priority[100], burst[100], waiting[100], turnaround[100];
    float total_wt = 0, total_tt = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input burst time and priority
    for (int i = 0; i < n; i++) {
        pid[i] = i;
        printf("Enter Priority for P%d: ", i);
        
        scanf("%d", &priority[i]);
        printf("Enter Burst Time for P%d: ", i);
        scanf("%d", &burst[i]);
    }

    // Sort based on priority (lower number = higher priority)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (priority[j] > priority[j + 1]) {
                // Swap priority
                int temp = priority[j];
                priority[j] = priority[j + 1];
                priority[j + 1] = temp;

                // Swap burst time
                temp = burst[j];
                burst[j] = burst[j + 1];
                burst[j + 1] = temp;

                // Swap process ID
                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    // Calculate waiting time and turnaround time
    waiting[0] = 0;
    turnaround[0] = burst[0];
    for (int i = 1; i < n; i++) {
        waiting[i] = waiting[i - 1] + burst[i - 1];
        turnaround[i] = waiting[i] + burst[i];
    }

    // Print table
    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n", pid[i], priority[i], burst[i], waiting[i], turnaround[i]);
        total_wt += waiting[i];
        total_tt += turnaround[i];
    }

    // Gantt Chart
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", pid[i]);
    }
    printf("|\n0");
    int time = 0;
    for (int i = 0; i < n; i++) {
        time += burst[i];
        printf("   %d", time);
    }

    // Averages
    printf("\n\nAverage Waiting Time: %.2f ms\n", total_wt / n);
    printf("Average Turnaround Time: %.2f ms\n", total_tt / n);

    return 0;
}
