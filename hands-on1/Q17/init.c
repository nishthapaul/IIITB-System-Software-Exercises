#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
int main() {
    int fd = open("ticket-info.txt", O_WRONLY);
    if (fd == -1) {
		printf("File ticket-info.txt doesn't exist \n");
		return 0;
	}
    int ticket_number = 0;
    scanf("%d", &ticket_number);
    // read(0, &ticket_number, sizeof(int));
    printf("%d \n", ticket_number);
    write(fd, &ticket_number, sizeof(int));
    close(fd);
}