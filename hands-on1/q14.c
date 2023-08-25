#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
int main(int nargs, char* filenames[]) {
    if (nargs == 1) {
        printf("No file provided !!!");
        return 0;
    }
    struct stat st;
    int ret = stat(filenames[1], &st);
    if (ret == -1) {
        printf("Error in opening and fetching the details of file \n");
        return 0;
    }
    switch (st.st_mode & S_IFMT) {
        case S_IFREG:
            printf("regular file\n");
            break;
        case S_IFDIR:
            printf("directory\n");
            break;
        case S_IFCHR:
            printf("character device\n");
            break;
        case S_IFBLK:
            printf("block device\n");
            break;
        case S_IFLNK:
            printf("symbolic (soft) link\n");
            break;
        case S_IFIFO:
            printf("FIFO or pipe\n");
            break;
        case S_IFSOCK:
            printf("socket\n");
            break;
        default:
            printf("unknown file type?\n");
    }
}