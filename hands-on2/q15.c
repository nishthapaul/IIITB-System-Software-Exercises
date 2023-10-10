/*
============================================================================
Name : q15.c
Author : Nishtha Paul
Q. Write a simple program to send some data from parent to the child process.
Date: 9th Sept, 2023.

Output:
Child read : This is a message from parent

Description:
int pipe(int filedes[2]);
filedes[0] - read
filedes[1] - write
Parent will write so it has to close the read end.
Child will read so it will close the write end.
============================================================================
*/
#include <unistd.h> // pipe(), fork(), write(), read()
#include <string.h> // strlen()
#include <stdio.h> // printf()
int main(){
    int filedes[2];
    if (pipe(filedes) == -1) {
        printf("Pipe could not be created\n");
        return 1;
    }
    if (fork() == 0) {
        close(filedes[1]);
        char msg_read_by_child[100];
        read(filedes[0], msg_read_by_child, sizeof(msg_read_by_child));
        printf("Child read : %s \n", msg_read_by_child);
    }
    else {
        close(filedes[0]);
        char *msg_written_by_parent = "This is a message from parent";
        write(filedes[1], msg_written_by_parent, strlen(msg_written_by_parent));
    }
    return 0;
}