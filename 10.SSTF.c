#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, head, total = 0;
    int req[20], visited[20] = {0};

    printf("Enter number of requests: ");
    scanf("%d", &n);

    printf("Enter requests: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);
//
    for(int i = 0; i < n; i++) {
        int min = 9999,pos = -1;

        for(int j = 0; j < n; j++) {
            int diff = abs(head - req[j]);
            if(visited[j] == 0 && diff < min) {
                min = diff;
                pos = j;
            }
        }
        total += min;
        head = req[pos];
        visited[pos] = 1;
    }
//
    printf("Total Seek Time = %d\n", total);
}
