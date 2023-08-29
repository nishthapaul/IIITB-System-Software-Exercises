#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>

int main() {
	int fd = open("file.txt", O_WRONLY|O_APPEND);
	if(fd == -1) {
		printf("File person-records.txt doesn't exist \n");
		return 0;
	}
	else{
        int fd2, fd3, fd4;
		printf("Using dup\n");
		fd2 = dup(fd);
		printf("fd1 = %d\n", fd);
		printf("fd2 = %d\n", fd2);

        char fd_text[] = "This is written by the original file descriptor\n";
        char dup_fd_text[] = "This is written by the duplicate file descriptor\n";
		write(fd, fd_text, sizeof(fd_text));
		write(fd2, dup_fd_text, sizeof(dup_fd_text));
		printf("Duplication successful...\n");

		printf("Using dup2\n");
		fd3 = dup2(fd, 27);
		printf("fd1 = %d\n", fd);
		printf("fd3 = %d\n", fd3);

        char dup2_fd_text[] = "Using dup2\n";
        write(fd, dup2_fd_text, sizeof(dup2_fd_text));
		write(fd, fd_text, sizeof(fd_text));
		write(fd3, dup_fd_text, sizeof(dup_fd_text));
		printf("Duplication successful...\n");

		printf("Using fcntl\n");
		fd4 = fcntl(fd, F_DUPFD, 27);
		printf("fd1 = %d\n", fd);
		printf("fd4 = %d\n", fd4);

        char fcntl_fd_text[] = "Using fcntl\n";
        write(fd, fcntl_fd_text, sizeof(fcntl_fd_text));
		write(fd, fd_text, sizeof(fd_text));
		write(fd4, dup_fd_text, sizeof(dup_fd_text));
		printf("Duplication successful...\n");

		close(fd);
		close(fd2);
		close(fd3);
		close(fd4);
	}
	return 0;
}