#include <stdio.h>

int f(int *a){
	*a+=5;
	return 4;
}

int main(){
	int b = 5;
	// functional side effect occurs, the result is 5+5+4
	b += f(&b);
	printf("The result is %d\n", b);
	return 0;
}
