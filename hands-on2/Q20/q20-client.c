/*
============================================================================
Name : q20-client.c
Author : Nishtha Paul
Q. Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 10th Oct, 2023.

Output:
Input in server - My name is Nishtha
Output in client -
Message from server is :: My name is Nishtha

Requirement:
Create a fifo first :
mkfifo -m 0744 myfifo
============================================================================
*/
#include <unistd.h> // read()
#include <fcntl.h> // open()
#include <stdio.h> // printf()
int main() {
    char output[100];
    int fd = open("myfifo", O_RDONLY);
    read(fd, output, sizeof(output));
    printf("Message from server is :: %s \n", output);
    return 0;
}