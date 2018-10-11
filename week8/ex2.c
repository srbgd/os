#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
#define KB 1024
#define MB (KB*KB)

int main(){
	void* p[SIZE];
	for(int i = 0; i < SIZE; i++){
		p[i] = malloc(10 * MB);
		memset(p[i], 0, 10 * MB);
		sleep(1);
	};
	for(int i = 0; i < SIZE; i++){
		free(p[i]);
	};
	return 0;
}
