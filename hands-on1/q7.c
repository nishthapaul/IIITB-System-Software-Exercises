#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>
#include <unistd.h>
int main(int nargs, char* filenames[]) {
	if (nargs != 2) {
        printf("Insufficient arguments !! 2 required. \n");
        return 0;
    }
	int fd_read = open(filenames[1], O_RDONLY);
	int fd_write = open(filenames[2], O_WRONLY | O_CREAT, 0777);

	if (fd_read == -1) {
		printf("File %s doesn't exist \n", filenames[1]);
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