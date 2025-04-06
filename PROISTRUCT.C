#include <stdio.h>

struct Process {
    int pid;
    int priority;
    int burst;
    int waiting;
    int turnaround;
};

int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    struct Process p[n];
    float total_wt = 0, total_tt = 0;

    // Input
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("Enter Priority for P%d: ", p[i].pid);
        scanf("%d", &p[i].priority);
        printf("Enter Burst Time for P%d: ", p[i].pid);
        scanf("%d", &p[i].burst);
    }

    // Sort based on priority (lower value = higher priority)
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (p[j].priority > p[j + 1].priority) {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }

    // Calculate Waiting and Turnaround Time
    p[0].waiting = 0;
    p[0].turnaround = p[0].burst;
    for (int i = 1; i < n; i++) {
        p[i].waiting = p[i - 1].waiting + p[i - 1].burst;
        p[i].turnaround = p[i].waiting + p[i].burst;
    }

    // Output Table
    printf("\nProcess\tPriority\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t%d\t\t%d\n",
               p[i].pid, p[i].priority, p[i].burst, p[i].waiting, p[i].turnaround);
        total_wt += p[i].waiting;
        total_tt += p[i].turnaround;
    }

    // Gantt Chart
    printf("\nGantt Chart:\n");
    for (int i = 0; i < n; i++) {
        printf("| P%d ", p[i].pid);
    }
    printf("|\n0");
    int time = 0;
    for (int i = 0; i < n; i++) {
        time += p[i].burst;
        printf("   %d", time);
    }

    // Averages
    printf("\n\nAverage Waiting Time: %.2f ms\n", total_wt / n);
    printf("Average Turnaround Time: %.2f ms\n", total_tt / n);

    return 0;
}
