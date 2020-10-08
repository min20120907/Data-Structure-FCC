#include<stdio.h>

void swap(int *a,int *b){
	int c = *a;
	*a = *b;
	*b = c;
}

int main(){
	int a = 1, b = 2;
	swap(&a, &b);
	printf("%d \n",a);
	printf("%d \n",b);
	return 0;
}
