#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	char *sent = "this is an exercise";

	for (int i =0; i< strlen(sent);i++){
		char tmp =  (((int) sent[i]-77)%26)+97;
		if(!isalpha(sent[i]))
			tmp = sent[i];
		printf("%c", tmp);
	}
	printf("\n");

	return 0;
}
