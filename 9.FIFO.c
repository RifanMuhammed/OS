#include <stdio.h>

// FIFO PAGE REPLACEMENT

int main() {

    int totalPages;
    int totalFrames;

    int i, j;

    int pageReference[20];
    int memoryFrames[10];

    int pageFaults = 0;

    int replaceIndex = 0;

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
    }

    for(i = 0; i < totalPages; i++) {

        pageFound = 0;

        for(j = 0; j < totalFrames; j++) {

            if(memoryFrames[j] ==
               pageReference[i]) {

                pageFound = 1;

                break;
            }
        }

        if(pageFound == 0) {

            memoryFrames[replaceIndex] =
                pageReference[i];

            replaceIndex =
                (replaceIndex + 1) % totalFrames;

            pageFaults++;
        }
    }

    printf("Page Faults = %d",
           pageFaults);
}


FIFO Page Replacement Algorithm
Start
Input number of pages
Input reference string
Input number of frames
Initialize all frames as empty
Set:
pageFaults = 0
replaceIndex = 0

Repeat for each page in reference string:

a. Assume page is not found

b. Check all frames:

If page already exists in frame:
Mark page as found
Stop checking

c. If page is not found:

Replace page at replaceIndex
Move replaceIndex to next frame
Increase page fault count
Display total page faults
Stop
