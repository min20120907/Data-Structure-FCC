#include<stdio.h>
#include<stdlib.h>

int values[] = {88, 56, 100, 2, 25};

// Declare the compare funciton that can convert any type of variable into integer hash
int cmpfunc (const void *a, const void * b){
	return (*(int*)a - *(int*)b);
}

int main(){
	int n;

	printf("Before sorting the list is: \n");
	
	for( n = 0; n < 5; n++)
		printf("%d ", values[n]);
	
	qsort(values, 5, sizeof(int), cmpfunc);
	
	printf("\nAfter sorting the list is: \n");

	for (n = 0; n < 5; n++)
		printf("%d ", values[n]);

	printf("\n");
	return 0;
}
