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
	printf("%d\n", gcd(252,198));
	return 0;
}
