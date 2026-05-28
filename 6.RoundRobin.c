#include <stdio.h>

// ROUND ROBIN SCHEDULING

int main() {

    int totalProcesses, i;

    int currentTime = 0;
    int completedProcesses = 0;

    int timeQuantum = 3;

    int burstTime[10];
    int arrivalTime[10];
    int remainingTime[10];
    int waitingTime[10];
    int turnaroundTime[10];
    int completionTime[10];

    int finished[10] = {0};

    printf("Enter number of processes: ");
    scanf("%d", &totalProcesses);

    for(i = 0; i < totalProcesses; i++) {

        printf("P%d Burst Arrival: ", i + 1);

        scanf("%d %d",
              &burstTime[i],
              &arrivalTime[i]);

        remainingTime[i] = burstTime[i];
    }

    while(completedProcesses < totalProcesses) {

        int processFound = 0;

        for(i = 0; i < totalProcesses; i++) {

            if(arrivalTime[i] <= currentTime &&
               finished[i] == 0) {

                processFound = 1;

                if(remainingTime[i] > timeQuantum) {

                    remainingTime[i] -= timeQuantum;

                    currentTime += timeQuantum;

                } else {

                    currentTime += remainingTime[i];

                    completionTime[i] = currentTime;

                    remainingTime[i] = 0;

                    finished[i] = 1;

                    completedProcesses++;
                }
            }
        }

        if(processFound == 0) {

            currentTime++;
        }
    }

    for(i = 0; i < totalProcesses; i++) {

        turnaroundTime[i] =
            completionTime[i] - arrivalTime[i];

        waitingTime[i] =
            turnaroundTime[i] - burstTime[i];
    }

    float averageWaitingTime = 0;

    for(i = 0; i < totalProcesses; i++) {

        averageWaitingTime += waitingTime[i];
    }

    averageWaitingTime /= totalProcesses;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < totalProcesses; i++) {

        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",

               i + 1,
               arrivalTime[i],
               burstTime[i],
               completionTime[i],
               turnaroundTime[i],
               waitingTime[i]);
    }

    printf("\nAvg Waiting Time = %.2f\n",
           averageWaitingTime);

    return 0;
}
