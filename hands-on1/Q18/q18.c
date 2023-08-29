#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct Student {
   int roll_no;
   char name[20];
};
int main() {
    printf("Before entering into critical section \n");
    int fd = open("person-records.txt", O_RDWR);
    if (fd == -1) {
		printf("File person-records.txt doesn't exist \n");
		return 0;
	}

   struct flock flockstr;

   printf("Give record number on which you want to read / write ? \n");
   int record_no;

   // read(0, &record_no, sizeof(int));
   char record_no_char;
   read(0, &record_no_char, sizeof(char));
   record_no = record_no_char - '0';
   // scanf("%d", &record_no);
   printf("Record %d \n", record_no);
   if (record_no > 3 || record_no <= 0) {
      printf("Invalid record selected \n");
      return 0;
   }

   // // Consume and discard newline character
   char discard;
   read(0, &discard, sizeof(char));

   printf("Which task do you want to perform? \n");
   printf("Give R for read or W for Write \n");
   char task;
   read(0, &task, sizeof(char));
   if (task == 'R') {
      printf("You have selected to read \n");
      flockstr.l_type = F_RDLCK;
   } else if (task == 'W') {
      printf("You have selected to write \n");
      flockstr.l_type = F_WRLCK;
   } else {
      printf("Incorrect task option selected \n");
      return 0;
   }

   // Consume and discard newline character
   read(0, &discard, sizeof(char));

   struct Student stdnt;
   
   lseek(fd, ( record_no - 1 ) * sizeof(struct Student), SEEK_CUR);
   read(fd, &stdnt, sizeof(struct Student));
   printf("Record No : %d \n Roll No: %d \n Name : %s \n", record_no, stdnt.roll_no, stdnt.name);

   // ................. It is always picking the first record
   printf("Before: Going into Record %d \n", record_no);
   flockstr.l_whence = SEEK_SET;
   flockstr.l_start =  ( record_no - 1 ) * sizeof(struct Student);
   flockstr.l_len = sizeof(struct Student);
   flockstr.l_pid = getpid();

   printf("Waiting to acquire lock on record %d \n", record_no);
   fcntl(fd, F_SETLKW, &flockstr);
   printf("Acquired lock on record %d \n", record_no);

   if (task == 'W') {
      printf("You selected to write on this record. \n Please give the new name of the student to be updated \n");
      char newname[10];
      read(0, &newname, sizeof(newname));
      strcpy(stdnt.name, newname);
      lseek(fd, -1 * sizeof(struct Student), SEEK_CUR);
      write(fd, &stdnt, sizeof(struct Student));
   }

   printf("Press enter to exit record %d \n", record_no);
   
   getchar();

   printf("Exiting critical section \n");
   flockstr.l_type = F_UNLCK;
   fcntl(fd, F_SETLKW, &flockstr);

   printf("Out of critical section \n");
}