#include <stdio.h>
// FIFO
int main() {
    int n, f, i, j;
    int pages[20], frames[10];
    int faults = 0, front = 0, found;

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

        if(found == 0) {
            frames[front] = pages[i];
            front = (front + 1) % f;
            faults++;
        }
    }
//
    printf("Page Faults = %d", faults);
}
