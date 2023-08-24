Q1. Create the following types of a files using system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)

- Given the pathname of an existing file in oldpath, the link() and symlink() system call creates a new link, using the pathname specified in newpath. If newpath already exists, it is not overwritten; instead, an error (EEXIST) (-1) results.

- File sample.txt should be present and hardlink, softlink and fifo should not be present, otherwise we'lll get an error.

Q3. Write a program to create a file and print the file descriptor value. Use creat() system call
- creat(path, mode) is equivalent to
open(path, O_CREAT | O_TRUNC | O_WRONLY, mode);
If the file doesn't exist, it will create a new file, but if it exists, then no error.

Q4. Write a program to open an existing file with read write mode. Try O_EXCL flag also.
- O_EXCL - This flag is used with O_CREAT.
- to indicate that if the file already exists, it should not be opened, and open() will give error.
- It wants that we should bring a non existing filE and it will create
- But the question says to try to open an existing file with O_EXCL, but it will giev error. SO they just want us to witness an error.

Q5. Write a program to create five new files with infinite loop. Execute the program in the background and check the file descriptor table at /proc/pid/fd.
- Here, I used open() system call to create files.
If we specify O_CREAT, then we have to give a mode otherwise it will take a random vllue from the buffer.

Q6. Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
send 0 in fd for stdin
send 1 in fd for stdin
Tell the user to give (;) to stop writing

Q7. Write a program to copy file1 into file2 - replicate cp command

