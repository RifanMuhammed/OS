#include <stdio.h>
//SJF SCHEDULING
int main() {
    int n, i, time = 0, completed = 0;
    int bt[10], at[10], wt[10], tat[10], ct[10], done[10] = {0};

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("P%d Burst Arrival: ", i+1);
        scanf("%d %d", &bt[i], &at[i]);
    }

    while(completed < n) {
        int min = 9999, idx = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && done[i] == 0 && bt[i] < min) {
                min = bt[i];
                idx = i;
            }
        }

        if(idx != -1) {
            time += bt[idx];
            ct[idx] = time;
            done[idx] = 1;
            completed++;
        } else {
            time++;
        }
    }

    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    float avg = 0;
    for(i = 0; i < n; i++) {
        avg += wt[i];
    }
    avg /= n;

    printf("\nAvg Waiting Time = %.2f\n", avg);

    return 0;
}
