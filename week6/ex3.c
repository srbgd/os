#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

#define ever (;;)

void handler(int signal){
	puts("Signal captured");
};

int main(){
	struct sigaction action;
	action.sa_handler = handler;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	if(sigaction(SIGINT, &action, NULL)){
		perror("Can't bind signal handler");
		exit(EXIT_FAILURE);
	};
	for ever { sleep(1); };
	exit(EXIT_SUCCESS);
}
