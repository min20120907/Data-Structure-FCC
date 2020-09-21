#include<stdio.h>
#include <stdlib.h>

int main(void){
	printf("Please enter a threshold number: \n");
	int threshold;
	scanf("%d", &threshold);

	int randArr[10];
	int min=0, max=0;
	int *v1, *v2;

	v1 = malloc(sizeof(int)*10);
	v2 = malloc(sizeof(int)*10);

	srand(0);
	
	for(int i = 0; i < 10; i++){
		randArr[i] = rand();
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

	return 0;
}
