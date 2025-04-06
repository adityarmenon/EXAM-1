#include <stdio.h>

int a[30][30], m[30][30], n[30][30], v[30], av[30], s[30], dav[30];
int i, j, k, p, r, ind = 0;

void main() {
    printf("Enter the number of processes: ");
    scanf("%d", &p);
    printf("Enter the number of resources: ");
    scanf("%d", &r);

    printf("Enter the allocation matrix:\n");
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &a[i][j]);

    printf("Enter the max allocation matrix:\n");
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            scanf("%d", &m[i][j]);

    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            n[i][j] = m[i][j] - a[i][j];

    printf("Enter the available resources: ");
    for (i = 0; i < r; i++) {
        scanf("%d", &av[i]);
        dav[i] = av[i];
    }

    for (i = 0; i < p; i++)
        v[i] = 0;

    // Safe sequence check
    for (k = 0; k < p; k++) {
        for (i = 0; i < p; i++) {
            if (v[i] == 0) {
                int flag = 0;
                for (j = 0; j < r; j++)
                    if (n[i][j] > av[j]) {
                        flag = 1;
                        break;
                    }

                if (flag == 0) {
                    v[i] = 1;
                    s[ind++] = i;
                    for (int x = 0; x < r; x++)
                        av[x] += a[i][x];
                }
            }
        }
    }

    int flag = 1;
    for (i = 0; i < p; i++)
        if (v[i] == 0) {
            flag = 0;
            printf("Not a safe sequence\n");
            return;
        }

    printf("Safe sequence: ");
    for (i = 0; i < p - 1; i++)
        printf("P%d -> ", s[i]);
    printf("P%d\n", s[i]);

    // Handle request
    int req, new[r];
    printf("Enter request process: ");
    scanf("%d", &req);
    printf("Enter the resource request: ");
    for (i = 0; i < r; i++)
        scanf("%d", &new[i]);

    for (j = 0; j < r; j++) {
        if (new[j] > n[req][j]) {
            printf("Error: Request exceeds need.\n");
            return;
        }
    }

    for (i = 0; i < r; i++) {
        a[req][i] += new[i];
        n[req][i] -= new[i];
        av[i] -= new[i];
    }

    printf("Updated Available Resources: ");
    for (i = 0; i < r; i++)
        printf("%d ", av[i]);
    printf("\n");

    // Re-check safe sequence
    for (i = 0; i < p; i++)
        v[i] = 0;
    ind = 0;

    for (k = 0; k < p; k++) {
        for (i = 0; i < p; i++) {
            if (v[i] == 0) {
                int flag = 0;
                for (j = 0; j < r; j++)
                    if (n[i][j] > av[j]) {
                        flag = 1;
                        break;
                    }

                if (flag == 0) {
                    v[i] = 1;
                    s[ind++] = i;
                    for (int x = 0; x < r; x++)
                        av[x] += a[i][x];
                }
            }
        }
    }

    flag = 1;
    for (i = 0; i < p; i++)
        if (v[i] == 0) {
            flag = 0;
            printf("Not a safe sequence\n");
            return;
        }

    printf("New Safe sequence: ");
    for (i = 0; i < p - 1; i++)
        printf("P%d -> ", s[i]);
    printf("P%d\n", s[i]);
}
