#include <sys/mman.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

const char* str = "This is a nice day";
#define LEN 18

int main(){
	int fd = open("ex1.txt", O_RDWR | O_CREAT | O_TRUNC);
	if(fd == -1){
		perror("open");
		return 1;
	};
	if(lseek(fd, LEN - 1, SEEK_SET) == -1){
		perror("lseek");
		return 1;
	};
	if(write(fd, "", 1) == -1){
		perror("write");
		return 1;
	};
	void* buf = mmap(NULL, LEN, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	if(buf == (void *)-1){
		perror("mmap");
		return 1;
	}
	memcpy(buf, str, LEN);
	msync(buf, LEN, MS_SYNC);
	munmap(buf, LEN);
	close(fd);
	return 0;
}
