#include <stdio.h>
#include <stdlib.h>

#define MAX_FRAMES 10
#define MAX_PAGES 30

// FIFO Page Replacement
void fifo(int pages[], int n, int capacity) {
    int frames[MAX_FRAMES];
    int index = 0, faults = 0;

    // Initialize all frames to -1 (empty)
    for (int i = 0; i < capacity; i++) frames[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;

        // Check if page is already in frame
        for (int j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // If not found, insert it (FIFO style)
        if (!found) {
            frames[index] = pages[i];
            index = (index + 1) % capacity;
            faults++;
        }
    }

    printf("FIFO Page Faults: %d\n", faults);
}

// Optimal Page Replacement
void optimal(int pages[], int n, int capacity) {
    int frames[MAX_FRAMES];
    int faults = 0;

    for (int i = 0; i < capacity; i++) frames[i] = -1;

    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        if (!found) {
            int index = -1, farthest = i;

            // Find the page not used for the longest in future
            for (int j = 0; j < capacity; j++) {
                int k;
                for (k = i + 1; k < n; k++) {
                    if (frames[j] == pages[k]) break;
                }

                if (k == n) {
                    index = j;
                    break;
                }

                if (k > farthest) {
                    farthest = k;
                    index = j;
                }
            }

            if (index == -1) index = 0;

            frames[index] = pages[i];
            faults++;
        }
    }

    printf("Optimal Page Faults: %d\n", faults);
}

// LRU Page Replacement
void lru(int pages[], int n, int capacity) {
    int frames[MAX_FRAMES], time[MAX_FRAMES];
    int counter = 0, faults = 0;

    for (int i = 0; i < capacity; i++) {
        frames[i] = -1;
        time[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int found = 0;

        for (int j = 0; j < capacity; j++) {
            if (frames[j] == pages[i]) {
                found = 1;
                counter++;
                time[j] = counter; // Update recent use time
                break;
            }
        }

        if (!found) {
            int lru = 0;

            for (int j = 1; j < capacity; j++) {
                if (time[j] < time[lru]) {
                    lru = j;
                }
            }

            frames[lru] = pages[i];
            counter++;
            time[lru] = counter;
            faults++;
        }
    }

    printf("LRU Page Faults: %d\n", faults);
}

// Main Function
int main() {
    int pages[MAX_PAGES], n, capacity;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter the page reference string: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &capacity);

    fifo(pages, n, capacity);
    optimal(pages, n, capacity);
    lru(pages, n, capacity);

    return 0;
}
