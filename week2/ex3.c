#include <stdio.h>
#include <stdlib.h>

char* buf;

void print_triangle(int n, int l){
	for(int i = 0; i < l; i++){
		buf[i] = ' ';
	}
	for(int i = l; i < 2 * n - l + 1; i++){
		buf[i] = '*';
	}
	for(int i = 2 * n - l + 1; i < 2 * n + 1; i++){
		buf[i] = ' ';
	}
	buf[2 * n + 1] = 0;
	puts(buf);
	if(l > 0){
		print_triangle(n, l - 1);
	}
}

int main(int argc, char** argv) {
	if(argc == 2){
		int n = atoi(argv[1]) - 1;
		buf = malloc(2 * n + 1);
		print_triangle(n , n);
	}else{
		return 1;
	}
	return 0;
}
