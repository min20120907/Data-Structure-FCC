#include <stdio.h>
#include<stdlib.h>

int main(int argc, char **argv) {
	int i;
	for(i=1;i<=10;){
		++i;
		if(i==5){
			break;
		}
		printf("%d",i);
	}
	printf("\n");
	for(i=1;i<=10;) {
		++i;
		if(i==5){
			continue;
		}
		printf("%d",i);
	}
		
	return 0;
}
