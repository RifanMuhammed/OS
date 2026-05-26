#include <stdio.h>
#include <unistd.h>

int main() {
    int i;
    pid_t pid;
    
    printf("Parent PID = %d\n", getpid());
    for(i = 1; i <= 3; i++) {
        pid = fork();

        if(pid == 0) {
            printf("Child %d PID = %d\n", i, getpid());
            return 0;
        }
    }
}
