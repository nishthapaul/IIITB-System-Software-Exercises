#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main(int nargs, char* filenames[]) {
    if (nargs == 1) {
        printf("No file provided !!! \n");
        return 0;
    }
	int fd = open(filenames[1], O_RDONLY);

	char str[1000] = "";
	char ch;
	int i = 1;

	while(read(fd, &ch, 1) > 0){
		if(ch == '\n'){
			printf("Line %d : %s\n", i, str);
			i++;
			strcpy(str, "");
		}
		else{
			strncat(str, &ch, 1);
		}
	}
    
	close(fd);
	return 0;
}