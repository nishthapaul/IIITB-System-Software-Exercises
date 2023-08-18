#include <fcntl.h>
#include <stdio.h>
int main() {
    int fd1 = open("sample1.txt", O_CREAT, 0744);
    printf("File Descriptor: %d \n", fd1);
    int fd2 = open("sample2.txt", O_CREAT, 0744);
    printf("File Descriptor: %d \n", fd2);
    int fd3 = open("sample3.txt", O_CREAT, 0777);
    printf("File Descriptor: %d \n", fd3);
    int fd4 = open("sample4.txt", O_CREAT, 0777);
    int fd5 = open("sample5.txt", O_CREAT, 0777);
    getchar();
}
