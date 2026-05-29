#include <stdio.h>
#include <stdlib.h>

int main() {

    int totalRequests;

    int headPosition;

    int totalSeekTime = 0;

    int diskRequests[20];

    printf("Enter number of requests: ");
    scanf("%d", &totalRequests);

    printf("Enter requests: ");

    for(int i = 0; i < totalRequests; i++) {

        scanf("%d", &diskRequests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &headPosition);

    // Sort requests

    for(int i = 0; i < totalRequests - 1; i++) {

        for(int j = i + 1; j < totalRequests; j++) {

            if(diskRequests[i] >
               diskRequests[j]) {

                int temp = diskRequests[i];

                diskRequests[i] =
                    diskRequests[j];

                diskRequests[j] = temp;
            }
        }
    }

    int startIndex = 0;

    while(startIndex < totalRequests &&
          diskRequests[startIndex] < headPosition)

        startIndex++;

    // Move right

    for(int i = startIndex;
        i < totalRequests; i++) {

        totalSeekTime +=
            abs(headPosition - diskRequests[i]);

        headPosition =
            diskRequests[i];
    }

    // Jump to beginning

    if(startIndex > 0) {

        totalSeekTime +=
            abs(headPosition - diskRequests[0]);

        headPosition =
            diskRequests[0];
    }

    // Continue moving right

    for(int i = 0; i < startIndex; i++) {

        totalSeekTime +=
            abs(headPosition - diskRequests[i]);

        headPosition =
            diskRequests[i];
    }

    printf("Total Seek Time (CSCAN) = %d\n",
           totalSeekTime);

    return 0;
}




CSCAN Algorithm
Start
Input number of disk requests
Input disk request queue
Input initial head position
Sort all requests in ascending order
Find first request greater than current head position
Move disk head to the right:
Service all higher requests
Add seek distance
Jump to beginning of disk
Continue servicing remaining requests from beginning
Calculate total seek time
Display total seek time
Stop
CSCAN Meaning

CSCAN = Circular SCAN

Disk head moves only in one direction.

After reaching end:

Head jumps back to beginning

Then continues again.

Like a circular elevator system.
