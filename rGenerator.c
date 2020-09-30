#include<stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Frac{
	int numerator;
	int denominator;
}frac;

// Declare the compare funciton, that can convert all the types of elements into integer hashcode.
int cmpfunc(const void * a, const void * b){
	return (*(int*)a - *(int*)b);
}

int main(void){
	printf("Please enter a threshold number: \n");
	double threshold;
	scanf("%lf", &threshold);
	
	int digits;

	printf("Please enter the digits of numbers:\n");
	scanf("%d", &digits);

	double randArr[10];
	int min=0, max=0;
	double *v1, *v2;

	v1 = malloc(sizeof(double)*10);
	v2 = malloc(sizeof(double)*10);

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
		printf("%lf ", randArr[i]);
	printf("\n");
	printf("max array: ");
	for(int i = 0;i < max-1;i++)
		printf("%lf ", v1[i]);
	
	printf("\nmin array: ");
	
	for(int i =0; i< min-1;i++)
		printf("%lf ", v2[i]);
	
	printf("\n");

	qsort(randArr, 10, sizeof(double), cmpfunc);
	printf("Sorted: ");
	for (int i = 0;i < 10; i++)
		printf("%lf ", randArr[i]);
	printf("\n");
	printf("medium value: %lf\n", ((double) randArr[5]+(double) randArr[4])/(double) 2);

	return 0;
}
