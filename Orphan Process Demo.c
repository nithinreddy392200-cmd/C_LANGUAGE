#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();
    
    if (pid < 0) {
        perror("Fork failed");
        exit(1);
    }
    
    if (pid > 0) {
        // Parent process
        printf("Parent (PID: %d) created child (PID: %d)\n", getpid(), pid);
        printf("Parent terminating immediately...\n");
        // Parent exits quickly, making child orphan
        exit(0);
    } else {
        // Child process
        printf("Child (PID: %d) starting work...\n", getpid());
        printf("Child's original parent PID was: %d\n", getppid());
        
        sleep(5);  // Simulate long-running child task
        
        printf("Child (PID: %d) checking parent after 5s...\n", getpid());
        printf("Child's new parent PID (init): %d\n", getppid());
        
        printf("Orphan child finishing work.\n");
        exit(0);
    }
    
    return 0;
}
