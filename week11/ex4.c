#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

const char* str = "This is a nice day";
#define LEN 18

int main(){
	int fd1 = open("ex4.txt", O_RDONLY);
	if(fd1 == -1){
		perror("open");
		return 1;
	};
	struct stat sb;
	if(fstat(fd1, &sb) == -1){
		perror("fstat");
		return 1;
	};
	int len = sb.st_size;
	if(!len){
		printf("Can't copy an empty file using mmap");
		return 0;
	}
	void* buf1 = mmap(NULL, len, PROT_READ, MAP_SHARED, fd1, 0);
	if(buf1 == (void *)-1){
		perror("mmap");
		return 1;
	};
	int fd2 = open("ex4.memcpy.txt", O_RDWR | O_CREAT | O_TRUNC, (mode_t)0666);
	if(fd2 == -1){
		perror("open");
		return 1;
	};
	if(lseek(fd2, len - 1, SEEK_SET) == -1){
		perror("lseek");
		return 1;
	};
	if(write(fd2, "", 1) == -1){
		perror("write");
		return 1;
	};
	void* buf2 = mmap(NULL, len, PROT_READ | PROT_WRITE, MAP_SHARED, fd2, 0);
	if(buf2 == (void *)-1){
		perror("mmap");
		return 1;
	};
	memcpy(buf2, buf1, len);
	msync(buf2, len, MS_SYNC);
	munmap(buf1, len);
	munmap(buf2, len);
	close(fd1);
	close(fd2);
	return 0;
}
