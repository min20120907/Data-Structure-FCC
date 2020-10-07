#include<stdio.h>

int main(){
	int k = 3;
	int *p;
	p = &k;
	printf("p is %d\n", *p);
	*p = 4;
	printf("p is %d\n", *p);
	return 0;
}
