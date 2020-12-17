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

char *toString(int a[], int size) {
	char tmp[101]="";

	int nchar;
	for(int i =0; i<size;i++) {
		char num[100]="";
		switch(a[i]){
			case 10:
				sprintf(num, "A%n", &nchar);
				break;
			case 11:
				sprintf(num, "B%n", &nchar);
				break;
			case 12:
				sprintf(num, "C%n", &nchar);
				break;
			case 13:
				sprintf(num, "D%n", &nchar);
				break;
			case 14:
				sprintf(num, "E%n", &nchar);
				break;
			case 15:
				sprintf(num, "F%n", &nchar);
				break;
			default:
				sprintf(num, "%d%n", a[i], &nchar);
				break;
		}
		strcat(tmp, num);
	}
	//printf("in toString it is %s\n",tmp);
	char* tmp_p = &tmp[0];
	return tmp_p;
}

// change base function maximum output 100 bits
char *base(int a, int b){
	int *result = malloc(sizeof(int) * 101);
	int i = 0;
	do{
		result[i] = a%b;
		i++;
		a /= b;
	}while((double)((double)a/(double)b)!=0);
	reverse(result, i);
	char *result_s = toString(result, i);
	//printf("%s", result_s);
	return result_s;
	//return result;
}



int main(int argc, char **argv) {
	int a, b;
	printf("Please input the number you test:\n");
	scanf("%d", &a);
	printf("Please input the base:\n");
	scanf("%d", &b);
	printf("The result is %s\n", base(a,b));
	return 0;
}
