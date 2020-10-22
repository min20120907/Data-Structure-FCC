#include<stdio.h>
#include<stdlib.h>
typedef struct Frac{
	int numerator;
	int denominator;
}frac;

int cmpfrac(const void *a, const void *b){
	frac aF = *(frac*)a;
	frac bF = *(frac*)b;
	double fracA = (double) aF.numerator / (double) aF.denominator;
	double fracB = (double) bF.numerator / (double) bF.denominator;
	if(fracA > fracB) return 1;
	if(fracA == fracB) return 0;
	if(fracA < fracB) return -1;
}

void printFrac (frac a){
	printf("%d/%d \n", a.numerator, a.denominator);
}

int main(int argc, char **argv){
	FILE *ptr;

	ptr = fopen("fraction_binary.bin","rb");  // r for read, b for binary
	frac frac_arr[10];
	//read binary file's fractions
	int i;
	for ( i = 0; i  < 10; i++ ){
		fscanf(ptr, "%d / %d",&frac_arr[i].numerator, &frac_arr[i].denominator);
	}
	printf("All the fractions: \n");
	for(i=0;i<10;i++)
		printFrac(frac_arr[i]);
	//printf("%d \n", cmpfrac(&frac_arr[0],&frac_arr[1]));
	qsort(frac_arr, 10, sizeof(frac), cmpfrac);
	printf("after sorting...\n");
	for(i=0;i<10;i++)
		printFrac(frac_arr[i]);
	ptr = fopen("fraction_binary.bin", "wb");
	for(i=0;i<10;i++)
		fprintf(ptr, "%d / %d \n", frac_arr[i].numerator, frac_arr[i].denominator) ;
	fclose(ptr);
	return 0;
}
