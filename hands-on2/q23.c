/*
============================================================================
Name : q23.c
Author : Nishtha Paul
Q. Write a program to print the maximum number of files can be opened within a process
and size of a pipe (circular buffer).
Date: 10th Oct, 2023.

Output :
PIPE_BUF = 512 	 OPEN_MAX = 256 

Description :
Max number of files opened within a process can be determined by OPEN_MAX macro.
Max amount of data that can be written to a pipe is determined by PIPE_BUF macro.
============================================================================
*/
#include <unistd.h>
#include <stdio.h>
int main() {
    long PIPE_BUF, OPEN_MAX;
    PIPE_BUF = pathconf(".", _PC_PIPE_BUF);
    OPEN_MAX = sysconf(_SC_OPEN_MAX);
    printf("PIPE_BUF = %ld \t OPEN_MAX = %ld \n", PIPE_BUF, OPEN_MAX);
    return 0;
}