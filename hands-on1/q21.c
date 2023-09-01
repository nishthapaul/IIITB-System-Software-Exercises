#include <unistd.h>
#include <stdio.h>
int main() {
    int pid = fork();
    if ( pid == 0 ) {
        printf("PID of child process is : %d \n", getpid());
    } else {
        printf("PID of parent process is : %d \n", getpid());
        printf("Parent: PID of child should be printed as : %d \n", pid);
    }
}