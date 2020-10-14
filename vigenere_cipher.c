#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int main(){
	char *init = "dollars";
	char *sent = "this is an exercise";
	char *encrypted = malloc(sizeof(sent));
	int space = 0;
	for (int i =0; i<strlen(sent);i++){
		int j = (i-space)%strlen(init);
			
		if(!isalpha(sent[i])){
                        encrypted[i] = sent[i];
			space++;	
		}else{
			encrypted[i] = ((int) sent[i] + (int) init[j] -97 -97) % 26 + 97;
		}
		
	}
	printf("%s\n", encrypted);
	return 0;
}
