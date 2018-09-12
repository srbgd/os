#include <stdio.h>
#include <unistd.h>

int main(){
	for(int i = 0; i < 3; i++){
		pid_t pid = fork();
		if(pid == -1){
			perror("Fork failed");
			return 1;
		}
	}
	sleep(5);
	return 0;
}
