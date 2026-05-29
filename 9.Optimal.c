#include <stdio.h>

// OPTIMAL PAGE REPLACEMENT

int main() {

    int totalPages, totalFrames, i, j;

    int pageReference[20];

    int memoryFrames[10];

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

        // PAGE FAULT

        if(pageFound == 0) {

            int replacePosition = -1;

            int farthestUse = i + 1;

            for(j = 0; j < totalFrames; j++) {

                int k;

                // Check future page usage

                for(k = i + 1; k < totalPages; k++) {

                    if(memoryFrames[j] ==
                       pageReference[k]) {

                        break;
                    }
                }

                // Page never used again

                if(k == totalPages) {

                    replacePosition = j;

                    break;
                }

                // Page used farthest in future

                if(k > farthestUse) {

                    farthestUse = k;

                    replacePosition = j;
                }
            }

            // If all pages will be used again

            if(replacePosition == -1) {

                replacePosition = 0;
            }

            memoryFrames[replacePosition] =
                pageReference[i];

            pageFaults++;
        }
    }

    printf("Page Faults = %d",
           pageFaults);

    return 0;
}



Optimal Page Replacement Algorithm
Start
Input number of pages
Input reference string
Input number of frames
Initialize all frames as empty
Set page faults = 0

Repeat for each page in reference string:

a. Check whether page already exists in frames

b. If page exists:

Page Hit
Continue

c. Else:

Find the page whose next use is farthest in future
If a page is never used again, replace it immediately
Replace selected page with new page
Increase page faults
Display total page faults
Stop
