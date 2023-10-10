/*
============================================================================
Name : q21-server.c
Author : Nishtha Paul
Q. Write two programs so that both can communicate by FIFO - Use two way communication.
Date: 10th Oct, 2023.

Output:
Give a message which server will send to client 
Hi, My name is Server
Message from client read by server is :: Hi, My name is Client 
============================================================================
*/
#include <unistd.h> // read(), write()
#include <fcntl.h> // open()
#include <stdio.h> // printf(), scanf()
#include <string.h> // strlen()
int main() {
    int fd_s2c = open("fifo_s2c", O_WRONLY);
    int fd_c2s = open("fifo_c2s", O_RDONLY);

    char msg_sent_by_server[100] = "";
    printf("Give a message which server will send to client \n");
    scanf("%[^\n]", msg_sent_by_server);
    write(fd_s2c, msg_sent_by_server, strlen(msg_sent_by_server));
    
    char msg_read_by_server[100] = "";
    read(fd_c2s, msg_read_by_server, sizeof(msg_read_by_server));
    printf("Message from client read by server is :: %s \n", msg_read_by_server);

    return 0;
}