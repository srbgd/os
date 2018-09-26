#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

#define ever (;;)

int main(){
	int fd[2];
	if(pipe(fd) == -1){
		perror("Can't create a pipe");
		exit(EXIT_FAILURE);
	}else{
		puts("A pipe created");
	};
	pid_t pid = fork();
	if(pid == -1){
		perror("Can't fork this process");
		exit(EXIT_FAILURE);
	}else if(pid == 0){
		// first child
		puts("First child created");
		pid_t second_child;
		if(read(fd[0], &second_child, sizeof(second_child)) == -1){
			perror("Can't read 2nd child pid from the pipe");
			exit(EXIT_FAILURE);
		}else{
			puts("First child recieved pid of the second child");
		};
		puts("First child is sleeping 2 seconds");
		sleep(2);
		puts("First child is about to kill the second");
		kill(second_child, SIGSTOP);
		puts("First child terminates");
		exit(EXIT_SUCCESS);
	}else{
		// parent
		pid_t first_child = pid;
		pid = fork();
		if(pid == -1){
			perror("Can't fork this process");
			exit(EXIT_FAILURE);
		}else if(pid == 0){
			puts("Second child created");
			for ever { puts("Second child is alive"); sleep(1); };
		}else{
			// parent
			puts("Parent writes pid of the second child into the pipe");
			if(write(fd[1], &pid, sizeof(pid)) == -1){
				perror("Can't write 2nd child pid into the pipe");
				exit(EXIT_FAILURE);
			};
			puts("Parent waits for the termination of the second child");
			int status;
			if(waitpid(pid, &status, WUNTRACED) == -1){
				perror("Can't wait for the 1st child process");
				exit(EXIT_FAILURE);
			};
			if(WIFSTOPPED(status) && WSTOPSIG(status) == SIGSTOP){
				puts("Second child was stopped by SIGSTOP signal");
			}else{
				puts("Second child was not stopped by SIGSTOP signal");
			};
			puts("Parent process is terminating");
		};
	}
	exit(EXIT_SUCCESS);
}
