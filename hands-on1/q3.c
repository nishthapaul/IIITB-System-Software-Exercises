#include <fcntl.h>
#include <stdio.h>
int main() {
    int fd = creat("sample10.txt", 0777);
    printf("File Descriptor: %d \n", fd);
}
