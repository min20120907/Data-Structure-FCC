#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv){
	char *outcome, *predict;
	printf("Assuming we have 5 outcome condition branches, please input the 5 actaul outcomes:\n");
	scanf("%s", outcome);
	char state = 0;
	for(int i = 0;i < 5;i++){
		if(outcome[i]=='T')
			state++;
		else if(outcome[i]=='N'){}
			
	}
	return 0;
}
