/*
============================================================================
Name : q20-server.c
Author : Nishtha Paul
Q. Write two programs so that both can communicate by FIFO -Use one way communication.
Date: 10th Oct, 2023.
============================================================================
*/
#include <unistd.h> // pipe(), fork(), write(), read()
#include <string.h> // strlen()
#include <stdio.h> // printf(), scanf()
#include <fcntl.h> // open(), close()
int main() {
    char* input;
    int fd = open("myfifo", O_WRONLY);
    scanf("%[^\n]", input);
    write(fd, input, strlen(input));
    return 0;
}