#include <stdio.h>
#include <sys/file.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
    int fd = open("q10-file.txt", O_RDWR);
    printf("Before applying locking \n");
    flock(fd, LOCK_EX);
    printf("Acquiring exclusive lock \n");
    getchar();
    flock(fd, LOCK_UN);
}