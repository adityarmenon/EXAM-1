#include <stdio.h>

int a[30][30], m[30][30], n[30][30], v[30], av[30], s[30];
int i, j, k, p, r, ind;

void safe() {
    for (i = 0; i < p; i++) v[i] = 0;
    ind = 0;

    for (k = 0; k < p; k++) {
        for (i = 0; i < p; i++) {
            if (!v[i]) {
                int flag = 1;
                for (j = 0; j < r; j++)
                    if (n[i][j] > av[j]) {
                        flag = 0;
                        break;
                    }

                if (flag) {
                    v[i] = 1;
                    s[ind++] = i;
                    for (j = 0; j < r; j++)
                        av[j] += a[i][j];
                }
            }
        }
    }

    for (i = 0; i < p; i++)
        if (!v[i]) {
            printf("Not a safe sequence\n");
            return;
        }

    printf("Safe sequence: ");
    for (i = 0; i < p - 1; i++)
        printf("P%d -> ", s[i]);
    printf("P%d\n", s[i]);
}

void main() {
    printf("Enter the number of processes: ");
    scanf("%d", &p);
    printf("Enter the number of resources: ");
    scanf("%d", &r);

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &a[i][j]);

    printf("Enter the max matrix:\n");
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++) {
            scanf("%d", &m[i][j]);
            n[i][j] = m[i][j] - a[i][j];
        }

    printf("Enter available resources: ");
    for (i = 0; i < r; i++)
        scanf("%d", &av[i]);

    safe();

    int req, new[30];
    printf("Enter request process: ");
    scanf("%d", &req);
    printf("Enter resource request: ");
    for (i = 0; i < r; i++)
        scanf("%d", &new[i]);

    for (i = 0; i < r; i++) {
        if (new[i] > n[req][i]) {
            printf("Request exceeds need.\n");
            return;
        }
        if (new[i] > av[i]) {
            printf("Resources not available.\n");
            return;
        }
    }

    for (i = 0; i < r; i++) {
        a[req][i] += new[i];
        n[req][i] -= new[i];
        av[i] -= new[i];
    }

    safe(); // Check safe state again after request
}
