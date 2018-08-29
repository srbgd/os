#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUF_SIZE 1024

char buf[BUF_SIZE];

int main() {
	fputs("string: ", stdout);
	fgets(buf, BUF_SIZE, stdin);
	int n = strlen(buf) - 1;
	buf[n] = 0;
	char temp;
	for(int i = 0; i < n / 2; i++){
		temp = buf[i];
		buf[i] = buf[n - i - 1];
		buf[n - i - 1] = temp;
	};
	printf("reversed: %s\n", buf);
	return 0;
}
