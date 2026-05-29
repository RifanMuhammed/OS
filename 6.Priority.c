#include <stdio.h>
// PRIORITY SCHEDULING
int main() {
    int totalProcesses, i, j;

    int currentTime = 0;
    int completedProcesses = 0;

    int burstTime[10];
    int arrivalTime[10];
    int waitingTime[10];
    int turnaroundTime[10];
    int completionTime[10];
    int priority[10];

    int finished[10] = {0};

    printf("Enter number of processes: ");
    scanf("%d", &totalProcesses);

    for(i = 0; i < totalProcesses; i++) {
        printf("P%d Burst Arrival Priority: ", i + 1);
        scanf("%d %d %d",&burstTime[i], &arrivalTime[i],&priority[i]);
    }

    while(completedProcesses < totalProcesses) {
        int selectedProcess = -1;
        for(i = 0; i < totalProcesses; i++) {
            if(arrivalTime[i] <= currentTime &&
               finished[i] == 0) {

                if(selectedProcess == -1 ||
                   priority[i] > priority[selectedProcess]) {
                    selectedProcess = i;
                }
            }
        }

        if(selectedProcess != -1) {
            currentTime += burstTime[selectedProcess];
            completionTime[selectedProcess] =currentTime;
            finished[selectedProcess] = 1;
            completedProcesses++;
        }
        else {
            currentTime++;
        }
    }

    for(i = 0; i < totalProcesses; i++) {
        turnaroundTime[i] =completionTime[i] - arrivalTime[i];
        waitingTime[i] =turnaroundTime[i] - burstTime[i];
    }

    float averageWaitingTime = 0;
    for(i = 0; i < totalProcesses; i++)
        averageWaitingTime += waitingTime[i];
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

Priority Scheduling Algorithm
Start
Input number of processes
Input:
Burst Time (BT)
Arrival Time (AT)
Priority
Initialize:
Current Time = 0
Completed Processes = 0
Mark all processes as unfinished

Repeat until all processes are completed:

a. Find process:

whose Arrival Time ≤ Current Time
not yet completed
having highest priority

b. If a process is found:

Execute process completely
Update Current Time
Calculate Completion Time (CT)
Mark process as completed
Increase completed count

c. Else:

Increase Current Time by 1
Calculate Turnaround Time (TAT):

TAT=CT−AT

Calculate Waiting Time (WT):

WT=TAT−BT

Calculate Average Waiting Time:

Average WT=
Number of Processes
Sum of WT
	​


Display:
AT
BT
CT
TAT
WT
Average WT
Stop
