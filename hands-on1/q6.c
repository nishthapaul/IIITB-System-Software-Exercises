#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdio.h>
#include <unistd.h>
int main() {
	int fd_stdin = 0;
	int fd_stdout = 1;
	char* ch;
	printf("Give semi colon (;) to quit \n");
	while (1) {
		read(fd_stdin, ch, 1);
		if (*ch == ';') { break; }
		write(fd_stdout, ch, 1);
	}
}
