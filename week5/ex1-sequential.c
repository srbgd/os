#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

void* dowork(void* arg){
	printf("I am thread number %d amd my thread_id is %lu\n", *((int*)arg), pthread_self());
	pthread_exit(NULL);
};

void create_thread(int i){
	pthread_t thread;
	int* arg = (int*)malloc(sizeof(int));
	*arg = i;
	if(pthread_create(&thread, NULL, dowork, arg)){
		exit(EXIT_FAILURE);
	};
	if(pthread_join(thread, NULL)){
		exit(EXIT_FAILURE);
	};
	free(arg);
};

int main(){
	for(int i = 0; i < 3; i++){
		printf("I am about to create thread number %d\n", i);
		create_thread(i);
		printf("I have created thread number %d\n", i);
	};
	exit(EXIT_SUCCESS); /* this is not success because some threads still can be running */
};
