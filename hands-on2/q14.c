/*
============================================================================
Name : q14.c
Author : Nishtha Paul
Q. Write a simple program to create a pipe, write to the pipe, read from pipe and display on the monitor.
Date: 9th Sept, 2023.

Output:
Message read is ::: This message will be written

Description:
We can check the /proc/<pid>/fd to see that it contains
0, 1, 2, 3, 4 fds
0, 1, 2 refer to /dev/pts/3 (terminal slaves)
3 and 4 refer to filedes[0] and filedes[1].
============================================================================
*/
#include <unistd.h> // pipe(), write(), read()
#include <stdio.h> // printf()
#include <string.h> // strlen()
int main() {
    int filedes[2];
    if (pipe(filedes) == -1) {
        printf("Pipe could not be created\n");
        return 1;
    }
    char* msg_written = "This message will be written";
    write(filedes[1], msg_written, strlen(msg_written));
    char msg_read[100] = "";
    read(filedes[0], msg_read, sizeof(msg_read));
    printf("Message read is ::: %s \n", msg_read);
}