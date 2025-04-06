#include <stdio.h>
#include <stdlib.h>

void first(int mem[], int proc[], int m, int p) {
    int a[100], b[100];
    int flag1[100], flag2[100];

    for (int i = 0; i < m; i++) {
        a[i] = mem[i];
        flag1[i] = 0;
    }
    for (int i = 0; i < p; i++) {
        b[i] = proc[i];
        flag2[i] = 0;
    }

    printf("\nFirst Fit\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < m; j++) {
            if (a[j] >= b[i] && flag1[j] != 1 && flag2[i] != 1) {
                printf("Process %d is allocated to block %d, Wastage = %d\n", b[i], a[j], a[j] - b[i]);
                flag1[j] = 1;
                flag2[i] = 1;
                break;
            }
        }
        if (flag2[i] == 0) {
            printf("Process %d could not be allocated\n", b[i]);
        }
    }
}

void best(int mem[], int proc[], int m, int p) {
    int a[100], b[100];
    int flag1[100], flag2[100];

    for (int i = 0; i < m; i++) {
        a[i] = mem[i];
        flag1[i] = 0;
    }
    for (int i = 0; i < p; i++) {
        b[i] = proc[i];
        flag2[i] = 0;
    }

    int temp;
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j]; a[j] = a[j + 1]; a[j + 1] = temp;
            }
        }
    }

    printf("\nBest Fit\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < m; j++) {
            if (a[j] >= b[i] && flag1[j] != 1 && flag2[i] != 1) {
                printf("Process %d is allocated to block %d, Wastage = %d\n", b[i], a[j], a[j] - b[i]);
                flag1[j] = 1;
                flag2[i] = 1;
                break;
            }
        }
        if (flag2[i] == 0) {
            printf("Process %d could not be allocated\n", b[i]);
        }
    }
}

void worst(int mem[], int proc[], int m, int p) {
    int a[100], b[100];
    int flag1[100], flag2[100];

    for (int i = 0; i < m; i++) {
        a[i] = mem[i];
        flag1[i] = 0;
    }
    for (int i = 0; i < p; i++) {
        b[i] = proc[i];
        flag2[i] = 0;
    }

    int temp;
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (a[j] < a[j + 1]) {
                temp = a[j]; a[j] = a[j + 1]; a[j + 1] = temp;
            }
        }
    }

    printf("\nWorst Fit\n");
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < m; j++) {
            if (a[j] >= b[i] && flag1[j] != 1 && flag2[i] != 1) {
                printf("Process %d is allocated to block %d, Wastage = %d\n", b[i], a[j], a[j] - b[i]);
                flag1[j] = 1;
                flag2[i] = 1;
                break;
            }
        }
        if (flag2[i] == 0) {
            printf("Process %d could not be allocated\n", b[i]);
        }
    }
}

int main() {
    int proc[100], mem[100], m, p;

    printf("Enter total number of memory blocks: ");
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        printf("Enter size of Memory Block M%d: ", i );
        scanf("%d", &mem[i]);
    }

    printf("Enter total number of processes: ");
    scanf("%d", &p);
    for (int j = 0; j < p; j++) {
        printf("Enter size of Process P%d: ", j);
        scanf("%d", &proc[j]);
    }

    first(mem, proc, m, p);
    best(mem, proc, m, p);
    worst(mem, proc, m, p);

    return 0;
}
