#include <sys/resource.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define SIZE 10
#define KB 1024
#define MB (KB*KB)

int main(){
	void* p[SIZE];
	struct rusage* stat = malloc(sizeof(struct rusage));
	for(int i = 0; i < SIZE; i++){
		p[i] = malloc(10 * MB);
		memset(p[i], 0, 10 * MB);
		getrusage(RUSAGE_SELF, stat);
		// this way of getting memory usage information in Linux is not maintained anymore but problems statement demands to use it
		printf("shared: %ld\t data: %ld\t stack: %ld\n", stat->ru_ixrss, stat->ru_idrss, stat->ru_isrss);
		sleep(1);
	};
	free(stat);
	for(int i = 0; i < SIZE; i++){
		free(p[i]);
	};
	return 0;
}
