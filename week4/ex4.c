#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 100

char buf[BUFFER_SIZE];

char* pattern = " \f\n\r\t\v";

char* strip(char* str){
	char* striped = str;
	while(strpbrk(striped, pattern) == striped){
		striped++;
	}
	strcpy(str, striped);
	for(int i = strlen(str) - 1; i && strchr(pattern, str[i]); i--){
		str[i] = 0;
	}
	return str;
}

char** split(char* str){
	char** args = malloc(sizeof(char*));
	if(!args){
		fputs("Failed to allocate memory\n", stderr);
		exit(1);
	}
	args[0] = NULL;
	int count = 0;
	for (char *p = strtok(str, pattern); p != NULL; p = strtok(NULL, pattern)){
		args = realloc(args, sizeof(char*));
		if(!args){
				fputs("Failed to allocate memory\n", stderr);
				exit(1);
			}
		args[count] = strip(strdup(p));
		args[++count] = NULL;
	}
	return args;
}

void exec(char** args){
	pid_t pid = fork();
	if(pid == -1){
		fputs("Fork failed\n", stderr);
		exit(1);
	}else if(pid){
		if(wait(NULL) == -1){
			perror("Can't wait for the child process");
			exit(1);
		};
	}else{
		if(execvp(args[0], args) == -1){
			perror("Can't run new process");
			exit(1);
		}
	}
}

int main(){
	for(;;){
		fputs("$ ", stdout);
		fgets(buf, BUFFER_SIZE, stdin);
		exec(split(strip(buf)));
	}
	return 0;
}
