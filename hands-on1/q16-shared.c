#include <stdio.h>
#include <sys/file.h>
#include <unistd.h>
#include <fcntl.h>
int main() {
    int fd = open("q10-file.txt", O_RDWR);
    printf("Before applying locking \n");
    flock(fd, LOCK_SH);
    printf("Acquiring shared lock \n");
    getchar();
    flock(fd, LOCK_UN);
    close(fd);
}