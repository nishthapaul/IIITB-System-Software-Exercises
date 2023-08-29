#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int nargs, char* filenames[]) {
    if (nargs == 1) {
        printf("No file provided !!! \n");
        return 0;
    }
	int fd = open(filenames[1], O_RDWR);
	int rval = fcntl(fd, F_GETFL);
	int flag = rval & O_ACCMODE;
	if (flag == O_RDONLY) {
        printf("File is open in Read Only mode. \n");
    }
	else if (flag == O_WRONLY) {
        printf("File is open in Write Only mode.\n");
    } else if(flag == O_RDWR) {
        printf("File is open in Read and Write mode.\n");
    } else {
        printf("Others.\n");
    }
	close(fd);
	return 0;
}