#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include <stdio.h>

#define ever (;;)

void kill_handler(int signal){
	puts("Kill signal captured");
};

void stop_handler(int signal){
	puts("Stop signal captured");
};

void usr1_handler(int signal){
	puts("User 1 signal captured");
};

int main(){
	struct sigaction action;
	sigemptyset(&action.sa_mask);
	action.sa_flags = 0;
	action.sa_handler = kill_handler;
	if(sigaction(SIGKILL, &action, NULL)){
		perror("Can't bind kill signal handler");
		// exit(EXIT_FAILURE);
		// do not exit because this code always executes as long as kill signal can't be handled
	};
	action.sa_handler = stop_handler;
	if(sigaction(SIGSTOP, &action, NULL)){
		perror("Can't bind stop signal handler");
		// exit(EXIT_FAILURE);
		// do not exit because this code always executes as long as stop signal can't be handled
	};
	action.sa_handler = usr1_handler;
	if(sigaction(SIGUSR1, &action, NULL)){
		perror("Can't bind user 1 signal handler");
		exit(EXIT_FAILURE);
	};
	for ever { sleep(1); };
	exit(EXIT_SUCCESS);
}
