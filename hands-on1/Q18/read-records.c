#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
struct Student {
   int roll_no;
   char name[20];
};
int main() {
    int fd = open("person-records.txt", O_RDONLY);
    if (fd == -1) {
		printf("File person-records.txt doesn't exist \n");
		return 0;
	}
   
   printf("Students Details : \n");
   int record_no = 0;

   struct Student std;

   record_no = record_no + 1;
   printf("Record Number : %d \n", record_no);
   read(fd, &std, sizeof(struct Student));
   printf("Roll No. : %d \n", std.roll_no);
   printf("Name : %s \n \n", std.name);

   record_no = record_no + 1;
   printf("Record Number : %d \n", record_no);
   read(fd, &std, sizeof(struct Student));
   printf("Roll No. : %d \n", std.roll_no);
   printf("Name : %s \n \n", std.name);

   record_no = record_no + 1;
   printf("Record Number : %d \n", record_no);
   read(fd, &std, sizeof(struct Student));
   printf("Roll No. : %d \n", std.roll_no);
   printf("Name : %s \n", std.name);

   close(fd);
}