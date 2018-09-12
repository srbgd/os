#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 100

char buf[BUFFER_SIZE];

void strip(char* str){
	int l = strlen(str), n = 0;
	for(int i = 0; i < l; i++){
		if(isspace(str[i])){
			n++;
		}else{
			break;
		}
	}
	strcpy(str, str + n);
	l -= n;
	for(int i = 0; i < l; i++){
		if(isspace(str[i])){
			str[i] = 0;
			break;
		}
	}
}

void exec(char* str){
	pid_t pid = fork();
	if(pid == 0){
		execlp(str, str, NULL);
	}else{
		wait(NULL);
	}
}

int main(){
	for(;;){
		fputs("$ ", stdout);
		fgets(buf, BUFFER_SIZE, stdin);
		strip(buf);
		exec(buf);
	}
	return 0;
}
