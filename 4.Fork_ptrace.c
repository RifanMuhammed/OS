#include <stdio.h>
#include <unistd.h>
#include <sys/ptrace.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    pid = fork();

    if (pid < 0) {
        printf("Fork failed\n");
    } else if (pid == 0) {
        
        // Child process requests tracing
        ptrace(PTRACE_TRACEME, 0, NULL, NULL);
        
        printf("Child Process\n");
        printf("PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
    } else {
        wait(NULL);
        
        printf("Parent Process\n");
        printf("PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
        
        printf("Parent is tracing child using ptrace\n");
    }

    return 0;
}

// NOTE
// ptrace() system call is used for tracing processes.
// PTRACE_TRACEME inside it means "This process should be traced by its parent."
