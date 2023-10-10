/*
============================================================================
Name : q16.c
Author : Nishtha Paul
Q. Write a program to send and receive data from parent to child vice versa.
Use two way communication.
Date: 9th Sept, 2023.

Output :
Parent will send data to child 
Child read::: Message sent by parent 
Now child will send data to parent 
Parent read::: Message sent by child 

Description:
2 way communication, we will use 2 pipes.
p2c to send data from parent to child
c2p to send data from child to parent

Learning :
1) In child, earlier I wrote, 
char msg_read_by_child[100];
read(p2c[0], msg_read_by_child, sizeof(msg_read_by_child));
printf("Child read::: %s \n", msg_read_by_child);
Output:
Parent will send data to child 
Child read::: Message sent by parentU??$ 
Now child will send data to parent 
Parent read::: Message sent by child 
.........................................
I was getting garbage value in 2nd line (after parent)
i.e. garbage value in msg sent by parent. This is happening because the array msg_read_by_child had grabage value.
So, either initialize this array with "" like
char msg_read_by_child[100] = "";
or
read 1 less characters and put \0 at the last index of number of bytes read.
char msg_read_by_child[100];
ssize_t bytes_read = read(p2c[0], msg_read_by_child, sizeof(msg_read_by_child) - 1);
msg_read_by_child[bytes_read] = '\0';
printf("Child read::: %s \n", msg_read_by_child);
This was happening because were not handling the null-termination of strings.
============================================================================
*/
#include <unistd.h> // pipe(), fork(), write(), read()
#include <string.h> // strlen()
#include <stdio.h> // printf()
int main() {
    int p2c[2];
    int c2p[2];
    if (pipe(p2c) == -1) {
        printf("Pipe P2C could not be created\n");
        return 1;
    }
    if (pipe(c2p) == -1) {
        printf("Pipe C2P could not be created\n");
        return 1;
    }
    if (fork() == 0) {
        close(p2c[1]);
        char msg_read_by_child[100] = "";
        read(p2c[0], msg_read_by_child, sizeof(msg_read_by_child));
        printf("Child read::: %s \n", msg_read_by_child);

        printf("Now child will send data to parent \n");
        close(c2p[0]);
        char* msg_sent_by_child = "Message sent by child";
        write(c2p[1], msg_sent_by_child, strlen(msg_sent_by_child));
    } else {
        printf("Parent will send data to child \n");
        close(p2c[0]);
        char* msg_sent_by_parent = "Message sent by parent";
        write(p2c[1], msg_sent_by_parent, strlen(msg_sent_by_parent));

        close(c2p[1]);
        char msg_read_by_parent[100];
        read(c2p[0], msg_read_by_parent, sizeof(msg_read_by_parent));
        printf("Parent read::: %s \n", msg_read_by_parent);
    }
    return 0;
}