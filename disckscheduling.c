#include <stdio.h>
#include <stdlib.h>

void fcfs(int requests[], int n, int head) {
    int seek_count = 0;
    for (int i = 0; i < n; i++) {
        seek_count += abs(requests[i] - head);
        head = requests[i];
    }
    printf("FCFS Total Seek Count: %d\n", seek_count);
}

void sstf(int req[], int n, int head) {
    int seek = 0, done[100] = {0};

    for (int i = 0; i < n; i++) {
        int min = 10000, idx = -1;

        for (int j = 0; j < n; j++) {
            if (!done[j]) {
                int diff = abs(req[j] - head);
                if (diff < min) {
                    min = diff;
                    idx = j;
                }
            }
        }
        seek += min;
        head = req[idx];
        done[idx] = 1;
    }

    printf("SSTF Seek Count: %d\n", seek);
}

void scan(int req[], int n, int head, int size) {
    int seek = 0;

    // Sort the request array
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (req[i] > req[j]) {
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    // Find the first request greater than the head
    int i = 0;
    while (i < n && req[i] < head) i++;

    // Move right (towards higher track numbers)
    for (int j = i; j < n; j++) {
        seek += abs(req[j] - head);
        head = req[j];
    }

    // Go to the end of the disk
    seek += abs((size - 1) - head);
    head = size - 1;

    // Now go back left to the beginning
    for (int j = i - 1; j >= 0; j--) {
        seek += abs(req[j] - head);
        head = req[j];
    }

    printf("SCAN Seek Count: %d\n", seek);
}



void cscan(int req[], int n, int head, int size) {
    int seek = 0;

    // Sort the request array
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (req[i] > req[j]) {
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    // Find the first request greater than the head
    int i = 0;
    while (i < n && req[i] < head) i++;

    // Move right (towards higher track numbers)
    for (int j = i; j < n; j++) {
        seek += abs(req[j] - head);
        head = req[j];
    }

    // Go to the end of the disk
    seek += abs((size - 1) - head);
    head = 0;

    // Move from beginning and service remaining requests
    for (int j = 0; j < i; j++) {
        seek += abs(req[j] - head);
        head = req[j];
    }

    printf("CSCAN Total Seek Count: %d\n", seek);
}


void look(int req[], int n, int head) {
    int seek = 0;

    // Sort the request array
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (req[i] > req[j]) {
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    // Find the first request greater than the head
    int i = 0;
    while (i < n && req[i] < head) i++;

    // Move right (towards higher track numbers)
    for (int j = i; j < n; j++) {
        seek += abs(req[j] - head);
        head = req[j];
    }

    // Now move left (towards smaller track numbers)
    for (int j = i - 1; j >= 0; j--) {
        seek += abs(req[j] - head);
        head = req[j];
    }

    printf("LOOK Total Seek Count: %d\n", seek);
}


void clook(int req[], int n, int head) {
    int seek = 0;

    // Sort the request array
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (req[i] > req[j]) {
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    // Find the first request greater than the head
    int i = 0;
    while (i < n && req[i] < head) i++;

    // Move right (towards higher track numbers)
    for (int j = i; j < n; j++) {
        seek += abs(req[j] - head);
        head = req[j];
    }

    // Jump to the lowest request and continue right again
    for (int j = 0; j < i; j++) {
        seek += abs(req[j] - head);
        head = req[j];
    }

    printf("CLOOK Total Seek Count: %d\n", seek);
}


int main() {
    int n, head, disk_size;
    int requests[100];
    printf("Enter the number of requests: ");
    scanf("%d", &n);
    printf("Enter the request queue: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &requests[i]);
    }
    printf("Enter the initial head position: ");
    scanf("%d", &head);
    printf("Enter the disk size: ");
    scanf("%d", &disk_size);

    fcfs(requests, n, head);
    sstf(requests, n, head);
    scan(requests, n, head, disk_size);
    cscan(requests, n, head, disk_size);
    look(requests, n, head);
    clook(requests, n, head);

    return 0;
}
