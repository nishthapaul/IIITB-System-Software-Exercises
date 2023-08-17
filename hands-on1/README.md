Q1. Create the following types of a files using system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)

Given the pathname of an existing file in oldpath, the link() and symlink() system call creates a new link, using the pathname specified in newpath. If newpath already exists, it is not overwritten; instead, an error (EEXIST) (-1) results.

File sample.txt should be present and hardlink, softlink and fifo should not be present, otherwise we'lll get an error.

Q2. 