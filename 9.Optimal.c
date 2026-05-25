#include <stdio.h>
// OPTIMAL
int main() {
    int n, f, i, j;
    int pages[20], frames[10];
    int faults = 0, found;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter reference string: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &f);

    for(i = 0; i < f; i++) {
        frames[i] = -1;
    }
//
    for(i = 0; i < n; i++) {
        found = 0;
        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // page fault
        if(found == 0) {
            int pos = -1;
            int farthest = i + 1;
            for(j = 0; j < f; j++) {
                int k;
                // search future references
                for(k = i + 1; k < n; k++) {
                    if(frames[j] == pages[k]) {
                        break;
                    }
                }
                // page never used again
                if(k == n) {
                    pos = j;
                    break;
                }
                // page used farthest in future
                if(k > farthest) {
                    farthest = k;
                    pos = j;
                }
            }
            // if all pages used again
            if(pos == -1) {
                pos = 0;
            }

            frames[pos] = pages[i];
            faults++;
        }
    }
//
    printf("Page Faults = %d", faults);
}
