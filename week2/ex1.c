#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
	int i = INT_MAX;
	float f = FLT_MAX;
	double d = DBL_MAX;
	printf("int\tsize: %ld\tvalue: %d\n", sizeof(i), i);
	printf("float\tsize: %ld\tvalue: %f\n", sizeof(f), f);
	printf("double\tsize: %ld\tvalue: %f\n", sizeof(d), d);
	return 0;
}
