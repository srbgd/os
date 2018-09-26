#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define BUF_SIZE 100
char buf1[BUF_SIZE], buf2[BUF_SIZE];

int main(){
	memset(buf1, 0, BUF_SIZE);
	memset(buf2, 0, BUF_SIZE);
	strcat(buf2, "Test string");
	int fd[2];
	if(pipe(fd) == -1){
		perror("Can't create a pipe");
		exit(EXIT_FAILURE);
	};
	if(write(fd[1], buf2, strlen(buf2) + 1) == -1){
		perror("Can't write to the pipe");
		exit(EXIT_FAILURE);
	};
	if(read(fd[0], buf1, BUF_SIZE) == -1){
		perror("Can't read from the pipe");
		exit(EXIT_FAILURE);
	};
	puts(buf1);
	close(fd[0]);
	close(fd[1]);
	exit(EXIT_SUCCESS);
}
