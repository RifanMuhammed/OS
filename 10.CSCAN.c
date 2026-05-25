#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, total = 0;
    int req[20];

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &req[i]);
    }    
        
    printf("Enter initial head position: ");
    scanf("%d", &head);

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(req[i] > req[j]) {
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

    int idx = 0;
    while(idx < n && req[idx] < head)
        idx++;
//
    // move right
    for(int i = idx; i < n; i++) {
        total += abs(head - req[i]);
        head = req[i];
    }
    // jump to beginning
    if(idx > 0) {
        total += abs(head - req[0]);
        head = req[0];
    }
    // continue right again
    for(int i = 0; i < idx; i++) {
        total += abs(head - req[i]);
        head = req[i];
    }
//
    printf("Total Seek Time (CSCAN) = %d\n", total);
}
