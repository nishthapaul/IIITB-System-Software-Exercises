#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
int main() {
	if ( link("sample.txt", "hardlink") < 0 ) {
		perror( "Hard Link could not be created" );
		return 1;
	}
	if ( symlink("sample.txt", "softlink") < 0 ) {
		perror( "Soft Link could not be created" );
		return 1;
	}
	if ( mkfifo("fifo", 0777) < 0 ) {
		perror( "FIFO could not be created" );
		return 1;
	}
	return 0;
}
