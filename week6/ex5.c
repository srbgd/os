#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <stdio.h>

#define ever (;;)

int main(){
	pid_t pid = fork();
	if(pid == -1){
		perror("Can't fork this process");
		exit(EXIT_FAILURE);
	}else if(pid == 0){
		for ever { puts("I'm alive"); sleep(1); };
	}else{
		sleep(10);
		kill(pid, SIGTERM);
		sleep(3); // shows that the child is not printing "i am alive" anymore
	}
	exit(EXIT_SUCCESS);
}
