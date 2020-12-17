#include <stdio.h>

int gcd(int a, int b) {
	if(a==0) return b;
	else if(a>b){
		return gcd(a%b,b);
	}else if(b>a){
		return gcd(b%a,a);
	}
}

int main(int argc, char **argv){
	int a,b;
	printf("Please input 2 numbers to gcd: \n");
	scanf("%d",&a);
	scanf("%d",&b);
	printf("%d\n", gcd(a,b));
	return 0;
}
