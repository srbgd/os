#include <stdio.h>
#include <unistd.h>

int main(){
	int n = 1;
	pid_t pid = fork();
	if(pid == -1){
		perror("Fork failed");
		return 1;
	}else if(pid){
		printf("Hello from parent [%d - %d]\n", pid, n);
	}else{
		printf("Hello from child [%d - %d]\n", pid, n);
	}
	return 0;
}
