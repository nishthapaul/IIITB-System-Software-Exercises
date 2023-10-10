/*
============================================================================
Name : q21-client.c
Author : Nishtha Paul
Q. Write two programs so that both can communicate by FIFO - Use two way communication.
Date: 10th Oct, 2023.

Output:
Message from server read by client is :: Hi, My name is Server 
Give a message which client will send to server 
Hi, My name is Client

Requirement:
Create 2 fifos :
mkfifo -m 0744 fifo_s2c // server to client
mkfifo -m 0744 fifo_c2s // client to server
============================================================================
*/
#include <unistd.h> // read(), write()
#include <fcntl.h> // open()
#include <stdio.h> // printf(), scanf()
#include <string.h> // strlen()
int main() {
    int fd_s2c = open("fifo_s2c", O_RDONLY);
    int fd_c2s = open("fifo_c2s", O_WRONLY);

    char msg_read_by_client[100] = "";
    read(fd_s2c, msg_read_by_client, sizeof(msg_read_by_client));
    printf("Message from server read by client is :: %s \n", msg_read_by_client);

    char msg_sent_by_client[100] = "";
    printf("Give a message which client will send to server \n");
    scanf("%[^\n]", msg_sent_by_client);
    write(fd_c2s, msg_sent_by_client, strlen(msg_sent_by_client));

    return 0;
}