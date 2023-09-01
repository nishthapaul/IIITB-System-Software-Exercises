#include <sys/stat.h>
#include <stdio.h>
#include <time.h>
int main() {
    struct stat st;
    int a = stat("q1.c", &st);
    if (a == -1) {
        printf("Error opening and fetching the details of file");
        return 0;
    }
    printf("Inode Number - %ld \n", (long) st.st_ino);
    printf("Number of Hard Links - %ld \n", (long) st.st_nlink);
    printf("User ID of file owner - %ld \n", (long) st.st_uid);
    printf("Group ID of file owner - %ld \n", (long) st.st_gid);
    printf("Total file size - %ld Bytes \n", (long) st.st_size);
    printf("Optimal block size for I/O (bytes) - %ld Bytes \n", (long) st.st_blksize);
    printf("Blocks allocated for the file - %ld \n", (long) st.st_blocks);
    printf("Time of last access - %s", ctime(&st.st_atime));
    printf("Time of last data modification - %s", ctime(&st.st_mtime));
    printf("Time of last file status change - %s", ctime(&st.st_ctime));
    printf("%d \n", S_IFMT);
    printf("%d \n", st.st_mode & S_IFMT);
    printf("%d \n", S_IFREG);
}