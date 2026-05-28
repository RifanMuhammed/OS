#include <stdio.h>
// FCFS SCHEDULING
int main() {

    int totalProcesses, i;

    int burstTime[10];
    int arrivalTime[10];
    int waitingTime[10];
    int turnaroundTime[10];
    int completionTime[10];

    printf("Enter number of processes: ");
    scanf("%d", &totalProcesses);

    for(i = 0; i < totalProcesses; i++) {
        printf("P%d Burst Arrival: ", i + 1);
        scanf("%d %d",&burstTime[i],&arrivalTime[i]);
    }

    // Calculate Completion Time

    completionTime[0] =arrivalTime[0] + burstTime[0];

    for(i = 1; i < totalProcesses; i++) {
        if(completionTime[i - 1] < arrivalTime[i])
            completionTime[i] =arrivalTime[i] + burstTime[i];
        else
            completionTime[i] =completionTime[i - 1] + burstTime[i];
    }

    // Calculate TAT and WT
    for(i = 0; i < totalProcesses; i++) {
        turnaroundTime[i] =completionTime[i] - arrivalTime[i];
        waitingTime[i] =turnaroundTime[i] - burstTime[i];
    }
     // Display Output
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < totalProcesses; i++) {
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",i + 1,
               arrivalTime[i],
               burstTime[i],
               completionTime[i],
               turnaroundTime[i],
               waitingTime[i]);
    }

    // Average Waiting Time
    float averageWaitingTime = 0;

    for(i = 0; i < totalProcesses; i++)
        averageWaitingTime += waitingTime[i];
        averageWaitingTime /= totalProcesses;

    printf("\nAvg Waiting Time = %.2f\n",averageWaitingTime);
    return 0;
}
