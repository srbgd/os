#include <stdlib.h>
#include <stdio.h>

void bubble_sort(int* a, int n){
	int temp, newn;
	do {
		newn = 0;
		for(int i = 0; i < n; i++){
			if(a[i] < a[i - 1]){
				temp = a[i - 1];
				a[i - 1] = a[i];
				a[i] = temp;
				newn = i;
			}
		}
		n = newn;
	} while(n);
}

int main(){
	int n;
	printf("Enter the size of the array: ");
	scanf("%d", &n);
	int* a = malloc(n * sizeof(int));
	printf("Enter elements of the array: ");
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	bubble_sort(a, n);
	printf("Sorted array: ");
	for(int i = 0; i < n - 1; i++){
		printf("%d, ", a[i]);
	}
	printf("%d\n", a[n - 1]);
	return 0;
}
