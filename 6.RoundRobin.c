#include <stdio.h>
//ROUND ROBIN SCHEDULING
int main() {
    int n, i, time = 0, completed = 0, tq = 3;
    int bt[10], at[10], rt[10], wt[10], tat[10], ct[10], done[10] = {0};

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("P%d Burst Arrival: ", i+1);
        scanf("%d %d", &bt[i], &at[i]);
        rt[i] = bt[i];
    }
//
    while(completed < n) {
        int count=0;
        
        for(i=0;i<n;i++){
            if(at[i]<=time && done[i]==0){
                found=1
                
                if(rt[i]>tq){
                    rt[i] -=tq;
                    time +=tq;
                } else {
                    time+=rt[i];
                    ct[i]=time;
                    rt[i]=0;
                    done[i]=1;
                    completed++;
                }
            }
        }
        
        if(found==0){
            time++;
        }
    }
//    
    for(i = 0; i < n; i++) {
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];
    }

    float avg = 0;
    for(i = 0; i < n; i++) {
        avg += wt[i];
    }
    avg /= n;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t%d\t%d\t%d\t%d\t%d\n",i+1, at[i], bt[i], ct[i], tat[i], wt[i]);
    }
    printf("\nAvg Waiting Time = %.2f\n", avg);

    return 0;
}
