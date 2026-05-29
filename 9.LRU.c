#include <stdio.h>

// LRU PAGE REPLACEMENT

int main() {

    int totalPages, totalFrames, i, j;

    int pageReference[20];
    int memoryFrames[10];

    int lastUsed[10];

    int pageFaults = 0;

    int pageFound;

    printf("Enter number of pages: ");
    scanf("%d", &totalPages);

    printf("Enter reference string: ");

    for(i = 0; i < totalPages; i++) {

        scanf("%d", &pageReference[i]);
    }

    printf("Enter number of frames: ");
    scanf("%d", &totalFrames);

    for(i = 0; i < totalFrames; i++) {

        memoryFrames[i] = -1;

        lastUsed[i] = -1;
    }

    for(i = 0; i < totalPages; i++) {

        pageFound = 0;

        for(j = 0; j < totalFrames; j++) {

            if(memoryFrames[j] ==
               pageReference[i]) {

                pageFound = 1;

                lastUsed[j] = i;

                break;
            }
        }

        if(pageFound == 0) {

            int leastRecentlyUsed = 0;

            for(j = 1; j < totalFrames; j++) {

                if(lastUsed[j] <
                   lastUsed[leastRecentlyUsed]) {

                    leastRecentlyUsed = j;
                }
            }

            memoryFrames[leastRecentlyUsed] =
                pageReference[i];

            lastUsed[leastRecentlyUsed] = i;

            pageFaults++;
        }
    }

    printf("Page Faults = %d",
           pageFaults);

    return 0;
}



LRU Algorithm
Start
Input number of pages
Input reference string
Input number of frames
Initialize:
all frames as empty
all last used values as -1
Set page faults = 0

Repeat for every page in reference string:

a. Check whether page already exists in frames

b. If page exists:

Update its last used position

c. Else:

Find least recently used page
Replace it with new page
Update last used position
Increase page faults
Display total page faults
Stop
