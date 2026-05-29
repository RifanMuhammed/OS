#include <stdio.h>
#include <stdlib.h>

int main() {

    int totalRequests;

    int headPosition;

    int totalSeekTime = 0;

    int diskRequests[20];

    int completed[20] = {0};

    printf("Enter number of requests: ");
    scanf("%d", &totalRequests);

    printf("Enter requests: ");

    for(int i = 0; i < totalRequests; i++) {

        scanf("%d", &diskRequests[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &headPosition);

    for(int i = 0; i < totalRequests; i++) {

        int minimumDistance = 9999;

        int nearestRequest = -1;

        for(int j = 0; j < totalRequests; j++) {

            int distance =
                abs(headPosition - diskRequests[j]);

            if(completed[j] == 0 &&
               distance < minimumDistance) {

                minimumDistance = distance;

                nearestRequest = j;
            }
        }

        totalSeekTime += minimumDistance;

        headPosition =
            diskRequests[nearestRequest];

        completed[nearestRequest] = 1;
    }

    printf("Total Seek Time = %d\n",
           totalSeekTime);

    return 0;
}


SSTF Algorithm
Start
Input number of disk requests
Input request queue
Input initial head position
Mark all requests as unvisited

Repeat until all requests are completed:

a. Find request nearest to current head position

b. Move head to nearest request

c. Add seek distance to total seek time

d. Mark request as completed

Display total seek time
Stop
