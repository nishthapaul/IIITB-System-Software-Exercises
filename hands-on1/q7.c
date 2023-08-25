#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>
#include <unistd.h>
int main(int nargs, char* filenames[]) {
	printf("a: %d", a);
	int fd_read = open("readFrom.txt", O_RDONLY);
	int fd_write = open("readTo.txt", O_WRONLY | O_CREAT, 0777);

	if (fd_read == -1) {
		printf("File readFrom.txt doesn't exist");
		return 0;
	}

	char ch;
	while (read(fd_read, &ch, 1) > 0) {
        write(fd_write, &ch, 1);
    }

	close(fd_read);
    close(fd_write);

    return 0;
}