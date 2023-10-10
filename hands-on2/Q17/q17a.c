/*
============================================================================
Name : q17(a).c
Author : Nishtha Paul
Q. Write a program to execute ls -l | wc using dup.
Date: 9th Sept, 2023.

Output:
       5      38     248
(Same output is displayed when we run this command in the terminal itself)

Description:
fd 0 points to stdin
fd 1 points to stdout
For executing "ls -l",
If we just call execv(ls -l), stdout (fd = 1) is pointing to the terminal, so it will put it's output on terminal,
but we want to pass that output into the pipe
So, we will close stdout -> close(1), means stdout now will not point to terminal.
so, will use dup(fd[1]), it will get the smallest fd which is closed i.e. 1
So, stdout (fd = 1) will now point to our pipe's write end.
Whatever execv will write, will go to stdout, which will pass on to our pipe.

Same will done for wc
we want parent to take input from pipe.
we closed stdin so that it doesn't take input from terminal, and takes from pipe read end.
so dup(fd[0])

Parent's fd 0 1 2 are different from child because both are 2 different processes
Output of exec("wc") will go to the terminal because we haven't disturbed the stdout of parent.

Flow of command - Child (ls -l) | Parent (wc)
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
        close(1);
        dup(fd[1]);
        execlp("ls", "ls", "-l", (char *)NULL);
    } else {
        close(fd[1]);
        close(0);
        dup(fd[0]);
        execlp("wc", "wc", (char *)NULL);
    }
    return 0;
}