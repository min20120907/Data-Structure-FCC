#include<stdio.h>

typedef struct Frac{
	int numerator;
	int denominator;
}frac;

int cmpfrac(const void *a, const void *b){
	return ((*(frac*)a).numerator / (*(frac*)a).denominator) - ((*(frac*)b).numerator / (*(frac*)b).denominator);
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

	//qsort();
	return 0;
}
