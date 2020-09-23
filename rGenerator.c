#include<stdio.h>
#include <stdlib.h>
#include <math.h>

// Declare the compare funciton, that can convert all the types of elements into integer hashcode.
int cmpfunc(const void * a, const void * b){
	return (*(int*)a - *(int*)b);
}

int main(void){
	printf("Please enter a threshold number: \n");
	int threshold;
	scanf("%d", &threshold);
	
	int digits;

	printf("Please enter the digits of numbers:\n");
	scanf("%d", &digits);

	int randArr[10];
	int min=0, max=0;
	int *v1, *v2;

	v1 = malloc(sizeof(int)*10);
	v2 = malloc(sizeof(int)*10);

	srand(0);
	
	for(int i = 0; i < 10; i++){
		randArr[i] = rand() % (int) (pow((double)10, (double)digits));
		if(randArr[i] >= threshold){	
			v1[max] = randArr[i];
			max++;
		}
		else if(randArr[i] < threshold){
			v2[min] = randArr[i];
			min++;
		}
	}
	printf("random array: ");
	for (int i = 0; i< 10;i++)
		printf("%d ", randArr[i]);
	printf("\n");
	printf("max array: ");
	for(int i = 0;i < max-1;i++)
		printf("%d ", v1[i]);
	
	printf("\nmin array: ");
	
	for(int i =0; i< min-1;i++)
		printf("%d ", v2[i]);
	
	printf("\n");

	qsort(randArr, 10, sizeof(int), cmpfunc);
	printf("Sorted: ");
	for (int i = 0;i < 10; i++)
		printf("%d ", randArr[i]);
	printf("\n");
	printf("medium value: \n%d\n", randArr[5]);

	return 0;
}
