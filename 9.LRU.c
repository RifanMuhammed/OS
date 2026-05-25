#include <stdio.h>

int main() {

    int n, f, i, j;
    int pages[20], frames[10], used[10];
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
        used[i] = -1;                       //additional
    }
//
    for(i = 0; i < n; i++) {
        found = 0;

        for(j = 0; j < f; j++) {
            if(frames[j] == pages[i]) {
                found = 1;
                used[j] = i;                //additional
                break;
            }
        }

        if(found == 0) {
            int lru = 0;
            for(j = 1; j < f; j++) {
                if(used[j] < used[lru]) {
                    lru = j;
                }
            }

            frames[lru] = pages[i];
            used[lru] = i;
            faults++;
        }
    }
//
    printf("Page Faults = %d", faults);

    return 0;
}
