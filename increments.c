#include <stdio.h>
#include <stdlib.h>

int increment(int a[], int size){
	
	int i, sum=0,tmp=0;
	for (i=0;i<size;i++){
		if(a[i]==0)
			sum=0;
		else
			sum++;
		if(tmp<sum)
			tmp=sum;
	}
	return tmp;
}

int main(int argc, char **argv){
	int test[] = {0,0,1,0,1,1,0,1,1,1,1};
	printf("%d",increment(test,11));
	return 0;
}
