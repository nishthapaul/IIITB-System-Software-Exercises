Q1. Create the following types of a files using system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)

- Given the pathname of an existing file in oldpath, the link() and symlink() system call creates a new link, using the pathname specified in newpath. If newpath already exists, it is not overwritten; instead, an error (EEXIST) (-1) results.

- File sample.txt should be present and hardlink, softlink and fifo should not be present, otherwise we'll get an error.

Q3. Write a program to create a file and print the file descriptor value. Use creat() system call
- creat(path, mode) is equivalent to
open(path, O_CREAT | O_TRUNC | O_WRONLY, mode);
If the file doesn't exist, it will create a new file, but if it exists, then no error.

Q4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.
- O_EXCL - This flag is used with O_CREAT.
- to indicate that if the file already exists, it should not be opened, and open() will give error.
- It wants that we should bring a non existing file and it will create
- But the question says to try to open an existing file with O_EXCL, but it will giev error. SO they just want us to witness an error.

Q5. Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.
- Here, I used open() system call to create files.
If we specify O_CREAT, then we have to give a mode otherwise it will take a random vllue from the buffer.

Q6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
- send 0 in fd for stdin
- send 1 in fd for stdin
- Tell the user to give (;) to stop writing

Q7. Write a program to copy file1 into file2 - replicate cp command
- Use ```int main(int nargs, char* filenames[])``` to take arguments into main method. Variables name can differ.
- Give 2 file names as arguments while running - ```./a.out <source filename> <destination filename>```

Q8. 

Q9. Write a program to print the information of inode about a given file.
- Use stat system call which takes in file name and struct stat pointer (which will be filled with inode details and can be used later)
- Chapter 15

Q10. Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10 bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
- lseek(fd, 0, SEEK_CUR) with 0 offset bytes is used to retrieve the current location of file offset
-  ```od -a q10-file.txt ```
0000000    a   b   c   d   e   f   g   h   i   j nul nul nul nul nul nul
0000020  nul nul nul nul   q   r   s   t   u   v   w   x   y   z        
0000036

Q11. Write a program to open a file, duplicate the file descriptor and append the file with both the descriptors and check whether the file is updated properly or not. a. use dup b. use dup2 c. use fcntl
- dup() duplicates an existing object descriptor and returns its value to the calling process
- In dup2(), the value of the new descriptor fildes2 is specified. If fildes and fildes2 are equal, then dup2() just returns fildes2; no other changes are made to the existing descriptor. Otherwise, if descriptor fildes2 is already in use, it is first deallocated as if a close(2) call had been done first.
- fcntl() - If we give a file descriptor which is already in use, it will assign the next greater file descriptor.

Q12.Write a program to find out the opening mode of a file. Use fcntl.
- Give the file name as argument while running - ```./a.out <filename>```. This will tell which mode is the file open in.
- I have written the code to open the file in RDWR mode, that is why this file will always be opened in Read/Write mode. If you want to open in Read only or Write only mode, then use O_RDONLY / O_WRONLY. Then the output will be shown accordingly.
- The portable file access modes O_RDONLY, O_WRONLY, and O_RDWR may not correspond to individual bits. To determine the file access mode with fcntl, you must extract the access mode bits from the retrieved file status flags, using the O_ACCMODE mask.
- Macro: int O_ACCMODE
This macro is a mask that can be bitwise-ANDed with the file status flag value to recover the file access mode, assuming that a standard file access mode is in use.

Q13. Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to verify whether the data is available within 10 seconds or not (check in $man 2 select).

Q14. Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file
- Learnt from book (Chapter 15)
- Give the file name as argument while running - ```./a.out <filename>```
- Use lstat() instead of stat()
- stat():
When you use the stat() function on a symbolic link, it returns information about the target of the link (the file or directory that the link points to), rather than the link itself.
If you use stat() on a symbolic link, you won't be able to differentiate between the link itself and the target it points to.
lstat():
The lstat() function is specifically designed to provide information about the symbolic link itself, rather than its target.
When you use lstat() on a symbolic link, it returns information about the link itself, including whether it is a symbolic link and the permissions of the link.

Q15. Write a program to display the environmental variable of the user (use environ).
```environ``` is a array of character arrays or aray of strings

Q16. Implement Mandatory Locking
2 files - q16-shared.c and q16-exclusive.c
Compile - ```gcc -o shared q16-shared.c ``` and ```gcc -o excl q16-exclusive.c ```
Run - ```./shared``` and ```./excl```
We can run 2 shared simultaneously, and both can enter in critical section together.
But, if one shared is in critical section, exclusive can't enter and vica versa.

Q17. Ticket Reservation
If lseek() is not used, then it will append the new number at the end
Then, ```od -a ticket-info.txt ``` looks like this
C nul nul nul   D nul nul nul 
```od -a <filename>``` - to check the contents of the file

Q18. 
