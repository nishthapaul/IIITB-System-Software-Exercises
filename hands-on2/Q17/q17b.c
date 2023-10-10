/*
============================================================================
Name : q17(b).c
Author : Nishtha Paul
Q. Write a program to execute ls -l | wc using dup2.
Date: 9th Sept, 2023.

Output:
       5      38     248
(Same output is displayed when we run this command in the terminal itself)

Description:
We have to use dup2 here.
So, we don't have to explicitely close(1) because 
dup2() will close the file descriptor demanded and the reallocated to us.
============================================================================
*/
#include <unistd.h> // pipe(), fork(), write(), read()
#include <string.h> // strlen()
#include <stdio.h> // printf()
int main() {
    int fd[2];
    if (pipe(fd) == -1) {
        printf("Pipe could not be created\n");
        return 0;
    }
    if (fork() == 0) {
        close(fd[0]);
        dup2(fd[1], 1);
        execlp("ls", "ls", "-l", (char *)NULL);
    } else {
        close(fd[1]);
        dup2(fd[0], 0);
        execlp("wc", "wc", (char *)NULL);
    }
    return 0;
}