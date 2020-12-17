#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// A utility function to print an array of size n 
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++){
    	if(arr[i]<10)
	    printf("%d", arr[i]);
	else
		switch(arr[i]){
			case 10:
				printf("A");
				break;
			case 11:
				printf("B");
				break;
			case 12:
				printf("C");
				break;
			case 13:
				printf("D");
				break;
			case 14:
				printf("E");
				break;
			case 15:
				printf("F");
				break;
		}
    }
}


void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void reverse(int arr[], int n)
{
    int aux[n];
 
    for (int i = 0; i < n; i++) {
        aux[n - 1 - i] = arr[i];
    }
 
    for (int i = 0; i < n; i++) {
        arr[i] = aux[i];
    }
}
// change base function maximum output 100 bits
void base(int a, int b){
	int result[101];
	int i = 0;
	do{
		result[i] = a%b;
		i++;
		a /= b;
	}while((double)((double)a/(double)b)!=0);
	reverse(result, i);
	printf("The result is ");
	printArray(result,i);
	printf("\n");
}



int main(int argc, char **argv) {
	int a, b;
	printf("Please input the number you test:\n");
	scanf("%d", &a);
	printf("Please input the base:\n");
	scanf("%d", &b);
	base(a,b);
	return 0;
}
