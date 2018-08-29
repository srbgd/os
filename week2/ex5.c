#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char* buf;

void print_triangle(int n, int l){
	for(int i = 0; i < l; i++){
		buf[i] = ' ';
	}
	for(int i = l; i < 2 * n - l + 1; i++){
		buf[i] = '*';
	}
	buf[2 * n - l + 1] = 0;
	puts(buf);
	if(l > 0){
		print_triangle(n, l - 1);
	}
}

void print_triangle1(int n, int l){
	for(int i = 0; i < n - l + 1; i++){
		buf[i] = '*';
	}
	buf[n - l + 1] = 0;
	puts(buf);
	if(l > 0){
		print_triangle1(n, l - 1);
	}
}

void print_triangle2(int n, int l){
	for(int i = 0; i < abs((n - l + n / 2) % n - n / 2) + 1; i++){
		buf[i] = '*';
	}
	buf[abs((n - l + n / 2) % n - n / 2) + 1] = 0;
	puts(buf);
	if(l > 0){
		print_triangle2(n, l - 1);
	}
}

void print_square(int n, int l){
	for(int i = 0; i <= n; i++){
		buf[i] = '*';
	}
	buf[n + 1] = 0;
	puts(buf);
	if(l > 0){
		print_square(n, l - 1);
	}
}

int main(int argc, char** argv) {
	if(argc == 2){
		int n = atoi(argv[1]) - 1;
		buf = malloc(2 * n + 1);
		print_triangle(n , n);
		puts("");
		print_triangle1(n , n);
		puts("");
		print_triangle2(n , n);
		puts("");
		print_square(n, n);
	}else{
		return 1;
	}
	return 0;
}
