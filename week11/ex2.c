#include <stdio.h>
#include <unistd.h>

char buf[5];

int main(){
	setvbuf(stdout, buf, _IOLBF, 5);
	printf("H");
	sleep(1);
	printf("e");
	sleep(1);
	printf("l");
	sleep(1);
	printf("l");
	sleep(1);
	printf("o");
	sleep(1);
	printf("\n");
	return 0;
}
