#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include <stdio.h>

void* my_realloc(void* ptr, size_t size){
	if(ptr == NULL){
		return malloc(size);
	};
	if(size == 0){
		free(ptr);
		return NULL;
	};
	size_t old_size = malloc_usable_size(ptr);
	void* new_ptr = malloc(size);
	memcpy(new_ptr, ptr, (old_size > size)?(size):(old_size));
	free(ptr);
	return new_ptr;
}

int main(){
	int *p = my_realloc(NULL, sizeof(int) * 5);
	memset(p, 0, sizeof(int) * 5);
	p[2] = 42;
	p = my_realloc(p, sizeof(int) * 3);
	printf("%d\n", p[2]);
	my_realloc(p, 0);
	return 0;
}
