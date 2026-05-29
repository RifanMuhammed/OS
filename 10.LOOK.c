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

    for(int i = 0; i < totalRequests; i++)

        scanf("%d", &diskRequests[i]);

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

    // Move right side

    for(int i = startIndex;
        i < totalRequests; i++) {

        totalSeekTime +=
            abs(headPosition - diskRequests[i]);

        headPosition =
            diskRequests[i];
    }

    // Move left side

    for(int i = startIndex - 1;
        i >= 0; i--) {

        totalSeekTime +=
            abs(headPosition - diskRequests[i]);

        headPosition =
            diskRequests[i];
    }

    printf("Total Seek Time = %d\n",
           totalSeekTime);

    return 0;
}



SCAN Algorithm
Start
Input number of disk requests
Input disk request queue
Input initial head position
Sort all requests in ascending order
Find first request greater than head position
Move disk head to the right:
Service all higher requests
Add seek distances
After reaching end:
Reverse direction
Service left-side requests
Calculate total seek time
Display total seek time
Stop
SCAN Meaning

SCAN is also called:

Elevator Algorithm

Disk head moves:

in one direction first
then reverses direction

Like an elevator:

goes up
then comes back down
