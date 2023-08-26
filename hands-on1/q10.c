#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int main() {
    int fd = open("q10-file.txt", O_RDWR);
    if (fd == -1) {
		printf("File q10-file.txt doesn't exist \n");
		return 0;
	}

    char *ch = "abcdefghij";
    write(fd, ch, 10);
    lseek(fd, 10, SEEK_CUR);
    ch = "qrstuvwxyz";
    write(fd, ch, 10);
    printf("%lld \n" , lseek(fd, 0, SEEK_CUR));

    close(fd);
    return 0;
}