#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
struct Student {
   int roll_no;
   char name[20];
};
int main() {
    int fd = open("person-records.txt", O_RDWR | O_CREAT);
    if (fd == -1) {
		printf("File person-records.txt doesn't exist \n");
		return 0;
	}
   struct Student inp1 = {123, "Ram"};
   struct Student inp2 = {456, "Sita"};
   struct Student inp3 = {789, "Ravan"};

   write(fd, &inp1, sizeof(struct Student));
   write(fd, &inp2, sizeof(struct Student));
   write(fd, &inp3, sizeof(struct Student));

   close(fd);
}