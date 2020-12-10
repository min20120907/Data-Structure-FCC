#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char str[100] = "20 @ 30 @ @";
	char dest[100]="";
	sscanf(str,"%s ", dest);
	printf("%ld\n",strlen(str));
	return 0;
}
