#include <stdlib.h>
#include <stdio.h>

int main(){
	int n;
	printf("Enter N: ");
	scanf("%d", &n);
	int* a = malloc(sizeof(int) * n);
	if(a == NULL){
		return EXIT_FAILURE;
	}
	for(int i = 0; i < n; i++){
		a[i] = i;
	};
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	};
	printf("\n");
	free(a);
	return EXIT_SUCCESS;
}
