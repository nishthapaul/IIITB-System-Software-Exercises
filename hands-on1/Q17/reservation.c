#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int main() {
    printf("Before applying exclusive locking \n");
    printf("Before entering into critical section \n");
    int fd = open("ticket-info.txt", O_RDWR);
    if (fd == -1) {
		printf("File ticket-info.txt doesn't exist \n");
		return 0;
	}
    flock(fd, LOCK_EX);
    printf("Acquired exclusive lock \n");
    int ticket_number = 0;
    read(fd, &ticket_number, sizeof(int));
    printf("Reading previous ticket number ::: %d \n", ticket_number);
    printf("Press enter to confirm your ticket \n");
    getchar();
    printf("Incrementing ticket number \n");
    ticket_number = ticket_number + 1;
    lseek(fd, 0, SEEK_SET);
    write(fd, &ticket_number, sizeof(int));
    printf("New Ticket Number updated \n");
    flock(fd, LOCK_UN);
    close(fd);
}